#include<stdio.h>

long long n;
int ans = 0;

void judge(long long a,int flag3,int flag5,int flag7){
  if(a <= n && flag3 == 1 && flag5 == 1 && flag7 == 1){
    ans ++;
  }

  if(n > 10*a){
    judge(10*a+3,1,flag5,flag7);
    judge(10*a+5,flag3,1,flag7);
    judge(10*a+7,flag3,flag5,1);
  }

}

int main(void){
  scanf("%lld",&n);

  judge(3,1,0,0);
  judge(5,0,1,0);
  judge(7,0,0,1);

  printf("%d\n",ans);

  return 0;
}