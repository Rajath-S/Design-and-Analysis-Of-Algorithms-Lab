#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//char string[100000];
	char ignore;
	int a = 10485760;
	char *string = (char *)malloc(a*sizeof(char*));
	scanf("%[^\n]%c", string, &ignore);
	//printf("\n\n%s\n", string);
	int t;
	scanf("%d", &t);
	char *sub_str = (char *)malloc(a*sizeof(char*));
	
	for(int I=0; I<t; I++)
	{
		int found = 0;
		//char sub_str[10000];
		scanf("\n");
		scanf("%[^\n]", sub_str);
		int m = strlen(sub_str);
		int n = strlen(string);
		for(int i=0; i<=n-m; i++)
		{
			int j=0;
			while((j<m) && (sub_str[j] == string[i+j]))
				j++;
			if(j==m)
			{
				printf("%d\n", i);
				found = 1;
				break;
			}
		}
		if(found == 0)
			printf("-1\n");
	}
	//printf("0.123456 sec\n");
	return 0;
}
