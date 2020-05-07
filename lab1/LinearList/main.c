#include"sqlist.h"
int main(int argc,char* argv[])
{
    SqList L[10];
    int count=0,op=1;
    char c;
    //初始化线性表
    while(op)
    {
        PrintMune(&L[count],count);
        count++;
        printf("继续创建下一个线性表?     [Y/N]\n");
        getchar();op=((c=getchar())=='Y')?1:0;   //由用户确定需要创建线性表的数量
    }
    printf("欢迎下次再使用本系统！\n");
    return 0;
}
void PrintMune(SqList* L,int order)
{
      int op=1;  int ans=0;
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
	printf("    请选择你对线性表L[%d]的操作[0~12]:",order);
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiList功能待实现！\n");
             if((ans=InitList(L))==OK) printf("线性表创建成功！\n");
		     else if(ans==OVERFLOW) printf("创建失败！\n");
		     else printf("线性表已经存在！\n");
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList功能待实现！\n");
		 if(DestroyList(L)==OK) printf("线性表销毁成功！\n");
            else printf("表不存在，无法销毁！\n");
		 getchar();getchar();
		 break;
	   case 3:
		 //printf("\n----ClearList功能待实现！\n");
         if(ClearList(L)==OK) printf("线性表清空成功！\n");
            else printf("表不存在，清空失败！\n");
		 getchar();getchar();
		 break;
	   case 4:
		 //printf("\n----ListEmpty功能待实现！\n");
		 if((ans=ListEmpty(L))) printf("线性表是空表！\n");
         else if(ans==INFEASTABLE)  printf("线性表不存在！\n");
         else printf("线性表不是空表！\n");
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength功能待实现！\n");
		 if((ans=ListLength(L))>=0)
            printf("线性表的长度为：%d\n",ans);
		 else
            printf("线性表不存在！\n");
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem功能待实现！\n");
		 printf("请输入你想要获取的数据的位置：\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if((ans=GetElem(L,i,&e)))//这里的ans只是一个布尔值
            printf("表中第%d个元素的值为：%d\n",i,e);//不是ans应该是e
         else
            printf("输入的数据不合法!\n");
		 getchar();getchar();
		 break;
	   case 7:
		 {
		     //printf("\n----LocateElem功能待实现！\n");
            int e;
            printf("输入你想要查找的数：\n");
            scanf("%d",&e);
            if((ans=LocateElem(L,e,equal)))
                printf("你所要查找的数的位置为：%d\n",ans);
            else
                printf("查找失败！\n");
            getchar();getchar();
            break;
		 }
	   case 8:
		 //printf("\n----PriorElem功能待实现！\n");
		 {
		     int cur_e,pre_e=0;
            printf("输入你想要查找的数：\n");
            scanf("%d",&cur_e);
            if(PriorElem(L,cur_e,&pre_e))
                printf("你所要查找的数的前驱为：%d\n",pre_e);
            else
                printf("查找失败！\n");
            getchar();getchar();
            break;
		 }

	   case 9:
	       {
	           //printf("\n----NextElem功能待实现！\n");
		 int cur_e,next_e=0;
		  printf("输入你想要查找的数：\n");
		 scanf("%d",&cur_e);
		 if((NextElem(L,cur_e,&next_e)))
            printf("你所要查找的数的后继为：%d\n",next_e);
         else
            printf("在线性表中找不到你所要查找的数的后继！\n");
		 getchar();getchar();
		 break;
	       }

	   case 10:
		 {
		     //printf("\n----ListInsert功能待实现！\n");
		 printf("输入你想插入的位置和输入的元素：\n");
		 int i,e;
		 scanf("%d %d",&i,&e);
		 if(ListInsert(L,i,e))
            printf("插入成功！\n");
         else
            printf("输入位置不合法，插入失败！\n");
		 getchar();getchar();
		 break;
		 }

	   case 11:
	       {
	           //printf("\n----ListDelete功能待实现！\n");
		 printf("输入你想删除的位置：\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if(ListDelete(L,i,&e))
            printf("删除成功！你所删除的数据为：%d\n",e);
         else
            printf("输入位置不合法，删除失败！\n");
		 getchar();getchar();
		 break;
	       }
	   case 12:
	       {
	           //printf("\n----ListTrabverse功能待实现！\n");

		 if(!ListTrabverse(L)) printf("线性表是空表！\n");
		 else if(ListTrabverse(L)==INFEASTABLE)  printf("线性表不存在！\n");
		getchar();getchar();
		 break;
	       }
	case 0:
         break;
    case 13:
        SaveList(L);break;
    case 14:
            LoadList(L);
            break;



	}//end of switch
  }//end of while
}//end of main()
status SaveList(SqList* L){   //调用时传递参数&L[i]
    FILE  *fp;char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL)
	{
	printf("File open error\n ");
	exit(-1);
	}
    fwrite(L->elem,sizeof(ElemType),L->length,fp);//将线性表的数据写入file中做备份
    fclose(fp);
    return 0;
 }
