#include<stdio.h>

#define IMF 998244353
typedef long long ll;

int n , k , rute[200010] = {0};


int main(void){
  scanf("%d %d",&n ,&k);

  int l[k] , r[k];
  for(int i = 0;i < k;i ++){
    scanf("%d %d",&l[i] ,&r[i]);

    for(int j = l[i];j <= r[i];j ++){
      rute[j] = 1;
    }
  }

  int tas[200020] , count = 0;
  for(int i = 1;i <= n;i ++){
    if(rute[i] == 1){
      tas[count] = i;
      count ++;
    }
  }

  int flag = 1;
  int dp[200020] = {0};

  for(int i = 0;i < n;i ++){
    dp[i] = -1;
  }

  dp[1] = 0;

    for(int i = 1;i <= n;i ++){
      if(dp[i] != -1){
        for(int j = 0;j < count;j ++){
          if(i + tas[j] <= n){
            flag = 1;
            if(dp[i] == -1){
              dp[i+tas[j]] = 0;
            }
            dp[i+tas[j]] += (dp[i]+1)%IMF;
            dp[i+tas[j]] %= IMF;
          }
        }
      }
    }

  printf("%lld\n",dp[n]);

}