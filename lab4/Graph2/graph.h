#include "common.h"

//����ڵ�
typedef struct ArcNode
{
    int adjhead;                     //�û�ָ��Ķ����λ��
    int adjtail;                     //��ͷ��λ��
    struct ArcNode *nextarc;        //ָ����һ������ָ��
}ArcNode;
//��ֵ��
typedef struct ElemType
{
    int key;                      //�ؼ���
    int value;                      //��Ϣ
}ElemType;
//ͷ���
typedef struct VNode
{
    ElemType data;
    ArcNode* firstarc;
    struct VNode* next;            //ָ���һ�������ڸö���Ļ���ָ��
}VNode;

typedef struct Graph
{
    VNode* vnode;               //��������
    int vexnum;                 //��ǰͼ�Ķ�����
    int arcnum;                 //��ǰͼ�Ļ���

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



