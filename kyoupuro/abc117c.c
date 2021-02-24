#include<stdio.h>

int up(const void *a,const void *b){
  return *(int *)a - *(int *)b;
}

int down(const void *a,const void *b){
  return *(int *)b - *(int *)a;
}

int main(void){
  int n , m;
  scanf("%d %d",&n,&m);

  int x[100010] , sa[100010];
  for(int i = 0;i < m;i ++){
    scanf("%d",&x[i]);
  }

  qsort(x,m,sizeof(int),up);
  
  for(int i = 0;i < m-1;i ++){
    sa[i] = x[i+1] - x[i];
  }

  qsort(sa,m-1,sizeof(int),down);
  int ans = 0 , min = 0;
  for(int i = 0;i < m-1;i ++){
    if(i < n-1){
      min += sa[i];
    }
    ans += sa[i];
  }

  printf("%d\n",ans-min);
  

  return 0;
}