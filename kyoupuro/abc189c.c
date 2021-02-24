#include<stdio.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  else{
    return b;
  }
}

int main(void){
  int n , a[10010];

  scanf("%d",&n);
  for(int i = 0;i < n;i ++){
    scanf("%d",&a[i]);
  }

  int min , ans = 0;
  for(int i = 0;i < n;i ++){
    min = a[i];
    for(int j = i;j < n;j ++){
      if(min > a[j]){
        min = a[j];
      }
      if(ans < min*(j-i+1)){
        ans = min*(j-i+1);
      }
    }
  }

  printf("%d\n",ans);

  return 0;
}
