#include<stdio.h>

typedef long long ll;
#define IMF 1000000007

int main(void){
  ll n , m;
  scanf("%lld %lld",&n ,&m);

  int yakusu[500][2] = {0} , kosu = 0;

  ll waru = m, count = 2;
  while(waru != 1){
    while(waru%count == 0){
      waru %= count;
      yakusu[kosu][0] = count;
      yakusu[kosu][1] ++; 
    }
    count ++;
    kosu ++;
  }


  


  

  
}