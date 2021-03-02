#include<stdio.h>

enum{
  A,
  C,
  G,
  T
};

int main(void){
  int n;
  scanf("%d",&n);

  int dp[110][5] = {0};
  
  for(int i = 0;i < 4;i ++){
    dp[0][i] = 1;
  }

  for(int i = 0;i < 110;i ++){
    for(int j = 0;j < 4;j ++){
      //A
      dp[i+1][A] += dp[i][j];
      //C
      //AGC
      if(j == G){
        if(i-1 >= 0){
          dp[i+1][C] -= dp[i-1][A];
        }
      }
      else{
        dp[i+1][C] += dp[i][j];
      }
      //G
      dp[i+1][G] += dp[i][j];
      //T
      dp[i+1][T] += dp[i][j];
    }
  }

  printf("%d\n",dp[n-1][A]+dp[n-1][G]+dp[n-1][C]+dp[n-1][T]);

  return 0;
  
}