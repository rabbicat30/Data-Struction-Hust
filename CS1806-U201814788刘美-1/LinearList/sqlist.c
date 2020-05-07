#include"common.h"
#include"sqlist.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

status InitList(SqList* L){
    /*����һ���յ����Ա�*/
    L=(SqList*)malloc(LIST_INIT_SIZE*sizeof(SqList));
    if(!L->elem) exit(OVERFLOW);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}
status DestroyList(SqList* L){
    /*����һ���Ѵ��ڵ����Ա�*/
    if(!L->elem)
        return INFEASTABLE;
    L->listsize=L->length=0;
    free(L->elem);
    return OK;
}
status ClearList(SqList* L){
    /*���һ���Ѵ��ڵ����Ա�*/
    if(!L->elem)
        return INFEASTABLE;
    L->length=0;
    return OK;
}
status ListEmpty(SqList* L){
    /*�ж����Ա��Ƿ�Ϊ��*/
    if(!L->elem)
        return INFEASTABLE;
    if(L->length)   return FALSE;
    return TRUE;
}
int ListLength(SqList* L){
    /*�������Ա��Ԫ�س���*/
    if(!L->elem)
        return INFEASTABLE;
    return L->length;
}
status GetElem(SqList* L,int i,ElemType e){
    /*��e����L�еĵ�i��Ԫ�ص�ֵ*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<1||i>L.length)
        return ERROR;   //�����iֵ���Ϸ�
    e=*(L->elem+i);
    return OK;
}
status LocateElem(SqList* L,ElemType e,(*compare)(ElemType x,ElemType y)){
    /*compare����Ϊ������ָ�����*/
    if(!L->elem)
        return INFEASTABLE;
    for(int i=0;i<L.length;i++)
        if(compare(L[i],e)==0)
            return i;
    return -1;
}
status PriorElem(SqList* L,ElemType cur,ElemType pre_e){
    /*��cur��L������Ԫ���Ҳ��ǵ�һ��������pre_e����ǰ��*/
    /*�������ʧ��*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L.length;i++)
        if((j=LocateElem(L,cur,equal(cur,L[i])))>0)
            return pre_e=*(L.elem+j-1);
    return ERROR;
}
status NextElem(SqList* L,ElemType cur,ElemType next_e){
    /*��cur��L������Ԫ���Ҳ������һ������next���غ��*/
    /*�������ʧ��*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L.length;i++)
        if(0<(j=LocateElem(L,cur,equal(cur,L[i])))<L.length-1)
            return next_e=-(L.elem+j+1);
    return ERROR;
}
status ListInsert(SqList* L,int i,ElemType e){
    /*��L�ĵ�i��λ��ǰ�����µ�����e�����ȼ�1*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<0||i>L.length)     return ERROR;
    if(L.length>=L.listsize){
            //��ǰ����ռ����������ӷ���
        Sqlist *newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)    exit(OVERFLOW); //�洢�ڴ����ʧ��
        L.elem=newbase;
        L.listsize +=LISTINCREMENT;
    }
    for(int j=L.length-1;j>=i-1;j--)
            L[j+1]=L[j];                 //����λ�ü�֮���Ԫ�غ���
    L[i-1]=e;
    ++L.length;
    return OK;
}
status ListDelete(SqList* L,int i,ElemType e){
    /*ɾ��L�ĵ�i�����ݣ�����e������ֵ��L�ĳ��ȼ�1*/
    if(i<0||i>L.length)     return ERROR;
    e=L[i-1];
    for(int j=i-1;j<L.length;j++)
        L[j]=L[j+1];
    --L.length;
    return e;
}
status ListTrabverse(SqList *L){
    int i;
    printf("\n-----------all elements -----------------------\n");
    for(i=0;i<L.length;i++)
        printf("%d ",L.elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L.length;
}
