#include<stdio.h>
#include<math.h>


int main(void){
  int h,w,k;
  scanf("%d %d %d",&h,&w,&k);

  char c[10][10];
  int kuro[10][10] = {0};
  for(int i = 0;i < h;i ++){
    scanf("%s",c[i]);
  }

  for(int i = 0;i < h;i ++){
    for(int j = 0;j < w;j ++){
      if(c[i][j] == '#'){
        kuro[i][j] ++;
      }
    }
  }
  int tate[10] = {0},yoko[10] = {0},t,y,ta=0,yo=0;
  int zan = 0,ans = 0;
  for(int i = 0;i < pow(2,h);i ++){
    for(int j = 0;j < pow(2,w);j ++){
      t = i;
      y = j;
      ta = 0 , yo = 0;
      while(t > 0){
        tate[ta] = t%2;
        ta ++;
        t /= 2;
      }
      while(y > 0){
        yoko[yo] = y%2;
        yo ++;
        y /= 2;
      }
      
      for(int l = 0;l < h;l ++){
        for(int m = 0;m < w;m ++){
          if(tate[l] == 0 && yoko[m] == 0){
            zan += kuro[l][m];
          }
        }
      }
        //printf("%d\n",zan);
        if(zan == k){
          ans ++;
        }
        for(int p = 0;p < 7;p ++){
          tate[p] = 0;
          yoko[p] = 0;
        }
        zan = 0;
      }
    }

  printf("%d\n",ans);

  return 0;


}