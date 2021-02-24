#include<stdio.h>

int main(void){
  int n,a;
  scanf("%d %d",&n,&a);

  int k,x[51];
  for(int i = 0;i < n;i ++){
    scanf("%d",&k);
    x[i] = k-a;
  }

 int plus[2510],mias[2510],ans = 0;

 for(int i = 0;i < 2510;i ++){
   plus[i] = -1;
   mias[i] = -1;
 }
 plus[0] = 0;
 mias[0] = 0;

 for(int i = 0;i < n;i ++){
   for(int i = 0;i <= 2500;i ++){
     if(plus[i] != -1){
       if(i+x[i] == 0){
         ans += plus[i];
       }
       else if(i+x[i] > 0){
         if(plus[i]+1 > plus[])
       }
     }
   }
 }




}