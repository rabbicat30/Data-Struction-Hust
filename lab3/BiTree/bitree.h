#include"common.h"
typedef struct BiTNode{
    ElemType elem;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;
status CreateBiTree(BiTree* t,ElemType* defination,int count,int* flag,int isempty);
status DestroyBiTree(BiTree* t,int flag);
status ClearBiTree(BiTree t,int flag);
status BiTreeEmpty(BiTree t,int flag);
status BiTreeDepth(BiTree t,int flag);
BiTree LocateNode(BiTree t,int e);
BiTree GetParent(BiTree t,int e);
status Assign(BiTree t,int e,int val,int flag);
BiTree GetSibling(BiTree t,int e);
status InsertNode(BiTree t,int e,int LR,BiTree c,int flag,int isempty);
status DeleteNode(BiTree* t,int e,int flag);
status PreOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty);
status InOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty);
status PostOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty);
status LevelOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag);
status SaveTree(BiTree t,ElemType def,FILE* fp);
status LoadTree(BiTree* t,ElemType* def,int count,int* flag);
