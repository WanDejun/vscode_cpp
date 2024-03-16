#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int cnt;

void critical_section() {
    std::lock_guard<std::mutex> lock(mtx);
    
    std::cout << std::this_thread::get_id() << "\t" << cnt << std::endl;
    cnt++;
}

int main() {
    std::thread t[10];
    for (int i = 0; i < 10; i++) {
        t[i] = std::thread(critical_section);
    }

    for (int i = 0; i < 10; i++) {
        t[i].join();
    }

    system("pause");
    return 0;
}