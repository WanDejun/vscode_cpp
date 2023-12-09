#include <bits/stdc++.h>
using namespace std;

class Rect {
private:
    int x, x_size, y, y_size;
public:
    void GetDetails(int _x, int _y, int _x_size, int _y_size) {
        x = _x;
        y = _y;
        x_size = _x_size;
        y_size = _y_size;
    }
    int Area() {
        return x_size * y_size;
    }
    void swap(Rect& r) {
        Rect t;

        t.x = r.x;
        t.y = r.y;
        t.x_size = r.x_size;
        t.y_size = r.y_size;

        r.x = x;
        r.y = y;
        r.x_size = x_size;
        r.y_size = y_size;

        x = t.x;
        y = t.y;
        x_size = t.x_size;
        y_size = t.y_size;
    }
};

int main () {
    Rect rect1, rect2;
    
    int nums[4] = {};
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }

    rect1.GetDetails(nums[0], nums[1], nums[2], nums[3]);
    rect2.GetDetails(nums[0] - 1, nums[1] - 1, nums[2] + 1, nums[3] + 1);

    rect2.swap(rect1);

    int area = rect1.Area();
    cout << area << endl;

    system("pause");

    return 0;
}