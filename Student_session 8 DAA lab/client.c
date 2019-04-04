#include<stdlib.h>
#include<stdio.h>
#include"session8_dfsbfs.h"
#include<time.h>
#include<math.h>
#define nano 1000000000L
int main()
{struct timespec start,end;
	int dfs = 0;
  printf("starting function\n");
  int testcases,numOfNodes;
  scanf("%d",&testcases);
  for(int i=0;i<testcases;i++)
  {
  scanf("%d",&numOfNodes);
  printf("%d nodes in graph\n",numOfNodes);
  //take input in the form of an array
	printf("taking input for each test case\n");
	int **x = malloc(numOfNodes * sizeof(int*));
	for (int i = 0; i <numOfNodes; i++)
	{
		x[i] = malloc(numOfNodes * sizeof(int));
     }
	for(int i = 0; i <numOfNodes; i++)
	{
		for(int j = 0;j <numOfNodes; j++)
		{
			scanf("%d",&(x[i][j]));
		}
	}
	// printf("input taken\n");
	// for(int i = 0; i <numOfNodes; i++)
	// {
	// 	for(int j = 0;j <numOfNodes; j++)
	// 	{
	// 		printf("%d",(x[i][j]));
	// 	}
	// 	printf("\n");
	// }
	//printf("\n");
	int numcomp;
	printf("computing number of components...\n");
	clock_gettime(CLOCK_REALTIME,&start);
	if (dfs)
		numcomp = count_components_dfs(x, numOfNodes);
	else
		numcomp = count_components_dfs(x, numOfNodes);
	clock_gettime(CLOCK_REALTIME,&end);
	double time_=(end.tv_sec-start.tv_sec)+(end.tv_nsec-start.tv_nsec)*pow(10, -9);
	printf("number of components=%d\n",numcomp);
	if(dfs=1)
		printf("time taken for dfs= %lf \n",time_);
	else
		printf("time taken for bfs= %lf \n",time_);

	for(int i=0;i<numOfNodes;i++)
	{
		free(x[i]);
	}
	free(x);
	printf("memory freed\n\n");

  }

  



  
  
}
