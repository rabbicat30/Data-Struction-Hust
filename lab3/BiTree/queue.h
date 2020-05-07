#include "bitree.h"
//�й���ʽ���еĶ���Ͳ���
//ֻ���ڱ����ϲ��漰ɾ�������Բ������ѭ������
typedef struct QNode{
    BiTree T;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
    QueuePtr front; //ͷָ��
    QueuePtr rear;  //βָ��
}LinkQueue,*pLinkQueue;
pLinkQueue InitQueue(pLinkQueue q)
{
    q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!q->front) exit(OVERFLOW);
    q->front->next=NULL;
    return q;
}
status EnQueue(pLinkQueue q,BiTree t)
{
    //����Ԫ��t��Ϊq���µĶ�βԪ��
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)  exit(OVERFLOW);
    p->T=t;p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return OK;
}
BiTree DeQueue(pLinkQueue q)
{
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    p=q->front->next;
    if(p->next==NULL)   //ɾ���������ֻ��һ��Ԫ��
        q->rear=q->front;
    else
        q->front->next=p->next;
    BiTree t=p->T;
    free(p);
    return t;
}
