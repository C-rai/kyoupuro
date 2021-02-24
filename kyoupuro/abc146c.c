#include<stdio.h>

typedef long long ll;
#define IMF 1000000000
ll a ,b ,x; 
ll keta(ll x){
  ll k = 1;
  ll y = x;
  while(y/10 != 0){
    k ++;
    y /= 10;
  }

  return k;
}



int main(void){
  scanf("%lld %lld %lld",&a,&b,&x);


  ll l = 0 , r = IMF;

  if(a*IMF + b*keta(IMF) <= x){
    l = IMF;
  }

  else{
   ll mid;
   while(r-l > 1){
     mid = (l+r)/2;
     if(a*mid + b*(keta(mid)) <= x){
       l = mid;
     } 
     else{
       r = mid;
     }
    }
  }


  printf("%lld\n",l);

  return 0;


}