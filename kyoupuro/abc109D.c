#include<stdio.h>

int main(void){
  int h , w;
  scanf("%d %d",&h ,&w);

  int a[50][50];
  for(int i = 1;i <= h;i ++){
    for(int j = 1;j <= w;j ++){
      scanf("%d",&a[i][j]);
      }
    }
  
  int ans[2500][4] , n = 0;
  for(int i = 1;i <= h;i ++){
    for(int j = 1;j < w;j ++){
      if(a[i][j]%2 == 1){
        a[i][j] --;
        a[i][j+1] ++;
        ans[n][0] = i;
        ans[n][1] = j;
        ans[n][2] = i;
        ans[n][3] = j + 1;
        n ++;
      }
    }
  }

  for(int i = 1;i < h;i ++){
    if(a[i][w]%2 == 1){
      a[i][w] --;
      a[i+1][w] ++;
      ans[n][0] = i;
      ans[n][1] = w;
      ans[n][2] = i+1;
      ans[n][3] = w;
      n ++;
    }
  }

  printf("%d\n",n);
  for(int i = 0;i < n;i ++){
    printf("%d %d %d %d\n",ans[i][0] , ans[i][1] , ans[i][2] , ans[i][3]);
  }

  return 0;
}
