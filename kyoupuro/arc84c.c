#include<stdio.h>
#include<stdlib.h>

int down(const void *x,const void *y){
  return  *(int *)x - *(int *)y;
}

int main(void){
  int n;
  scanf("%d",&n);

  int a[10001],b[10001],c[10001];
  for(int i = 0;i < n;i ++){
    scanf("%d",&a[i]);
  }
  for(int i = 0;i < n;i ++){
    scanf("%d",&b[i]);
  }
  for(int i = 0;i < n;i ++){
    scanf("%d",&c[i]);
  }

  qsort(a,n,sizeof(int),down);
  qsort(b,n,sizeof(int),down);
  qsort(c,n,sizeof(int),down);
  int l_a,r_a,l_c,r_c,mid_a,mid_c;
  int ans = 0;
  for(int i = 0;i < n;i ++){
    l_a = 0,r_a = n-1;
    while(r_a - l_a > 1){
      mid_a = (l_a+r_a)/2;
      if(a[mid_a] < b[i]){
        l_a = mid_a;
      }
      else{
        r_a = mid_a;
      }
    }
    l_c = 0,r_c = n-1;
    while(r_c-l_c > 1){
      mid_c = (l_c+r_c)/2;
      if(c[mid_c] < b[i]){
        l_c = mid_c;
      }
      else{
        r_c = mid_c;
      }
    }
    printf("%d %d\n",r_a,l_c);
    ans += (r_a+1) * (l_c+1);
  }
  printf("%d\n",ans);

  return 0;
}