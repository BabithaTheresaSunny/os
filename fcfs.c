#include<stdio.h>
#include <stdlib.h>
void main()
{
    int h,n,ar[20],count=0;
    printf("enter the head position");
    scanf("%d",&h);
    printf("\nenter the no of i/o requests");
    scanf("%d",&n);
    printf("\nenter the request queue:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
printf("Seek sequence is:\n");
 for(int i=0;i<n;i++)
    {
        printf("%d",ar[i]);
        printf("\n");
    }

    for(int i=0;i<n;i++)
    {
      count=count+abs(h-ar[i]);
      h=ar[i];
    }
printf("\ntotal seek count is %d",count);

}
