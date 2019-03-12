#include"session8_dfsbfs.h"
#include<stdio.h>
#include<stdlib.h>
void dfs(int vertex,int* visited,int** g,int numberOfComponents,int nodes);
void bfs(int vertex, int* visited, int* queue, int** g, int numberOfComponents, int n, int f, int r);
int count_components_dfs(int **g, int n)
{
  // g is a graph and n is number of of vertices
	int* visited = (int*)malloc(sizeof(int)*n);
  int numberOfComponents=0;
  for(int i=0;i<n;i++)
  {
    visited[i]=0;
  }
  for(int i=0;i<n;i++)
  {
        if(visited[i]==0)
        {
          numberOfComponents++;
          dfs(i,visited,g,numberOfComponents,n);

        }
  }
  printf("visited_array for dfs\n");
  for(int i=0;i<n;i++)
  {
    printf("%d",visited[i]);
  }
  printf("\n");
  free(visited);
  return numberOfComponents;
}
void dfs(int vertex,int* visited,int** g,int numberOfComponents,int n)
{
  visited[vertex]=numberOfComponents;
  for(int i=0;i<n;i++)
  {
    if(g[vertex][i]==1&&visited[i]==0)                 //perform dfs for all adjacent vertices if the vertex was not previously visited
    {
      dfs(i,visited,g,numberOfComponents,n);
    }
  }
}

int count_components_bfs(int **g, int n)
{
	// g is a graph and n is number of of vertices
	int* visited = (int*)malloc(sizeof(int)*n);
	int* queue = (int*)malloc(sizeof(int)*n);
	int f = 0;int r = -1;
	int numberOfComponents = 0;
	for (int i = 0;i < n;i++)
	{
		visited[i] = 0;
		queue[i] = 0;
	}
	for (int i = 0;i < n;i++)
	{
		if (visited[i] == 0)//if vertex has not been visited
		{
			numberOfComponents++;
			bfs(i, visited,queue, g, numberOfComponents, n,f,r);

		}
	}
	printf("visited_array for bfs\n");
	for (int i = 0;i < n;i++)
	{
		printf("%d", visited[i]);
	}
	printf("\n");
	free(visited);
	free(queue);
	return numberOfComponents;
}
	
void bfs(int vertex, int* visited,int* queue, int** g, int numberOfComponents, int n,int f,int r)
{
	   
		for (int i = 0; i < n; i++)                     //iter through all adjacent nodes and store the adjacent nodes in a queue
			if (g[vertex][i] && !visited[i])
				queue[++r] = i;
		if (f <= r)     //if its a valid queue meaning not empty
		{
			visited[queue[f]] = numberOfComponents;
			bfs(queue[f++],visited,queue,g,numberOfComponents,n,f,r);
		}
}

