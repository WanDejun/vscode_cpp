#include <stdio.h>
#include <windows.h>
using namespace std;
int main()
{
    float x = 0.1;
    if (x == 0.1) printf("1");
    else if (x == 0.1f) printf("2");
    else printf("3");

    system("pause");
    return 0;
}