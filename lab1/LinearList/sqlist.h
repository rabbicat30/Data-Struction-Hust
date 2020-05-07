#include"common.h"
/*page22 */
/*线性表的动态分配顺序存储结构*/
#define LIST_INIT_SIZE 100  //初始分配量
#define LISTINCREMENT  10   //分配增量
typedef struct SqList{  //顺序表（顺序结构）的定义
	ElemType*  elem;        //存储空间基址
	int length;             //当前长度
	int listsize;//当前分配的存储容量
}SqList;
status InitList(SqList* L);
status DestroyList(SqList* L);
status ClearList(SqList* L);
status ListEmpty(SqList* L);
int ListLength(SqList* L);
status GetElem(SqList* L,int i,ElemType* e);
status LocateElem(SqList* L,ElemType e,int (*compare)(ElemType x,ElemType y)); //简化过
status PriorElem(SqList* L,ElemType cur,ElemType* pre_e);
status NextElem(SqList* L,ElemType cur,ElemType* next_e);
status ListInsert(SqList* L,int i,ElemType e);
status ListDelete(SqList* L,int i,ElemType* e);
status ListTrabverse(SqList* L);  //简化过
void PrintMune(SqList* L,int i);
status SaveList(SqList* L);
status LoadList(SqList* L);
