#include <console.h>

//��ȡ����λ��x
int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.X);
}


//��ȡ����λ��y
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.Y);
}

//���ù���λ��
void gotoxy(int x, int y) {
    COORD coord = {short(x), short(y)}; 
    //COORD��Windows API�ж����һ�ֽṹ�����ͣ���ʾ����̨��Ļ�ϵ����ꡣ
    //��������Ƕ�����COORD���͵ı���coord�������β�x��y���г�ʼ����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    //GetStdHandle(STD_OUTPUT_HANDLE); ��ȡ����̨������
    //Ȼ����SetConsoleCursorPosition���ÿ���̨(cmd)���λ��
}