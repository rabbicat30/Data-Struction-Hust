#include"common.h"
/*page22 */
/*���Ա�Ķ�̬����˳��洢�ṹ*/
#define LIST_INIT_SIZE 100  //��ʼ������
#define LISTINCREMENT  10   //��������
//�������
typedef struct LNode{  //˳���˳��ṹ���Ķ���
	ElemType  elem;        //��������
	struct LNode *next;             //ָ����һ������ָ��
}LNode,*LinkList;
//��������
status InitList(LinkList* headp,int* flag);
status DestroyList(LinkList* headp,int flag);
status ClearList(LinkList headp,int flag);
status ListEmpty(LinkList headp,int flag);
int ListLength(LinkList headp,int flag);
status GetElem(LinkList headp,int i,ElemType* e,int flag);
status LocateElem(LinkList headp,ElemType e,int (*compare)(ElemType x,ElemType y),int flag); //�򻯹�
status PriorElem(LinkList headp,ElemType cur,ElemType* pre_e,int flag);
status NextElem(LinkList headp,ElemType cur,ElemType* next_e,int flag);
status ListInsert(LinkList headp,int i,ElemType e,int flag);
status ListDelete(LinkList headp,int i,ElemType* e,int flag);
status ListTrabverse(LinkList headp,int flag);  //�򻯹�
status SaveList(LinkList headp);
status LoadList(LinkList headp);

