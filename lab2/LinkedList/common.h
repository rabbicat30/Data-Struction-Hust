#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*�鱾��10ҳ��Ԥ���峣��������*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���
status equal(ElemType x,ElemType y){
    return (x-y);
}


