#include"sqlist.h"
int main(int argc,char* argv[])
{
    SqList L[10];
    int count=0,op=1;
    char c;
    //��ʼ�����Ա�
    while(op)
    {
        PrintMune(&L[count],count);
        count++;
        printf("����������һ�����Ա�?     [Y/N]\n");
        getchar();op=((c=getchar())=='Y')?1:0;   //���û�ȷ����Ҫ�������Ա������
    }
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
	printf("    ��ѡ��������Ա�L[%d]�Ĳ���[0~12]:",order);
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiList���ܴ�ʵ�֣�\n");
             if((ans=InitList(L))==OK) printf("���Ա����ɹ���\n");
		     else if(ans==OVERFLOW) printf("����ʧ�ܣ�\n");
		     else printf("���Ա��Ѿ����ڣ�\n");
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
		 if(DestroyList(L)==OK) printf("���Ա����ٳɹ���\n");
            else printf("�����ڣ��޷����٣�\n");
		 getchar();getchar();
		 break;
	   case 3:
		 //printf("\n----ClearList���ܴ�ʵ�֣�\n");
         if(ClearList(L)==OK) printf("���Ա���ճɹ���\n");
            else printf("�����ڣ����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 4:
		 //printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
		 if((ans=ListEmpty(L))) printf("���Ա��ǿձ�\n");
         else if(ans==INFEASTABLE)  printf("���Ա����ڣ�\n");
         else printf("���Ա��ǿձ�\n");
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength���ܴ�ʵ�֣�\n");
		 if((ans=ListLength(L))>=0)
            printf("���Ա�ĳ���Ϊ��%d\n",ans);
		 else
            printf("���Ա����ڣ�\n");
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem���ܴ�ʵ�֣�\n");
		 printf("����������Ҫ��ȡ�����ݵ�λ�ã�\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if((ans=GetElem(L,i,&e)))//�����ansֻ��һ������ֵ
            printf("���е�%d��Ԫ�ص�ֵΪ��%d\n",i,e);//����ansӦ����e
         else
            printf("��������ݲ��Ϸ�!\n");
		 getchar();getchar();
		 break;
	   case 7:
		 {
		     //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
            int e;
            printf("��������Ҫ���ҵ�����\n");
            scanf("%d",&e);
            if((ans=LocateElem(L,e,equal)))
                printf("����Ҫ���ҵ�����λ��Ϊ��%d\n",ans);
            else
                printf("����ʧ�ܣ�\n");
            getchar();getchar();
            break;
		 }
	   case 8:
		 //printf("\n----PriorElem���ܴ�ʵ�֣�\n");
		 {
		     int cur_e,pre_e=0;
            printf("��������Ҫ���ҵ�����\n");
            scanf("%d",&cur_e);
            if(PriorElem(L,cur_e,&pre_e))
                printf("����Ҫ���ҵ�����ǰ��Ϊ��%d\n",pre_e);
            else
                printf("����ʧ�ܣ�\n");
            getchar();getchar();
            break;
		 }

	   case 9:
	       {
	           //printf("\n----NextElem���ܴ�ʵ�֣�\n");
		 int cur_e,next_e=0;
		  printf("��������Ҫ���ҵ�����\n");
		 scanf("%d",&cur_e);
		 if((NextElem(L,cur_e,&next_e)))
            printf("����Ҫ���ҵ����ĺ��Ϊ��%d\n",next_e);
         else
            printf("�����Ա����Ҳ�������Ҫ���ҵ����ĺ�̣�\n");
		 getchar();getchar();
		 break;
	       }

	   case 10:
		 {
		     //printf("\n----ListInsert���ܴ�ʵ�֣�\n");
		 printf("������������λ�ú������Ԫ�أ�\n");
		 int i,e;
		 scanf("%d %d",&i,&e);
		 if(ListInsert(L,i,e))
            printf("����ɹ���\n");
         else
            printf("����λ�ò��Ϸ�������ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
		 }

	   case 11:
	       {
	           //printf("\n----ListDelete���ܴ�ʵ�֣�\n");
		 printf("��������ɾ����λ�ã�\n");
		 int i,e=0;
		 scanf("%d",&i);
		 if(ListDelete(L,i,&e))
            printf("ɾ���ɹ�������ɾ��������Ϊ��%d\n",e);
         else
            printf("����λ�ò��Ϸ���ɾ��ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	       }
	   case 12:
	       {
	           //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");

		 if(!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
		 else if(ListTrabverse(L)==INFEASTABLE)  printf("���Ա����ڣ�\n");
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
status SaveList(SqList* L){   //����ʱ���ݲ���&L[i]
    FILE  *fp;char filename[30];
    printf("input file name: ");
    scanf("%s",filename);
    if ((fp=fopen(filename,"wb"))==NULL)
	{
	printf("File open error\n ");
	exit(-1);
	}
    fwrite(L->elem,sizeof(ElemType),L->length,fp);//�����Ա������д��file��������
    fclose(fp);
    return 0;
 }
status LoadList(SqList* L){
    L->length=0;
    FILE  *fp;char filename[30];
    printf("������Ҫ������ļ������ƣ�");
    scanf("%s",filename);
    if ((fp=fopen(filename,"rb"))==NULL)
	{
        printf("File open error\n ");
        exit(-1);
	}
    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
        L->length++;
    //�����Ա��ֵ����ݱ��޸ĺ󣬿������½������ļ��е����ݶ������Ա���У��ָ���ԭ����״̬
    fclose(fp);
    return 0;
    }
status InitList(SqList* L){
    /*����һ���յ����Ա�*/
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
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
    L->elem=NULL;
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
status ListLength(SqList* L){
    /*�������Ա��Ԫ�س���*/
    if(!L->elem)
        return INFEASTABLE;
    return L->length;
}
status GetElem(SqList* L,int i,ElemType* e){
    /*��e����L�еĵ�i��Ԫ�ص�ֵ*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<1||i>L->length)
        return ERROR;   //�����iֵ���Ϸ�
    *e=*(L->elem+i-1);
    return OK;//��һ��д��return *e,�����ᵼ�������i��Ԫ�ص�ֵΪ0�����жϴ���
}
status LocateElem(SqList* L,ElemType e,int (*compare)(ElemType x,ElemType y)){
    /*compare����Ϊ������ָ�����*/
    if(!L->elem)
        return INFEASTABLE;
    for(int i=0;i<L->length;i++)
        if((*compare)(L->elem[i],e)==0)
            return i+1;
    return FALSE;
}
status PriorElem(SqList* L,ElemType cur,ElemType *pre_e){
    /*��cur��L������Ԫ���Ҳ��ǵ�һ��������pre_e����ǰ��*/
    /*�������ʧ��*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L->length;i++)
        if((j=LocateElem(L,cur,equal))>1)
        {
            *pre_e=*(L->elem+j-2);   //����Locate���ص���λ������������е��±꣬λ����±�Ҫ��1������Ӧ�ü�2
            return OK;
        }

    return ERROR;
}
status NextElem(SqList* L,ElemType cur,ElemType* next_e){
    /*��cur��L������Ԫ���Ҳ������һ������next���غ��*/
    /*�������ʧ��*/
    if(!L->elem)
        return INFEASTABLE;
        int j;
    for(int i=0;i<L->length;i++)
        if((j=LocateElem(L,cur,equal))>0&&j<L->length)
        {
            *next_e=*(L->elem+j); //  ͬ�������prior����������ֻ��Ҫj,����Ҫ��1
            return OK;
        }

    return ERROR;
}
status ListInsert(SqList* L,int i,ElemType e){
    /*��L�ĵ�i��λ��ǰ�����µ�����e�����ȼ�1*/
    if(!L->elem)
        return INFEASTABLE;
    if(i<0||i>L->length+1)     return ERROR;
    if(L->length>=L->listsize){
            //��ǰ����ռ����������ӷ���
        ElemType* newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)    exit(OVERFLOW); //�洢�ڴ����ʧ��
        L->elem=newbase;
        L->listsize +=LISTINCREMENT;
    }
    for(int j=L->length-1;j>=i-1;j--)
            *(L->elem+j+1)=*(L->elem+j);        //����λ�ü�֮���Ԫ�غ���
    *(L->elem+i-1)=e;
    ++L->length;
    return OK;
}
status ListDelete(SqList* L,int i,ElemType* e){
    /*ɾ��L�ĵ�i�����ݣ�����e������ֵ��L�ĳ��ȼ�1*/
    if(i<0||i>L->length)     return ERROR;
    *e=*(L->elem+i-1);  //�ڶ����޸�ʱ��û����eǰ���ȡֵ���ţ�����e��ֵ�ڵ��ú�����û�иı�
    for(int j=i-1;j<L->length;j++)
        L->elem[j]=L->elem[j+1];
    --L->length;
    return OK;  //��һ���޸�ʱ���ص���*e,��ʵ���ϣ�*e��ֵ�����ǰ�ƺ�ĵ�i���������뷵�ص����ĺ�һ����
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



