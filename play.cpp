#include <iostream>
#include <cstring>
#include <format>
using namespace std;

int main () {
    char str1[] = "123";
    char str2[4]; strcpy(str2, "123");
    char* str3 = new char[4]{"123"};

    *(str1 + 1) = '4';
    *(str2 + 1) = '5';
    *(str3 + 1) = '6';

    cout << std::format("str1: {0}\nstr2: {1}\nstr3: {2}", str1, str2, str3) << endl;

    delete[] str3;

    system("pause");
}