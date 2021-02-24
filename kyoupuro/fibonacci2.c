#include<stdio.h>

#define IMF 100000000
typedef long long ll;

int fib[10000] = {0};
int fibdp(int max){
  if(max == 0){
    return 0;
  }
  if(max == 1){
    return 1;
  }

  for(int i = 2;i <= max;i ++){
    fib[i] = fib[i-1] + fib[i-2];
  }

  return fib[max];
}

int main(void){
  int n;
  scanf("%d",&n);

  int ans = fibdp(n);

  return 0;
}