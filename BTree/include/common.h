#ifndef __COMMON_HEAD__
#define __COMMON_HEAD__

//常用头文件
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
//#include <limits.h>

//常用常量
#define OK 1
// #define ERROR -1

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define UNSUCCESS -2

#define OVERFLOW 3
// OVERFLOW已默认宏定义为3

//常用类型定义
typedef int Status;

typedef int ElemType;
typedef int KeyType; //关键字类型

typedef struct
{
    KeyType key;
    //...其他数据项
} RecordType, RcdType; //记录类型，RcdType为RecordType的简写

#endif