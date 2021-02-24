#include<stdio.h>

int main(void){
  long long n , time[6];
  long long min = 1000000000000000 , mini , ans;
  scanf("%lld",&n);

  for(int i = 0;i < 5;i ++){
    scanf("%lld",&time[i]);
    if(min > time[i]){
      min = time[i];
      mini = i;
    }
  }

  if(n%min != 0){
    ans = n/min + 5;
  }

  else{
    ans = n/min + 4;
  }

  printf("%lld\n",ans);

  return 0;

}