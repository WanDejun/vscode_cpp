#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int x;
    double y;
    cin >> x;
    if (x <= 15) y = 4 * static_cast<double>(x) / 3;
    else y = 2.5 * x - 17.5;
    printf("%.2f", y);
    return 0;
}
