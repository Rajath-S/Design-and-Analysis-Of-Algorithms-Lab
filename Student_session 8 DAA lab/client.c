#include<stdlib.h>
#include<stdio.h>
#include"session8_dfsbfs.h"


int main()
{
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
	printf("input taken\n");
	for(int i = 0; i <numOfNodes; i++)
	{
		for(int j = 0;j <numOfNodes; j++)
		{
			printf("%d",(x[i][j]));
		}
		printf("\n");
	}
	//printf("\n");
	int numcomp;
	printf("computing number of components...\n");
	if (dfs)
		numcomp = count_components_dfs(x, numOfNodes);
	else
		numcomp = count_components_dfs(x, numOfNodes);
	printf("number of components=%d\n",numcomp);
	for(int i=0;i<numOfNodes;i++)
	{
		free(x[i]);
	}
	free(x);
	printf("memory freed\n\n");

  }

  



  
  
}
