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
	printf("    ��ѡ���������L[%d]�Ĳ���[0~12]:",count);
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiList���ܴ�ʵ�֣�\n");
             if((ans=InitList(&L[count],&flag))==OK) printf("�������ɹ���\n");
		     else if(ans==OVERFLOW) printf("����ʧ�ܣ�\n");
		     else printf("�����Ѿ����ڣ�\n");
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
		 if(DestroyList(&L[count],flag)==OK) printf("�������ٳɹ���\n");
            else printf("�����ڣ��޷����٣�\n");
		 getchar();getchar();
		 break;
	   case 3:
		 //printf("\n----ClearList���ܴ�ʵ�֣�\n");
         if(ClearList(L[count],flag)==OK) printf("������ճɹ���\n");
            else printf("�����ڣ����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 4:
		 //printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
		 if((ans=ListEmpty(L[count],flag))==1) printf("�����ǿձ�\n");
         else if(ans==INFEASTABLE)  printf("�������ڣ�\n");
         else printf("�����ǿձ�\n");
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength���ܴ�ʵ�֣�\n");
		 if((ans=ListLength(L[count],flag))>=0)
            printf("����ĳ���Ϊ��%d\n",ans);
		 else
            printf("�������ڣ�\n");
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem���ܴ�ʵ�֣�\n");
		 printf("����������Ҫ��ȡ�����ݵ�λ�ã�\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if((ans=GetElem(L[count],i,&e,flag))==1)//�����ansֻ��һ������ֵ
            printf("���е�%d��Ԫ�ص�ֵΪ��%d\n",i,e);//����ansӦ����e
         else if(ans==0)
            printf("��������ݲ��Ϸ�!\n");
         else printf("�������ڣ�\n");
		 getchar();getchar();
		 break;
	   case 7:
		 {
		     //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
            int e;
            printf("��������Ҫ���ҵ�����\n");
            scanf("%d",&e);
            if((ans=LocateElem(L[count],e,equal,flag))>0)
                printf("����Ҫ���ҵ�����λ��Ϊ��%d\n",ans);
            else if(ans==0)
                printf("����ʧ�ܣ�\n");
            else
                printf("�������ڣ�\n");
            getchar();getchar();
            break;
		 }
	   case 8:
		 //printf("\n----PriorElem���ܴ�ʵ�֣�\n");
		 {
		     int cur_e,pre_e=0;
            printf("��������Ҫ���ҵ�����\n");
            scanf("%d",&cur_e);
            if((ans=PriorElem(L[count],cur_e,&pre_e,flag))==1)
                printf("����Ҫ���ҵ�����ǰ��Ϊ��%d\n",pre_e);
            else if(ans==0)
                printf("����ʧ�ܣ�\n");
            else
                printf("�������ڣ�\n");
            getchar();getchar();
            break;
		 }

	   case 9:
	       {
	           //printf("\n----NextElem���ܴ�ʵ�֣�\n");
		 int cur_e,next_e=0;
		  printf("��������Ҫ���ҵ�����\n");
		 scanf("%d",&cur_e);
		 if((ans=NextElem(L[count],cur_e,&next_e,flag))==1)
            printf("����Ҫ���ҵ����ĺ��Ϊ��%d\n",next_e);
         else if(ans==0)
            printf("����ʧ�ܣ�\n");
         else
            printf("�������ڣ�\n");
		 getchar();getchar();
		 break;
	       }

	   case 10:
		 {
		     //printf("\n----ListInsert���ܴ�ʵ�֣�\n");
		 printf("������������λ�ú������Ԫ�أ�\n");
		 int i,e;
		 scanf("%d %d",&i,&e);
		 if((ans=ListInsert(L[count],i,e,flag))==1)
            printf("����ɹ���\n");
         else if(ans==0)
            printf("����λ�ò��Ϸ�������ʧ�ܣ�\n");
        else
            printf("�������ڣ�\n");
		 getchar();getchar();
		 break;
		 }

	   case 11:
	       {
	           //printf("\n----ListDelete���ܴ�ʵ�֣�\n");
		 printf("��������ɾ����λ�ã�\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if((ans=ListDelete(L[count],i,&e,flag))==1)
            printf("ɾ���ɹ�������ɾ��������Ϊ��%d\n",e);
         else if(ans==0)
            printf("����λ�ò��Ϸ���ɾ��ʧ�ܣ�\n");
         else
            printf("�������ڣ�\n");
		 getchar();getchar();
		 break;
	       }
	   case 12:
	       {
	           //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");

		 if((ans=ListTrabverse(L[count],flag))==0) printf("������ǿձ�\n");
		 else if(ans==INFEASTABLE)  printf("�������ڣ�\n");
		getchar();getchar();
		 break;
	       }
	case 0:
         printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");break;
    case 13:
        SaveList(L[count]);break;
    case 14:
            LoadList(L[count]);
            break;



	}//end of switch
  }//end of while
  count++;
  printf("����������һ�����Ա�?     [Y/N]\n");
  getchar();op=((c=getchar())=='Y')?1:0;   //���û�ȷ����Ҫ�������Ա������
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
        fwrite(&(p->elem),sizeof(ElemType),1,fp);//�����Ա������д��file��������
        p=p->next;
    }


    fclose(fp);
    return 0;
 }
