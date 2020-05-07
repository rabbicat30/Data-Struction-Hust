#include "graph.h"
//有关链式队列的定义和操作
//只用在遍历上不涉及删除，所以不用设计循环队列
typedef struct QNode{
    VNode v;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
    QueuePtr front; //头指针
    QueuePtr rear;  //尾指针
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
    //插入元素t作为q的新的队尾元素
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
    if(p->next==NULL)   //删除后队列中只有一个元素
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
