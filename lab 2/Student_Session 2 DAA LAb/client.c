#include<stdlib.h>
#include<stdio.h>
#include"session2_strmatch.h"
#define MAXLENGTH 100
int main()
{
  char text[100], pattern[100];

  int position;
  //printf("Enter some text\n");
  scanf(" %[^\n]s",text);
  int n;

  //printf("Enter the number of times");
  scanf("%d",&n);

  int result;
  for(int i=0;i<n;i++)
  {
    //printf("Enter a string to find\n");
    scanf(" %[^\n]s",pattern);
    //printf("thanks for entering %s",pattern);
    result=strmatch_pattern(text,pattern);
    //printf("Matched at: %d",result);
    printf("%d\n",result);
  }
}
