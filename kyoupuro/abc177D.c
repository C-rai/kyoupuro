#include<stdio.h>

int par[200001];
int siz[200001];

void init(int n){
  for(int i = 0;i < n;i ++){
    par[i] = i;
    siz[i] = 0;
  }
}

int root(int x){
  int count = 0 , s[200001];
  if(par[x] == x){
    for(int i = 0;i < count;i ++){
      par[s[i]] = x;
    }
    return x;
  }
  else{
    s[count] = par[x];
    count ++;
    return par[x] = root(par[x]);
  }
}

void unit(int x,int y){
  x = root(x);
  y = root(y);
  if(x != y){
    if(siz[x] >= siz[y]){
      par[y] = x;
      siz[y] = siz[x];
    }
    else{
      par[x] = y;
      siz[y] += siz[x];
    }
  }
}

int max(int x,int y){
  if(x >= y){
    return x;
  }
  else{
    return y;
  }
}

int main(void){
  int n, m ,a , b , ma = 0;
  scanf("%d %d",&n ,&m);
  init(n);

  for(int i = 0;i < m;i ++){
    scanf("%d %d",&a,&b);
    unit(a,b);
  }

  for(int i = 1;i <= n;i ++){
    ma = max(ma,size(i));
  }

  printf("%d",ma);

  return 0;
}