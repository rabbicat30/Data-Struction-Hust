#include "queue.h"
int flag=1;     //������ʶͼ�Ƿ񴴽���0��ʾ����
int count=0;   //������
status (*VisitFunc)(Graph* graph,int v);    //�������
int visited[100];   //������־���飬Ϊ0��ʾΪ������Ϊ1Ϊ����
int testcount=0;    //��������������
int main(void)
{
    int op=1,ans=0;
    char c;
    int id=0;
    int vexnum,arcnum;
    VNode *Vex=NULL;    //����Ķ�������
    ArcNode *Arc=NULL;  //����Ļ�������
    Graph graph[10];    //��ͼ
    int u,val;      //λ�ú͹ؼ���
    int v,w;        //λ�ú͹ؼ���
    while(op)
    {
        printf("������Ҫ������ͼ����ţ�[0-9]\n");
        scanf("%d",&id);
        while(op)
        {
            system("cls");	printf("\n\n");
            printf("      Menu for Binary Tree On Sequence Structure \n");
            printf("-------------------------------------------------\n");
            printf("    	  1. CreateGraph              7. InsertVex\n");
            printf("    	  2. DestroyGraph             8. DeleteVex\n");
            printf("    	  3. LocateVex                9. InsertArc\n");
            printf("    	  4. PutVex                   10. DeleteArc\n");
            printf("    	  5. FirstAdjVex              11. DFSTraverse\n");
            printf("    	  6. NextAdjVex               12. BFSTraverse\n");
            printf("          13. SaveGraph               14. LoadGraph\n");
            printf("          15. Test                    0. exist\n");
            printf("-------------------------------------------------\n");

            printf("��ѡ�����ͼG[%d]�Ĳ���[0~12]:",id);
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                    printf("������Ҫ������ͼ�Ķ������ͻ�����Ŀ��\n");
                    scanf("%d",&vexnum);
                    scanf("%d",&arcnum);
                    //�ӱ�ͷλ�ò��봴������������ͷ���Ķ�������Vex
                    Vex=(VNode* )malloc(sizeof(VNode));     //���䶥���ͷ�ڵ�
                    Vex->firstarc=NULL;
                    Vex->next=NULL;
                    Arc=(ArcNode*)malloc(arcnum*sizeof(ArcNode));
                    printf("��λ�����붥�����Ϣ��\n");
                    printf("���붥��Ĺؼ��ֺ����ݣ�\n");
                    for(int i=0;i<vexnum;i++)
                    {
                        VNode* vp=(VNode*)malloc(sizeof(VNode));
                        scanf("%d %d",&((vp->data).key),&((vp->data).value));
                        vp->firstarc=NULL;
                        vp->next=Vex->next;Vex->next=vp;
                    }
                    printf("��λ�����뻡����Ϣ��\n");
                    for(int i=0;i<arcnum;i++)
                    {
                       scanf("%d %d",&Arc[i].adjtail,&Arc[i].adjhead);
                        Arc[i].nextarc=NULL;
                    }

                    CreateGraph(&graph[id],Vex,Arc,vexnum,arcnum);
                    getchar();getchar();
                    break;

                case 2:
                    printf("2. ����ͼ��\n");
                    if((ans=DestroyGraph(&graph[id]))==INFEASTABLE)
                        printf("ͼ��δ������\n");
                    else if(ans==ERROR)
                        printf("ͼ�ѱ����٣�\n");
                    else
                        printf("���ٳɹ���\n");
                    getchar();getchar();
                    break;

                case 3:
                    printf("���Ҷ���\n");
                    printf("������ҵĶ���Ĺؼ��֣�\n");
                    scanf("%d",&u);
                    if((ans=LocateVex(&graph[id],u))==INFEASTABLE)
                        printf("ͼ��δ������\n");
                    else if(ans==EMPTY)
                        printf("ͼ�����ڣ�\n");
                    else if(ans==ERROR)
                        printf("�Ҳ���������㣡\n");
                    else
                        printf("����λ���ڽӱ�ĵ�%d��λ��",ans);
                    getchar();getchar();
                    break;

                case 4:
                    printf("Ϊ���㸳ֵ\n");
                    printf("���븳ֵ�Ĺؼ��ֺ���Ϣ��\n");
                    scanf("%d %d",&u,&val);
                    if((ans=PutVex(&graph[id],u,val))==INFEASTABLE)
                        printf("ͼ��δ������\n");
                    else if(ans==EMPTY)
                        printf("ͼ�����ڣ�\n");
                    else if(ans==ERROR)
                        printf("�Ҳ��������Ķ��㣡\n");
                    else
                        printf("��ֵ�ɹ�!\n");
                    getchar();getchar();
                    break;

                case 5:
                    printf("5. ���ҵ�һ�ڽӵ�\n");
                    printf("������ҵĶ����λ�ã�\n");
                    scanf("%d",&u);
                    if(u>graph[id].vexnum||u<=0)
                        printf("����λ�ò��Ϸ�!\n");
                    else if((ans=FirstAdjVex(&graph[id],u))==INFEASTABLE)
                        printf("ͼ��δ������\n");
                    else if(ans==EMPTY)
                        printf("ͼ�����ڣ�\n");

                    else if(ans==ERROR)
                            printf("�ö��㲻���ڵ�һ�ڽӵ㣡\n");
                    else
                            printf("��һ�ڽӵ��λ��Ϊ��%d",ans);


                    getchar();getchar();
                    break;
                case 6:
                    printf("6. ������һ�ڽӵ�\n");
                    printf("������ҵĶ����λ��:\n");
                    scanf("%d",&v);
                    printf("����ö�����ڽӵ��λ��:\n");
                    scanf("%d",&w);
                    if(v>graph[id].vexnum||w>graph[id].vexnum||v<=0||w<=0)
                           printf("�����λ�ò��Ϸ���\n");
                    else if((ans=NextAdjVex(&graph[id],v,w))==INFEASTABLE)
                        printf("ͼ��δ������\n");
                    else if((ans=NextAdjVex(&graph[id],v,w))==EMPTY)
                        printf("ͼ�����ڣ�\n");
                    else
                    {
                            if((ans=NextAdjVex(&graph[id],v,w))==ERROR)
                                printf("û�������ڽӵ㣡\n");
                            else
                                printf("��һ���ڽӵ��λ��Ϊ��%d",ans);

                    }
                    getchar();getchar();
                    break;
                case 7:
                    {

                    printf("7. ���붥��\n");
                    VNode v;
                    printf("�������Ķ���Ĺؼ��ֺ���Ϣ��\n");
                    scanf("%d %d",&v.data.key,&v.data.value);
                    v.firstarc=NULL;
                    if((ans=InsertVex(&graph[id],v))==INFEASTABLE)
                        printf("ͼ��δ������\n");
                    else if(ans==EMPTY)
                        printf("ͼ������!\n");

                    else
                        printf("����ɹ�������󶥵����ĿΪ��%d\n",graph[id].vexnum);
                    getchar();getchar();
                    break;
                    }
                case 8:
                    {
                        printf("8. ɾ������\n");
                        VNode v;
                        printf("����ɾ������Ĺؼ��ֺ���Ϣ��\n");
                        scanf("%d %d",&v.data.key,&v.data.value);
                        if((ans=DeleteVex(&graph[id],v))==INFEASTABLE)
                            printf("ͼ��δ������\n");
                        else if(ans==EMPTY)
                            printf("ͼ�����ڣ�\n");
                        else if(ans==ILLEAGAL)
                            printf("����Ķ��㲻��ȷ��\n");
                        else
                            printf("ɾ������ɹ���ɾ���󶥵����ĿΪ��%d ������ĿΪ%d\n",graph[id].vexnum,graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }

                case 9:
                    {
                        printf("9. ���뻡\n");
                        VNode v,w;
                        printf("���뻡β�Ĺؼ��ֺ�����\n");
                        scanf("%d %d",&v.data.key,&v.data.value);
                        printf("���뻡ͷ�Ĺؼ��ֺ�����\n");
                        scanf("%d %d",&w.data.key,&w.data.value);
                        if((ans=InsertArc(&graph[id],v,w))==INFEASTABLE)
                            printf("ͼ��δ������\n");
                        else if(ans==EMPTY)
                            printf("ͼ�����ڣ�\n");
                        else if(ans==ILLEAGAL)
                            printf("����Ķ��㲻��ȷ��\n");
                        else
                            printf("���뻡�ɹ��������Ļ�����ĿΪ%d\n",graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }
                case 10:
                    {
                         printf("10. ɾ����\n");
                         VNode v,w;
                         printf("����û��Ļ�β��ָ��Ķ���Ĺؼ�����Ϣ��\n");
                         scanf("%d %d",&v.data.key,&v.data.value);
                         printf("����û��Ļ�ͷָ��Ķ���Ĺؼ��ֺ���Ϣ��\n");
                         scanf("%d %d",&w.data.key,&w.data.value);
                         v.firstarc=w.firstarc=NULL;
                         if((ans=DeleteArc(&graph[id],v,w))==INFEASTABLE)
                            printf("ͼ��δ����!\n");
                         else if(ans==EMPTY)
                            printf("ͼ�����ڣ�\n");
                         else if(ans==ILLEAGAL)
                            printf("���붥�㲻�Ϸ�!\n");
                         else if(ans==ERROR)
                            printf("����������֮��û�л���\n");
                        else
                            printf("ɾ�����ɹ���ɾ���󻡵���ĿΪ��%d\n",graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }
                case 11:
                    {
                        printf("11. ��ȱ���\n");
                        testcount=0;        //ȫ�ֱ���ȷ��ÿ�α���ʱ����0��ʼ����
                        for(int i=1;i<=graph[id].vexnum;i++)
                            visited[i]=FALSE;
                        if(flag)
                            printf("ͼ��δ������\n");
                        else if(!(graph[id].vnode)->next)
                            printf("ͼ������\n");
                        else
                        {
                            int u;
                            printf("���뿪ʼ�����Ķ����λ�ã�\n");
                            scanf("%d",&u);
                            DFSTraverse(&graph[id],u,Visit);
                            if(testcount<graph[id].vexnum)
                                printf("����ʧ�ܣ�\n");
                        }
                        getchar();getchar();
                        break;
                    }
                case 12:
                    {
                        printf("12. ��ȱ���\n");
                        testcount=0;
                        if(flag)
                            printf("ͼ��δ������\n");
                        else if(!(graph[id].vnode)->next)
                            printf("ͼ������\n");
                        else
                        {
                            printf("���뿪ʼ�����Ķ����λ��:\n");
                            int v;
                            scanf("%d",&v);
                            BFSTraverse(&graph[id],v,Visit);
                            if(testcount<graph[id].vexnum)
                                printf("����ʧ�ܣ�\n");
                        }
                        getchar();getchar();
                        break;
                    }
                case 13:
                    {
                        printf("13. �����ļ�\n");
                        FILE *fp,*fq;
                        char vex_filename[30],arc_filename[30];
                        printf("���붥����ļ����ƣ�\n");
                        scanf("%s",vex_filename);
                        printf("���뻡���ļ�������:\n");
                        scanf("%s",arc_filename);
                        if ((fp=fopen(vex_filename,"wb+"))==NULL||(fq=fopen(arc_filename,"wb+"))==NULL)
                        {
                            printf("File open error\n ");
                            exit(-1);
                        }
                        else if((ans=SaveGraph(&graph[id],fp,fq))==INFEASTABLE)
                            printf("ͼ��δ����!\n");
                        else if(ans==EMPTY)
                            printf("ͼ�����ڣ�\n");
                        else
                            printf("����ɹ���\n");

                        getchar();getchar();
                        break;
                        }


                case 14:
                    {
                        if((ans=LoadGraph(&graph[id])==INFEASTABLE))
                            printf("ͼ��δ����!\n");
                        else if(ans==EMPTY)
                            printf("ͼ������!\n");
                        else
                            printf("����ɹ���\n");
                            getchar();getchar();
                            break;
                    }
                case 15:
                    {
                        VNode* vp=NULL;
                        for(vp=(graph[id].vnode)->next;vp;vp=vp->next)
                            printf("�ؼ��֣�%d ,���ݣ�%d\n",vp->data.key,vp->data.value);
                        printf("��������%d ����:%d",graph[id].vexnum,graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }
                case 0:
                    break;

            }//end of switch
        }//end of the inner while
        printf("����������һ��ͼ?     [Y/N]�������д��\n");
        getchar();op=((c=getchar())=='Y')?1:0;
        if(op==0)
        {
            printf("�Ƿ񷵻ص�֮ǰ�Ķ�������   [Y/N]�������д��\n");
            getchar();op=((c=getchar())=='Y')?1:0;
        }
        if(op==0)

        {
            flag=1;count=0;testcount=0;     //��ʼ��ȫ�ֱ�����ֵ
        }
    }//end of the outer while
    return 0;
}//end of main

status SaveGraph(Graph* graph,FILE* fp,FILE* fq)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //ͼ������
    else
    {
        VNode* vp=graph->vnode->next;
        //���ǵ������ļ����벻�����������ͷ�ڵ����
        while(vp)
        {
            fwrite(vp,sizeof(VNode),1,fp);    //�������
            ArcNode* arcq=vp->firstarc;
            while(arcq)
            {
                fwrite(arcq,sizeof(ArcNode),1,fq);    //������
                arcq=arcq->nextarc;
            }
            vp=vp->next;
        }
        fclose(fp);fclose(fq);
        return OK;

    }
}

status LoadGraph(Graph* graph)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //ͼ������
    else
    {
    FILE  *fp,*fq;
    char vex_filename[30],arc_filename[30];
    printf("������Ҫ����Ķ����ļ������ƣ�\n");
    scanf("%s",vex_filename);
    printf("��������Ļ����ļ�������:\n");
    scanf("%s",arc_filename);
    if ((fp=fopen(vex_filename,"rb"))==NULL||(fq=fopen(arc_filename,"rb"))==NULL)
    {
        printf("File open error\n ");
        exit(-1);
    }
    else
    {
        DestroyGraph(graph);
        VNode* vp=NULL;
        VNode* tail=graph->vnode;
        vp=(VNode*)malloc(sizeof(VNode));
        vp->firstarc=NULL;
        //���붥��
        while(fread(vp,sizeof(VNode),1,fp)) //֮ǰ����do whileѭ�������кܴ������
                                            //��������ֻҪ��ѭ������ֱ�����ó�fread�Ľ���Ϳ�����
        {
             graph->vexnum++;
             tail->next=vp;
             tail=vp;
             vp=(VNode*)malloc(sizeof(VNode));
             vp->firstarc=NULL;
        }
        free(vp);
        tail->next=NULL;
        //���뻡
        vp=graph->vnode->next;
        ArcNode* arcp=(ArcNode*)malloc(sizeof(ArcNode));    //һ��Ҫ�������������forѭ�������棬��Ϊwhileѭ����������µĽ���ȡ��һ�λ����������������ֶ�һ����
        arcp->nextarc=NULL;
        int fread_arc_ans=fread(arcp,sizeof(ArcNode),1,fq);     //����ֱ����fread�����Ľ����Ϊѭ���ж���������Ϊÿ��һ�жϾͻ������һ������
        for( ;vp;vp=vp->next)
        {
            ArcNode* tailarcp=vp->firstarc=NULL;    //tailarcp ÿ��ָ��������Ļ������һ���ڵ�

            while(fread_arc_ans)    //���ﲻҪֱ�ӷ���fread�Ľ��
            {                       //����ÿ�θ��������ʱ�򶼻�����һ�����룬����������һ����
                if(arcp->adjtail==vp->data.key)
                {
                    if(!vp->firstarc)   //���ڶ���֮�󣬱���ֳ��������
                    {
                        vp->firstarc=arcp;
                        tailarcp=arcp;
                    }

                    else    //���ڻ��ڵ�֮��
                    {
                        tailarcp->nextarc=arcp;   //tailarcp
                        tailarcp=arcp;
                    }
                }
                else
                    break;      //��һ��ͷ�ڵ�
                graph->arcnum++;
                arcp=(ArcNode*)malloc(sizeof(ArcNode));
                arcp->nextarc=NULL;
                fread_arc_ans=fread(arcp,sizeof(ArcNode),1,fq);
            }//while
        }//for
    }//else
        fclose(fp);fclose(fq);
        return OK;
    }//else
}//loadgraph
status CreateGraph(Graph* graph,VNode* Vex,ArcNode* Arc,int vexnum,int arcnum)
{
    if(!graph)      return INFEASTABLE;     //ͼΪ��
    else
    {
        graph->vnode=Vex;
        graph->vexnum=vexnum;
        graph->arcnum=arcnum;
        VNode* vp=Vex->next;
        ArcNode* arcp=NULL;
        for(int i=0;i<vexnum;i++,vp=vp->next)
        {
            for(int j=0;j<arcnum;j++)
            {
                if(Arc[j].adjtail==vp->data.key)
                {
                    //��Ϊ������vp����Ļ�
                     arcp=(ArcNode* )malloc((sizeof(ArcNode)));
                     arcp->adjhead=Arc[j].adjhead;
                     arcp->adjtail=Arc[j].adjtail;
                     arcp->nextarc=vp->firstarc;vp->firstarc=arcp;
                }//end of if
            }
    }
    flag=0;
    return OK;
    }
}
status DestroyGraph(Graph* graph)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return ERROR;   //ͼ������
    else
    {
        int num=graph->vexnum;
        VNode* vp=(graph->vnode)->next;
        VNode* vq=vp->next;//vp��ʼ��ֻ���һ��������������
        while(vp)
            {
                DeleteVex(graph,*vp);
                vp=vq;
                vq=(vq==NULL)?vq:vq->next;
            }

    graph->vnode->next=NULL;
    return OK;
}
}
status LocateVex(Graph* graph,int u)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //ͼ������
    else
    {
        VNode* vp=NULL;
        int count=1;
        for(vp=(graph->vnode)->next;vp;vp=vp->next,count++)
            if(u==vp->data.key)
                return count;
        if(!vp)
            return ERROR;
    }
}
VNode* GetVex(Graph* graph,int u)
{
   //u�Ƕ����λ��,�ú�����Ϊ�˷���ĳ��λ�õĶ������Ϣ
    if(u<=0)    //����ʧ��
        return NULL;
    VNode* vp=(graph->vnode)->next;
    for(int i=1;i<u;i++)
        vp=vp->next;
    return vp;

}
status PutVex(Graph* graph,int u,int val)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)  return EMPTY;
    int pos=LocateVex(graph,u);
    VNode* v=GetVex(graph,pos);
    if(pos==ERROR) return ERROR;    //����ʧ��
    else
    {
         v->data.value=val;
         return OK;
    }
}
status FirstAdjVex(Graph* graph,int u)
{
    if(flag)
        return INFEASTABLE;
    else if(!(graph->vnode)->next)
        return EMPTY;
    else
    {
        VNode* v=GetVex(graph,u);
        if(!v->firstarc)     //�����ڵ�һ�ڽӵ�
            return ERROR;
        else
        {
            int head=(v->firstarc)->adjhead;     //�ҵ���βָ��Ķ����λ�ã���ֵΪ�ؼ���
            return LocateVex(graph,head);
        }

    }
}
status NextAdjVex(Graph* graph,int v, int w)
{
    //v,w�Ƕ����λ�򣬷���v�����w����һ�ڽӵ�
    if(flag)
        return INFEASTABLE;
    else if(!(graph->vnode)->next)
        return EMPTY;
    else
    {
        VNode* vm=GetVex(graph,v);              //�ҵ�����
        int index=(GetVex(graph,w))->data.key;    //�ҵ����ڽӶ���Ĺؼ���
        ArcNode* arc=vm->firstarc;               //���α�����
        while(arc&&arc->adjhead!=index)
            arc=arc->nextarc;
        if(!arc)         //wΪ�����ڽӵ�
            return ERROR;
        else    //�ҵ�����͸��ڽӵ�Ļ�
        {

            if(!arc->nextarc)
                return ERROR;
            else
            {
                int head=arc->nextarc->adjhead;     //�����w����һ�ڽӵ�Ĺؼ���
                return LocateVex(graph,head);
            }

    }
    }
}
status InsertVex(Graph* graph,VNode v)
{
    if(flag)
        return INFEASTABLE;
    else if(!(graph->vnode)->next)
        return EMPTY;
    else
    {
        VNode* vp=(VNode*)malloc(sizeof(VNode));
        vp->data.key=v.data.key;        //����Ľڵ㸳ֵ
        vp->data.value=v.data.value;
        vp->firstarc=NULL;
        vp->next=(graph->vnode)->next;   //���������У�ͷ�巨
        (graph->vnode)->next=vp;
        graph->vexnum++;
        return OK;
    }
}


