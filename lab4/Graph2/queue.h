#include "graph.h"
//�й���ʽ���еĶ���Ͳ���
//ֻ���ڱ����ϲ��漰ɾ�������Բ������ѭ������
typedef struct QNode{
    VNode v;
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

status EnQueue(Graph* G,pLinkQueue q,int v)
{
    //����Ԫ��t��Ϊq���µĶ�βԪ��
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)  exit(OVERFLOW);
    p->v=*GetVex(G,v);p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return OK;
}

VNode DeQueue(pLinkQueue q)
{
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    p=q->front->next;
    if(p->next==NULL)   //ɾ���������ֻ��һ��Ԫ��
        q->rear=q->front;
    else
        q->front->next=p->next;
    VNode u=p->v;
    free(p);
    return u;
}

status QueueEmpty(pLinkQueue q)
{
    if(q->front==q->rear) return TRUE;
    else return FALSE;
}
