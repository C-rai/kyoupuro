#include<stdio.h>

int main(void){
  int n;
  char s[5010];
  scanf("%d %s",&n ,s);

  int a[5010] = {0} , t[5010] = {0} , g[5010] = {0} , c[5010] = {0};
  for(int i = 0;s[i] != '\0';i ++){
    if(s[i] == 'A'){
      a[i] ++;
    }
    else if(s[i] == 'T'){
      t[i] ++;
    }
    else if(s[i] == 'G'){
      g[i] ++;
    }
    else if(s[i] == 'C'){
      c[i] ++;
    }
    a[i+1] = a[i];
    t[i+1] = t[i];
    g[i+1] = g[i];
    c[i+1] = c[i];
  }

  int coa ,cot ,cog ,coc;
  int count = 0;
  for(int i = 0;s[i] != '\0';i ++){
    for(int j = n;j > i;j --){
      coa = 2*a[n] - a[i]-a[j];
      cot = 2*t[n] - t[i]-t[j];
      cog = 2*g[n] - g[i]-g[j];
      coc = 2*c[n] - c[i]-c[j];

      if(coa == cot && cog == coc){
        count ++;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}