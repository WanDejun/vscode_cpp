#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <windows.h>
using namespace std;

#define PI acos(-1)

const float theta_spacing = 0.07;  // 旋转体切面的圆上的点弧度旋转
const float phi_spacing = 0.02;    // 旋转体绕轴每份旋转弧度

const int screen_height = 50;
const int screen_width = 50;

const float R1 = 1.5;  // 旋转体切面圆半径
const float R2 = 4;  // 旋转体切面圆心和旋转轴距离
const float K2 = 10;  // 人和旋转体旋转中心的距离
// 基于屏幕大小计算 K1
// 对于torus的边缘, 也就是距离旋转中心$R1+R2$
// 我们希望它能被展示到屏幕的 3/8,也就是整个展示到屏幕的6/8,上下左右留白1/8
// 根据3D和2D转换关系
// 屏幕宽度*3/8 = K1*(R1+R2)/(K2+0)
const float K1 = screen_width * K2 * 3 / (8 * (R1 + R2));

void render_frame(float A, float B) {  // A,B就是上面的旋转角度
    // 预计算 A,B的sin和cos
    float cosA = cos(A), sinA = sin(A);
    float cosB = cos(B), sinB = sin(B);
    // 输出字符
    vector<vector<char>> output(screen_width, vector<char>(screen_height, ' '));
    // 2D屏幕上的点原来在eslint3D物体上的z坐标记录
    vector<vector<float>> zbuffer(screen_width, vector<float>(screen_height));

    // 且面圆上的点
    for (float theta = 0; theta < 2 * PI; theta += theta_spacing) {
        // 预先计算 theta 的sin和cos
        float costheta = cos(theta), sintheta = sin(theta);

        // 旋转体 ,上面的圆绕旋转轴旋转phi
        for (float phi = 0; phi < 2 * PI; phi += phi_spacing) {
            // 同样预先计算 phi 的 sin和cos
            float cosphi = cos(phi), sinphi = sin(phi);

            // 绕y轴旋转前 圆上的点 的 x,y
            float circlex = R2 + R1 * costheta;
            float circley = R1 * sintheta;

            // 计算出最终的 3D (x,y,z) 坐标,
            // 上面公式是想对于旋转中心,这里z加上K2 表示相对于人的眼睛的
            float x = circlex * (cosB * cosphi + sinA * sinB * sinphi) -
                      circley * cosA * sinB;
            float y = circlex * (sinB * cosphi - sinA * cosB * sinphi) +
                      circley * cosA * cosB;
            float z = K2 + cosA * circlex * sinphi + circley * sinA;
            float ooz = 1 / z;  // "one over z"

            // 计算在屏幕上的x和y,因为是屏幕上原点要移动到 屏幕中心,
            // 至此有了2D上的位置
            int xp = (int)(screen_width / 2 + K1 * ooz * x);
            int yp = (int)(screen_height / 2 - K1 * ooz * y);

            // 计算光照
            float L = cosphi * costheta * sinB - cosA * costheta * sinphi -
                      sinA * sintheta +
                      cosB * (cosA * sintheta - costheta * sinA * sinphi);
            // 因为选取的光的模长度sqrt2, 所以光强度[-sqrt2,sqrt2]之间,
            // 小于零的视作在背面直接看不见
            if (L >= 0) {
                // 检查z级别, z越小ooz越大,离人越近,覆盖优先级更高
                if (ooz > zbuffer[xp][yp]) {
                    zbuffer[xp][yp] = ooz;
                    int luminance_index = L * 8;
                    // luminance_index 现在范围是 0..11 (8*sqrt(2) = 11.3)
                    // 因此字符映射如下
                    output[xp][yp] = ".,-~:;=!*#$@"[luminance_index];
                }
            }
        }
    }
    // 最后输出output到屏幕即可
    // 在终端里 控制光标到终端的起始,可以重用屏幕输出
    //printf("\x1b[H");
    for (int j = 0; j < screen_height; j++) {
        for (int i = 0; i < screen_width; i++) { putchar(output[i][j]); }
        putchar('\n');
    }
}

int main() {
    for (float i = 0; 1; i+=0.1) { 
        render_frame(i, 1);
        Sleep(1000);
        system("cls");
    }
    system("pause");
    return 0;
}