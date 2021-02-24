#include<stdio.h>

typedef long long ll;

int main(void){
  ll h , w , m;
  scanf("%lld %lld %lld",&h ,&w ,&m);
  
  ll xy[m][2];
  ll xbom[300010] = {0}, ybom[300010] = {0};

  for(int i = 0;i < m;i ++){
    scanf("%lld %lld",&xy[i][0] ,&xy[i][1]);
    xbom[xy[i][0]] ++;
    ybom[xy[i][0]] ++;
  }

  int xmax = 0 , ymax = 0;
  int ansx , ansy;
  for(int i = 0;i <= 300000;i ++){
    if(xmax < xbom[i]){
      xmax = xbom[i];
      ansx = i;
    }
    if(ymax < ybom[i]){
      ymax = ybom[i];
      ansy = i;
    }
  }

  int flag = 0;
  for(int i = 0;i < m;i ++){
    if(xy[i][0] == ansx && xy[i][1] == ansy){
      flag = 1;
    }
  }

  printf("%d\n",xmax + ymax - flag);

  return 0;

}