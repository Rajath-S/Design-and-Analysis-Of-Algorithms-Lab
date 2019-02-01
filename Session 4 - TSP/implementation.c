#include"session4_tsp.h"
#include<math.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
int tsp(int** graph, int n)
{
	int mincost=INT_MAX;
	int cost;
	//int Permutation[n-1];
	int* Permutation=(int*)malloc(sizeof(int)*(n-1));
	for(int i=0;i<n-1;i++)
	{
		Permutation[i]=i+1;
		}
	
	do{
		cost=graph[0][Permutation[0]];
		cost=cost+graph[Permutation[n-2]][0];
		for(int i=0;i<=n-3;i++)
		{
			cost=cost+graph[Permutation[i]][Permutation[i+1]];
		}
		if(cost<mincost)
			mincost=cost;
	}while(get_next_permutation(Permutation,n-1));
	return mincost;
	
}
	
	
	
	
int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}
