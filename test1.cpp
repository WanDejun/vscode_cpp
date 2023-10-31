#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#define LENGTH 15
HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
COORD coord = { 0,0 };
//双缓冲处理显示
DWORD bytes = 0;
char a[LENGTH + 1] = "---------------", b[LENGTH + 1] = "***************";
bool buf_flag = 0;

void show() {
    int i, j;
    HANDLE *p = &hOutBuf;
    char *s = a;
    if (buf_flag) {p = &hOutput;s = b;}
    for (i = 0; i < LENGTH; i++) {
        coord.Y = i;
        WriteConsoleOutputCharacterA(*p, s, LENGTH, coord, &bytes);
    }
    SetConsoleActiveScreenBuffer(*p);

    printf("123");
    
    Sleep(1000);
    buf_flag = !buf_flag;
}

int main() {
    //创建新的控制台缓冲区
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //隐藏两个缓冲区的光标
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
    while (1)
    {
        show();
    }
}