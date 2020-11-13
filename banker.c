#include<stdio.h>
#include <stdlib.h>
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;

printf("Enter the no of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	completed[i] = 0;

printf("\nenter the no of resources : ");
scanf("%d", &r);

printf("\nenter the max matrix for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nfor  P%d : ", i );
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}

printf("\nenter the allocation for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nfor  P%d : ",i );
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);	
}

printf("\nenter the available resources : ");
for(i = 0; i < r; i++)
		scanf("%d", &avail[i]);	


	for(i = 0; i < p; i++)
		for(j = 0; j < r; j++)
			need[i][j] = Max[i][j] - alloc[i][j];
		
do
{
	
	

	process = -1;

	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if(avail[j] < need[i][j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d completed", process + 1);
		safeSequence[count] = process + 1;
		count++;
		for(j = 0; j < r; j++)
		{
			avail[j] += alloc[process][j];
			
			completed[process] = 1;
		}
	}
}while(count != p && process != -1);

if(count == p)
{
	printf("\n system is in a safe state\n");
	printf("safe sequence is : ");
	for( i = 0; i < p; i++)
			printf("%d  ", safeSequence[i]);
	printf("\n");
}
else
	printf("\nThe system is in unsafe state");

}