#include<stdio.h>

long long ans = 0;
int l , mae = 0;
int a, n;

int dp(int a,int n){
  if(a <= 0){
    return 0;
  }
  for(int i = 1;i <= a-(11-n);i ++){
    a -= i;
    n ++;
    //printf("%d %d %d\n",n,i,a);
    if(n == 11){
    ans += a;
    return 0;
   }
    else dp(a,n);
    n --;
    a += i;
  }
  
}

int main(void){
  scanf("%d",&l);

int dfs[12][200] = {0};
for(int i = 0;i < 12;i ++){
  for(int j = 0;j < 200;j ++){
    dfs[i][j] = -1;
  }
}

for(int i = 0;i <= l;i ++){
  dfs[0][i] = 0;
}

  for(int i = 0;i < 11;i ++){
    for(int j= 1;j <= l;j ++){
      if(l-j > 0 && dfs[i][j] == 0){
        dfs[i+1][l-j] = 0;
      }
    }
  }

  for(int i = 0;i <= l;i ++){
    if(dfs[11][i] == 0){
      ans += dfs[11][i];
    }
  }
  printf("%lld\n",ans);



  return 0;

}