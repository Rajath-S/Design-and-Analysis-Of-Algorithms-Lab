#include<math.h>
#include"session4_tsp.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define nano 1000000000L
int main()
{
  int n;
  double time1,time2;
  scanf("%d", &n); //n > 1
  //cost_matrix=int *arr = (int *)malloc(n *n*sizeof(int));
  int mincost;
  //int cost_matrix[n][n];
  int** graph=(int**)malloc(sizeof(int*)*n);
  for(int i=0;i<n;i++)
  {
  	graph[i]=(int*)malloc(sizeof(int)*n);
  	for(int j=0;j<n;j++)
  	{
  		scanf("%d",&graph[i][j]);
  	}
  }
  /*
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        printf("%d ",graph[i][j]);
      }
      printf("\n");
    }
    */
    struct timespec start1,start2,end1,end2;
    clock_gettime(CLOCK_REALTIME,&start1);
    mincost=tsp(graph,n);
    clock_gettime(CLOCK_REALTIME,&end1);
   printf("%d\n",mincost);
   time1=(end1.tv_sec-start1.tv_sec)+(double)(end1.tv_nsec-start1.tv_nsec)/nano;
   printf("%lf\n",time1);
}
