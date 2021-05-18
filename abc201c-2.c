#include<stdio.h>

int main(void){
  char s[11];
  scanf("%s",s);

  int maru = 0,batu = 0,que = 0;
  int mcheck[10] = {0},bcheck[10] = {0};
  for(int i = 0;i < 10;i ++){
    if(s[i] == 'o'){
      maru ++;
      mcheck[i] ++;
    }
    else if(s[i] == 'x'){
      batu ++;
      bcheck[i] ++; 
    }
    else{
      que ++;
    }
  }
  int sum[10] = {0},flag = 1;
  int ans = 0;
  for(int i = 0;i < 10;i ++){
    for(int j = 0;j < 10;j ++){
      for(int k = 0;k < 10;k ++){
        for(int l = 0;l < 10;l ++){
          sum[i] ++;
          sum[j] ++;
          sum[k] ++;
          sum[l] ++;
          for(int m = 0;m < 10;m ++){
            if(mcheck[m] > 0){
              sum[m] --;
            }
            else if(bcheck[m] > 0){
              sum[m] *= -1;
            }
            if(sum[m] < 0){
              flag = 0;
            }
          }
          if(flag){
            ans ++;
          }
          flag = 1;
          for(int p = 0;p < 10;p ++){
            sum[p] = 0;
          }
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}