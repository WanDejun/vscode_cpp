#include <iostream>

template <typename T>
class My_shared_ptr {
private:
    T* pointer;
    int* RefCounter;
public:
    explicit My_shared_ptr(T* resource_ptr) : pointer(resource_ptr), RefCounter(new(int)(1)) {} // 通过普通指针初始化

    My_shared_ptr() : pointer(nullptr), RefCounter(nullptr) {} // 默认构造函数

    My_shared_ptr(const My_shared_ptr<T>& p) { // 拷贝构造函数
        pointer = p.pointer;
        RefCounter = p.RefCounter;
        if (pointer != nullptr) (*RefCounter)++;
    }

    My_shared_ptr(My_shared_ptr<T>&& p) { // 移动构造函数
        p.swap(*this);
    }

    My_shared_ptr<T> operator=(const My_shared_ptr<T>& p) { // 拷贝赋值函数
        pointer = p.pointer;
        RefCounter = p.RefCounter;
        if (pointer != nullptr) (*RefCounter)++;
    }

    My_shared_ptr<T> operator=(My_shared_ptr<T>&& p) { // 移动赋值函数
        p.swap(*this);
    }

    ~My_shared_ptr() {
        RefCounter--;
        if (pointer != nullptr && (*RefCounter) == 0) {
            delete pointer;
            delete RefCounter;
        }
    }

    void swap(My_shared_ptr<T>& p) {
        p.pointer = pointer;
        p.RefCounter = RefCounter;
        pointer = nullptr;
        RefCounter = nullptr;
    }

    T* Get() const {
        return pointer;
    }

    int GetRefCounter() const {
        return RefCounter == nullptr ? 0 : *RefCounter;
    }
};

int main() {
    My_shared_ptr<int> ptr1(new(int)(4));
    My_shared_ptr<int> ptr2(ptr1);

    std::cout << "ptr2--> RefCounter:" << ptr2.GetRefCounter() << "  Val:" << *ptr2.Get() << std::endl;

    My_shared_ptr<int> ptr3(std::move(ptr1));
    *ptr2.Get() = 10;

    std::cout << "ptr3--> RefCounter:" << ptr3.GetRefCounter() << "  Val:" << *ptr3.Get() << std::endl;

    system("pause");
    return 0;
}