#include"common.h"
/*page22 */
/*���Ա�Ķ�̬����˳��洢�ṹ*/
#define LIST_INIT_SIZE 100  //��ʼ������
#define LISTINCREMENT  10   //��������
typedef struct SqList{  //˳���˳��ṹ���Ķ���
	ElemType*  elem;        //�洢�ռ��ַ
	int length;             //��ǰ����
	int listsize;//��ǰ����Ĵ洢����
}SqList;
status InitList(SqList* L);
status DestroyList(SqList* L);
status ClearList(SqList* L);
status ListEmpty(SqList* L);
int ListLength(SqList* L);
status GetElem(SqList* L,int i,ElemType* e);
status LocateElem(SqList* L,ElemType e,int (*compare)(ElemType x,ElemType y)); //�򻯹�
status PriorElem(SqList* L,ElemType cur,ElemType* pre_e);
status NextElem(SqList* L,ElemType cur,ElemType* next_e);
status ListInsert(SqList* L,int i,ElemType e);
status ListDelete(SqList* L,int i,ElemType* e);
status ListTrabverse(SqList* L);  //�򻯹�
void PrintMune(SqList* L,int i);
status SaveList(SqList* L);
status LoadList(SqList* L);
