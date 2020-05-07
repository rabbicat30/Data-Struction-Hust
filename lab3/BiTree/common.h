#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
/*书本第10页，预定义常量和类型*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAXLENG  100
#define ILLEAGAL -3
#define EMPTY 2
typedef int status;
typedef struct Elem{
    int key;
    int value;
}ElemType;//定义键值，key为节点编号，value为二叉树节点存储的数据
void visit(ElemType node)
{

    printf("关键字：%d 内容：%d\n",node.key,node.value);
}


