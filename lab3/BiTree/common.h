#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
/*�鱾��10ҳ��Ԥ���峣��������*/
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
}ElemType;//�����ֵ��keyΪ�ڵ��ţ�valueΪ�������ڵ�洢������
void visit(ElemType node)
{

    printf("�ؼ��֣�%d ���ݣ�%d\n",node.key,node.value);
}


