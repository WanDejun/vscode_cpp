#include <math.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

// template <typename T>
// class Matrix {
// private:
//     int                         rowSize;
//     int                         columnSize;
//     std::vector<std::vector<T>> MX;
// public:
//     Matrix(int rowSize, int columnSize) {
//         this->columnSize = columnSize;
//         this->rowSize = rowSize;
//         MX = std::vector<std::vector<T>>(rowSize, std::vector(columnSize,
//         0));
//     }
//     Matrix(const std::vector<std::vector<T>>& vec) {
//         rowSize = vec.size();
//         columnSize = vec[0].size;
//         MX = std::vector<std::vector<T>>(rowSize, std::vector(columnSize,
//         0)); for (int i = 0; i < rowSize; i++) {
//             for (int j = 0; j < columnSize; j++) {
//                 MX[i][j] = vec[i][j];
//             }
//         }
//     }
//     Matrix(const Matrix<T>& mx) {
//         rowSize = mx.rowSize;
//         columnSize = mx.columnSize;
//         MX = std::vector<std::vector<T>>(rowSize, std::vector(columnSize,
//         0)); for (int i = 0; i < rowSize; i++) {
//             for (int j = 0; j < columnSize; j++) {
//                 MX[i][j] = mx[i][j];
//             }
//         }
//     }
//     Matrix<T> multipl(const Matrix<T>& A, const Matrix<T>& B) {
//         if (A.columnSize != B.rowSize) exit(1);
//     }
// };

template <typename T>
std::vector<std::vector<T>>
MatrixMutiply(const std::vector<std::vector<T>>& A,
              const std::vector<std::vector<T>>& B) {
    if (A[0].size() != B.size()) {
        printf("Error in MatrixMutiply! A: %d * %d; B: %d * %d\n", A.size(),
               A[0].size(), B.size(), B[0].size());
        system("pause");
        exit(0);
    }

    std::vector<std::vector<T>> ret(A.size(), std::vector<T>(B[0].size(), 0));

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
const float detCycleAngle = 0.05;
const float detangleY = 0.05;

const int WinHeight = 50;
const int WinWidth = 50;

const float R1 = 2;
const float R2 = 4;
const float disZ = 20;
const float ref_disZ = WinHeight * disZ * 3 / (8 * (R1 + R2));

void renderDonuts(float angleX, float angleZ) {
    float cos_angleX = cos(angleX), cos_angleZ = cos(angleZ);
    float sin_angleX = sin(angleX), sin_angleZ = sin(angleZ);

    std::vector<std::vector<float>> MxRotateX(
        { { 1, 0, 0 },
          { 0, cos_angleX, sin_angleX },
          { 0, -sin_angleX, cos_angleX } });
    std::vector<std::vector<float>> MxRotateZ({ { cos_angleZ, sin_angleZ, 0 },
                                                { -sin_angleZ, cos_angleZ, 0 },
                                                { 0, 0, 1 } });

    // 初始化
    float deepth[WinHeight][WinWidth];
    char  output[WinHeight][WinWidth];
    for (int i = 0; i < WinHeight; i++) {
        for (int j = 0; j < WinWidth; j++) {
            output[i][j] = ' ';
            deepth[i][j] = 1e10;
        }
    }
    std::vector<std::vector<float>> xyz({ { 0, 0, 0 } }), Nxyz({ { 0, 0, 0 } });

    // 截面圆有限元划分
    for (float theta = 0; theta < 2 * pi; theta += detCycleAngle) {
        float sin_theta = sin(theta), cos_theta = cos(theta);
        float cycleX = R2 + R1 * cos_theta, cycleY = R1 * sin_theta;

        // 截面圆绕y轴旋转
        for (float angleY = 0; angleY < 2 * pi; angleY += detangleY) {
            float sin_angleY = sin(angleY), cos_angleY = cos(angleY);

            std::vector<std::vector<float>> MxRotateY = {
                { cos_angleY, 0, sin_angleY },
                { 0, 1, 0 },
                { -sin_angleY, 0, cos_angleY }
            };

            xyz[0] = { cycleX, cycleY, 0 };
            Nxyz[0] = { cos_theta, sin_theta, 0 };

            // 以人眼的相对坐标
            xyz = MatrixMutiply(xyz, MxRotateY);
            xyz = MatrixMutiply(xyz, MxRotateX);
            xyz = MatrixMutiply(xyz, MxRotateZ);

            Nxyz = MatrixMutiply(Nxyz, MxRotateY);
            Nxyz = MatrixMutiply(Nxyz, MxRotateX);
            Nxyz = MatrixMutiply(Nxyz, MxRotateZ);

            float X = xyz[0][0], Y = xyz[0][1], Z = xyz[0][2] + disZ;
            float NX = Nxyz[0][0], NY = Nxyz[0][1], NZ = Nxyz[0][2];

            int refX = X * ref_disZ / Z + WinWidth / 2;
            int refY = -Y * ref_disZ / Z + WinHeight / 2;

            float L = 1 / sqrt(2) * NX + 1 / sqrt(2) * NY + 1 * NZ;

            if (X > 8 || Y > 8 || X < -8 || Y < -8) {
                printf("Error in line135");
                system("pause");
                exit(0);
            }

            if (L >= 0 && deepth[refY][refX] > Z) {
                output[refY][refX] = ".,-~:;=!*#$@"[int(L * 8)];
                deepth[refY][refX] = Z;
            }
        }
    }
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
        renderDonuts(i, i);
        Sleep(400);
        system("cls");
        Sleep(100);
    }
    Sleep(1000);
    //renderDonuts(2.2, 0.5);
    system("pause");
    return 0;
}