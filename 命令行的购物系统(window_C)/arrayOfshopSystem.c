
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
struct Goods
{
    int  goods_id;             /*商品编号*/
    char  goods_name[50];      /*商品名称*/
    char  goods_type[50];      /*商品种类*/
    float goods_inputprice;    /*商品进价*/
    float goods_outputprice;   /*商品售价*/
    int   goods_num;           /*商品进货量*/
}*p,*q;
struct sell
{
    
    int sell_id;          /*卖出商品的编号*/
    char sell_name[50];   /*卖出商品的名称*/
    float sell_price;     /*卖出商品价格*/
    int sell_num;         /*卖出商品的数量*/
    char sell_people[50]; /*购买人的名字*/
}*n,*m;
struct sell shopping[50];
struct Goods GoodsDates[50]={
    {1,"短袖","衣服",150,200,500},
    {2,"短裤","裤子",160,230,400}
};
int seaech_id(int x);
void insertGoods();
void xiugaiGoods();
void deleteGoods();
void update();
void chaxun();
void chaxun_id();
void chaxun_name();
void chaxun_outputprice();
void surface();
void change_id();
void addgoods();
void type();
void residue();
int proving();
void shop();
void printfshop();
int searchshop_id(int x);
void change_shop();
void delshop();
void chaxun_shop();
void shop_enter();
void showgoods();
int findgoods_totle();
int findshop_totle();
void readgoods();
void readshop();
void writeshop();
void writegoods();
void sell_system();
void sell_select();
main()
{
    
    
    int m;
    readshop();
    readgoods();
    printf("\t\t-------------来者何人？------------\n");
    while(1)
    {
        char st;
        int tip;
        printf("\t\t顾客扣'k'");
        printf("\t管理员扣'g':");
        fflush(stdin);
        scanf("%c",&st);
        if(st=='k')
        {
            printf("\t\tWelcome To My Store\n");
            printf("这是小店的商品:\n");
            while(1)
            {
                int flag;
                showgoods();
                shop();
                printfshop();
                printf("尊敬的顾客，你还要继续剁手么？");
                printf("输入'1'退出,输入任意键继续。");
                scanf("%d",&flag);
                if(flag==1)
                    break;
            }
        }
        else
        {
            printf("请输入管理员密码:");
            m=proving();
            if(m==1)
            {
                while(1)
                {
                    int s_num,flag1;
                    surface();
                    scanf("%d",&s_num);
                    switch(s_num)
                    {
                        case 1:insertGoods();
                            break;
                        case 2:residue();
                            break;
                        case 3:update();
                            break;
                        case 4:chaxun();
                            break;
                        case 5:sell_select();
                            break;
                        default:printf("你的输入不在1~5之内.\n");
                    }
                    printf("(主函数)退出请按'0',返回上一级请按任意键.");
                    scanf("%d",&flag1);
                    if(flag1==0)
                        break;
                }
            }
            else
            {
                printf("\t\t\t你不是管理员!");
            }
        }
        printf("返回上一级按任意键，退出请按'0'");
        scanf("%d",&tip);
        if(tip==0)
            break;
    }
}
void sell_select()
{
    int num;
    
    while(1)
    {int flag;
        sell_system();
        scanf("%d",&num);
        switch(num)
        {
            case 1:printfshop();
                break;
            case 2:delshop();
                break;
            case 3:shop_enter();
                break;
            case 4:change_shop();
                break;
            default:printf("你的输入不在1~5之内.");
        }
        printf("继续使用销售管理员权限按任意键，退出按'0'.");
        scanf("%d",&flag);
        if(flag==0)
            break;
    }
}
void sell_system()
{
    printf("\t-----------销售管理系统-----------\n");
    printf("\t---------1.查询销售记录-----------\n");
    printf("\t---------2.删除销售记录-----------\n");
    printf("\t---------3.添加销售记录-----------\n");
    printf("\t---------4.修改销售记录-----------\n");
    printf("请输入操作编号:");
}
void readgoods()
{
    FILE *fp1;
    p=&GoodsDates;
    fp1=fopen("c:\\商品信息.txt","rb");
    fread(p,sizeof(struct Goods),50,fp1);
    fclose(fp1);
}
void readshop()
{
    FILE *fp2;
    n=&shopping;
    fp2=fopen("c:\\消费记录.txt","rb");
    fread(n,sizeof(struct sell),50,fp2);
    fclose(fp2);
}
void writeshop()
{
    FILE *fp2;
    int y;
    n=&shopping;
    y=findshop_totle();;
    fp2=fopen("c:\\消费记录.txt","wb");
    fwrite(n,sizeof(struct sell),y,fp2);
    fclose(fp2);
}
void writegoods()
{
    FILE *fp1;
    int y;
    p=&GoodsDates;
    y=findgoods_totle();;
    fp1=fopen("c:\\商品信息.txt","wb");
    fwrite(p,sizeof(struct Goods),y,fp1);
    fclose(fp1);
}
int findgoods_totle()
{
    int k=0,i;
    
    for(i=0;i<50;i++)
    {
        if(GoodsDates[i].goods_id!=0)
            k++;
    }
    return k;
}
int findshop_totle()
{
    int k=0,i;
    for(i=0;i<50;i++)
    {
        if(shopping[i].sell_id!=0)
            k++;
    }
    return k;
}
void showgoods()
{
    int i;
    printf("\t\t编号 \t名称 \t价格\t 数量\t \n");
    for(i=0;i<50;i++)
    {
        if(GoodsDates[i].goods_id==0)
            continue;
        printf("\t\t%d  \t%s   %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
    }
    
}
void shop()
{
    int shop_id,shop_num,flag,taojia,taojia_j,i,y;
    float shop_price;
    char shop_name[20];
    printf("请输入你要买商品的编号:");
    scanf("%d",&shop_id);
    i=searchgoods_id(shop_id);/*编号*/
    shop_price=GoodsDates[i].goods_outputprice;
    printf("是否讨价还价.\n");
    printf("按'1'讨价还价,按任意键好爽购买.:");
    scanf("%d",&taojia);
    if(taojia==1)
    {
        printf("顾客：可以减10块钱么，大学生难哪。么么哒~~~~~~\n");
        printf("售货员：~~~好吧，看你这么诚恳，给你减10块钱。\n");
        printf("~~~~假装没钱~~~~~~~请按‘1’,直接下单按任意键:\n");
        shop_price=shop_price-10;
        scanf("%d",&taojia_j);
        if(taojia_j==1)
        {
            printf("顾客：哎呀，刚坐车了，口袋钱不够，再减20直接下单,么么哒~~~~\n");
            printf("售货员：~~~~~~算了，亏本买你啦。\n");
            shop_price=shop_price-20;
        }
    }
    printf("尊敬的顾客，你要买几件%s:",GoodsDates[i].goods_name);
    scanf("%d",&shop_num);
    printf("确认购买吗？确定请按任意键,取消请按'0':");
    scanf("%d",&flag);
    if(flag==0)
    {
        printf("已取消购买.");
    }
    else
    {
        printf("尊敬的顾客，请输入你的名字:\n");
        y=findshop_totle();
        scanf("%s",&shop_name);
        GoodsDates[i].goods_num=GoodsDates[i].goods_num-shop_num;
        shopping[y].sell_id=shop_id;
        strcpy(shopping[y].sell_name,GoodsDates[i].goods_name);
        strcpy(shopping[y].sell_people,shop_name);
        shopping[y].sell_price=shop_price;
        shopping[y].sell_num=shop_num;
        writeshop();
        readshop();
        writegoods();
    }
}
void shop_enter()
{
    printfshop();
    int j=0,i;
    while(1)
    {
        if(shopping[j].sell_id!=0)
            j++;
        else
            break;
    }
    for(i=j;i<50;i++)
    {
        int check;
        printf("\t\t\t\t请输入消费记录商品编号:");
        scanf("%d",&shopping[i].sell_id);
        printf("\t\t\t\t请输入消费记录商品名称:");
        scanf("%s",&shopping[i].sell_name);
        printf("\t\t\t\t请输入消费记录商品价格:");
        scanf("%f",&shopping[i].sell_price);
        printf("\t\t\t\t请输入消费记录商品数量:");
        scanf("%d",&shopping[i].sell_num);
        printf("\t\t\t\t请输入消费记录购买人:");
        scanf("%s",&shopping[i].sell_people);
        printf("继续录入选“1”，退出选“0”:");
        scanf("%d",&check);
        if(check==0)
            break;
    }
    writeshop();
}
void delshop()
{
    int i,t,shop_id;
    printf("请输入要删除的消费记录商品序号:");
    scanf("%d",&i);
    printf("\t\t编号 \t名称 \t价格\t 数量\t 购买人姓名 \n");
    printf("\t\t%d \t%s \t%5.2f \t%d \t%s\n",shopping[i-1].sell_id,shopping[i-1].sell_name,shopping[i-1].sell_price,shopping[i-1].sell_num,shopping[i-1].sell_people);
    printf("\n\t\t!!警告：数据删除后不可修复！是否继续？\n");
    printf("\n\t\t   继续请选“1”，取消请选“0”:\n");
    scanf("%d",&t);
    if( t== 1 )
    {
        shopping[i-1].sell_id =0;
        strcpy(shopping[i-1].sell_name ,"\0");
        strcpy(shopping[i-1].sell_people,"\0");
        shopping[i-1].sell_price= 0;
        shopping[i-1].sell_num= 0;
        writeshop();
    }
    if(t==1)
        printf("删除成功\n");
    else
        printf("保留商品\n");
}
void chaxun_shop()
{
    int shop_id,i;
    printf("请输入你想要查询商品的编号:\n");
    scanf("%d",&shop_id);
    i=searchshop_id(shop_id);
    printf("\t\t编号 \t名称 \t价格\t 数量\t 购买人姓名 \n");
    printf("\t\t%d \t%s \t%5.2f \t%d \t%s\n",shopping[i].sell_id,shopping[i].sell_name,shopping[i].sell_price,shopping[i].sell_num,shopping[i].sell_people);
}
void change_shop()
{
    
    int shop_id,id,i;
    printfshop();
    printf(" \t\t\t 请输入要修改的商品消费记录序号:  ");
    scanf("%d",&i);
    printf("此条记录为:\n");
    printf("\t\t编号 \t名称 \t价格\t 数量\t 购买人姓名 \n");
    printf("\t\t%d \t%s \t%5.2f \t%d \t%s\n",shopping[i-1].sell_id,shopping[i-1].sell_name,shopping[i-1].sell_price,shopping[i-1].sell_num,shopping[i-1].sell_people);
    printf(" \t\t\t\t 请输入修改后的消费记录商品编号:  ");
    scanf("%d",&shopping[i-1].sell_id);
    printf(" \t\t\t\t 请输入修改后的消费记录商品名称:  ");
    scanf("%s",&shopping[i-1].sell_name);
    printf(" \t\t\t\t 请输入修改后的消费记录商品售价:  ");
    scanf("%f",&shopping[i-1].sell_price);
    printf(" \t\t\t\t 请输入修改后的消费记录商品数量:  ");
    scanf("%d",&shopping[i-1].sell_num);
    printf(" \t\t\t\t 请输入修改后的消费记录商品购买人:  ");
    scanf("%s",&shopping[i-1].sell_people);
    printf("\t\t编号 \t名称 \t价格\t 数量\t 购买人姓名 \n");
    printf("\t\t%d \t%s \t%5.2f \t%d \t%s\n",shopping[i-1].sell_id,shopping[i-1].sell_name,shopping[i-1].sell_price,shopping[i-1].sell_num,shopping[i-1].sell_people);
    writeshop();
}

void printfshop()
{
    int i;
    printf("当前消费记录为:\n");
    printf("\t\t编号 \t名称 \t价格\t 数量\t 购买人姓名 \n");
    for(i=0;i<50;i++)
    {
        if(shopping[i].sell_id==0)
            continue;
        printf("\t\t%d \t%s \t%5.2f \t%d \t%s\n",shopping[i].sell_id,shopping[i].sell_name,shopping[i].sell_price,shopping[i].sell_num,shopping[i].sell_people);
    }
}
void residue()
{
    int i;
    printf("当前库存量为:\n");
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
    for(i=0;i<50;i++)
    {
        if(GoodsDates[i].goods_id==0 )
            continue;
        printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
    }
}
void surface()
{
    
    printf("\t---------超级管理员权限-----------\n");
    printf("\t---------1.进货-------------------\n");
    printf("\t---------2.输出商品信息-----------\n");
    printf("\t---------3.更新商品信息-----------\n");
    printf("\t---------4.查询商品信息-----------\n");
    printf("\t---------5.进入销售管理系统-------\n");
    printf("请输入操作编号:");
}
void type()
{
    printf("\t-------1.商品编号---------\n");
    printf("\t-------2.商品名称---------\n");
    printf("\t-------3.商品种类---------\n");
    printf("\t-------4.商品进价---------\n");
    printf("\t-------5.商品售价---------\n");
    printf("\t-------6.商品数量---------\n");
}
void insertGoods()
{
    int j=0,i;
    while(1)
    {
        if(GoodsDates[j].goods_id!=0)
            j++;
        else
            break;
    }
    for(i=j;i<50;i++)
    {
        int check;
        printf("\t\t\t\t请输入商品编号:");
        scanf("%d",&GoodsDates[i].goods_id);
        printf("\t\t\t\t请输入商品名称:");
        scanf("%s",&GoodsDates[i].goods_name);
        printf("\t\t\t\t请输入商品种类:");
        scanf("%s",&GoodsDates[i].goods_type);
        printf("\t\t\t\t请输入商品进价:");
        scanf("%f",&GoodsDates[i].goods_inputprice);
        printf("\t\t\t\t请输入商品单价:");
        scanf("%f",&GoodsDates[i].goods_outputprice);
        printf("\t\t\t\t请输入商品数量:");
        scanf("%d",&GoodsDates[i].goods_num);
        printf("\t\t\t\t继续录入选“1”，退出选“0”:\n");
        writegoods();
        scanf("%d",&check);
        if(check==0)
            break;
    }
    
    
}
void xiugaiGoods()
{
    int searchgoods_id;
    int i,k;
    printf("\t\t\t 请输入要修改的商品编号:  ");
    scanf("%d",&searchgoods_id);
    
    for(i=0;i<50;i++)
    {
        if( GoodsDates[i].goods_id == searchgoods_id )
        {
            printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
            printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
        }
        printf("目前的编号有：");
        for(k=0;k<50;k++)
        {
            if(GoodsDates[k].goods_id==0)
                continue;
            printf("%d",GoodsDates[k].goods_id);
        }
        printf(" \t\t\t\t 请输入修改后的商品编号:  ");
        scanf("%d",&GoodsDates[i].goods_id);
        printf(" \t\t\t\t 请输入修改后的商品名称:  ");
        scanf("%s",&GoodsDates[i].goods_name);
        printf(" \t\t\t\t 请输入修改后的商品种类:  ");
        scanf("%s",&GoodsDates[i].goods_type);
        printf(" \t\t\t\t 请输入修改后的商品进价:  ");
        scanf("%f",&GoodsDates[i].goods_inputprice);
        printf(" \t\t\t\t 请输入修改后的商品售价:  ");
        scanf("%f",&GoodsDates[i].goods_outputprice);
        printf(" \t\t\t\t 请输入修改后的商品数量:  ");
        scanf("%d",&GoodsDates[i].goods_num);
        printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
        printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
    }
    
}
int searchshop_id(int x)
{
    int k,i;
    for(i=0;i<50;i++)
    {
        if(shopping[i].sell_id==x)
        {k=i;
            break;
        }
    }
    return k;
}
int searchgoods_id(int x)
{
    int k,i;
    for(i=0;i<50;i++)
    {
        if(GoodsDates[i].goods_id==x)
        {k=i;
            break;
        }
    }
    return k;
}
void deleteGoods()
{
    int i,t;
    int goods_id;
    printf("请输入要删除的商品编号:");
    scanf("%d",&goods_id);
    i=searchgoods_id(goods_id);
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
    printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
    printf("\n\t\t!!警告：数据删除后不可修复！是否继续？\n");
    printf("\n\t\t   继续请选“1”，取消请选“0”:\n");
    scanf("%d",&t);
    if( t== 1 )
    {
        GoodsDates[i].goods_id =0;
        strcpy(GoodsDates[i].goods_name ,"\0");
        strcpy(GoodsDates[i].goods_type,"\0");
        GoodsDates[i].goods_inputprice= 0;
        GoodsDates[i].goods_outputprice= 0;
        GoodsDates[i].goods_num= 0;
        writegoods();
    }
    if(t==1)
        printf("删除成功\n");
    else
        printf("保留商品\n");
}

void update()
{
    int update_num,flag;
    flag=1;
    while(flag)
    {
        printf("\t---------------更新---------------\n");
        printf("\t---------1.修改商品信息-----------\n");
        printf("\t---------2.删除商品信息-----------\n");
        printf("\t---------3.添加商品信息-----------\n");
        printf("请输入操作编号:");
        scanf("%d",&update_num);
        switch(update_num)
        {
            case 1:
                printf("正在进入修改信息功能-----------\n");
                change_id();
                break;
                
                
            case 2:
                printf("正在进入删除商品信息------------\n");
                deleteGoods();
                break;
                
            case 3:
                printf("正在进入添加商品信息------------\n");
                addgoods();
                break;
        }
        printf("继续更新请扣'1'，退出请按'0':");
        scanf("%d",&flag);
    }
}
void change_id()
{
    int i,id,k;
    
    int   goods_id; /*商品编号*/
    char  goods_name[50];  /*商品名称*/
    char  goods_type[50];      /*商品种类*/
    float goods_inputprice;   /*商品进价*/
    float goods_outputprice;  /*商品售价*/
    int   goods_num;           /*商品进货量*/
    printf("目前商品的编号有：");
    for(k=0;k<50;k++)
    {
        if(GoodsDates[k].goods_id==0)
            continue;
        printf("%d    ",GoodsDates[k].goods_id);
    }
    printf("请输入你要修改商品的编号:");
    scanf("%d",&id);
    i=searchgoods_id(id);
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
    printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
    printf("\t你想修改此商品的哪个信息?\n");
    type();
    while(1)
    {
        int num;
        int judge;
        printf("请输入操作编号:");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
                printf("你希望此商品的编号为:\n");
                scanf("%d",&goods_id);
                GoodsDates[i].goods_id =goods_id;
                break;
            case 2:printf("你希望此商品的名称为:");
                scanf("%s",&goods_name);
                strcpy(GoodsDates[i].goods_name,goods_name);
                break;
            case 3:	printf("你希望此商品的种类为:\n");
                scanf("%s",&goods_type);
                
                strcpy(GoodsDates[i].goods_type,goods_type);
                break;
            case 4:printf("你希望此商品的进价为:\n");
                scanf("%f",&goods_inputprice);
                GoodsDates[i].goods_inputprice=goods_inputprice;
                break;
            case 5:printf("你希望此商品的售价为:\n");
                scanf("%f",&goods_outputprice);
                GoodsDates[i].goods_outputprice=goods_outputprice;
                break;
            case 6:printf("你希望此商品的数量为:\n");
                scanf("%d",&goods_num);
                GoodsDates[i].goods_num=goods_num;
                break;
            default:printf("输入有误.");
        }
        printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
        printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
        printf("退出修改按'1',继续修改按任意键.");
        writegoods();
        scanf("%d",&judge);
        if(judge==1)
            break;
    }
}
void addgoods()
{
    int j=0,i;
    while(1)
    {
        if(GoodsDates[j].goods_id!=0)
            j++;
        else
            break;
    }
    for(i=j;i<50;i++)
    {
        int check;
        printf("\t\t\t\t请输入商品编号:");
        scanf("%d",&GoodsDates[i].goods_id);
        printf("\t\t\t\t请输入商品名称:");
        scanf("%s",&GoodsDates[i].goods_name);
        printf("\t\t\t\t请输入商品种类:");
        scanf("%s",&GoodsDates[i].goods_type);
        printf("\t\t\t\t请输入商品进价:");
        scanf("%f",&GoodsDates[i].goods_inputprice);
        printf("\t\t\t\t请输入商品单价:");
        scanf("%f",&GoodsDates[i].goods_outputprice);
        printf("\t\t\t\t请输入商品数量:");
        scanf("%d",&GoodsDates[i].goods_num);
        printf("继续录入选“1”，退出选“0”:");
        scanf("%d",&check);
        if(check==0)
            break;
    }
    writegoods();
    
}
void chaxun()
{
    int  numOperator;
    printf("\t----------------查询----------------\n");
    printf("\t---------1.按商品编号查询-----------\n");
    printf("\t---------2.按商品名称查询-----------\n");
    printf("\t---------3.按商品售价查询-----------\n");
    printf("\t---------4.返回上一级---------------\n");
    printf("请输入相应操作编号: ");
    while(1)
    {
        int tip;
        scanf("%d",&numOperator);
        switch(numOperator)
        {
            case 1 :chaxun_id();
                break;
            case 2 :chaxun_name();
                break;
            case 3 :chaxun_outputprice();
                break;
            case 4 :
                break;
            default:printf("请输入1~4以内的数值:");	
        }
        printf("退出查询请按0,继续查询按任意键.");
        scanf("%d",&tip);
        if(tip==0)
            break;
    }
}
void chaxun_id()
{
    int goods_NUM,i;
    printf("请输入你想要查询商品的编号:\n");
    scanf("%d",&goods_NUM);
    i=searchgoods_id(goods_NUM);
    printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
    printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
}
void chaxun_name()
{
    char gn[10];
    int i,tf;
    printf("请输入你想要查询商品的名称:\n");
    scanf("%s",&gn);
    for(i=0;i<50;i++)
    {
        tf=strcmp(gn,GoodsDates[i].goods_name);
        if(tf==0)
        {
            printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
            printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
        }
    }
}
void chaxun_outputprice()
{
    int outprice,i;
    printf("请输入你想要查询商品的出售价格:\n");
    scanf("%d",&outprice);
    for(i=0;i<50;i++)
    {
        if(outprice==GoodsDates[i].goods_outputprice)
        {
            printf("\t\t编号 \t名称 \t类别 \t进价 \t单价 \t数量\n");
            printf("\t\t%d \t%s \t%s \t%5.2f %5.2f  \t%d\n",GoodsDates[i].goods_id,GoodsDates[i].goods_name,GoodsDates[i].goods_type,GoodsDates[i].goods_inputprice,GoodsDates[i].goods_outputprice,GoodsDates[i].goods_num);
        }
    }
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
