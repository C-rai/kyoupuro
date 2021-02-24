#include<stdio.h>

#define IMF 998244353
typedef long long ll;
 
ll fib[10000] = {0};

int fibonacci(int start ,int end){
  fib[start] = fib[start-1] + fib[start-2];
  fib[start] %= IMF;

  if(start == end){
    return fib[end];
  }

  fibonacci(start+1,end);
}

int main(void){
  int n;
  scanf("%d",&n);

  fib[0] = 0 , fib[1] = 1;
  
  if(n == 0){
    printf("0\n");
  }

  else if(n == 1){
    printf("1\n");
  }

  else{
    ll ans = fibonacci(2,n);
    printf("%lld\n",ans);
  }

  return 0;
}