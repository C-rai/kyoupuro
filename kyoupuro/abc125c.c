#include<stdio.h>

int l[100010] , r[100010];
int  lcm(int a,int b){
  if(a < b){
    int temp = b;
    b = a;
    a = temp;
  }

  if(b == 0){
    return a;
  }
  else{
    lcm(b,a%b);
  }
}

int main(void){
  int n , a[100010];
  scanf("%d",&n);

  for(int i = 0;i < n;i ++){
    scanf("%d",&a[i]);
  }

  
  l[0] = a[0];
  for(int i = 1;i < n-1;i ++){
    l[i] = lcm(l[i-1],a[i]);
    
  }

  
  r[n-1] = a[n-1];
  for(int i = n-2;i > 0;i --){
    r[i] = lcm(r[i+1],a[i]);
    
  }

  int ans = r[1];
  for(int i = 1;i <= n-2;i ++){
    //printf("%d %d\n",l[i-1],r[i+1]);
    if(ans < lcm(l[i-1],r[i+1])){
      ans = lcm(l[i-1],r[i+1]);
    }
  }

  if(ans < l[n-2]){
    ans = l[n-2];
  }

  printf("%d\n",ans);

  return 0;

}