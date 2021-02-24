#include<stdio.h>

#define IMF 1000000007
typedef long long ll;
ll up(const void *s,const void *t){
  return *(ll *)t - *(ll *)s;
}

ll min(ll q , ll r){
  if(q < r){
    return q;
  }
  else{
    return r;
  }
}

int main(void){
  int x , y , z , k;
  scanf("%d %d %d %d",&x ,&y ,&z ,&k);

  ll a[x] , b[y] , c[z];
  for(int i = 0;i < x;i ++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < y;i ++){
    scanf("%lld",&b[i]);
  }
  for(int i = 0;i < z;i ++){
    scanf("%lld",&c[i]);
  }

  qsort(a,x,sizeof(ll),up);
  qsort(b,y,sizeof(ll),up);
  qsort(c,z,sizeof(ll),up);

  ll tas[x+y] , count = 0;
  for(int i = 0;i < x;i ++){
    for(int j = 0;j < y;j ++){
      tas[count] = a[i] + b[j];
      count ++;
    }
  }

  qsort(tas,x+y,sizeof(ll),up);

  ll ans[k+1];
  int tascount = 0 , ccount = 0;
  count = 0;

  while(count < k){
    if()
  }

  return 0;
  
}