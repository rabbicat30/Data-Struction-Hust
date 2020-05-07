#include "common.h"

//链表节点
typedef struct ArcNode
{
    int adjhead;                     //该弧指向的顶点的位置
    int adjtail;                     //弧头的位置
    struct ArcNode *nextarc;        //指向下一条弧的指针
}ArcNode;
//键值对
typedef struct ElemType
{
    int key;                      //关键字
    int value;                      //信息
}ElemType;
//头结点
typedef struct VNode
{
    ElemType data;
    ArcNode* firstarc;
    struct VNode* next;            //指向第一条依附于该顶点的弧的指针
}VNode;

typedef struct Graph
{
    VNode* vnode;               //顶点序列
    int vexnum;                 //当前图的顶点数
    int arcnum;                 //当前图的弧数

}Graph;

status CreateGraph(Graph* graph,VNode* Vex,ArcNode* Arc,int vexnum,int arcnum);
status DestroyGraph(Graph* graph);
status LocateVex(Graph* graph,int u);
VNode* GetVex(Graph* graph,int u);
status PutVex(Graph* graph,int u,int val);
status FirstAdjVex(Graph* graph,int u);
status NextAdjVex(Graph* graph,int v, int w);
status InsertVex(Graph* graph,VNode v);
status DeleteVex(Graph* graph,VNode v);
status InsertArc(Graph* graph,VNode v,VNode w);
status DeleteArc(Graph* graph,VNode v,VNode w);
status DFSVisit(Graph* graph,int i,int* visited);
status DFSTraverse(Graph* graph,int v,status (*Visit)(Graph* graph,int v));
status Visit(Graph* graph,int v);
status SaveGraph(Graph* graph,FILE* fp,FILE* fq);
status LoadGraph(Graph* graph);
void BFSTraverse(Graph* G,int v,status (*Visit)(Graph* G,int v));
status IntArc(Graph* graph,int v);
status OutArc(Graph* graph,int v);



