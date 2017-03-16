/* Note:Your choice is C IDE */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "malloc.h"
#include "time.h"
typedef struct Goods
{
    int   goods_id; /*商品编号*/
    char  goods_name[50];  /*商品名称*/
    char  goods_type[50];      /*商品种类*/
    float goods_inputprice;   /*商品进价*/
    float goods_outputprice;  /*商品售价*/
    int   goods_num;          /*商品数量*/
    char  goods_date[20];    /*进货日期*/
    int   goods_quality;            /*保质期*/
    struct Goods *next;
}GOD,*List;
typedef struct sell
{
    int sell_id;/*记录编号*/
    char sell_name[50];/*商品名称*/
    int sell_num;/*商品数量*/
    float sell_price;/*出售价格*/
    char sell_date[50];/*出售日期*/
    char sell_people[50];/*购买人姓名*/
    struct sell *next;
}SLL,*Sist;
List insert();
void goods_export(List L);
void delet_goods(List L);
void find_goods_id(List L,int x);/*找到编号并输出*/
int return_goods_id(List L,int x);/*找到编号返回值*/
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
void sell_insert(Sist H,Sist p);
void showgoods(List L);
void readsell(Sist H);
void writesell(Sist H);
void sell_shop(List L,Sist H);
void sell_print(Sist H);
void ad_sell_print();
int return_sell_id(Sist H,int x);
void delet_sell(Sist H);
void find_sell_id(Sist H,int x);
void print_sell(Sist H,int x);
void delet_sell(Sist H);
void change_sell_name();
void change_sell(Sist H);
void system_sell(Sist H);
void surface();
void change_mima(char *p);
void count_price_print(List L);
void count_jilu_print(Sist H);
void tonji();
void count(List L,Sist H);
void sell_profit(Sist H,List L);
void good_profit(List L);
main()
{
    int m;
    char start,flag,flag1;
    char pd1[20],pd2[20];
    FILE  *fp,*fp1,*fp2;
    List L;
    Sist H;
    H=(Sist)malloc(sizeof(SLL));
    H->next=NULL;
    L=(List)malloc(sizeof(GOD));
    L->next=NULL;
    readgoods(L);
    readsell(H);
    if((fp2=fopen("e:\\消费记录.txt","rb"))==NULL)
    {
        fp2=fopen("e:\\消费记录.txt","wb");
        fclose(fp2);
    }
    if((fp1=fopen("e:\\商品信息.txt","rb"))==NULL)
    {
        fp1=fopen("e:\\商品信息.txt","wb");
        fclose(fp1);
    }
    fp=fopen("c:\\aa.txt","rb");
    fread(pd1,20,1,fp);
    fclose(fp);
    while(1)
    {
        surface();
        start=getch();
        if(start=='k'||start=='K')
        {
            system("cls");
            printf("本店的商品:\n");
            showgoods(L);
            printf("输入你想买商品的编号:\n");
            
            sell_shop(L,H);
            
            printf("购买成功!");
        }
        else
            if(start=='g'||start=='G')
            {
                printf("请输入密码:");
                scanf("%s",&pd2);
                m=strcmp(pd1,pd2);
                if(m==0)
                {
                    while(1)
                    {
                        int select;
                        char q[10];
                        char a[10];
                        ad_print();
                        printf("请输入操作编号:");
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
                            case 5:system("cls");
                                goods_export(L);
                                break;
                            case 6:system_sell(H);
                                break;
                            case 7:change_mima(&pd1);
                                break;
                            case 8:count(L,H);
                                break;
                            case 0:main();
                            default:printf("你的输入不在0~8之间!\n");
                        }
                        printf("N:退出超级管理员系统，任意键继续。\n");
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
            else
                printf("输入错误!\n");
        printf("返回界面按任意键，退出按'n'");
        flag1=getch();
        if(flag1=='N'||flag1=='n')
            break;
    }
}

void tonji()
{
    system("cls");
    printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【综合统计系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
    printf("------------------------------系统菜单显示如下--------------------------------\n");
    printf("\t\t\t  ---1.查询商品价格---\n");
    printf("\t\t\t  ---2.查询消费记录---\n");
    printf("\t\t\t  ---3.目前营业利润---\n");
    printf("\t\t\t  ---4.按商品利润排版-\n");
    printf("\t\t\t  ---0.退出查询系统---\n");
}
void sell_profit(Sist H,List L)
{
    int flag;
    Sist s=H->next;
    printf("目前消费记录:\n");
    printf("\t\t商品 \t进价 \t售价 \t利润\n");
    while(s!=NULL)
    {
        List p=L->next;
        printf("\t\t%s",s->sell_name);
        while(p!=NULL)
        {
            flag=strcmp(p->goods_name,s->sell_name);
            if(flag==0)
            {
                printf("\t%5.2f",p->goods_inputprice);
                break;
            }
            p=p->next;
        }
        printf("\t%5.2f",s->sell_price);
        printf("\t%5.2f\n",s->sell_price-p->goods_inputprice);
        s=s->next;
    }
}
void good_profit(List L)
{
    float data[50];
    int s;
    float *p1;
    int num,j,k,l,f,i=0;
    j=0;
    List p=L->next;
    while(p!=NULL)
    {
        data[i]=p->goods_outputprice-p->goods_inputprice;
        i++;
        p=p->next;
    }
    j=i;
    num=0;
    for(k=0;k<j-1;k++)
    {
        l=k;
        for(f=k+1;f<j;f++)
            if(data[l]<data[f])
            {
                s=data[l];
                data[l]=data[f];
                data[f]=s;
            }
    }
    printf("目前商品的利润排行为:\n");
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t日期 \t利润\n");
    while(i>0)
    {
        List s=L->next;
        while(1)
        {
            if(s->goods_outputprice-s->goods_inputprice==data[num])
            {
                printf("\t\t%d",s->goods_id);
                printf("\t%s",s->goods_name);
                printf("\t%s",s->goods_type);
                printf("\t%5.2f",s->goods_inputprice);
                printf("\t%5.2f",s->goods_outputprice);
                printf("   %s",s->goods_date);
                printf("  %5.2f\n",data[num]);
                break;
            }
            s=s->next;
        }
        num++;
        i--;
    }
}
void count(List L,Sist H)
{
    int num;
    tonji();
    printf("请输入操作编号:");
    scanf("%d",&num);
    switch(num)
    {
        case 1:count_price_print(L);
            break;
        case 2:count_jilu_print(H);
            break;
        case 3:sell_profit(H,L);
            break;
        case 4:good_profit(L);
            break;
        case 0:break;
        default:printf("你的输入不在0~4之间!\n");
    }
}
void count_jilu_print(Sist H)
{
    int zon=0;
    int num=0;
    Sist p=H->next;
    Sist s=H->next;
    while(s!=NULL)
    {
        zon++;
        s=s->next;
    }
    printf("总共有%d条记录,",zon);
    printf("以下就是这些记录的日期和购买人:\n");
    while(p!=NULL)
    {
        if(num<1)
        {
            printf("\t\t商品 \t日期   \t\t姓名\n");
        }
        printf("\t\t%s",p->sell_name);
        printf("\t%s",p->sell_date);
        printf("\t%s\n",p->sell_people);
        num++;
        p=p->next;
    }
}

void count_price_print(List L)
{
    int zon=0;
    int num=0;
    List p=L->next;
    List s=L->next;
    while(s!=NULL)
    {
        zon++;
        s=s->next;
    }
    printf("总共有%d件商品",zon);
    printf("以下就是这些商品的名称，进价，售价:\n");
    while(p!=NULL)
    {
        if(num<1)
        {
            printf("\t\t名称  \t进价 \t单价\n");
        }
        
        printf("\t\t%s",p->goods_name);
        printf("\t%5.2f",p->goods_inputprice);
        printf("\t%5.2f\n",p->goods_outputprice);
        p=p->next;
        num++;
    }
}
void change_mima(char *p)
{
    
    char  f[20],a[20];
    FILE  *fp;
    printf("请输入旧密码:");
    scanf("%s",&a);
    if(strcmp(p,a)==0)
    {
        printf("密码正确，请输入新密码:");
        scanf("%s",&f);
        fp=fopen("c:\\aa.txt","wb");
        fwrite(f,20,1,fp);
        fclose(fp);
        fp=fopen("c:\\aa.txt","rb");
        fread(p,20,1,fp);
        fclose(fp);
        printf("\n密码修改成功!");
    }
    else
        printf("密码错误!");
}
void surface()
{
    system("cls");
    printf("\n\n\t+-----------------------------------------------------+\n");
    printf("\t|                        超市系统                     |\n");
    printf("\t+-----------------------------------------------------+\n");
    printf("\t|                       顾客入口'K'                   |\n");
    printf("\t|-----------------------------------------------------|\n");
    printf("\t|                      管理员入口'G'                  |\n");
    printf("\t|-----------------------------------------------------|\n");
    printf("\t|                     请输入您的选择                  |\n");
    printf("\t+-----------------------------------------------------+\n");
    printf("\n\n");
}
void print_sell(Sist H,int x)
{
    Sist p=H->next;
    while(p!=NULL)
    {
        
        if(p->sell_id==x)
        {
            printf("此编号的销售记录为:\n");
            printf("\t\t编号 \t名称 \t销量 \t价格   \t日期   \t姓名\n");
            printf("\t\t%d",p->sell_id);
            printf("\t%s",p->sell_name);
            printf("\t%d",p->sell_num);
            printf("\t%5.2f",p->sell_price);
            printf("  %s",p->sell_date);
            printf(" %s\n",p->sell_people);
            break;
        }
        p=p->next;
        
    }
    
}
void sell_print(Sist H)
{
    int num=0;
    Sist p=H->next;
    while(p!=NULL)
    {
        if(num<1)
        {
            printf("\t\t编号 \t名称 \t销量 \t价格   \t日期   \t姓名\n");
        }
        printf("\t\t%d",p->sell_id);
        printf("\t%s",p->sell_name);
        printf("\t%d",p->sell_num);
        printf("\t%5.2f",p->sell_price);
        printf("  %s",p->sell_date);
        printf(" %s\n",p->sell_people);
        num++;
        p=p->next;
    }
}
void sell_shop(List L,Sist H)
{
    int id,num,date;
    char s_date;
    List p;
    Sist r;
    scanf("%d",&id);
    find_goods_id(L,id);
    p=return_list_id(L,id);
    printf("双日价格减半，单日价格不变!");
    printf("请输入今天的日期:\n");
    scanf("%d",&date);
    if(date%2==0)
    {
        r=(Sist)malloc(sizeof(SLL));
        printf("今天是你的幸运日，价格减半!");
        printf("\n尊敬顾客，你要买多少%s:",p->goods_name);
        scanf("%d",&num);
        p->goods_num=p->goods_num-num;
        Sist t=H->next;
        printf("目前已有的编号:");
        while(t!=NULL)
        {
            printf("|%d| ",t->sell_id);
            t=t->next;
        }
        printf("输入此单的编号:");
        scanf("%d",&r->sell_id);
        strcpy(r->sell_name,p->goods_name);
        r->sell_num=num;
        r->sell_price=p->goods_outputprice/2;
        printf("\n正在下单-------请输入今天的年月份:");
        scanf("%s",&r->sell_date);
        printf("由于国家需要实名认证,请问你的名字是？:");
        scanf("%s",&r->sell_people);
        r->next=NULL;
        sell_insert(H,r);
        writesell(H);
        writegoods(L);
    }
    else{
        r=(Sist)malloc(sizeof(SLL));
        printf("\n尊敬顾客，你要买多少%s:",p->goods_name);
        scanf("%d",&num);
        p->goods_num=p->goods_num-num;
        printf("目前已有的编号:");
        Sist t=H->next;
        while(t!=NULL)
        {
            printf("|%d| ",t->sell_id);
            t=t->next;
        }
        printf("输入此单的编号:");
       	scanf("%d",&r->sell_id);
        strcpy(r->sell_name,p->goods_name);
        r->sell_num=num;
        r->sell_price=p->goods_outputprice/2;
        printf("\n正在下单-------请输入今天的年月份:");
        scanf("%s",&r->sell_date);
        printf("由于国家需要实名认证,请问你的名字是？:");
        scanf("%s",&r->sell_people);
        r->next=NULL;
        sell_insert(H,r);
        writesell(H);
        writegoods(L);
    }
}
void writesell(Sist H)
{
    FILE *fp2;
    Sist p=H->next;
    fp2=fopen("e:\\消费记录.txt","wb");
    while(p!=NULL)
    {
        fwrite(p,sizeof(SLL),1,fp2);
        p=p->next;
    }
    fclose(fp2);
}
void readsell(Sist H)
{
    int num,i;
    FILE *fp2;
    Sist p;
    fp2=fopen("e:\\消费记录.txt","rb");
    fseek(fp2,0,2);
    num=ftell(fp2)/sizeof(SLL);
    fseek(fp2,0,0);
    for(i=0;i<num;i++)
    {
        p=(Sist)malloc(sizeof(SLL));
        fread(p,sizeof(SLL),1,fp2);
        p->next=NULL;
        sell_insert(H,p);
    }
    fclose(fp2);
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

void showgoods(List L)
{
    
    List p=L->next;
    printf("\t\t编号 \t名称 \t单价 \t库存 \t日期 \t保质期\n");
    while(p!=NULL)
    {
        printf("\t\t%d",p->goods_id);
        printf("\t%s",p->goods_name);
        printf("\t%5.2f",p->goods_outputprice);
        printf("\t%d",p->goods_num);
        printf("   %s",p->goods_date);
        printf("  %d\n",p->goods_quality);
        p=p->next;
    }
}
void sell_insert(Sist H,Sist p)
{
    Sist s=H;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=p;
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
void add_sell(Sist H)
{
    char flag;
    Sist p,t;
    Sist s=H;
    t=H->next;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    while(1)
    {
        p=(Sist)malloc(sizeof(SLL));
        printf("目前已有的编号:");
        t=H->next;
        while(t!=NULL)
        {
            printf("|%d| ",t->sell_id);
            t=t->next;
        }
        printf("\n\n请输入消费记录商品编号:");
        scanf("%d",&p->sell_id);
        printf("请输入消费记录商品名称:");
        scanf("%s",&p->sell_name);
        printf("请输入消费记录商品数量:");
        scanf("%d",&p->sell_num);
        printf("请输入消费记录出售价格:");
        scanf("%f",&p->sell_price);
        printf("请输入消费记录进货日期:");
        scanf("%s",&p->sell_date);
        printf("请输入购买人姓名:");
        scanf("%s",&p->sell_people);
        p->next=NULL;
        s->next=p;
        s=s->next;
        writesell(H);
        printf("\nY:继续 N：结束");
        flag=getch();
        if(flag=='N'||flag=='n')
        {system("cls");
            break;
        }
    }
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
int return_sell_id(Sist H,int x)
{
    int num=0;
    Sist p=H->next;
    while(p!=NULL)
    {
        if(p->sell_id==x)
        {
            num=1;
            break;
        }
        p=p->next;
    }
    return num;
    
}
void delet_sell(Sist H)
{
    int num,flag,delet;
    Sist p,s,t;
    p=H;
    t=p->next;
    printf("\t\t------------删除记录信息------------\n");
    printf("当前库存:\n");
    sell_print(H);
    printf("请输入你要删除记录的编号:");
    scanf("%d",&num);
    flag=return_sell_id(H,num);
    if(1)
    {
        print_sell(H,num);
        printf("删除此数据将不能复原，确认删除按'1',取消删除按'0'");
        scanf("%d",&delet);
        if(delet)
        {
            while(t->sell_id!=num)
            {
                p=p->next;
                t=p->next;
            }
            s=p;
            s->next=t->next;
            free(t);
            writesell(H);
        }
    }
    else
    {
        printf("没有找到编号为%d的记录",num);
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
    int num,tip,tip1;
    char change;
    List p;
    printf("请输入你要修改的商品的编号:");
    scanf("%d",&num);
    tip=return_goods_id(L,num);
    p=return_list_id(L,num);
    find_goods_id(L,num);
    if(tip==1)
    {
        printf("\t\t-------------修改商品信息----------------\n");
        printf("修改此商品的全部信息扣'q',修改此商品的部分信息扣'b'\n");
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
                    case 1:printf("商品编号:");scanf("%d",&p->goods_id);
                        break;
                    case 2:printf("商品名称:");scanf("%s",&p->goods_name);
                        break;
                    case 3:printf("商品种类:");scanf("%s",&p->goods_type);
                        break;
                    case 4:printf("进货价格:");scanf("%f",&p->goods_inputprice);
                        break;
                    case 5:printf("出售价格:");scanf("%f",&p->goods_outputprice);
                        break;
                    case 6:printf("商品数量:");scanf("%d",&p->goods_num);
                        break;
                    case 7:printf("进货日期:");scanf("%s",&p->goods_date);
                        break;
                    case 8:printf("商品保质期(月份为单位):");scanf("%d",&p->goods_quality);
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
    while(p->goods_id!=x)
    {
        
        if(p==NULL)
            break;
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
    int num,flag,flag1;
    float price1,price2;
    num=0;
    flag1=0;
    List p=L->next;
    system("cls");
    printf("请输入你要查询商品的进货价格范围(输入格式xx,xx):");
    scanf("%f,%f",&price1,&price2);
    while(p!=NULL)
    {
        
        if(p->goods_inputprice>=price1&&p->goods_inputprice<=price2)
        {
            flag=1;
            flag1=1;
        }
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
    if(flag1==0)
        printf("没有找到符合条件的商品!\n");
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
    system("cls");
    printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超级管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
    printf("------------------------------系统菜单显示如下--------------------------------\n");
    printf("\t\t\t  ---1.添加商品信息---\n");
    printf("\t\t\t  ---2.删除商品信息---\n");
    printf("\t\t\t  ---3.修改商品信息---\n");
    printf("\t\t\t  ---4.查询商品信息---\n");
    printf("\t\t\t  ---5.输出商品信息---\n");
    printf("\t\t\t  ---6.进入销售管理---\n");
    printf("\t\t\t  ---7.修改管理员密码-\n");
    printf("\t\t\t  ---8.综合查询统计---\n");
    printf("\t\t\t  ---0.退出管理系统---\n");
}
void system_sell(Sist H)
{
    while(1)
    {
        int num,flag;
        ad_sell_print();
        printf("请输入操作编号:");
        scanf("%d",&num);
        switch(num)
        {
            case 1:add_sell(H);
                break;
            case 2:delet_sell(H);
                break;
            case 3:change_sell(H);
                break;
            case 4:sell_print(H);
                break;
            case 0:break;
            default:printf("你的输入不在0~4之间!");
        }
        printf("留在销售管理系统请按'1',退出按任意键!:");
        scanf("%d",&flag);
        if(flag==1)
            continue;
        else
            break;
    }
}
void change_sell(Sist H)
{
    int num;
    Sist p=H->next;
    sell_print(H);
    printf("请输入你要修改记录的编号:");
    scanf("%d",&num);
    print_sell(H,num);
    while(1)
    {
        int import,flag;
        change_sell_name();
        scanf("%d",&import);
        switch(import)
        {
            case 1:scanf("%d",&p->sell_id);
                break;
            case 2:scanf("%s",&p->sell_name);
                break;
            case 3:scanf("%d",&p->sell_num);
                break;
            case 4:scanf("%f",&p->sell_price);
                break;
            case 5:scanf("%s",&p->sell_date);
                break;
            case 6:scanf("%s",&p->sell_people);
                break;
            default:printf("你的输入不在1~6之间!");
        }
        writesell(H);
        printf("继续修改此商品的信息请按'1',退出按任意键!:");
        scanf("%d",&flag);
        if(flag==1)
            continue;
        else
            break;
    }
}
void change_sell_name()
{
    printf("\t修改销售记录");
    printf("\t1.编号\n");
    printf("\t2.名称\n");
    printf("\t3.销量\n");
    printf("\t4.价格\n");
    printf("\t5.日期\n");
    printf("\t6.姓名\n");
    printf("请输入操作序号:");
}
void ad_sell_print()
{
    
    printf("\n\t\t--后台销售管理-----\n");
    printf("\t\t--1.添加销售记录---\n");
    printf("\t\t--2.删除销售记录---\n");
    printf("\t\t--3.修改销售记录---\n");
    printf("\t\t--4.输出销售记录---\n");
    printf("\t\t--0.退出管理系统---\n");
}
