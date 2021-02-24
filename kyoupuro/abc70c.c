#include<stdio.h>

typedef unsigned long long  ll;

ll gcm(ll a,ll b){
  if(a < b){
    ll temp = a;
    a = b;
    b = temp;
  }

  if(b == 0){
    return a;
  }

  gcm(b,a%b);
}

int main(void){
  int n;
  scanf("%d",&n);

  ll t[110];
  for(int i = 0;i < n;i ++){
    scanf("%lld",&t[i]);
  }

  ll ans = gcm(t[0],t[1]);
  //printf("%lld\n",ans);
  ans = t[0]/ans*t[1];
  
  for(int i = 2;i < n;i ++){
    ll temp = ans;
    ans = temp/gcm(temp,t[i]);
    ans *= t[i];
  }
  printf("%lld\n",ans);


  return 0;
  
}