status DeleteVex(Graph* graph,VNode v)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //ͼ������
    else
    {
        int pos=LocateVex(graph,v.data.key);
        int arccount=0;
        if(pos<=0)      return ILLEAGAL;       //����ʧ��

        else
        {
            VNode* vp=GetVex(graph,pos);
           //ɾ����ɾ�ڵ㷢���Ļ�
            ArcNode* arcp=vp->firstarc;     //��������ָ��
            ArcNode* arcq=arcp;
            while(arcp!=NULL)
            {   //���ٻ�
                arcq=arcp->nextarc;
                free(arcp);
                arcp=arcq;
                arccount++;
            }
            vp->firstarc=NULL;  //ÿ��free��Ҫ�ǵ�����Ϊnull,��Ϊfree���Ὣ��ַ��Ϊ��
            //ɾ��ָ���ɾ�ڵ�Ļ�
            VNode* vvp=(graph->vnode)->next;
        for(int i=0;i<graph->vexnum;i++)
        {

            ArcNode* in_arcp=vvp->firstarc;
            if(in_arcp!=NULL)
            {
                if(in_arcp->adjhead==vp->data.key)
                    {
                        vvp->firstarc=in_arcp->nextarc;
                        free(in_arcp); in_arcp=NULL;arccount++;
                    }
                else
                {
                    while(in_arcp!=NULL)
                    {
                        ArcNode* in_arcq=in_arcp;
                        in_arcp=in_arcp->nextarc;
                        if(in_arcp!=NULL)
                        if(in_arcp->adjhead==vp->data.key)
                        {
                            in_arcq->nextarc=in_arcp->nextarc;
                            free(in_arcp);
                            in_arcp=NULL;arccount++;
                        }

                }//while
            }//else
            }//if
            vvp=vvp->next;

        }
            //����ͷ���
           if(pos==1)
                (graph->vnode)->next=vp->next;
           else
           {
                VNode* vq=GetVex(graph,pos-1);
                 //�ҵ���ɾ�ڵ����һ���ڵ�
                vq->next=vp->next;
           }
           free(vp);vp=NULL;
        }
        graph->vexnum--;

        graph->arcnum -=arccount;

    }
    return OK;
}

