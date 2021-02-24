#include<stdio.h>

int main(void){
  int n;
  scanf("%d",&n);
  int f[110][11] , p[110][11];

  for(int i = 0;i < n;i ++){
    for(int j = 1;j <= 10;j ++){
      scanf("%d",&f[i][j]);
    }
  }

  for(int i = 0;i < n;i ++){
    for(int j = 0;j <= 10;j ++){
      scanf("%d",&p[i][j]);
    }
  }

  int open[12] = {0} , tas = 1;
  int check[110] = {0} , max = -1000000000 , kei = 0;
  for(int i = 1;i < 1024;i ++){
    int temp = i;
    while(temp != 0){
      open[tas] = temp%2;
      temp /= 2;
      tas ++;
    }
    

    for(int j = 0;j < n;j ++){
      for(int k = 1;k <= 10;k ++){
        if(open[k] == 1 && f[j][k] == 1){
          check[j] ++;
        }
      }
    }

    for(int j = 0;j < n;j ++){
      kei += p[j][check[j]];
      check[j] = 0;
    }

    if(kei > max){
      max = kei;
    }
    tas = 1;
    kei = 0;
  }
  printf("%d\n",max);

  return 0;
}