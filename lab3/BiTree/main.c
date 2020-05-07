#include"queue.h"
int num=0;
int isempty=0; //isempty用来判断是否被clear，即根节点存在但是内容为空
int main(void){
    int count=0;   //记录需要创建的二叉树节点的个数，包括空节点
    int flag=1;
    ElemType defination[100];   //存放二叉树的节点序列
    BiTree T[10];              //线性表多棵二叉树管理
    BiTree pans=NULL;          //注意防止指针悬挂
    int op=1,ans=0;
    int order=0;               //当前操作的二叉树的二叉树数组下标
    char c;
    ElemType def;               //用于读入文件时做空节点用
    def.key=0;def.value=0;
    while(op)
    {
        printf("输入你要操作的二叉树的序号：[0-9]\n");
        scanf("%d",&order);
        while(op)
        {
            system("cls");	printf("\n\n");
            printf("      Menu for Binary Tree On Sequence Structure \n");
            printf("-------------------------------------------------\n");
            printf("    	  1. CreateBiTree              7. Assign\n");
            printf("    	  2. DestroyBiTree            8. GetSibling\n");
            printf("    	  3. ClearBiTree              9. InsertNode\n");
            printf("    	  4. BiTreeEmpty              10. DeleteNode\n");
            printf("    	  5. BiTreeDepth              11. PreOrderTraverse\n");
            printf("    	  6. LocateNode               12. InOrderTraverse\n");
            printf("          13. PostOrderTraverse       14. LevelOrderTraverse\n");
            printf("          15. GetParent               16. SaveTree\n");
            printf("    	  17. LoadTree                0. Exit\n");
            printf("-------------------------------------------------\n");

            printf("请选择你对二叉树T[%d]的操作[0~12]:",order);
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                    printf("请按照先序序列分别输入二叉树T[%d]节点关键字和需要存储的数据，并以空格或回车键分隔：\n",order);
                    printf("注意输入的关键字和数据均为整数！\n");
                    printf("输入关键字为0表示节点为空，且不需要输入数据！\n");
                    printf("输入关键字为-1结束！\n");
                    scanf("%d",&((defination[count]).key));
                    while((defination[count]).key!=-1)//输入节点编号
                    {

                        if(defination[count].key>0)    //节点的数据域存在则为数据域赋值，否则为系统自动分配的值
                        {
                            scanf("%d",&((defination[count]).value));
                        }
                        count++;
                        scanf("%d",&((defination[count]).key));

                    }
            if((ans=CreateBiTree(&T[order],defination,count,&flag,isempty))==1)
                    printf("二叉树创建成功!\n");
                else if(ans==OVERFLOW)
                    printf("二叉树创建失败！\n");
                getchar();getchar();
                break;
            case 2:
                if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                    if((ans=DestroyBiTree(&T[order],flag))==INFEASTABLE)
                        printf("二叉树尚未创建！\n");
                    else
                        printf("二叉树销毁成功！\n");
                }
                getchar();getchar();
                break;

            case 3:
                if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                    if((ans=ClearBiTree(T[order],flag))==INFEASTABLE)
                        printf("二叉树尚未创建！\n");
                    else
                    {
                        printf("二叉树清空成功！\n");
                        isempty=1;
                    }
                }
               getchar();getchar();
                break;
            case 4:
                if(isempty)
                    printf("二叉树被清空了！\n");
                else if((ans=BiTreeEmpty(T[order],flag))==INFEASTABLE)
                    printf("二叉树尚未创建！\n");
                else if(ans==1)
                    printf("二叉树为空二叉树！\n");
                else
                    printf("二叉树不是空的!\n");
                getchar();getchar();
                break;
            case 5:
                if(isempty)
                    printf("二叉树被清空了！\n");
                else if((ans=BiTreeDepth(T[order],flag))>=0)
                    printf("二叉树的深度为：%d\n",ans);
                else
                    printf("二叉树尚未创建！\n");
                getchar();getchar();
                break;
            case 6:
                if(flag)        printf("二叉树尚未被创建！\n");
                else if(isempty)      printf("二叉树被清空了！\n");
                else if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                printf("输入查找的节点的关键字：\n");
                int e;
                scanf("%d",&e);
                if((pans=LocateNode(T[order],e)))
                    visit(pans->elem);
                else if(pans==NULL)
                    printf("找不到关键字为%d的节点！\n",e);
                }
                getchar();getchar();
                break;
            case 7:
                {
                    int e;
                    int val;
                    printf("输入想要赋值的节点的关键字和值：\n");
                    scanf("%d",&e);
                    scanf("%d",&val);
                    if(flag)    printf("二叉树尚未被创建！\n");
                    else if(isempty)
                        printf("二叉树被清空了！\n");
                    else if((ans=Assign(T[order],e,val,flag))==INFEASTABLE)
                        printf("二叉树尚未创建！\n");
                    else if(ans==0)
                        printf("二叉树是空二叉树！\n");
                    else if(ans==EMPTY)
                        printf("输入关键字不合法！\n");
                     else
                        printf("赋值成功！\n");
                    getchar();getchar();
                    break;
                }

            case 8:
                {
                   if(!T[order])    printf("二叉树是空树！\n");
                    else if(flag)    printf("二叉树尚未被创建！\n");
                    else
                    {
                        int e;
                        printf("输入查找的节点的关键字：");
                        scanf("%d",&e);
                    //无法区分空二叉树和无兄弟节点
                    if(isempty)
                        printf("二叉树被清空了！\n");
                    else if((pans=GetSibling(T[order],e))==NULL)
                            printf("该节点没有兄弟节点！\n");
                        else
                        {
                            printf("该节点的兄弟节点的");
                            visit(pans->elem);
                        }
                    }
                    getchar();getchar();
                    break;
                }

            case 9:
                {
                   printf("输入插入位置的关键字：");
                int e;
                scanf("%d",&e);
                BiTree c=(BiTree)malloc(sizeof(BiTNode));
                printf("分别输入插入的节点的关键字和内容：");
                scanf("%d",&c->elem.key);
                scanf("%d",&c->elem.value);
                c->lchild=NULL;
                c->rchild=NULL;
                printf("你想将插入的节点作为左孩子还是右孩子？\n");
                printf("输入0表示左，输入1表示右\n");
                int LR;
                scanf("%d",&LR);
                if((ans=InsertNode(T[order],e,LR,c,flag,isempty))==INFEASTABLE)
                    printf("二叉树尚未创建！\n");
                else if(ans==ERROR)
                    printf("二叉树是空二叉树！\n");
                else if(ans==OK)
                    printf("插入成功！\n");
                else if(ans==ILLEAGAL)
                    printf("输入的LR不合法！\n");
                else if(ans==EMPTY)
                    printf("输入关键字不合法！\n");
                getchar();getchar();
                break;
                }

            case 10:
                {
                    int e;
                    printf("输入删除的节点的关键字：");
                    scanf("%d",&e);
                    if((ans=DeleteNode(&T[order],e,flag))==INFEASTABLE)  //不要把ans的右括号括在infeastable后面，会导致ans赋值为表达式的布尔值
                        printf("二叉树尚未创建！\n");
                    else if(ans==ERROR)
                        printf("二叉树是空树！\n");
                    else if(ans==OK)
                        printf("删除成功！\n");
                    else if(ans==EMPTY)
                        printf("输入的关键字不合法！\n");
                    getchar();getchar();
                    break;
                }

            case 11:
                if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                    printf("前序遍历二叉树\n");
                    if((ans=PreOrderTraverse(T[order],visit,flag,isempty))==OK) ;
                    else if(ans==EMPTY)
                        printf("二叉树被清空了！\n");
                    else if(ans==INFEASTABLE)
                        printf("二叉树尚未被创建！\n");
                }
                getchar();getchar();
                break;
            case 12:
                if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                    printf("中序遍历二叉树\n");
                    if((ans=InOrderTraverse(T[order],visit,flag,isempty))==OK)  ;
                    else if(ans==EMPTY)
                        printf("二叉树被清空了！\n");
                    else if(ans==INFEASTABLE)
                        printf("二叉树尚未被创建！\n");
                }
                getchar();getchar();
                break;
            case 13:
                if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                    printf("后序遍历二叉树\n");
                    if((ans=PostOrderTraverse(T[order],visit,flag,isempty))==OK);
                    else if(ans==INFEASTABLE)
                        printf("二叉树尚未被创建!\n");
                    else if(ans==EMPTY)
                        printf("二叉树被清空了！\n");
                }
                getchar();getchar();
                break;
            case 14:
                if(!T[order])    printf("二叉树是空树！\n");
                else
                {
                    printf("层序遍历二叉树\n");
                    if((ans=LevelOrderTraverse(T[order],visit,flag))==OK)   ;
                    else if(ans==INFEASTABLE)
                        printf("二叉树尚未创建！");
                    else if(ans==EMPTY)
                        printf("二叉树被清空了！\n");
                }
                getchar();getchar();
                break;
            case 15:
                {
                    if(!T[order])   printf("二叉树是空树！\n");
                    else if(flag)   printf("二叉树尚未被创建！\n");
                    else
                    {
                        printf("输入要查找双亲的节点的关键字：\n");
                        int e;
                        scanf("%d",&e);
                        if(isempty)
                            printf("二叉树被清空了！\n");
                        else if((pans=GetParent(T[order],e))==NULL)
                            printf("找不到双亲节点！\n");
                        else
                        {
                            printf("该节点的双亲节点的");
                            visit(pans->elem);
                        }
                    }
                    getchar();getchar();
                    break;
                }
            case 16:
                {
                    if(isempty)
                        printf("二叉树被清空了！\n");
                    else if(flag)    printf("二叉树尚未被创建！\n");
                    else if(!T[order])    printf("二叉树是空树！\n");
                    else
                    {
                        FILE  *fp;char filename[30];
                        printf("input file name: ");
                        scanf("%s",filename);
                        if ((fp=fopen(filename,"wb+"))==NULL)
                        {
                            printf("File open error\n ");
                            exit(-1);
                        }
                        else
                            SaveTree(T[order],def,fp);
                        fclose(fp);

                    }
                    getchar();getchar();
                    break;
                }

            case 17:
                {
                    if(flag)    printf("二叉树尚未被创建！\n");
                    else if(!T[order])      printf("二叉树是空树！\n");
                    else
                    {
                        LoadTree(&T[order],defination,count,&flag);
                        isempty=0;
                    }
                    getchar();getchar();
                    break;
                }

            case 0:
                break;
            }//end of switch
        }//end of the inner while
        printf("继续创建下一个二叉树?     [Y/N]（输入大写）\n");
        getchar();op=((c=getchar())=='Y')?1:0;
        if(op==0)
        {
            printf("是否返回到之前的二叉树？   [Y/N]（输入大写）\n");
            getchar();op=((c=getchar())=='Y')?1:0;
        }
        isempty=0;

    }//end of the outer while
    return 0;
}//end of main
status SaveTree(BiTree t,ElemType def,FILE* fp)
{
    //按先序序列的顺序将初始二叉树数据写入文件中
	if(t)
        fwrite(&(t->elem),sizeof(ElemType),1,fp);
    else
        fwrite(&(def),sizeof(ElemType),1,fp);
    if(t)
    {
       SaveTree(t->lchild,def,fp);
       SaveTree(t->rchild,def,fp);
    }

    return OK;
}
status LoadTree(BiTree* t,ElemType* def,int count,int* flag)
{
    FILE  *fp;char filename[30];
    printf("输入需要载入的文件的名称：");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
	{
        printf("File open error\n ");
        exit(-1);
	}
	num=0;  //  一定要记得对num进行修改，不然无法创建二叉树
	int i=0;
    while(fread(&def[i],sizeof(ElemType),1,fp)) i++;
    *flag=0;
    DestroyBiTree(t,flag);
    CreateBiTree(t,def,i,&flag,isempty);
    return 0;
}
status CreateBiTree(BiTree* t,ElemType* defination,int count,int* flag,int isempty)
{
   if(defination[num].key==0)   //关键字为0，意味着是空节点
        {
            *t=NULL;
            num++;
        }

   else if(num<count)
   {
       if(!(*t=(BiTree)malloc(sizeof(BiTNode))))
         exit(OVERFLOW);
       (*t)->elem.key=defination[num].key;
       (*t)->elem.value=defination[num].value;
        (*t)->lchild=(*t)->rchild=NULL;
       num++;
       CreateBiTree(&((*t)->lchild),defination,count,flag,isempty);
       CreateBiTree(&((*t)->rchild),defination,count,flag,isempty);
    }
    *flag = 0 ;
    isempty=0;
    return OK;
}
status DestroyBiTree(BiTree* t,int flag)
{
    //后序递归销毁二叉树
    //必须传入双重指针才能销毁成功
    if(flag)    return INFEASTABLE;     //没有创建二叉树就不能销毁
    if(*t)
    {
        DestroyBiTree(&((*t)->lchild),flag);
        DestroyBiTree(&((*t)->rchild),flag);
        free(*t);
    }*t=NULL;
    isempty=0;
    return OK;
}