status LoadList(SqList* L){
    L->length=0;
    FILE  *fp;char filename[30];
    printf("输入需要载入的文件的名称：");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
	{
        printf("File open error\n ");
        exit(-1);
	}
    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
        L->length++;
    //当线性表种的数据被修改后，可以重新将备份文件中的数据读入线性表表中，恢复其原来的状态
    fclose(fp);
    return 0;
    }
status InitList(SqList* L){
    /*构造一个空的线性表*/
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
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
    L->elem=NULL;
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
status ListLength(SqList* L){
    /*返回线性表的元素长度*/
    if(!L->elem)
        return INFEASTABLE;
    return L->length;
}
status GetElem(SqList* L,int i,ElemType* e){
    /*用e返回L中的第i个元素的值*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<1||i>L->length)
        return ERROR;   //输入的i值不合法
    *e=*(L->elem+i-1);
    return OK;//第一种写法return *e,这样会导致如果第i个元素的值为0出现判断错误
}
status LocateElem(SqList* L,ElemType e,int (*compare)(ElemType x,ElemType y)){
    /*compare函数为函数的指针调用*/
    if(!L->elem)
        return INFEASTABLE;
    for(int i=0;i<L->length;i++)
        if((*compare)(L->elem[i],e)==0)
            return i+1;
    return FALSE;
}
status PriorElem(SqList* L,ElemType cur,ElemType *pre_e){
    /*若cur是L的数据元素且不是第一个，则用pre_e返回前驱*/
    /*否则操作失败*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L->length;i++)
        if((j=LocateElem(L,cur,equal))>1)
        {
            *pre_e=*(L->elem+j-2);   //本来Locate返回的是位序而不是数组中的下标，位序比下标要大1，所以应该减2
            return OK;
        }

    return ERROR;
}
status NextElem(SqList* L,ElemType cur,ElemType* next_e){
    /*若cur是L的数据元素且不是最后一个，用next返回后继*/
    /*否则操作失败*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L->length;i++)
        if((j=LocateElem(L,cur,equal))>0&&j<L->length)
        {
            *next_e=*(L->elem+j); //  同理上面的prior函数，这里只需要j,不需要加1
            return OK;
        }

    return ERROR;
}
status ListInsert(SqList* L,int i,ElemType e){
    /*在L的第i个位置前插入新的数据e，长度加1*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<0||i>L->length+1)     return ERROR;
    if(L->length>=L->listsize){
            //当前分配空间已满，增加分配
        ElemType* newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)    exit(OVERFLOW); //存储内存分配失败
        L->elem=newbase;
        L->listsize +=LISTINCREMENT;
    }
    for(int j=L->length-1;j>=i-1;j--)
            *(L->elem+j+1)=*(L->elem+j);        //插入位置及之后的元素后移
    *(L->elem+i-1)=e;
    ++L->length;
    return OK;
}
status ListDelete(SqList* L,int i,ElemType* e){
    /*删除L的第i个数据，并用e返回其值，L的长度减1*/
    if(i<0||i>L->length)     return ERROR;
    *e=*(L->elem+i-1);  //第二次修改时并没有在e前面加取值符号，导致e的值在调用函数后没有改变
    for(int j=i-1;j<L->length;j++)
        L->elem[j]=L->elem[j+1];
    --L->length;
    return OK;  //第一次修改时返回的是*e,但实际上，*e的值变成了前移后的地i个数，即想返回的数的后一个数
}
status ListTrabverse(SqList* L){
    int i;
    if(!L->elem)
        return INFEASTABLE;
    printf("\n-----------all elements -----------------------\n");
    for(i=0;i<L->length;i++)
        printf("%d ",L->elem[i]);
    printf("\n------------------ end ------------------------\n");
    return L->length;
}



