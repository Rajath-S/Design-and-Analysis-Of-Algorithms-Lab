#include"session8_dfsbfs.h"
#include<stdio.h>
void dfs(int vertex,int* visited,int** g,int numberOfComponents,int nodes);
int count_components_dfs(int **g, int n)
{
  // g is a graph and n is number of of vertices
  int visited[n];
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
  printf("visited_array\n");
  for(int i=0;i<n;i++)
  {
    printf("%d\n",visited[i]);
  }
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
