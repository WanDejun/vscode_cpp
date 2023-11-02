#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define LENGTH 25
//#define SLEEP_TIME 100 //难度
#define BODY 1
#define CANDY 2

int SLEEP_TIME; //难度

HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
COORD coord = { 0,0 };
//双缓冲处理显示
DWORD bytes = 0;
char output_data[(LENGTH + 5) << 1][(LENGTH + 5) << 1];
bool buf_flag = 0;

typedef struct LOCATION{
    int x;
    int y;
}snake_loc, candy_loc;

snake_loc snake_Head, snake_Tail;
struct LOCATION mx_next[LENGTH][LENGTH]; //标记后节点
struct LOCATION mx_pre[LENGTH][LENGTH]; //标记前节点
bool mx_flag[LENGTH][LENGTH]; //标记蛇身
candy_loc candy;
bool flag_game_over = 0;

int dis[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int key_status = 0; //0:up 1:down 2:left 3:right

int score = 1; //aslo length
char outline[(LENGTH + 5) << 1];

void _init_() {
    system("chcp 437");
    system("cls");
    srand(time(0));
    for (int i = 0; i < ((LENGTH + 2) << 1); i++) outline[i] = '*'; //边界字符串初始化
    outline[(LENGTH + 2) << 1] = '\0';
    for (int i = 0; i < LENGTH; i++) { //初始化边界
        output_data[i][0] = '*';
        output_data[i][1] = ' ';
        output_data[i][(LENGTH + 1) << 1 | 1] = '*';
        output_data[i][(LENGTH + 1) << 1] = ' ';
    }


    snake_Head.x = rand() % LENGTH; //初始化头
    snake_Head.y = rand() % LENGTH;
    snake_Tail.x = snake_Head.x; //初始化尾
    snake_Tail.y = snake_Head.y;
    mx_flag[snake_Head.x][snake_Head.y] = 1;

    do { //初始化糖果
        candy.x = rand() % LENGTH; 
        candy.y = rand() % LENGTH;
    } while (candy.x == snake_Head.x && candy.y == snake_Head.y);

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

}

void fill_in_data() {
    int x, y, xx, yy;
    for (x = 0; x < LENGTH; x++) {
        for (y = 1; y <= LENGTH; y++) {
            output_data[x][y << 1] = ' ';
            output_data[x][y << 1 | 1] = ' ';
        }
    }
    for (x = snake_Head.x, y = snake_Head.y; 1; xx = mx_next[x][y].x, yy = mx_next[x][y].y, x = xx, y = yy) {
        output_data[x][(y + 1) << 1] = 219;
        output_data[x][(y + 1) << 1 | 1] = 219;
        
        if (x == snake_Tail.x && y == snake_Tail.y) break;
    }
    output_data[candy.x][(candy.y + 1) << 1] = '#';
    output_data[candy.x][(candy.y + 1) << 1 | 1] = '#';

}

void show() {
    HANDLE *out_buf = &hOutBuf;
    int i;
    char str[15];
    sprintf(str, "score: %3d", score);
    if (buf_flag) out_buf = &hOutput; //缓冲区切换

    coord.Y = 0;
    WriteConsoleOutputCharacterA(*out_buf, outline, (LENGTH + 2) << 1, coord, &bytes); //上边界
    for (i = 0; i < LENGTH; i++) {
        coord.Y = i + 1;
        WriteConsoleOutputCharacterA(*out_buf, output_data[i], (LENGTH + 2) << 1, coord, &bytes);
    }
    coord.Y++;
    WriteConsoleOutputCharacterA(*out_buf, outline, (LENGTH + 2) << 1, coord, &bytes); //下边界
    coord.Y++;
    WriteConsoleOutputCharacterA(*out_buf, str, 10, coord, &bytes); //输出分数
    SetConsoleActiveScreenBuffer(*out_buf);


    Sleep(SLEEP_TIME);
    buf_flag = !buf_flag;
}

void getkey() {
    char ch;
    if (_kbhit()){ //如果有按键按下，则_kbhit()函数返回真 w:119 a:97 s:115 d:100 esc:27
        ch = _getch(); //使用_getch()函数获取按下的键值
        switch (ch) {
        case 119:
            if (key_status != 1 || score == 1) key_status = 0;
            break;
        case 115:
            if (key_status != 0 || score == 1) key_status = 1;
            break;
        case 97:
            if (key_status != 3 || score == 1) key_status = 2;
            break;
        case 100:
            if (key_status != 2 || score == 1) key_status = 3;
            break;
        case 27:
            while (!_kbhit()) {
                Sleep(100);
            }
            getkey();
            break;
        default:
            break;
        }
    }
}

bool check_cycle_die(int xx, int yy) {
    return mx_flag[xx][yy];
}

void move_snake() {
    int xx = snake_Head.x + dis[key_status][0], yy = snake_Head.y + dis[key_status][1]; //head前移

    if (xx < 0 || yy < 0 || xx >= LENGTH || yy >= LENGTH) {flag_game_over = 1; return;} //判断越界

    if (check_cycle_die(xx, yy)) { flag_game_over = 1;return; } //撞上自己

    mx_pre[snake_Head.x][snake_Head.y].x = xx; //修改头指针
    mx_pre[snake_Head.x][snake_Head.y].y = yy;

    mx_next[xx][yy].x = snake_Head.x;
    mx_next[xx][yy].y = snake_Head.y;

    snake_Head.x = xx; //修改头
    snake_Head.y = yy;

    mx_flag[xx][yy] = 1;

    if (snake_Head.x == candy.x && snake_Head.y == candy.y) { //吃到糖果
        do {
            candy.x = rand() % LENGTH;
            candy.y = rand() % LENGTH;
        } while (mx_flag[candy.x][candy.y]);
        score++;
    }
    else {
        mx_flag[snake_Tail.x][snake_Tail.y] = 0;
        xx = mx_pre[snake_Tail.x][snake_Tail.y].x; //修改尾
        yy = mx_pre[snake_Tail.x][snake_Tail.y].y;

        snake_Tail.x = xx;
        snake_Tail.y = yy;
    }
}

void output_die() {
    HANDLE *out_buf = &hOutBuf;
    int i;
    if (buf_flag) out_buf = &hOutput;

    for (int i = 0; i < (LENGTH + 3) << 1; i++)
        outline[i] = ' ';

    for (int i = 0; i < LENGTH + 2; i++) {
        coord.Y = i;
        WriteConsoleOutputCharacterA(*out_buf, outline, (LENGTH + 3) << 1, coord, &bytes);
    }
    char str[5][120] = {"    ******       *          *     *        *******          ******    **     **   *******   ******  ",
                        "   **           * *        * *   * *       **              **    **    *     *    **        *     * ",
                        "  **   ****    *****      *   * *   *      *******        **      **    *   *     *******   ******  ",
                        "   **    **   *     *    **    *    **     **              **    **      * *      **        * **    ",
                        "    ***** *  ***   ***  ***    *    ***    *******          ******        *       *******   *   *** ",};
    for (i = 0; i < 5; i++) {
        coord.Y = i;
        WriteConsoleOutputCharacterA(*out_buf, str[i], 100, coord, &bytes);
    }
    SetConsoleActiveScreenBuffer(*out_buf);
    Sleep(3000);
    buf_flag = !buf_flag;
}

void game_start() {
    printf("choose your difficult level:\n1.easy\n2.middle\n3.hard\n>> ");
    int t;
    scanf("%d", &t);
    switch (t) {
    case 1:
        SLEEP_TIME = 500;
        break;
    case 2:
        SLEEP_TIME = 300;
        break;
    case 3:
        SLEEP_TIME = 100;
        break;
    default:
        printf("error!");
        Sleep(1000);
        exit(1);
        break;
    }

    fill_in_data();
    show();
    system("pause");
    while (!flag_game_over) {
        getkey();
        move_snake();
        fill_in_data();
        show();
    }
    output_die();
}

int main() {
    _init_();
    game_start();

    return 0;
}