status LoadList(LinkList headp){
    FILE  *fp;char filename[30];
    printf("������Ҫ������ļ������ƣ�");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
	{
        printf("File open error\n ");
        exit(-1);
	}
	LinkList p=headp;
    LinkList add=(LinkList)malloc(sizeof(LNode));
    while(fread(&(add->elem),sizeof(ElemType),1,fp))
        {//���ļ��е�����Ԫ��д���µĽ���У����µĽ�����������
            add->next=NULL;
            p->next=add;
            p=add;
            add=(LinkList)malloc(sizeof(LNode));
        }
    //�����Ա��ֵ����ݱ��޸ĺ󣬿������½������ļ��е����ݶ������Ա���У��ָ���ԭ����״̬
    free(add);
    fclose(fp);
    return 0;
    }
status InitList(LinkList* headp,int *flag){
    /*����һ���յ����Ա�*/
    *headp=(LinkList)malloc(sizeof(LNode));
    if(!headp) exit(OVERFLOW);
    (*headp)->next=NULL;
    *flag=0;
    return OK;
}
status DestroyList(LinkList* headp,int flag){
    /*����һ���Ѵ��ڵĴ�ͷ�ڵ�����Ա�*/
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
    /*���һ���Ѵ��ڵ����Ա�*/
    /*���������û�ڵ㣬���������ڣ����Լ�������ڵ㡣*/
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
    /*�ж����Ա��Ƿ�Ϊ��*/
    if(!headp||flag)
        return INFEASTABLE;
    if(headp->next==NULL)
        return TRUE;
    else return FALSE;
}
status ListLength(LinkList headp,int flag){
    /*�������Ա��Ԫ�س���*/
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
    /*��e����L�еĵ�i��Ԫ�ص�ֵ*/
    if(!headp||flag)    return INFEASTABLE;
    LinkList p=headp->next;
    int j=1;    //������
    while(p&&j<i){  //˳�����ֱ��pָ���i��Ԫ�ػ���Ϊ��
        p=p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;   //  ��i��Ԫ�ز�����
    *e=p->elem; //  ȡ��Ԫ��
    return OK;
}
status LocateElem(LinkList headp,ElemType e,int (*compare)(ElemType x,ElemType y),int flag){
    /*compare����Ϊ������ָ�����*/
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
    /*��cur��L������Ԫ���Ҳ��ǵ�һ��������pre_e����ǰ��*/
    /*�������ʧ��*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp->next;
    if(!p)  return ERROR;   //�ж��Ƿ�Ϊ�ձ�
    if(p->elem==cur)    return ERROR;   //  cur�ǵ�һ��Ԫ��
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
    /*��cur��L������Ԫ���Ҳ������һ������next���غ��*/
    /*�������ʧ��*/
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
    /*��L�ĵ�i��λ��ǰ�����µ�����e�����ȼ�1*/
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
    /*ɾ��L�ĵ�i�����ݣ�����e������ֵ��L�ĳ��ȼ�1*/
    if(!headp||flag)  return INFEASTABLE;
    LinkList p=headp;
    int j=0;
    while(p->next&&j<i-1){  //Ѱ�ҵ�i����㣬����pָ����ǰ��
        p=p->next;++j;
    }
    if(!(p->next)||j>i-1)   return ERROR;   //ɾ��λ�ò�����
    LinkList q=p->next;
    p->next=q->next;
    *e=q->elem;free(q); //�ͷ�ɾ�����
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

