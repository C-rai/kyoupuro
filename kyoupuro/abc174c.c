#include<stdio.h>

int main(void){
  int n,a[100001],flag=0;
 
  scanf("%d",&n);

  a[1] = 7%n;
  for(int i=2;i <= n;i ++){
    a[i] = (a[i-1]*10+7)%n;
  }

  for(int i = 1;i <= n;i ++){
    if(a[i] == 0){
      printf("%d\n",i);
      flag = 1;
      i += n;
    }
  }

  if(flag == 0){
    printf("-1\n");
  }

  return 0;
}