status ClearBiTree(BiTree t,int flag)
{
    //不带头结点，t直接指向根节点，则销毁其他节点只保留根节点并保留其内容
    if(flag)    return INFEASTABLE;
    DestroyBiTree(&(t->lchild),flag);
    DestroyBiTree(&(t->rchild),flag);
    t->lchild=t->rchild=NULL;   //要把根节点的左右孩子指针置为空
    return OK;
}
status BiTreeEmpty(BiTree t,int flag)
{
    if(flag)    return INFEASTABLE;
    return t==NULL;
}
status BiTreeDepth(BiTree t,int flag)
{
    if(flag)    return INFEASTABLE;
    if(t==NULL) return ERROR;
    if(t->lchild==NULL&&t->rchild==NULL)
        return 1;
    int ldepth=0;
    int rdepth=0;
    if(t->lchild)
        ldepth=BiTreeDepth(t->lchild,flag);
    if(t->rchild)
        rdepth=BiTreeDepth(t->rchild,flag);
    return (ldepth>rdepth)?ldepth+1:rdepth+1;

}
BiTree LocateNode(BiTree t,int e)
{
    //找到关键字与e相同的节点并返回改节点
    if(t==NULL)     return NULL;   //空
    if((t->elem).key==e)   return t;
    BiTree q;
    if(q=LocateNode(t->lchild,e))  return q;    //传入的节点参数不是要查找的节点就返回空
                                                //当且仅当找到查找的节点才返回非空
                                                //此时就不用继续查找右子树，直接返回，注意不能不带返回
    if(q=LocateNode(t->rchild,e))  return q;
}
BiTree GetParent(BiTree t,int e)
{
    if(t==NULL)         return NULL;    //一定要注意这条语句和下面的语句顺序不能调换
                                        //因为传入的t可能为空指针，调用空指针的数据域会出错，所以要先判断是否为空
    if(e==t->elem.key)  return NULL;    //查询的节点为根节点，无双亲

    if(t->lchild&&(t->lchild->elem.key==e))
        return t;
    if(t->rchild&&t->rchild->elem.key==e)
        return t;
    else
    {
        BiTree q;
        if(q=GetParent(t->lchild,e))       return q;
        if(q=GetParent(t->rchild,e))       return q;
    }

}
status Assign(BiTree t,int e,int val,int flag)
{
    //给关键字为e的节点赋值val
    if(flag)        return INFEASTABLE;
    if(t==NULL)     return ERROR;
    BiTree p=LocateNode(t,e);    //找到节点
    if(p==NULL)     return EMPTY;
    p->elem.value=val;  //赋值
    return OK;
}
BiTree GetSibling(BiTree t,int e)
{
    if(t->elem.key==e)     return NULL;     //查找的节点为根节点，没有兄弟
    BiTree p=NULL,pp=NULL;    //p为关键字为e的节点，pp为p的双亲节点
    p=LocateNode(t,e);
    if(p==NULL) return NULL;
    pp=GetParent(t,e);
    if(p==pp->lchild)   return pp->rchild;
    else return pp->lchild;
}
status InsertNode(BiTree t,int e,int LR,BiTree c,int flag,int isempty)
{
    if(flag)    return INFEASTABLE;     //二叉树没有被创建
    if(t==NULL) return ERROR;       //空二叉树
    isempty=0;
    BiTree p,q;
    p=LocateNode(t,e);
    if(p==NULL)     return EMPTY;   //表示找不到关键字
    if(LR==0)       //插入节点c作为p的左孩子
    {
        q=p->lchild;
        p->lchild=c;
    }
    else if(LR==1)      //插入节点c作为p的右孩子
    {
        q=p->rchild;
        p->rchild=c;
    }
    else return ILLEAGAL;   //LR输入不合法
    c->lchild=NULL;
    c->rchild=q;
    return OK;
}
status DeleteNode(BiTree* t,int e,int flag)
{
    //要传入双重指针否则对根节点删除之后程序会异常结束运行
    if(flag)        return INFEASTABLE;
    if(*t==NULL)     return ERROR;
    BiTree p=NULL,pp=NULL;
    if((*t)->elem.key==e)      //删除的是根节点
    {
            p=*t;
            if((*t)->lchild==NULL)     //根的度为一，且左孩子为空，则右孩子作为根节点
                    *t=(*t)->rchild;
            else if((*t)->rchild==NULL)    //根的度为一，且右孩子为空，则左孩子作为根节点
                *t=(*t)->lchild;
            else
            {                       //根的度为二
                pp=*t=(*t)->lchild;     //根的左孩子为新的根节点
                while(pp->rchild)    pp=pp->rchild;     //遍历到待删的根的左孩子的最右节点
                pp->rchild=p->rchild;           //待删的根的右子树作为其左子树的最右节点的右子树
            }
    }
    else
    {
        p=LocateNode(*t,e);
        if(p==NULL);    return EMPTY;
        pp=GetParent(*t,e);
        if(p->lchild==NULL&&p->rchild==NULL)    //待删节点p为叶子节点
        {
            if(pp->lchild==p)   pp->lchild=NULL;    //p为pp的左孩子，删除后pp的左孩子为空
            else
                pp->rchild=NULL;        //p为pp右孩子
        }
        else if(pp->lchild==p)   //  待删节点不为叶子节点，且为pp的左孩子
        {
            if(p->lchild==NULL&&p->rchild)  //待删节点p度为一，且左孩子为空
                pp->lchild=p->rchild;    //p的右孩子代替p
            else if(p->rchild==NULL&&p->lchild)
                pp->lchild=p->lchild;
            else if(p->lchild&&p->rchild)   //待删节点p的度为二
            {
                pp->lchild=p->lchild;   //p节点的左孩子代替p
                BiTree q=pp->lchild;
            while(q->rchild)    q=q->rchild;    //找到p的左子树的最右节点
            q->rchild=p->rchild;        //p的右子树做其左子树的最右节点的右子树
        }
        }
        else
        {
            //p为pp的右孩子，同理上述步骤
            if(p->lchild==NULL&&p->rchild)
                pp->rchild=p->rchild;
            else if(p->rchild==NULL&&p->lchild)
                pp->rchild=p->lchild;
            else if(p->lchild&&p->rchild)
            {
                pp->rchild=p->lchild;
                BiTree q=pp->rchild;
                while(q->rchild)    q=q->rchild;
                q->rchild=p->rchild;
            }
        }
    }
    free(p);    //  记得释放内存空间
    return OK;
}


status InOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty)
{
    //中序非递归算法
    if(flag) return INFEASTABLE;    //二叉树不存在
    if(isempty) return EMPTY;
    else
    {
        BiTree st[MAXLENG+1];
        int top=0;
        do
        {
            while(t)
            {
                if(top==MAXLENG)    exit(OVERFLOW);
                st[++top]=t;
                t=t->lchild;
            }//先左一直到最左节点
            if(top) //  非空栈
            {
                t=st[top--];
                visit((t->elem));
                t=t->rchild;
            }//end of if
        }while(t||top);
        return OK;
    }

}
status PreOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty)
{
    //前序递归算法
    if(flag) return INFEASTABLE;
    if(isempty) return EMPTY;
    else if(t)
    {
        visit((t->elem));
        PreOrderTraverse(t->lchild,visit,flag,isempty);
        PreOrderTraverse(t->rchild,visit,flag,isempty);

    }return OK;
}
status PostOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty)
{
    //后序递归算法
    if(flag)    return INFEASTABLE;
    if(isempty) return EMPTY;
    else if(t)
    {
        PostOrderTraverse(t->lchild,visit,flag,isempty);
        PostOrderTraverse(t->rchild,visit,flag,isempty);
        visit((t->elem));
    }
    return OK;
}
status LevelOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag)
{
    if(flag)    return INFEASTABLE;
    if(t==NULL) return ERROR;
    if(isempty) return EMPTY;
    pLinkQueue p=(pLinkQueue)malloc(sizeof(LinkQueue));
    p=InitQueue(p);
    if(EnQueue(p,t)==OVERFLOW)    exit(OVERFLOW);
    else
    {
        while(p->rear!=p->front)    //队列不为空
        {
            BiTree q=DeQueue(p);
            visit(q->elem);
            if(q->lchild)
                EnQueue(p,q->lchild);
            if(q->rchild)
                EnQueue(p,q->rchild);
        }
    }
    return OK;
}
