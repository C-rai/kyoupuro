#include<stdio.h>

int abs(int a,int b){
  if(a < b){
    return b-a;
  }
  else{
    return a-b;
  }
}

int lcm(int a,int b){
  if(a < b){
    int temp = a;
    a = b;
    b = temp;
  }

  if(b == 0){
    return a;
  }

  else{
    lcm(b,a%b);
  }
}

int main(void){
  int n , x;
  scanf("%d %d",&n,&x);

  int town[100010] , sa[100010];
  for(int i= 0;i < n;i ++){
    scanf("%d",&town[i]);
    sa[i] = abs(town[i],x);
  }

  int min = lcm(sa[0],sa[1]);
  int temp;
  for(int i = 2;i < n;i ++){
    temp = min;
    min = lcm(temp,sa[i]);
  }

  printf("%d\n",min);

  return 0;
}