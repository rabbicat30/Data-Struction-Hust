#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*书本第10页，预定义常量和类型*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //数据元素类型定义
status equal(ElemType x,ElemType y){
    return (x-y);
}

