#include<stdio.h>

int main(void){
  int  n , x; 
  int  v[1010],p[1010];
  scanf("%d %d",&n,&x);

  for(int i = 0;i < n;i ++){
    scanf("%d %d",&v[i],&p[i]);
  }

  int ans = -1;
  double sake = 0;
  for(int i = 0;i < n;i ++){
    sake += v[i]*p[i];
    //printf("%f\n",sake);
    if(sake > x*100){
      ans = i+1;
      i += 10000000;
    }
  }

  printf("%d\n",ans);
  

  
  return 0;
}