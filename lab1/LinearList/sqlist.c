#include"common.h"
#include"sqlist.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

status InitList(SqList* L){
    /*构造一个空的线性表*/
    L=(SqList*)malloc(LIST_INIT_SIZE*sizeof(SqList));
    if(!L->elem) exit(OVERFLOW);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}
status DestroyList(SqList* L){
    /*销毁一个已存在的线性表*/
    if(!L->elem)
        return INFEASTABLE;
    L->listsize=L->length=0;
    free(L->elem);
    return OK;
}
status ClearList(SqList* L){
    /*清空一个已存在的线性表*/
    if(!L->elem)
        return INFEASTABLE;
    L->length=0;
    return OK;
}
status ListEmpty(SqList* L){
    /*判断线性表是否为空*/
    if(!L->elem)
        return INFEASTABLE;
    if(L->length)   return FALSE;
    return TRUE;
}
int ListLength(SqList* L){
    /*返回线性表的元素长度*/
    if(!L->elem)
        return INFEASTABLE;
    return L->length;
}
status GetElem(SqList* L,int i,ElemType e){
    /*用e返回L中的第i个元素的值*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<1||i>L.length)
        return ERROR;   //输入的i值不合法
    e=*(L->elem+i);
    return OK;
}
status LocateElem(SqList* L,ElemType e,(*compare)(ElemType x,ElemType y)){
    /*compare函数为函数的指针调用*/
    if(!L->elem)
        return INFEASTABLE;
    for(int i=0;i<L.length;i++)
        if(compare(L[i],e)==0)
            return i;
    return -1;
}
status PriorElem(SqList* L,ElemType cur,ElemType pre_e){
    /*若cur是L的数据元素且不是第一个，则用pre_e返回前驱*/
    /*否则操作失败*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L.length;i++)
        if((j=LocateElem(L,cur,equal(cur,L[i])))>0)
            return pre_e=*(L.elem+j-1);
    return ERROR;
}
status NextElem(SqList* L,ElemType cur,ElemType next_e){
    /*若cur是L的数据元素且不是最后一个，用next返回后继*/
    /*否则操作失败*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L.length;i++)
        if(0<(j=LocateElem(L,cur,equal(cur,L[i])))<L.length-1)
            return next_e=-(L.elem+j+1);
    return ERROR;
}
status ListInsert(SqList* L,int i,ElemType e){
    /*在L的第i个位置前插入新的数据e，长度加1*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<0||i>L.length)     return ERROR;
    if(L.length>=L.listsize){
            //当前分配空间已满，增加分配
        Sqlist *newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)    exit(OVERFLOW); //存储内存分配失败
        L.elem=newbase;
        L.listsize +=LISTINCREMENT;
    }
    for(int j=L.length-1;j>=i-1;j--)
            L[j+1]=L[j];                 //插入位置及之后的元素后移
    L[i-1]=e;
    ++L.length;
    return OK;
}
status ListDelete(SqList* L,int i,ElemType e){
    /*删除L的第i个数据，并用e返回其值，L的长度减1*/
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
