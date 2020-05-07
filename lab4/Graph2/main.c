#include "queue.h"
int flag=1;     //用来标识图是否创建，0表示创建
int count=0;   //计数器
status (*VisitFunc)(Graph* graph,int v);    //输出函数
int visited[100];   //搜索标志数组，为0表示为搜索，为1为搜索
int testcount=0;    //搜索函数计数器
int main(void)
{
    int op=1,ans=0;
    char c;
    int id=0;
    int vexnum,arcnum;
    VNode *Vex=NULL;    //输入的顶点序列
    ArcNode *Arc=NULL;  //输入的弧的序列
    Graph graph[10];    //多图
    int u,val;      //位置和关键字
    int v,w;        //位置和关键字
    while(op)
    {
        printf("输入你要操作的图的序号：[0-9]\n");
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

            printf("请选择你对图G[%d]的操作[0~12]:",id);
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                    printf("输入需要创建的图的顶点数和弧的数目：\n");
                    scanf("%d",&vexnum);
                    scanf("%d",&arcnum);
                    //从表头位置插入创建，创建顶带头结点的顶点链表Vex
                    Vex=(VNode* )malloc(sizeof(VNode));     //分配顶点表头节点
                    Vex->firstarc=NULL;
                    Vex->next=NULL;
                    Arc=(ArcNode*)malloc(arcnum*sizeof(ArcNode));
                    printf("逆位序输入顶点的信息！\n");
                    printf("输入顶点的关键字和内容：\n");
                    for(int i=0;i<vexnum;i++)
                    {
                        VNode* vp=(VNode*)malloc(sizeof(VNode));
                        scanf("%d %d",&((vp->data).key),&((vp->data).value));
                        vp->firstarc=NULL;
                        vp->next=Vex->next;Vex->next=vp;
                    }
                    printf("逆位序输入弧的信息：\n");
                    for(int i=0;i<arcnum;i++)
                    {
                       scanf("%d %d",&Arc[i].adjtail,&Arc[i].adjhead);
                        Arc[i].nextarc=NULL;
                    }

                    CreateGraph(&graph[id],Vex,Arc,vexnum,arcnum);
                    getchar();getchar();
                    break;

                case 2:
                    printf("2. 销毁图！\n");
                    if((ans=DestroyGraph(&graph[id]))==INFEASTABLE)
                        printf("图尚未创建！\n");
                    else if(ans==ERROR)
                        printf("图已被销毁！\n");
                    else
                        printf("销毁成功！\n");
                    getchar();getchar();
                    break;

                case 3:
                    printf("查找顶点\n");
                    printf("输入查找的顶点的关键字：\n");
                    scanf("%d",&u);
                    if((ans=LocateVex(&graph[id],u))==INFEASTABLE)
                        printf("图尚未创建！\n");
                    else if(ans==EMPTY)
                        printf("图不存在！\n");
                    else if(ans==ERROR)
                        printf("找不到这个顶点！\n");
                    else
                        printf("顶点位于邻接表的第%d个位置",ans);
                    getchar();getchar();
                    break;

                case 4:
                    printf("为顶点赋值\n");
                    printf("输入赋值的关键字和信息：\n");
                    scanf("%d %d",&u,&val);
                    if((ans=PutVex(&graph[id],u,val))==INFEASTABLE)
                        printf("图尚未创建！\n");
                    else if(ans==EMPTY)
                        printf("图不存在！\n");
                    else if(ans==ERROR)
                        printf("找不到这样的顶点！\n");
                    else
                        printf("赋值成功!\n");
                    getchar();getchar();
                    break;

                case 5:
                    printf("5. 查找第一邻接点\n");
                    printf("输入查找的顶点的位置：\n");
                    scanf("%d",&u);
                    if(u>graph[id].vexnum||u<=0)
                        printf("输入位置不合法!\n");
                    else if((ans=FirstAdjVex(&graph[id],u))==INFEASTABLE)
                        printf("图尚未建立！\n");
                    else if(ans==EMPTY)
                        printf("图不存在！\n");

                    else if(ans==ERROR)
                            printf("该顶点不存在第一邻接点！\n");
                    else
                            printf("第一邻接点的位置为：%d",ans);


                    getchar();getchar();
                    break;
                case 6:
                    printf("6. 查找下一邻接点\n");
                    printf("输入查找的顶点的位置:\n");
                    scanf("%d",&v);
                    printf("输入该顶点的邻接点的位置:\n");
                    scanf("%d",&w);
                    if(v>graph[id].vexnum||w>graph[id].vexnum||v<=0||w<=0)
                           printf("输入的位置不合法！\n");
                    else if((ans=NextAdjVex(&graph[id],v,w))==INFEASTABLE)
                        printf("图尚未创建！\n");
                    else if((ans=NextAdjVex(&graph[id],v,w))==EMPTY)
                        printf("图不存在！\n");
                    else
                    {
                            if((ans=NextAdjVex(&graph[id],v,w))==ERROR)
                                printf("没有其他邻接点！\n");
                            else
                                printf("下一个邻接点的位置为：%d",ans);

                    }
                    getchar();getchar();
                    break;
                case 7:
                    {

                    printf("7. 插入顶点\n");
                    VNode v;
                    printf("输入插入的顶点的关键字和信息：\n");
                    scanf("%d %d",&v.data.key,&v.data.value);
                    v.firstarc=NULL;
                    if((ans=InsertVex(&graph[id],v))==INFEASTABLE)
                        printf("图尚未建立！\n");
                    else if(ans==EMPTY)
                        printf("图不存在!\n");

                    else
                        printf("插入成功！插入后顶点的数目为：%d\n",graph[id].vexnum);
                    getchar();getchar();
                    break;
                    }
                case 8:
                    {
                        printf("8. 删除顶点\n");
                        VNode v;
                        printf("输入删除顶点的关键字和信息：\n");
                        scanf("%d %d",&v.data.key,&v.data.value);
                        if((ans=DeleteVex(&graph[id],v))==INFEASTABLE)
                            printf("图尚未建立！\n");
                        else if(ans==EMPTY)
                            printf("图不存在！\n");
                        else if(ans==ILLEAGAL)
                            printf("输入的顶点不正确！\n");
                        else
                            printf("删除顶点成功！删除后顶点的数目为：%d 弧的数目为%d\n",graph[id].vexnum,graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }

                case 9:
                    {
                        printf("9. 插入弧\n");
                        VNode v,w;
                        printf("输入弧尾的关键字和内容\n");
                        scanf("%d %d",&v.data.key,&v.data.value);
                        printf("输入弧头的关键字和内容\n");
                        scanf("%d %d",&w.data.key,&w.data.value);
                        if((ans=InsertArc(&graph[id],v,w))==INFEASTABLE)
                            printf("图尚未建立！\n");
                        else if(ans==EMPTY)
                            printf("图不存在！\n");
                        else if(ans==ILLEAGAL)
                            printf("输入的顶点不正确！\n");
                        else
                            printf("插入弧成功！插入后的弧的数目为%d\n",graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }
                case 10:
                    {
                         printf("10. 删除弧\n");
                         VNode v,w;
                         printf("输入该弧的弧尾的指向的顶点的关键和信息：\n");
                         scanf("%d %d",&v.data.key,&v.data.value);
                         printf("输入该弧的弧头指向的顶点的关键字和信息：\n");
                         scanf("%d %d",&w.data.key,&w.data.value);
                         v.firstarc=w.firstarc=NULL;
                         if((ans=DeleteArc(&graph[id],v,w))==INFEASTABLE)
                            printf("图尚未建立!\n");
                         else if(ans==EMPTY)
                            printf("图不存在！\n");
                         else if(ans==ILLEAGAL)
                            printf("输入顶点不合法!\n");
                         else if(ans==ERROR)
                            printf("这两个顶点之间没有弧！\n");
                        else
                            printf("删除弧成功！删除后弧的数目为：%d\n",graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }
                case 11:
                    {
                        printf("11. 深度遍历\n");
                        testcount=0;        //全局变量确保每次遍历时都从0开始计数
                        for(int i=1;i<=graph[id].vexnum;i++)
                            visited[i]=FALSE;
                        if(flag)
                            printf("图尚未创建！\n");
                        else if(!(graph[id].vnode)->next)
                            printf("图不存在\n");
                        else
                        {
                            int u;
                            printf("输入开始遍历的顶点的位置：\n");
                            scanf("%d",&u);
                            DFSTraverse(&graph[id],u,Visit);
                            if(testcount<graph[id].vexnum)
                                printf("遍历失败！\n");
                        }
                        getchar();getchar();
                        break;
                    }
                case 12:
                    {
                        printf("12. 广度遍历\n");
                        testcount=0;
                        if(flag)
                            printf("图尚未创建！\n");
                        else if(!(graph[id].vnode)->next)
                            printf("图不存在\n");
                        else
                        {
                            printf("输入开始遍历的顶点的位置:\n");
                            int v;
                            scanf("%d",&v);
                            BFSTraverse(&graph[id],v,Visit);
                            if(testcount<graph[id].vexnum)
                                printf("遍历失败！\n");
                        }
                        getchar();getchar();
                        break;
                    }
                case 13:
                    {
                        printf("13. 读入文件\n");
                        FILE *fp,*fq;
                        char vex_filename[30],arc_filename[30];
                        printf("输入顶点的文件名称：\n");
                        scanf("%s",vex_filename);
                        printf("输入弧的文件的名称:\n");
                        scanf("%s",arc_filename);
                        if ((fp=fopen(vex_filename,"wb+"))==NULL||(fq=fopen(arc_filename,"wb+"))==NULL)
                        {
                            printf("File open error\n ");
                            exit(-1);
                        }
                        else if((ans=SaveGraph(&graph[id],fp,fq))==INFEASTABLE)
                            printf("图尚未建立!\n");
                        else if(ans==EMPTY)
                            printf("图不存在！\n");
                        else
                            printf("保存成功！\n");

                        getchar();getchar();
                        break;
                        }


                case 14:
                    {
                        if((ans=LoadGraph(&graph[id])==INFEASTABLE))
                            printf("图尚未创建!\n");
                        else if(ans==EMPTY)
                            printf("图不存在!\n");
                        else
                            printf("载入成功！\n");
                            getchar();getchar();
                            break;
                    }
                case 15:
                    {
                        VNode* vp=NULL;
                        for(vp=(graph[id].vnode)->next;vp;vp=vp->next)
                            printf("关键字：%d ,内容：%d\n",vp->data.key,vp->data.value);
                        printf("顶点数：%d 弧数:%d",graph[id].vexnum,graph[id].arcnum);
                        getchar();getchar();
                        break;
                    }
                case 0:
                    break;

            }//end of switch
        }//end of the inner while
        printf("继续创建下一个图?     [Y/N]（输入大写）\n");
        getchar();op=((c=getchar())=='Y')?1:0;
        if(op==0)
        {
            printf("是否返回到之前的二叉树？   [Y/N]（输入大写）\n");
            getchar();op=((c=getchar())=='Y')?1:0;
        }
        if(op==0)

        {
            flag=1;count=0;testcount=0;     //初始化全局变量的值
        }
    }//end of the outer while
    return 0;
}//end of main

status SaveGraph(Graph* graph,FILE* fp,FILE* fq)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //图不存在
    else
    {
        VNode* vp=graph->vnode->next;
        //考虑到后面文件载入不将顶点链表的头节点读入
        while(vp)
        {
            fwrite(vp,sizeof(VNode),1,fp);    //顶点读入
            ArcNode* arcq=vp->firstarc;
            while(arcq)
            {
                fwrite(arcq,sizeof(ArcNode),1,fq);    //弧读入
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
    else if(!(graph->vnode)->next)     return EMPTY;   //图不存在
    else
    {
    FILE  *fp,*fq;
    char vex_filename[30],arc_filename[30];
    printf("输入需要载入的顶点文件的名称：\n");
    scanf("%s",vex_filename);
    printf("输入载入的弧的文件的名称:\n");
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
        //读入顶点
        while(fread(vp,sizeof(VNode),1,fp)) //之前采用do while循环发现有很大的问题
                                            //后来发现只要将循环条件直接设置成fread的结果就可以了
        {
             graph->vexnum++;
             tail->next=vp;
             tail=vp;
             vp=(VNode*)malloc(sizeof(VNode));
             vp->firstarc=NULL;
        }
        free(vp);
        tail->next=NULL;
        //读入弧
        vp=graph->vnode->next;
        ArcNode* arcp=(ArcNode*)malloc(sizeof(ArcNode));    //一定要把这个申明放在for循环的外面，因为while循环里面分配新的结点读取过一次弧，如果放在里面会又读一条弧
        arcp->nextarc=NULL;
        int fread_arc_ans=fread(arcp,sizeof(ArcNode),1,fq);     //不能直接用fread函数的结果做为循环判断条件，因为每次一判断就会多载入一个顶点
        for( ;vp;vp=vp->next)
        {
            ArcNode* tailarcp=vp->firstarc=NULL;    //tailarcp 每次指向已载入的弧的最后一个节点

            while(fread_arc_ans)    //这里不要直接返回fread的结果
            {                       //否则每次更换顶点的时候都会多进行一步读入，导致跳过了一条弧
                if(arcp->adjtail==vp->data.key)
                {
                    if(!vp->firstarc)   //放在顶点之后，必须分出两种情况
                    {
                        vp->firstarc=arcp;
                        tailarcp=arcp;
                    }

                    else    //放在弧节点之后
                    {
                        tailarcp->nextarc=arcp;   //tailarcp
                        tailarcp=arcp;
                    }
                }
                else
                    break;      //下一个头节点
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
    if(!graph)      return INFEASTABLE;     //图为空
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
                    //弧为依附于vp顶点的弧
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
    else if(!(graph->vnode)->next)     return ERROR;   //图不存在
    else
    {
        int num=graph->vexnum;
        VNode* vp=(graph->vnode)->next;
        VNode* vq=vp->next;//vp初始化只想第一个顶点用来遍历
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
    else if(!(graph->vnode)->next)     return EMPTY;   //图不存在
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
   //u是顶点的位置,该函数是为了返回某个位置的顶点的信息
    if(u<=0)    //查找失败
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
    if(pos==ERROR) return ERROR;    //查找失败
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
        if(!v->firstarc)     //不存在第一邻接点
            return ERROR;
        else
        {
            int head=(v->firstarc)->adjhead;     //找到弧尾指向的顶点的位置，该值为关键字
            return LocateVex(graph,head);
        }

    }
}
status NextAdjVex(Graph* graph,int v, int w)
{
    //v,w是顶点的位序，返回v相对于w的下一邻接点
    if(flag)
        return INFEASTABLE;
    else if(!(graph->vnode)->next)
        return EMPTY;
    else
    {
        VNode* vm=GetVex(graph,v);              //找到顶点
        int index=(GetVex(graph,w))->data.key;    //找到该邻接顶点的关键字
        ArcNode* arc=vm->firstarc;               //依次遍历弧
        while(arc&&arc->adjhead!=index)
            arc=arc->nextarc;
        if(!arc)         //w为最后的邻接点
            return ERROR;
        else    //找到顶点和该邻接点的弧
        {

            if(!arc->nextarc)
                return ERROR;
            else
            {
                int head=arc->nextarc->adjhead;     //相对于w的下一邻接点的关键字
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
        vp->data.key=v.data.key;        //插入的节点赋值
        vp->data.value=v.data.value;
        vp->firstarc=NULL;
        vp->next=(graph->vnode)->next;   //插入链表中，头插法
        (graph->vnode)->next=vp;
        graph->vexnum++;
        return OK;
    }
}


status DeleteVex(Graph* graph,VNode v)
{
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //图不存在
    else
    {
        int pos=LocateVex(graph,v.data.key);
        int arccount=0;
        if(pos<=0)      return ILLEAGAL;       //查找失败

        else
        {
            VNode* vp=GetVex(graph,pos);
           //删除待删节点发出的弧
            ArcNode* arcp=vp->firstarc;     //遍历弧的指针
            ArcNode* arcq=arcp;
            while(arcp!=NULL)
            {   //销毁弧
                arcq=arcp->nextarc;
                free(arcp);
                arcp=arcq;
                arccount++;
            }
            vp->firstarc=NULL;  //每次free后都要记得设置为null,因为free不会将地址变为空
            //删除指向待删节点的弧
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
            //销毁头结点
           if(pos==1)
                (graph->vnode)->next=vp->next;
           else
           {
                VNode* vq=GetVex(graph,pos-1);
                 //找到待删节点的上一个节点
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
    else if(!(graph->vnode)->next)     return EMPTY;   //图不存在
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
                if(arcp->adjhead==val)      //第一邻接点的弧
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
    printf("关键字：%d 内容：%d\n",vp->data.key,vp->data.value);
    return OK;
}

status DFSTraverse(Graph* graph,int v,status (*Visit)(Graph* graph,int v))
{
  VisitFunc=Visit;
  VisitFunc(graph,v);
  visited[v]=TRUE;
  testcount++;
  int pos=FirstAdjVex(graph,v);     //第一邻接点的位置
  VNode* firstvp=GetVex(graph,pos);    //第一邻接点
  while(firstvp&&testcount<graph->vexnum)   //testcount计数防止一直循环输出
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
    Q=InitQueue(Q);     //和无向图不同，这里不需要for循环就可一实现
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
//下面两个函数后面实际上并没有用到，可以忽略
status InArc(Graph* graph,int v)
{
    //查找位置为v的顶点的入度
    if(flag)    return INFEASTABLE;
    else if(!(graph->vnode)->next)     return EMPTY;   //图不存在
    else
    {
        VNode* vvp=graph->vnode->next;
        int acount=0;
        VNode* vp=GetVex(graph,LocateVex(graph,v));     //位置为v的节点
        for(int i=0;i<graph->vexnum;i++)        //遍历整个图
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
    if((graph->vnode)->next==NULL)     return EMPTY;   //图不存在
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
