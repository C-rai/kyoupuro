#include<stdio.h>
int hon[11] = {0,2,5,5,4,5,6,3,7,6};
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);

  int a[10] = {0},x;
  for(int i = 0;i < m;i ++){
    scanf("%d",&x);
    a[x] = 1;
  }
  
  int dp[10010];
  for(int i = 0;i < 10010;i ++){
    dp[i] = -100000;
  }
  dp[0] = 0;
  for(int i = 0;i <= n;i ++){
    if(dp[i] != -100000){
      for(int j = 1;j <= 9;j ++){
        if(a[j] == 1){
          if(dp[i+hon[j]] <= dp[i]+1){
            dp[i+hon[j]] = dp[i]+1;
          }
        }
      }
    }
  }
  int k = n;

  while(k > 0){
    for(int i = 9;i > 0;i --){
      if(a[i] == 1){
        //printf("%d %d\n",dp[k],dp[k-hon[i]]);
        if(dp[k]-1 == dp[k-hon[i]] && k-hon[i] >= 0){
        printf("%d",i);
        k -= hon[i];
        i = 0;
      }
      }
    }
  }

  return 0;
}

