#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,k;

  scanf("%d",&n);
  Data arr1[n],arr2[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]->id);
    scanf("%d",&arr[i]->value);
  }
  for(int i=0;i<n;i++)
  {
    arr2[i]->id=arr1[i]->id;
    arr2[i]->value=arr1[i]->value;
  }

  scanf("%d",&k);
  Data* ptrToArrayK1,ptrToArrayK2;
  ptrToArrayK1=BubbleSort(&arr1,n,k)//returns copy of arr after k iterations
  for(i=0;i<n;i++)
  {
    printf("%d ",ptrToArrayK1[i]->id);
    printf("%d\n",ptrToArrayK1[i]->value);
  }
  ptrToArrayK2=SelectionSort(&arr2,n,k)//returns copy of arr after k iterations
  for(i=0;i<n;i++)
  {
    printf("%d ",ptrToArrayK2[i]->id);
    printf("%d\n",ptrToArrayK2[i]->value);
  }

}
