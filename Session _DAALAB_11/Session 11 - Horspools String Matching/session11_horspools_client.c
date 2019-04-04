#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int horspools_strmatch_pattern(char *text, char *pattern);

double time_elapsed(struct timespec *start, struct timespec *end);
int *horspools_strmatch_patterns(char *text, char **patterns, int t);

int main(){
	int i,l,n,*o;
	char *m,*a,*b,**p;
	struct timespec s,e;
	m=(char*)malloc(sizeof(char)*1024*1024);
	scanf("%[^\n]",m);getchar();
	l=0;while(m[l]!='\0')l++;a=(char*)malloc(sizeof(char)*(l+1));a[l]='\0';while(l--)a[l]=m[l];
	scanf("%d",&n);getchar();p=(char**)malloc(sizeof(char*)*n);//printf("done init\n");
	for(i=0;i<n;i++){
		scanf("%[^\n]",m);getchar();
		l=0;while(m[l]!='\0')l++;b=(char*)malloc(sizeof(char)*(l+1));b[l]='\0';while(l--)b[l]=m[l];//printf("s:%s\n",b);
		p[i]=b;
	}
	clock_gettime(CLOCK_REALTIME,&s);
	o=horspools_strmatch_patterns(a,p,n);
	clock_gettime(CLOCK_REALTIME,&e);
	for(i=0;i<n;i++){printf("%d\n",o[i]);free((void*)p[i]);
	}
	printf("%lf sec\n",time_elapsed(&s, &e));
	free((void*)o);free((void*)p);free((void*)a);free((void*)m);
	return 0;
}
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
/*int horspools_strmatch_pattern(char *text, char *pattern)
{
	int text_len = strlen(text);
	int pattern_len = strlen(pattern);
	int  i;
	int *table = (int*)malloc(sizeof(int)*300);
	for(i = 0 ; i<300; i++)
		table[i] = pattern_len;

	for(i = 0 ; i<pattern_len-1 ; i++)
		table[pattern[i]] = pattern_len-1-i;
	i = pattern_len - 1 ;
	int j = 0 ;
	while(i < text_len)
	{
		j = 0;
		while(j<pattern_len && text[i-j] == pattern[pattern_len-1-j])
			j = j + 1;
		if(j == pattern_len)
			return i-(pattern_len-1);
		i = i + table[text[i]];	
	}
	return -1; 
}

int *horspools_strmatch_patterns(char *text, char **patterns, int t)
{
	int *occurance=(int*)malloc(sizeof(int)*t);
	for(int i=0;i<t;i++)
		occurance[i]=horspools_strmatch_pattern(text, patterns[i]);
	return occurance;
}*/
