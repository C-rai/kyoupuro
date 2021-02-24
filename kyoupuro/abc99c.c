#include<stdio.h>

#define max 100000

int main(void){
  int n;
  scanf("%d",&n);

  int dp[max+10] = {0};
  for(int i = 0;i < max+10;i ++){
    dp[i] = i;
  }

  int tas = 1;
  while(tas < max){
    tas *= 6;
    for(int i = 0;i < max;i ++){
      if(dp[i+tas] > dp[i]+1){
        dp[i+tas] = dp[i]+1;
      }
    }
  }
  tas = 1;
  while(tas < max){
    tas *= 9;
    for(int i = 0;i < max;i ++){
      if(dp[i+tas] > dp[i]+1){
        dp[i+tas] = dp[i]+1;
      }
    }
  }

  printf("%d\n",dp[n]);

  return 0;

}