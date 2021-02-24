#include<stdio.h>

int main(void){
  char s[20];
  scanf("%s",s);

  int ans = 0 , check[5] = {0},x,tas,keta = 0;

  for(int i = 0;s[i] != '\0';i ++){
    x = s[i] - '0';
    tas += x;
    check[x%3] ++;
    keta ++;
  }
  int flag = 0;
  if(tas%3 == 0){
    printf("0\n");
    flag = 1;
  }

  else if(tas%3 == 1){
    if(check[1] > 0 && keta > 1){
      printf("1\n");
      flag = 1;
    }
    else if(check[2] > 1 && keta > 2){
      printf("2\n");
      flag = 1;
    }
  }
  else if(tas%3 ==2){
    if(check[2] > 0 && keta > 1){
      printf("1\n");
      flag = 1;
    }
    else if(check[1] > 1 && keta > 2){
      printf("2\n");
      flag = 1;
    }
  }
  if(flag == 0){
    printf("-1\n");
  }

  return 0;
}