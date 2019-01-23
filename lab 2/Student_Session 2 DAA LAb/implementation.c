#include "session2_strmatch.h"
#include<string.h>
int strmatch_pattern(char *text, char *pattern)
{
  int m=strlen(pattern);
  int n=strlen(text);
  for(int i=0;i<n-m;i++)    //sliding pattern
  {
    int j=0;
    while(j<m&& (pattern[j]==text[i+j]))   //checking if pattern is matched by looping till end of pattern
    {
      j=j+1;
    }
    if(j==m)           //successfully matched
      return i;
  }
  return -1;
}

// int *strmatch_patterns(char *text, char **patterns, int t)
// {
//   int m=strlen(pattern);
//   int n=strlen(text);
// }
