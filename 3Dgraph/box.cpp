#include <math.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

using std::vector;

template <typename T>
vector<vector<T>> MatrixMutiply(const vector<vector<T>>& A,
                                const vector<vector<T>>& B) {
    if (A[0].size() != B.size()) {
        printf("Error in MatrixMutiply! A: %d * %d; B: %d * %d\n", A.size(),
               A[0].size(), B.size(), B[0].size());
        system("pause");
        exit(0);
    }

    vector<vector<T>> ret(A.size(), vector<T>(B[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < B.size(); k++) {
                ret[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ret;
}

const float pi = acos(-1);
const float detX = 0.05;

const int WinHeight = 60;
const int WinWidth = 60;

const float R = 10;
const float disZ = 20;
const float ref_disZ = WinHeight * disZ * 2 / (4 * R);

void renderDonuts(float angleX, float angleY, float angleZ) {
    float light[] = { 0, 0, 1 };

    float cos_angleX = cos(angleX), sin_angleX = sin(angleX);
    float cos_angleY = cos(angleY), sin_angleY = sin(angleY);
    float cos_angleZ = cos(angleZ), sin_angleZ = sin(angleZ);

    vector<vector<float>> MxRotateX({ { 1, 0, 0 },
                                      { 0, cos_angleX, sin_angleX },
                                      { 0, -sin_angleX, cos_angleX } });

    vector<vector<float>> MxRotateZ({ { cos_angleZ, sin_angleZ, 0 },
                                      { -sin_angleZ, cos_angleZ, 0 },
                                      { 0, 0, 1 } });

    vector<vector<float>> MxRotateY = { { cos_angleY, 0, sin_angleY },
                                        { 0, 1, 0 },
                                        { -sin_angleY, 0, cos_angleY } };

    // 初始化
    float deepth[WinHeight][WinWidth];
    char  output[WinHeight][WinWidth];
    for (int i = 0; i < WinHeight; i++) {
        for (int j = 0; j < WinWidth; j++) {
            output[i][j] = ' ';
            deepth[i][j] = 1e10;
        }
    }
    vector<vector<float>> xyz({ { 0, 0, 0 } }),
        Nxyz({ { 0, 0, 0 } });  // 点坐标和法向量
    //下
    for (float X = -R / 2; X <= R / 2; X += detX) {
        for (float Y = -R / 2; Y <= R / 2; Y += detX) {
            float Z = -R / 2;
            xyz[0] = { X, Y, Z };
            Nxyz[0] = { 0, 0, -1 };

            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            Z = xyz[0][2] + disZ;

            int refX = xyz[0][0] * ref_disZ / Z + WinWidth / 2;
            int refY = -xyz[0][1] * ref_disZ / Z + WinHeight / 2;

            float L = light[0] * Nxyz[0][0] + light[1] * Nxyz[0][1] +
                      light[2] * Nxyz[0][2];

            if (L >= 0 && deepth[refY][refX] > xyz[0][2]) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 11)];
                deepth[refY][refX] = Z;
            }
        }
    }
    //上
    for (float X = -R / 2; X <= R / 2; X += detX) {
        for (float Y = -R / 2; Y <= R / 2; Y += detX) {
            float Z = R / 2;
            xyz[0] = { X, Y, Z };
            Nxyz[0] = { 0, 0, 1 };

            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            Z = xyz[0][2] + disZ;

            int refX = xyz[0][0] * ref_disZ / Z + WinWidth / 2;
            int refY = -xyz[0][1] * ref_disZ / Z + WinHeight / 2;

            float L = light[0] * Nxyz[0][0] + light[1] * Nxyz[0][1] +
                      light[2] * Nxyz[0][2];

            if (L >= 0 && deepth[refY][refX] > xyz[0][2]) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 11)];
                deepth[refY][refX] = Z;
            }
        }
    }
    // 左
    for (float X = -R / 2; X <= R / 2; X += detX) {
        for (float Z = -R / 2; Z <= R / 2; Z += detX) {
            float Y = -R / 2;
            xyz[0] = { X, Y, Z };
            Nxyz[0] = { 0, -1, 0 };

            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            Z = xyz[0][2] + disZ;

            int refX = xyz[0][0] * ref_disZ / Z + WinWidth / 2;
            int refY = -xyz[0][1] * ref_disZ / Z + WinHeight / 2;

            float L = light[0] * Nxyz[0][0] + light[1] * Nxyz[0][1] +
                      light[2] * Nxyz[0][2];

            if (L >= 0 && deepth[refY][refX] > xyz[0][2]) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 11)];
                deepth[refY][refX] = Z;
            }
        }
    }
    // 右
    for (float X = -R / 2; X <= R / 2; X += detX) {
        for (float Z = -R / 2; Z <= R / 2; Z += detX) {
            float Y = R / 2;
            xyz[0] = { X, Y, Z };
            Nxyz[0] = { 0, 1, 0 };

            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            Z = xyz[0][2] + disZ;

            int refX = xyz[0][0] * ref_disZ / Z + WinWidth / 2;
            int refY = -xyz[0][1] * ref_disZ / Z + WinHeight / 2;

            float L = light[0] * Nxyz[0][0] + light[1] * Nxyz[0][1] +
                      light[2] * Nxyz[0][2];

            if (L >= 0 && deepth[refY][refX] > xyz[0][2]) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 11)];
                deepth[refY][refX] = Z;
            }
        }
    }
    // 前
    for (float Y = -R / 2; Y <= R / 2; Y += detX) {
        for (float Z = -R / 2; Z <= R / 2; Z += detX) {
            float X = R / 2;
            xyz[0] = { X, Y, Z };
            Nxyz[0] = { 1, 0, 0 };

            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            Z = xyz[0][2] + disZ;

            int refX = xyz[0][0] * ref_disZ / Z + WinWidth / 2;
            int refY = -xyz[0][1] * ref_disZ / Z + WinHeight / 2;

            float L = light[0] * Nxyz[0][0] + light[1] * Nxyz[0][1] +
                      light[2] * Nxyz[0][2];

            if (L >= 0 && deepth[refY][refX] > Z) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 11)];
                deepth[refY][refX] = Z;
            }
        }
    }
    // 后
    for (float Y = -R / 2; Y <= R / 2; Y += detX) {
        for (float Z = -R / 2; Z <= R / 2; Z += detX) {
            float X = -R / 2;
            xyz[0] = { X, Y, Z };
            Nxyz[0] = { -1, 0, 0 };

            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            Z = xyz[0][2] + disZ;

            int refX = xyz[0][0] * ref_disZ / Z + WinWidth / 2;
            int refY = -xyz[0][1] * ref_disZ / Z + WinHeight / 2;

            float L = light[0] * Nxyz[0][0] + light[1] * Nxyz[0][1] +
                      light[2] * Nxyz[0][2];

            if (L >= 0 && deepth[refY][refX] > xyz[0][2]) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 11)];
                deepth[refY][refX] = Z;
            }
        }
    }
    // 输出
    for (int i = 0; i < WinHeight; i++) {
        for (int j = 0; j < WinWidth; j++) {
            putchar(output[i][j]);
            putchar(output[i][j]);
        }
        printf("\n");
    }
}

int main() {
    for (float i = 0; 1; i += 0.2) {
        renderDonuts(i, i, i);
        Sleep(400);
        system("cls");
        Sleep(100);
    }
    Sleep(1000);
    // renderDonuts(0, 1, 0);
    system("pause");
    return 0;
}