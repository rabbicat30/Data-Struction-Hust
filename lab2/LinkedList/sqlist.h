#include"common.h"
/*page22 */
/*线性表的动态分配顺序存储结构*/
#define LIST_INIT_SIZE 100  //初始分配量
#define LISTINCREMENT  10   //分配增量
//结点类型
typedef struct LNode{  //顺序表（顺序结构）的定义
	ElemType  elem;        //结点的数据
	struct LNode *next;             //指向下一个结点的指针
}LNode,*LinkList;
//链表类型
status InitList(LinkList* headp,int* flag);
status DestroyList(LinkList* headp,int flag);
status ClearList(LinkList headp,int flag);
status ListEmpty(LinkList headp,int flag);
int ListLength(LinkList headp,int flag);
status GetElem(LinkList headp,int i,ElemType* e,int flag);
status LocateElem(LinkList headp,ElemType e,int (*compare)(ElemType x,ElemType y),int flag); //简化过
status PriorElem(LinkList headp,ElemType cur,ElemType* pre_e,int flag);
status NextElem(LinkList headp,ElemType cur,ElemType* next_e,int flag);
status ListInsert(LinkList headp,int i,ElemType e,int flag);
status ListDelete(LinkList headp,int i,ElemType* e,int flag);
status ListTrabverse(LinkList headp,int flag);  //简化过
status SaveList(LinkList headp);
status LoadList(LinkList headp);

