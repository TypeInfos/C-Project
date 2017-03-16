#include "stdio.h"

int main()
{
    int max,temp,min,k = 0,i,s[10]={213,34,5,67,88,56,65,233,12,10};
    int *p;
    p=s;
    max=*(p);
    min=*(p);
    for(i=1;i<10;i++)
    {
        if(min>s[i])
        {
            k=i;
            min=s[i];
        }
    }
    temp=*(p);
    *(p)=*(p+k);
    *(p+k)=temp;
    for(i=0;i<10;i++)
    printf("%d ",s[i]);
    
}
