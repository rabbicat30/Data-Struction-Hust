#include "sqlist.h"
void main(int argc,char* argv[])
{

    LinkList L[10];
    int op=1;  int ans=0;int count=0;char c;int flag=1;
	while(op)
    {
        while(op){
    system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList        7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty       10. ListInsert\n");
	printf("    	  5. ListLength      11. ListDelete\n");
	printf("    	  6. GetElem         12. ListTrabverse\n");
	printf("          13. SaveList       14. LoadList\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你对链表L[%d]的操作[0~12]:",count);
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiList功能待实现！\n");
             if((ans=InitList(&L[count],&flag))==OK) printf("链表创建成功！\n");
		     else if(ans==OVERFLOW) printf("创建失败！\n");
		     else printf("链表已经存在！\n");
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList功能待实现！\n");
		 if(DestroyList(&L[count],flag)==OK) printf("链表销毁成功！\n");
            else printf("表不存在，无法销毁！\n");
		 getchar();getchar();
		 break;
	   case 3:
		 //printf("\n----ClearList功能待实现！\n");
         if(ClearList(L[count],flag)==OK) printf("链表清空成功！\n");
            else printf("表不存在，清空失败！\n");
		 getchar();getchar();
		 break;
	   case 4:
		 //printf("\n----ListEmpty功能待实现！\n");
		 if((ans=ListEmpty(L[count],flag))==1) printf("链表是空表！\n");
         else if(ans==INFEASTABLE)  printf("链表不存在！\n");
         else printf("链表不是空表！\n");
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength功能待实现！\n");
		 if((ans=ListLength(L[count],flag))>=0)
            printf("链表的长度为：%d\n",ans);
		 else
            printf("链表不存在！\n");
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem功能待实现！\n");
		 printf("请输入你想要获取的数据的位置：\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if((ans=GetElem(L[count],i,&e,flag))==1)//这里的ans只是一个布尔值
            printf("表中第%d个元素的值为：%d\n",i,e);//不是ans应该是e
         else if(ans==0)
            printf("输入的数据不合法!\n");
         else printf("链表不存在！\n");
		 getchar();getchar();
		 break;
	   case 7:
		 {
		     //printf("\n----LocateElem功能待实现！\n");
            int e;
            printf("输入你想要查找的数：\n");
            scanf("%d",&e);
            if((ans=LocateElem(L[count],e,equal,flag))>0)
                printf("你所要查找的数的位置为：%d\n",ans);
            else if(ans==0)
                printf("查找失败！\n");
            else
                printf("链表不存在！\n");
            getchar();getchar();
            break;
		 }
	   case 8:
		 //printf("\n----PriorElem功能待实现！\n");
		 {
		     int cur_e,pre_e=0;
            printf("输入你想要查找的数：\n");
            scanf("%d",&cur_e);
            if((ans=PriorElem(L[count],cur_e,&pre_e,flag))==1)
                printf("你所要查找的数的前驱为：%d\n",pre_e);
            else if(ans==0)
                printf("查找失败！\n");
            else
                printf("链表不存在！\n");
            getchar();getchar();
            break;
		 }

	   case 9:
	       {
	           //printf("\n----NextElem功能待实现！\n");
		 int cur_e,next_e=0;
		  printf("输入你想要查找的数：\n");
		 scanf("%d",&cur_e);
		 if((ans=NextElem(L[count],cur_e,&next_e,flag))==1)
            printf("你所要查找的数的后继为：%d\n",next_e);
         else if(ans==0)
            printf("查找失败！\n");
         else
            printf("链表不存在！\n");
		 getchar();getchar();
		 break;
	       }

	   case 10:
		 {
		     //printf("\n----ListInsert功能待实现！\n");
		 printf("输入你想插入的位置和输入的元素：\n");
		 int i,e;
		 scanf("%d %d",&i,&e);
		 if((ans=ListInsert(L[count],i,e,flag))==1)
            printf("插入成功！\n");
         else if(ans==0)
            printf("输入位置不合法，插入失败！\n");
        else
            printf("链表不存在！\n");
		 getchar();getchar();
		 break;
		 }

	   case 11:
	       {
	           //printf("\n----ListDelete功能待实现！\n");
		 printf("输入你想删除的位置：\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if((ans=ListDelete(L[count],i,&e,flag))==1)
            printf("删除成功！你所删除的数据为：%d\n",e);
         else if(ans==0)
            printf("输入位置不合法，删除失败！\n");
         else
            printf("链表不存在！\n");
		 getchar();getchar();
		 break;
	       }
	   case 12:
	       {
	           //printf("\n----ListTrabverse功能待实现！\n");

		 if((ans=ListTrabverse(L[count],flag))==0) printf("链表表是空表！\n");
		 else if(ans==INFEASTABLE)  printf("链表不存在！\n");
		getchar();getchar();
		 break;
	       }
	case 0:
         printf("欢迎下次再使用本系统！\n");break;
    case 13:
        SaveList(L[count]);break;
    case 14:
            LoadList(L[count]);
            break;



	}//end of switch
  }//end of while
  count++;
  printf("继续创建下一个线性表?     [Y/N]\n");
  getchar();op=((c=getchar())=='Y')?1:0;   //由用户确定需要创建线性表的数量
}
    }//end of main()
status SaveList(LinkList headp){
    FILE  *fp;char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb+"))==NULL)
	{
	printf("File open error\n ");
	exit(-1);
	}
	LinkList p=(headp)->next;
    while(p)
    {
        fwrite(&(p->elem),sizeof(ElemType),1,fp);//将线性表的数据写入file中做备份
        p=p->next;
    }


    fclose(fp);
    return 0;
 }
status LoadList(LinkList headp){
    FILE  *fp;char filename[30];
    printf("输入需要载入的文件的名称：");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
	{
        printf("File open error\n ");
        exit(-1);
	}
	LinkList p=headp;
    LinkList add=(LinkList)malloc(sizeof(LNode));
    while(fread(&(add->elem),sizeof(ElemType),1,fp))
        {//将文件中的数据元素写入新的结点中，再新的结点插入链表中
            add->next=NULL;
            p->next=add;
            p=add;
            add=(LinkList)malloc(sizeof(LNode));
        }
    //当线性表种的数据被修改后，可以重新将备份文件中的数据读入线性表表中，恢复其原来的状态
    free(add);
    fclose(fp);
    return 0;
    }
status InitList(LinkList* headp,int *flag){
    /*构造一个空的线性表*/
    *headp=(LinkList)malloc(sizeof(LNode));
    if(!headp) exit(OVERFLOW);
    (*headp)->next=NULL;
    *flag=0;
    return OK;
}
status DestroyList(LinkList* headp,int flag){
    /*销毁一个已存在的带头节点的线性表*/
    if(!*headp||flag)
        return INFEASTABLE;
    LinkList p=*headp;
    while(p){
        *headp=p->next;
        free(p);
        p=*headp;
    }
    return OK;
}
status ClearList(LinkList headp,int flag){
    /*清空一个已存在的线性表*/
    /*清空是链表没节点，但是链表还在，可以继续插入节点。*/
    if(!headp||flag)
        return INFEASTABLE;
    LinkList p=headp->next,q;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    headp->next=NULL;
    return OK;
}
status ListEmpty(LinkList headp,int flag){
    /*判断线性表是否为空*/
    if(!headp||flag)
        return INFEASTABLE;
    if(headp->next==NULL)
        return TRUE;
    else return FALSE;
}
status ListLength(LinkList headp,int flag){
    /*返回线性表的元素长度*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp->next;
    int count=0;
    while(p)
        {
            count++;
            p=p->next;
        }

    return count;
}
status GetElem(LinkList headp,int i,ElemType* e,int flag){
    /*用e返回L中的第i个元素的值*/
    if(!headp||flag)    return INFEASTABLE;
    LinkList p=headp->next;
    int j=1;    //计数器
    while(p&&j<i){  //顺序查找直到p指向第i个元素或者为空
        p=p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;   //  第i个元素不存在
    *e=p->elem; //  取出元素
    return OK;
}
status LocateElem(LinkList headp,ElemType e,int (*compare)(ElemType x,ElemType y),int flag){
    /*compare函数为函数的指针调用*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp->next;
    int count=0;
    while(p)
    {
        if((*compare)(p->elem,e)==0) return count+1;
        else
        {
            p=p->next;
            count++;
        }
    }
    return FALSE;
}
status PriorElem(LinkList headp,ElemType cur,ElemType *pre_e,int flag){
    /*若cur是L的数据元素且不是第一个，则用pre_e返回前驱*/
    /*否则操作失败*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp->next;
    if(!p)  return ERROR;   //判定是否为空表
    if(p->elem==cur)    return ERROR;   //  cur是第一个元素
    while(p->next)
    {
        if(p->next->elem==cur){
            *pre_e=p->elem;return OK;
        }
        p=p->next;
    }
    return ERROR;
}
status NextElem(LinkList headp,ElemType cur,ElemType* next_e,int flag){
    /*若cur是L的数据元素且不是最后一个，用next返回后继*/
    /*否则操作失败*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp->next;
    if(!p)  return ERROR;
    LinkList q=p->next;
    while(q){
        if(p->elem==cur){
            *next_e=q->elem;
            return OK;
        }
        else{
            p=q;q=q->next;
        }
    }
    return ERROR;
}
status ListInsert(LinkList headp,int i,ElemType e,int flag){
    /*在L的第i个位置前插入新的数据e，长度加1*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp;
    int j=0;
    while(p&&j<i-1) {p=p->next;++j;}
    if(!p||j>i-1)   return ERROR;
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->elem=e;s->next=p->next;
    p->next=s;
    return OK;
}
status ListDelete(LinkList headp,int i,ElemType* e,int flag){
    /*删除L的第i个数据，并用e返回其值，L的长度减1*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp;
    int j=0;
    while(p->next&&j<i-1){  //寻找第i个结点，并令p指向其前驱
        p=p->next;++j;
    }
    if(!(p->next)||j>i-1)   return ERROR;   //删除位置不合理
    LinkList q=p->next;
    p->next=q->next;
    *e=q->elem;free(q); //释放删除结点
    return OK;
}
status ListTrabverse(LinkList headp,int flag){
    if(!headp||flag)
        return INFEASTABLE;
    int i=0;
    LinkList p=headp->next;
    printf("\n-----------all elements -----------------------\n");
    for(;p;p=p->next,i++)
        printf("%d ",p->elem);
    printf("\n------------------ end ------------------------\n");
    return i;
}

