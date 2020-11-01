#include<stdio.h>

int main(void){
  int n;
  scanf("%d",&n);

  double x[n+1] , y[n+1];
  for(int i = 0;i < n;i ++){
    scanf("%lf %lf",&x[i],&y[i]);
    //printf("%d %d\n",&x[i],&y[i]);
  }

  double a , b;
  int flag = 0;
  for(int i = 0;i < n-2;i ++){
    for(int j = i+1;j < n-1;j ++){
      a = (y[j]-y[i])/(x[j]-x[i]);
      b = y[i] - a*x[i];
      if(x[j] == 0 && x[i] == 0){
        a = 99999999;
      }
      for(int k = j+1;k < n;k ++){
        if(y[k] == a*x[k] + b){
          flag = 1;
          i = j = k = n;
        }
        if(x[i] == x[j] && x[j] == x[k]){
          flag = 1;
          //printf("%d %d %d\n",i,j,k);
          i = j = k = n;
        }
      }
    }
  }

  if(flag == 1){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }

  return  0;
}