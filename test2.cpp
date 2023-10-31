#include <stdio.h>
#include <windows.h>
using namespace std;
int main()
{
    HANDLE hConsoleOutput =GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台输入句柄
    CHAR_INFO CharInfo;
    int i = 0 ,j = 0;
    CHAR_INFO charInfoAarray[80*25];
    COORD dwBufferSize = { 80, 25 };//固定值(控制台窗口固定的属性值)
    COORD dwBufferCoord = { 0, 0 };//缓冲区左上角的起始位置(即控制台左上角的第一个字符)
    SMALL_RECT rect = { 0, 0, 0, 0 };//显示多大的缓冲区: 大小是一个矩形(该矩形大小只有一个字符大小)
    CharInfo.Attributes = FOREGROUND_RED | BACKGROUND_GREEN;//前景色为红色,背景色为绿色
    CharInfo.Char.AsciiChar = 'H';//输出的字符
    charInfoAarray[0] = CharInfo;
    WriteConsoleOutput(hConsoleOutput, charInfoAarray, dwBufferSize, dwBufferCoord, &rect);
    getchar();
    return 0;
}