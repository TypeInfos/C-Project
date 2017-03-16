#include "stdio.h"
int maxCommon(int x,int y)
{
    int temp;
    if(x<y)
    {
        temp=x;
        x=y;
        y=temp;
    }
    while(y!=0)
    {
        temp=x%y;
        x=y;
        y=temp;
        
    }
    return(x);
}
int main()
{
    int a,b,max,min;
    printf("请输入两个INT数字:");
    scanf("%d,%d",&a,&b);
    max=maxCommon(a,b);
    min=a*b/max;
    printf("最大公约数:%d,最小公倍数:%d",max,min);
    return 0;
}
