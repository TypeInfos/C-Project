
#include "stdio.h"
#include "stdio.h"
typedef struct Goods
{
    int   goods_id;             /*商品编号*/
    char  goods_name[50];       /*商品名称*/
    char  goods_type[50];       /*商品种类*/
    float goods_inputprice;     /*商品进价*/
    float goods_outputprice;    /*商品售价*/
    int   goods_num;            /*商品数量*/
    char  goods_date[20];       /*进货日期*/
    int   goods_quality;        /*保质期*/
    struct Goods *next;
}GOD,*List;
List insert();
void goods_export(List L);
void delet_goods(List L);
void find_goods_id(List L,int x);   /*找到编号并输出*/
int return_goods_id(List L,int x);  /*找到编号返回值*/
void print_goods(List p);
void find_goods_name(List L);
void print_goods_information();
List return_list_id(List L,int x);
void change_goods(List L);
void search_goods_type(List L);
void search_goods_inputoutprice(List L);
void writegoods(List L);
void readgoods(List L);
void goods_insert(List L,List p);
void ad_print();
int proving();
void goods_jinhuo(List L);
void search_goods(List L);
void search_goods_print();
void search_goods_id(List L);
main()
{
    int m;
    char start,flag;
    List L;
    L=(List)malloc(sizeof(GOD));
    L->next=NULL;
    FILE *fp1;
    if((fp1=fopen("e:\\商品信息.txt","rb"))==NULL)
    {
        fp1=fopen("e:\\商品信息.txt","wb");
        fclose(fp1);
    }
    readgoods(L);
    printf("\t\tWelcome To My Store\n");
    printf("请输入密码:");
    m=proving();
    if(m==1)
    {
        while(1)
        {
            int select;
            ad_print();
            scanf("%d",&select);
            switch(select)
            {
                case 1:goods_jinhuo(L);
                    break;
                case 2:delet_goods(L);
                    break;
                case 3:change_goods(L);
                    break;
                case 4:search_goods(L);
                    break;
                case 5:goods_export(L);
                    break;
                default:printf("你的输入不在1~4之间!");
            }
            printf("N:退出超级管理员系统，任意键继续。");
            flag=getch();
            if(flag=='N'||flag=='n')
                break;
        }
    }
    else
    {
        printf("你不是管理员!");
    }
    
    
}
void writegoods(List L)
{
    FILE *fp1;
    List p=L->next;
    fp1=fopen("e:\\商品信息.txt","wb");
    while(p!=NULL)
    {
        fwrite(p,sizeof(GOD),1,fp1);
        p=p->next;
    }
    fclose(fp1);
}
void readgoods(List L)
{
    int num,i;
    FILE *fp1;
    List p;
    fp1=fopen("e:\\商品信息.txt","rb");
    fseek(fp1,0,2);
    num=ftell(fp1)/sizeof(GOD);
    fseek(fp1,0,0);
    for(i=0;i<num;i++)
    {
        p=(List)malloc(sizeof(GOD));
        fread(p,sizeof(GOD),1,fp1);
        p->next=NULL;
        goods_insert(L,p);
    }
    fclose(fp1);
}
void goods_insert(List L,List p)
{
    List s=L;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=p;
}
void goods_jinhuo(List L)
{
    char flag;
    List p,t;
    List s=L;
    t=L->next;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    while(1)
    {
        p=(List)malloc(sizeof(GOD));
        printf("目前已有的编号:");
        t=L->next;
        while(t!=NULL)
        {
            printf("|%d| ",t->goods_id);
            t=t->next;
        }
        printf("\n\n商品编号:");
        scanf("%d",&p->goods_id);
        printf("商品名称:");
        scanf("%s",&p->goods_name);
        printf("商品种类:");
        scanf("%s",&p->goods_type);
        printf("进货价格:");
        scanf("%f",&p->goods_inputprice);
        printf("出售价格:");
        scanf("%f",&p->goods_outputprice);
        printf("商品数量:");
        scanf("%d",&p->goods_num);
        printf("进货日期:");
        scanf("%s",&p->goods_date);
        printf("商品保质期(月份为单位):");
        scanf("%d",&p->goods_quality);
        p->next=NULL;
        s->next=p;
        s=s->next;
        writegoods(L);
        printf("\nY:继续 N：结束");
        flag=getch();
        if(flag=='N'||flag=='n')
        {system("cls");
            break;
        }
        
    }
    
}
void goods_export(List L)
{
    List p=L->next;
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量 \t日期 \t保质期\n");
    while(p!=NULL)
    {
        printf("\t\t%d",p->goods_id);
        printf("\t%s",p->goods_name);
        printf("\t%s",p->goods_type);
        printf("\t%5.2f",p->goods_inputprice);
        printf("\t%5.2f",p->goods_outputprice);
        printf("\t%d",p->goods_num);
        printf("   %s",p->goods_date);
        printf("  %d\n",p->goods_quality);
        p=p->next;
    }
}
void delet_goods(List L)/*删除编号函数*/
{
    int num,flag,delet;
    List p,s,t;
    p=L;
    t=p->next;
    printf("\t\t------------删除商品信息------------\n");
    printf("当前库存:\n");
    goods_export(L);
    printf("请输入你要删除商品的编号:");
    scanf("%d",&num);
    flag=return_goods_id(L,num);
    if(flag)
    {
        find_goods_id(L,num);
        printf("删除此数据将不能复原，确认删除按'1',取消删除按'0'");
        scanf("%d",&delet);
        if(delet)
        {
            while(t->goods_id!=num)
            {
                p=p->next;
                t=p->next;
            }
            s=p;
            s->next=t->next;
            free(t);
            writegoods(L);
        }
    }
    else
    {
        printf("没有找到编号为%d的商品",num);
    }
    
}
void print_goods(List p)
{
    printf("此商品的信息为:\n");
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量 \t日期 \t保质期\n");
    printf("\t\t%d",p->goods_id);
    printf("\t%s",p->goods_name);
    printf("\t%s",p->goods_type);
    printf("\t%5.2f",p->goods_inputprice);
    printf("\t%5.2f",p->goods_outputprice);
    printf("\t%d",p->goods_num);
    printf("   %s",p->goods_date);
    printf("  %d\n",p->goods_quality);
}
void find_goods_id(List L,int x)
{
    List p=L->next;
    while(p->goods_id!=x)
    {
        p=p->next;
    }
    print_goods(p);
}
void find_goods_name(List L)
{
    char name[20];
    int flag;
    List p=L->next;
    printf("请输入你要找的商品的名称:");
    scanf("%s",&name);
    while(1)
    {
        flag=strcmp(p->goods_name,name);
        
        if(flag==0||p==NULL)
            break;
        p=p->next;
    }
    if(flag==0)
    {
        print_goods(p);
    }
    else
    {
        printf("没有找到名称为%s的商品!\n",name);
    }
    
}
void change_goods(List L)
{
    int num,tip;
    char change;
    List p;
    printf("请输入你要修改的商品的编号:");
    scanf("%d",&num);
    tip=return_goods_id(L,num);
    p=return_list_id(L,num);
    
    if(tip==1)
    {
        printf("\t\t-------------修改商品信息----------------\n");
        printf("修改此商品的全部信息扣'q',修改此商品的部分信息扣'b'\n");
        fflush(stdin);
        change=getch();
        if(change=='q')
        {
            printf("\n\n商品编号:");
            scanf("%d",&p->goods_id);
            printf("商品名称:");
            scanf("%s",&p->goods_name);
            printf("商品种类:");
            scanf("%s",&p->goods_type);
            printf("进货价格:");
            scanf("%f",&p->goods_inputprice);
            printf("出售价格:");
            scanf("%f",&p->goods_outputprice);
            printf("商品数量:");
            scanf("%d",&p->goods_num);
            printf("进货日期:");
            scanf("%s",&p->goods_date);
            printf("商品保质期(月份为单位):");
            scanf("%d",&p->goods_quality);
            writegoods(L);
        }
        else
        {
            while(1)
            {
                int import,flag;
                print_goods_information();
                scanf("%d",&import);
                switch(import)
                {
                    case 1:scanf("%d",&p->goods_id);
                        break;
                    case 2:scanf("%s",&p->goods_name);
                        break;
                    case 3:scanf("%s",&p->goods_type);
                        break;
                    case 4:scanf("%f",&p->goods_inputprice);
                        break;
                    case 5:scanf("%f",&p->goods_outputprice);
                        break;
                    case 6:scanf("%d",&p->goods_num);
                        break;
                    case 7:scanf("%s",&p->goods_date);
                        break;
                    case 8:scanf("%d",&p->goods_quality);
                        break;
                    default:printf("你的输入不在1~8之间!");
                }
                writegoods(L);
                printf("继续修改此商品的信息请按'1',退出按任意键!:");
                scanf("%d",&flag);
                if(flag==1)
                    continue;
                else
                    break;
            }
        }
    }
    else{
        printf("没有找到编号为%d的商品",num);
    }
}

