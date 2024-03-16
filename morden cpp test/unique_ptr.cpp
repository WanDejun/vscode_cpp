#include <iostream>
#include <memory>

class Foo {
public:
    int val;
    Foo() {
        val = 0;
        std::cout << "Foo()" << std::endl;
    }
    Foo(const Foo& foo) {
        val = foo.val;
        std::cout << "Foo(const Foo& foo)" << std::endl;
    }
    Foo(const Foo&& foo) {
        val = foo.val;
        std::cout << "Foo(const Foo&& foo)" << std::endl;
    }
    ~Foo() {
        std::cout << "~Foo()" << std::endl;
    }
};

int main() {
    {
        std::unique_ptr<Foo> pointer1(std::make_unique<Foo>());
        std::unique_ptr<Foo> pointer2(std::move(pointer2));
    }
    
    system("pause");
    return 0;
}