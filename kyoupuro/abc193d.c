#include<stdio.h>
#include<math.h>


int main(void){
  double n;
  scanf("%lf",&n);
  char s[6],t[6];
  scanf("%s %s",s,t);

  int checks[10] = {0},checkt[10] = {0},total[10] = {0},flag = 1;
  double sp[10] = {0},tp[10] = {0};
  int sscore = 0,tscore = 0; 
  double ans = 0 , kei = 9*n-8;
  for(int i = 0;i < 4;i ++){
    checks[s[i]-'0'] ++;
    sp[s[i]-'0'] ++;
    checkt[t[i]-'0'] ++;
    tp[t[i]-'0'] ++;
    total[s[i]-'0'] ++;
    total[t[i]-'0'] ++;
  }

  for(int j = 1;j <= 9;j ++){
    for(int k = 1;k <= 9;k ++){
      checks[j] ++;
      checkt[k] ++;
      total[j] ++;
      total[k] ++;
      for(int i = 1;i <= 9;i ++){
        sscore += i*pow(10,checks[i]);
        tscore += i*pow(10,checkt[i]); 
      }
      if(sscore > tscore){
        for(int p =1;p <= 9;p ++){
          if(total[p] > n){
            flag = 0;
          }
        }
        if(flag == 1){
         double a=n-tp[j]-sp[j],b=n-tp[k]-sp[k];
         ans += a/kei * b/(kei-1);
        }
      }
      checks[j] --;
      checkt[k] --;
      total[j] --;
      total[k] --;
      sscore = 0;
      tscore = 0;
      flag = 1;
    }
  }


  printf("%f\n",ans);
  return 0;

}