void print_goods_information()
{
    printf("\t1.编号\n");
    printf("\t2.名称\n");
    printf("\t3.类别\n");
    printf("\t4.进价\n");
    printf("\t5.单价\n");
    printf("\t6.数量\n");
    printf("\t7.日期\n");
    printf("\t8.保质期\n");
    printf("请输入操作序号:");
}
int return_goods_id(List L,int x)
{
    List p=L->next;
    while(p->goods_id!=x||p==NULL)
    {
        p=p->next;
    }
    if(p==NULL)
        return 0;
    else
        return 1;
}
List return_list_id(List L,int x)
{
    List p=L->next;
    while(p->goods_id!=x||p==NULL)
    {
        p=p->next;
    }
    return p;
}
void search_goods_type(List L)
{
    int flag,num;
    char type[20];
    num=0;
    List p=L->next;
    printf("请输入你要查询商品的类型:");
    scanf("%s",&type);
    while(p!=NULL)
    {
        flag=strcmp(p->goods_type,type);
        if(flag==0)
        {
            if(num<1)
            {
                printf("此商品的信息为:\n");
                printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量 \t日期 \t保质期\n");
            }
            printf("\t\t%d",p->goods_id);
            printf("\t%s",p->goods_name);
            printf("\t%s",p->goods_type);
            printf("\t%5.2f",p->goods_inputprice);
            printf("\t%5.2f",p->goods_outputprice);
            printf("\t%d",p->goods_num);
            printf("   %s",p->goods_date);
            printf("  %d\n",p->goods_quality);
            num++;
        }
        p=p->next;
    }
}
void search_goods_inputoutprice(List L)
{
    int num,flag;
    float price1,price2;
    num=0;
    List p=L->next;
    printf("请输入你要查询商品的进货价格范围(输入格式xx,xx):");
    scanf("%f,%f",&price1,&price2);	
    while(p!=NULL)
    {
        
        if(p->goods_inputprice>=price1&&p->goods_inputprice<=price2)
            flag=1;
        else
            flag=0;
        if(flag==1)
        {
            if(num<1)
            {
                printf("此商品的信息为:\n");
                printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量 \t日期 \t保质期\n");
            }
            printf("\t\t%d",p->goods_id);
            printf("\t%s",p->goods_name);
            printf("\t%s",p->goods_type);
            printf("\t%5.2f",p->goods_inputprice);
            printf("\t%5.2f",p->goods_outputprice);
            printf("\t%d",p->goods_num);
            printf("   %s",p->goods_date);
            printf("  %d\n",p->goods_quality);
            num++;
        }
        p=p->next;
    }
}
void search_goods_print()
{
    printf("\n\t\t---1.按编号查询----\n");
    printf("\t\t---2.按类型查询----\n");
    printf("\t\t---3.按价格查询----\n");
}
void search_goods(List L)
{
    
    while(1)
    {
        char cha;
        int num;
        search_goods_print();
        printf("请输入操作编号:");
        scanf("%d",&num);
        switch(num)
        {
            case 1:search_goods_id(L);
                break;
            case 2:search_goods_type(L);
                break;
            case 3:search_goods_inputoutprice(L);
                break;
            default:printf("你的输入不在1~3之间!");
        }
        printf("Y:继续查询，N:退出查询!");
        cha=getch();
        if(cha=='N'||cha=='n')
            break;
    }
}
void search_goods_id(List L)
{
    int num,flag;
    printf("请输入你要查询的商品的编号:");
    scanf("%d",&num);
    flag=return_goods_id(L,num);
    if(flag==1)
    {
        find_goods_id(L,num);
    }
    else
    {
        printf("没有找到编号为%d的商品",num);
    }
}
void ad_print()
{
    printf("\n\t\t-----1.进货--------\n");
    printf("\t\t--2.删除商品信息---\n");
    printf("\t\t--3.修改商品信息---\n");
    printf("\t\t--4.查询商品信息---\n");
    printf("\t\t--5.输出商品信息---\n");
}
int proving()
{
    int k;
    char pd1[]="666";
    char pd2[10];
    scanf("%s",&pd2);
    if(strcmp(pd1,pd2))
        return 0;
    else
        return 1;
}
