#include<stdio.h>

typedef long long ll;
#define lim 1000000007

int main(void){
  ll n , m , a[100010];
  scanf("%lld %lld",&n ,&m);

  for(int i = 0;i < m;i ++){
    scanf("%lld",&a[i]);
  }

  ll dp[100010] = {0};
  for(int i = 0;i < m;i ++){
    dp[a[i]] = -1;
  }

  if(dp[1] == 0){
    dp[1] = 1;
    if(dp[2] == 0){
      dp[2] = 2;
    }
  }

  else if(dp[2] == 0){
    dp[2] = 1;
  }

  for(int i = 3;i <= n;i ++){
    if(dp[i] != -1){
      if(dp[i-1] != -1){
        dp[i] += dp[i-1];
        dp[i] %= lim;
      }
      if(dp[i-2] != -1){
        dp[i] += dp[i-2];
        dp[i] %= lim;
      }
    }
  }

  printf("%lld\n",dp[n]);

  return 0;


}