status InsertArc(Graph* graph,VNode v,VNode w)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //ͼ������
    else
    {
        int posv=LocateVex(graph,v.data.key);
        int posw=LocateVex(graph,w.data.key);
        if(posv<=0||posw<=0)
            return ILLEAGAL;
        else
        {
            VNode* vp=GetVex(graph,posv);
            ArcNode* arcp=(ArcNode*)malloc(sizeof(ArcNode));
            arcp->adjtail=v.data.key;
            arcp->adjhead=w.data.key;
            arcp->nextarc=vp->firstarc;
            vp->firstarc=arcp;
            graph->arcnum++;
            return OK;

        }
    }
}

status DeleteArc(Graph* graph,VNode v,VNode w)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)
        return EMPTY;
    else
    {
        int pos=LocateVex(graph,v.data.key);
        if(pos<=0)
            return ILLEAGAL;
        else
        {
            VNode* vp=GetVex(graph,pos);
            if(vp->firstarc==NULL)
                return ERROR;
            else
            {
                ArcNode* arcp=vp->firstarc;
                ArcNode* arcq=NULL;
                int val=w.data.key;
                if(arcp->adjhead==val)      //��һ�ڽӵ�Ļ�
                    vp->firstarc=NULL;
                else
                {
                   while(arcp&&arcp->adjhead!=val)
                    {
                        arcq=arcp;
                        arcp=arcp->nextarc;
                    }
                    if(!arcp)
                        return ILLEAGAL;
                    else
                    {
                        arcq->nextarc=arcp->nextarc;

                    }
                }
            free(arcp);
            graph->arcnum--;
            return OK;
          }//else
        }//else
    }//else
}//deletearc

