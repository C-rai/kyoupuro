#include<stdio.h>
 
int abs(int a,int b){
  if(a < b){
    int temp = a;
    a = b;
    b = temp;
  }
  if(b == 0){
    return a;
  }
  
  abs(b,a%b);
}
 
int main(void){
  int n , m;
  scanf("%d %d",&n ,&m);
 
  char s[n] , t[m];
  scanf("%s %s",s ,t);
 
  long long gcd = abs(n,m);
  long long gn = n/gcd , gm = m/gcd;
  
 
  int flag = 0;
  for(long long  i = 0;i < gcd;i ++){
    for(long long j = 0;j < gcd;j ++){
      if(gn*i == gm*j){
        //printf("%c %c\n",s[i],t[j]);
        if(s[i] != t[j]){
          flag = 1;
          i += n;
          j += m;
        }
      }
    }
  }
 
  if(flag == 0){
    printf("%lld\n",gn*gm*gcd);
  }
 
  else{
    printf("-1\n");
  }
 
  return 0;
}