#include<stdio.h>

int main(void){
  
  char s[100000];
  scanf("%s",s);

  int countz = 0,counto = 0,ans = 0;
  for(int i = 0;s[i] != '\0';i ++){
    if(s[i] == '0'){
      countz ++;
      if(counto > 0){
        countz --;
        counto --;
        ans += 2;
      }
    }
    if(s[i] == '1'){
      counto ++;
      if(countz > 0){
        countz --;
        counto --;
        ans += 2;
      }
    }
  }

  printf("%d\n",ans);

  return 0;
}