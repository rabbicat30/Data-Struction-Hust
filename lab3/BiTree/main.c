#include"queue.h"
int num=0;
int isempty=0; //isempty�����ж��Ƿ�clear�������ڵ���ڵ�������Ϊ��
int main(void){
    int count=0;   //��¼��Ҫ�����Ķ������ڵ�ĸ����������սڵ�
    int flag=1;
    ElemType defination[100];   //��Ŷ������Ľڵ�����
    BiTree T[10];              //���Ա��ö���������
    BiTree pans=NULL;          //ע���ָֹ������
    int op=1,ans=0;
    int order=0;               //��ǰ�����Ķ������Ķ����������±�
    char c;
    ElemType def;               //���ڶ����ļ�ʱ���սڵ���
    def.key=0;def.value=0;
    while(op)
    {
        printf("������Ҫ�����Ķ���������ţ�[0-9]\n");
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

            printf("��ѡ����Զ�����T[%d]�Ĳ���[0~12]:",order);
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                    printf("�밴���������зֱ����������T[%d]�ڵ�ؼ��ֺ���Ҫ�洢�����ݣ����Կո��س����ָ���\n",order);
                    printf("ע������Ĺؼ��ֺ����ݾ�Ϊ������\n");
                    printf("����ؼ���Ϊ0��ʾ�ڵ�Ϊ�գ��Ҳ���Ҫ�������ݣ�\n");
                    printf("����ؼ���Ϊ-1������\n");
                    scanf("%d",&((defination[count]).key));
                    while((defination[count]).key!=-1)//����ڵ���
                    {

                        if(defination[count].key>0)    //�ڵ�������������Ϊ������ֵ������Ϊϵͳ�Զ������ֵ
                        {
                            scanf("%d",&((defination[count]).value));
                        }
                        count++;
                        scanf("%d",&((defination[count]).key));

                    }
            if((ans=CreateBiTree(&T[order],defination,count,&flag,isempty))==1)
                    printf("�����������ɹ�!\n");
                else if(ans==OVERFLOW)
                    printf("����������ʧ�ܣ�\n");
                getchar();getchar();
                break;
            case 2:
                if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                    if((ans=DestroyBiTree(&T[order],flag))==INFEASTABLE)
                        printf("��������δ������\n");
                    else
                        printf("���������ٳɹ���\n");
                }
                getchar();getchar();
                break;

            case 3:
                if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                    if((ans=ClearBiTree(T[order],flag))==INFEASTABLE)
                        printf("��������δ������\n");
                    else
                    {
                        printf("��������ճɹ���\n");
                        isempty=1;
                    }
                }
               getchar();getchar();
                break;
            case 4:
                if(isempty)
                    printf("������������ˣ�\n");
                else if((ans=BiTreeEmpty(T[order],flag))==INFEASTABLE)
                    printf("��������δ������\n");
                else if(ans==1)
                    printf("������Ϊ�ն�������\n");
                else
                    printf("���������ǿյ�!\n");
                getchar();getchar();
                break;
            case 5:
                if(isempty)
                    printf("������������ˣ�\n");
                else if((ans=BiTreeDepth(T[order],flag))>=0)
                    printf("�����������Ϊ��%d\n",ans);
                else
                    printf("��������δ������\n");
                getchar();getchar();
                break;
            case 6:
                if(flag)        printf("��������δ��������\n");
                else if(isempty)      printf("������������ˣ�\n");
                else if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                printf("������ҵĽڵ�Ĺؼ��֣�\n");
                int e;
                scanf("%d",&e);
                if((pans=LocateNode(T[order],e)))
                    visit(pans->elem);
                else if(pans==NULL)
                    printf("�Ҳ����ؼ���Ϊ%d�Ľڵ㣡\n",e);
                }
                getchar();getchar();
                break;
            case 7:
                {
                    int e;
                    int val;
                    printf("������Ҫ��ֵ�Ľڵ�Ĺؼ��ֺ�ֵ��\n");
                    scanf("%d",&e);
                    scanf("%d",&val);
                    if(flag)    printf("��������δ��������\n");
                    else if(isempty)
                        printf("������������ˣ�\n");
                    else if((ans=Assign(T[order],e,val,flag))==INFEASTABLE)
                        printf("��������δ������\n");
                    else if(ans==0)
                        printf("�������ǿն�������\n");
                    else if(ans==EMPTY)
                        printf("����ؼ��ֲ��Ϸ���\n");
                     else
                        printf("��ֵ�ɹ���\n");
                    getchar();getchar();
                    break;
                }

            case 8:
                {
                   if(!T[order])    printf("�������ǿ�����\n");
                    else if(flag)    printf("��������δ��������\n");
                    else
                    {
                        int e;
                        printf("������ҵĽڵ�Ĺؼ��֣�");
                        scanf("%d",&e);
                    //�޷����ֿն����������ֵܽڵ�
                    if(isempty)
                        printf("������������ˣ�\n");
                    else if((pans=GetSibling(T[order],e))==NULL)
                            printf("�ýڵ�û���ֵܽڵ㣡\n");
                        else
                        {
                            printf("�ýڵ���ֵܽڵ��");
                            visit(pans->elem);
                        }
                    }
                    getchar();getchar();
                    break;
                }

            case 9:
                {
                   printf("�������λ�õĹؼ��֣�");
                int e;
                scanf("%d",&e);
                BiTree c=(BiTree)malloc(sizeof(BiTNode));
                printf("�ֱ��������Ľڵ�Ĺؼ��ֺ����ݣ�");
                scanf("%d",&c->elem.key);
                scanf("%d",&c->elem.value);
                c->lchild=NULL;
                c->rchild=NULL;
                printf("���뽫����Ľڵ���Ϊ���ӻ����Һ��ӣ�\n");
                printf("����0��ʾ������1��ʾ��\n");
                int LR;
                scanf("%d",&LR);
                if((ans=InsertNode(T[order],e,LR,c,flag,isempty))==INFEASTABLE)
                    printf("��������δ������\n");
                else if(ans==ERROR)
                    printf("�������ǿն�������\n");
                else if(ans==OK)
                    printf("����ɹ���\n");
                else if(ans==ILLEAGAL)
                    printf("�����LR���Ϸ���\n");
                else if(ans==EMPTY)
                    printf("����ؼ��ֲ��Ϸ���\n");
                getchar();getchar();
                break;
                }

            case 10:
                {
                    int e;
                    printf("����ɾ���Ľڵ�Ĺؼ��֣�");
                    scanf("%d",&e);
                    if((ans=DeleteNode(&T[order],e,flag))==INFEASTABLE)  //��Ҫ��ans������������infeastable���棬�ᵼ��ans��ֵΪ���ʽ�Ĳ���ֵ
                        printf("��������δ������\n");
                    else if(ans==ERROR)
                        printf("�������ǿ�����\n");
                    else if(ans==OK)
                        printf("ɾ���ɹ���\n");
                    else if(ans==EMPTY)
                        printf("����Ĺؼ��ֲ��Ϸ���\n");
                    getchar();getchar();
                    break;
                }

            case 11:
                if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                    printf("ǰ�����������\n");
                    if((ans=PreOrderTraverse(T[order],visit,flag,isempty))==OK) ;
                    else if(ans==EMPTY)
                        printf("������������ˣ�\n");
                    else if(ans==INFEASTABLE)
                        printf("��������δ��������\n");
                }
                getchar();getchar();
                break;
            case 12:
                if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                    printf("�������������\n");
                    if((ans=InOrderTraverse(T[order],visit,flag,isempty))==OK)  ;
                    else if(ans==EMPTY)
                        printf("������������ˣ�\n");
                    else if(ans==INFEASTABLE)
                        printf("��������δ��������\n");
                }
                getchar();getchar();
                break;
            case 13:
                if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                    printf("�������������\n");
                    if((ans=PostOrderTraverse(T[order],visit,flag,isempty))==OK);
                    else if(ans==INFEASTABLE)
                        printf("��������δ������!\n");
                    else if(ans==EMPTY)
                        printf("������������ˣ�\n");
                }
                getchar();getchar();
                break;
            case 14:
                if(!T[order])    printf("�������ǿ�����\n");
                else
                {
                    printf("�������������\n");
                    if((ans=LevelOrderTraverse(T[order],visit,flag))==OK)   ;
                    else if(ans==INFEASTABLE)
                        printf("��������δ������");
                    else if(ans==EMPTY)
                        printf("������������ˣ�\n");
                }
                getchar();getchar();
                break;
            case 15:
                {
                    if(!T[order])   printf("�������ǿ�����\n");
                    else if(flag)   printf("��������δ��������\n");
                    else
                    {
                        printf("����Ҫ����˫�׵Ľڵ�Ĺؼ��֣�\n");
                        int e;
                        scanf("%d",&e);
                        if(isempty)
                            printf("������������ˣ�\n");
                        else if((pans=GetParent(T[order],e))==NULL)
                            printf("�Ҳ���˫�׽ڵ㣡\n");
                        else
                        {
                            printf("�ýڵ��˫�׽ڵ��");
                            visit(pans->elem);
                        }
                    }
                    getchar();getchar();
                    break;
                }
            case 16:
                {
                    if(isempty)
                        printf("������������ˣ�\n");
                    else if(flag)    printf("��������δ��������\n");
                    else if(!T[order])    printf("�������ǿ�����\n");
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
                    if(flag)    printf("��������δ��������\n");
                    else if(!T[order])      printf("�������ǿ�����\n");
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
        printf("����������һ��������?     [Y/N]�������д��\n");
        getchar();op=((c=getchar())=='Y')?1:0;
        if(op==0)
        {
            printf("�Ƿ񷵻ص�֮ǰ�Ķ�������   [Y/N]�������д��\n");
            getchar();op=((c=getchar())=='Y')?1:0;
        }
        isempty=0;

    }//end of the outer while
    return 0;
}//end of main
status SaveTree(BiTree t,ElemType def,FILE* fp)
{
    //���������е�˳�򽫳�ʼ����������д���ļ���
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
    printf("������Ҫ������ļ������ƣ�");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
	{
        printf("File open error\n ");
        exit(-1);
	}
	num=0;  //  һ��Ҫ�ǵö�num�����޸ģ���Ȼ�޷�����������
	int i=0;
    while(fread(&def[i],sizeof(ElemType),1,fp)) i++;
    *flag=0;
    DestroyBiTree(t,flag);
    CreateBiTree(t,def,i,&flag,isempty);
    return 0;
}
status CreateBiTree(BiTree* t,ElemType* defination,int count,int* flag,int isempty)
{
   if(defination[num].key==0)   //�ؼ���Ϊ0����ζ���ǿսڵ�
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
    //����ݹ����ٶ�����
    //���봫��˫��ָ��������ٳɹ�
    if(flag)    return INFEASTABLE;     //û�д����������Ͳ�������
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
    //����ͷ��㣬tֱ��ָ����ڵ㣬�����������ڵ�ֻ�������ڵ㲢����������
    if(flag)    return INFEASTABLE;
    DestroyBiTree(&(t->lchild),flag);
    DestroyBiTree(&(t->rchild),flag);
    t->lchild=t->rchild=NULL;   //Ҫ�Ѹ��ڵ�����Һ���ָ����Ϊ��
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
    //�ҵ��ؼ�����e��ͬ�Ľڵ㲢���ظĽڵ�
    if(t==NULL)     return NULL;   //��
    if((t->elem).key==e)   return t;
    BiTree q;
    if(q=LocateNode(t->lchild,e))  return q;    //����Ľڵ��������Ҫ���ҵĽڵ�ͷ��ؿ�
                                                //���ҽ����ҵ����ҵĽڵ�ŷ��طǿ�
                                                //��ʱ�Ͳ��ü���������������ֱ�ӷ��أ�ע�ⲻ�ܲ�������
    if(q=LocateNode(t->rchild,e))  return q;
}
BiTree GetParent(BiTree t,int e)
{
    if(t==NULL)         return NULL;    //һ��Ҫע������������������˳���ܵ���
                                        //��Ϊ�����t����Ϊ��ָ�룬���ÿ�ָ�����������������Ҫ���ж��Ƿ�Ϊ��
    if(e==t->elem.key)  return NULL;    //��ѯ�Ľڵ�Ϊ���ڵ㣬��˫��

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
    //���ؼ���Ϊe�Ľڵ㸳ֵval
    if(flag)        return INFEASTABLE;
    if(t==NULL)     return ERROR;
    BiTree p=LocateNode(t,e);    //�ҵ��ڵ�
    if(p==NULL)     return EMPTY;
    p->elem.value=val;  //��ֵ
    return OK;
}
BiTree GetSibling(BiTree t,int e)
{
    if(t->elem.key==e)     return NULL;     //���ҵĽڵ�Ϊ���ڵ㣬û���ֵ�
    BiTree p=NULL,pp=NULL;    //pΪ�ؼ���Ϊe�Ľڵ㣬ppΪp��˫�׽ڵ�
    p=LocateNode(t,e);
    if(p==NULL) return NULL;
    pp=GetParent(t,e);
    if(p==pp->lchild)   return pp->rchild;
    else return pp->lchild;
}
status InsertNode(BiTree t,int e,int LR,BiTree c,int flag,int isempty)
{
    if(flag)    return INFEASTABLE;     //������û�б�����
    if(t==NULL) return ERROR;       //�ն�����
    isempty=0;
    BiTree p,q;
    p=LocateNode(t,e);
    if(p==NULL)     return EMPTY;   //��ʾ�Ҳ����ؼ���
    if(LR==0)       //����ڵ�c��Ϊp������
    {
        q=p->lchild;
        p->lchild=c;
    }
    else if(LR==1)      //����ڵ�c��Ϊp���Һ���
    {
        q=p->rchild;
        p->rchild=c;
    }
    else return ILLEAGAL;   //LR���벻�Ϸ�
    c->lchild=NULL;
    c->rchild=q;
    return OK;
}
status DeleteNode(BiTree* t,int e,int flag)
{
    //Ҫ����˫��ָ�����Ը��ڵ�ɾ��֮�������쳣��������
    if(flag)        return INFEASTABLE;
    if(*t==NULL)     return ERROR;
    BiTree p=NULL,pp=NULL;
    if((*t)->elem.key==e)      //ɾ�����Ǹ��ڵ�
    {
            p=*t;
            if((*t)->lchild==NULL)     //���Ķ�Ϊһ��������Ϊ�գ����Һ�����Ϊ���ڵ�
                    *t=(*t)->rchild;
            else if((*t)->rchild==NULL)    //���Ķ�Ϊһ�����Һ���Ϊ�գ���������Ϊ���ڵ�
                *t=(*t)->lchild;
            else
            {                       //���Ķ�Ϊ��
                pp=*t=(*t)->lchild;     //��������Ϊ�µĸ��ڵ�
                while(pp->rchild)    pp=pp->rchild;     //��������ɾ�ĸ������ӵ����ҽڵ�
                pp->rchild=p->rchild;           //��ɾ�ĸ�����������Ϊ�������������ҽڵ��������
            }
    }
    else
    {
        p=LocateNode(*t,e);
        if(p==NULL);    return EMPTY;
        pp=GetParent(*t,e);
        if(p->lchild==NULL&&p->rchild==NULL)    //��ɾ�ڵ�pΪҶ�ӽڵ�
        {
            if(pp->lchild==p)   pp->lchild=NULL;    //pΪpp�����ӣ�ɾ����pp������Ϊ��
            else
                pp->rchild=NULL;        //pΪpp�Һ���
        }
        else if(pp->lchild==p)   //  ��ɾ�ڵ㲻ΪҶ�ӽڵ㣬��Ϊpp������
        {
            if(p->lchild==NULL&&p->rchild)  //��ɾ�ڵ�p��Ϊһ��������Ϊ��
                pp->lchild=p->rchild;    //p���Һ��Ӵ���p
            else if(p->rchild==NULL&&p->lchild)
                pp->lchild=p->lchild;
            else if(p->lchild&&p->rchild)   //��ɾ�ڵ�p�Ķ�Ϊ��
            {
                pp->lchild=p->lchild;   //p�ڵ�����Ӵ���p
                BiTree q=pp->lchild;
            while(q->rchild)    q=q->rchild;    //�ҵ�p�������������ҽڵ�
            q->rchild=p->rchild;        //p�����������������������ҽڵ��������
        }
        }
        else
        {
            //pΪpp���Һ��ӣ�ͬ����������
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
    free(p);    //  �ǵ��ͷ��ڴ�ռ�
    return OK;
}


status InOrderTraverse(BiTree t,void (*visit)(ElemType node),int flag,int isempty)
{
    //����ǵݹ��㷨
    if(flag) return INFEASTABLE;    //������������
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
            }//����һֱ������ڵ�
            if(top) //  �ǿ�ջ
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
    //ǰ��ݹ��㷨
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
    //����ݹ��㷨
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
        while(p->rear!=p->front)    //���в�Ϊ��
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