status Visit(Graph* graph,int v)
{
    VNode* vp=GetVex(graph,v);
    printf("�ؼ��֣�%d ���ݣ�%d\n",vp->data.key,vp->data.value);
    return OK;
}

status DFSTraverse(Graph* graph,int v,status (*Visit)(Graph* graph,int v))
{
  VisitFunc=Visit;
  VisitFunc(graph,v);
  visited[v]=TRUE;
  testcount++;
  int pos=FirstAdjVex(graph,v);     //��һ�ڽӵ��λ��
  VNode* firstvp=GetVex(graph,pos);    //��һ�ڽӵ�
  while(firstvp&&testcount<graph->vexnum)   //testcount������ֹһֱѭ�����
  {
     if(!visited[pos])
         DFSTraverse(graph,pos,VisitFunc);

     int nextpos=NextAdjVex(graph,v,pos);
     VNode* next_vex=GetVex(graph,nextpos);
     if(next_vex)
     {
          VNode* nextvp=next_vex;
          pos=nextpos;
     }

     else
        break;

  }


}

void BFSTraverse(Graph* G,int v,status (*Visit)(Graph* G,int x))
{
    for(int u=1;u<=G->vexnum;++u)
        visited[u]=FALSE;
    pLinkQueue Q=(pLinkQueue)malloc(sizeof(LinkQueue));
    Q=InitQueue(Q);     //������ͼ��ͬ�����ﲻ��Ҫforѭ���Ϳ�һʵ��
    testcount=0;
    visited[v]=TRUE;
    Visit(G,v);
    testcount++;
    EnQueue(G,Q,v);
    while(!QueueEmpty(Q))
    {
        VNode vu=DeQueue(Q);
        int u=LocateVex(G,vu.data.key);
        for(int w=FirstAdjVex(G,u);w>0;w=NextAdjVex(G,u,w))
        if(!visited[w])
        {
            visited[w]=TRUE;
            Visit(G,w);
            testcount++;
            EnQueue(G,Q,w);
        }//if
    }//while
}//BFSTraverse
//����������������ʵ���ϲ�û���õ������Ժ���
status InArc(Graph* graph,int v)
{
    //����λ��Ϊv�Ķ�������
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //ͼ������
    else
    {
        VNode* vvp=graph->vnode->next;
        int acount=0;
        VNode* vp=GetVex(graph,LocateVex(graph,v));     //λ��Ϊv�Ľڵ�
        for(int i=0;i<graph->vexnum;i++)        //��������ͼ
        {
             ArcNode* in_arcp=vvp->firstarc;
            if(in_arcp!=NULL)
            {
                if(in_arcp->adjhead==vp->data.key)
                    acount++;
                else
                {
                    while(in_arcp!=NULL)
                    {
                        ArcNode* in_arcq=in_arcp;
                        in_arcp=in_arcp->nextarc;
                        if(in_arcp!=NULL)
                        if(in_arcp->adjhead==vp->data.key)
                        {
                            in_arcq->nextarc=in_arcp->nextarc;
                            acount++;
                        }//if
                    }//while
                }//else

        }//if
    vvp=vvp->next;
    }return acount;

}
}

status OutArc(Graph* graph,int v)
{
    if(flag)    return INFEASTABLE;
    if((graph->vnode)->next==NULL)     return EMPTY;   //ͼ������
    else
    {
        VNode* vp=GetVex(graph,v);
        ArcNode* arcp=vp->firstarc;
        int acount=0;
        while(arcp)
        {
            acount++;
            arcp=arcp->nextarc;
        }
        return acount;
    }
}
