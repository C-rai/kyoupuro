#include<stdio.h>

typedef long long ll;

ll ab(ll a){
  if(a > 0){
    return a;
  }
  else{
    return -a;
  }
}

int main(void){
  ll x,k,d;
  ll ans;
  scanf("%lld %lld %lld",&x,&k,&d);

  if(ab(x) >= ab(k*d)){
    ans = ab(ab(x)-ab(k*d));
  }

  else{
    if((k-(x/d))%2 == 0){
      ans = ab(x%d);
    }
    else{
      ans = ab(ab(x%d)-d);
    }
  }

  printf("%lld\n",ans);

  return 0;
}