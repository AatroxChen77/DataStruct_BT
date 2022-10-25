#include <console.h>

//获取光标的位置x
int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.X);
}


//获取光标的位置y
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.Y);
}

//设置光标的位置
void gotoxy(int x, int y) {
    COORD coord = {short(x), short(y)}; 
    //COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。
    //上面语句是定义了COORD类型的变量coord，并以形参x和y进行初始化。
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    //GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
    //然后用SetConsoleCursorPosition设置控制台(cmd)光标位置
}