#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define keta 4   /*答えの桁数*/
#define dousuu 1 /*同じ数は最大何個までか*/
#define syu 9   /*数字の最大値*/

int main(void){
  int r;
  int ans[keta];
  int check[syu+1] = {0} , count = 0;
	
	/*答えの生成*/
	srand( (unsigned)time( NULL ) );

  while(count < keta){
    r = rand()%syu+1;
    if(check[r] < dousuu){
      check[r] ++;
      ans[count] = r;
      count ++;
    }
  }

  for(int i = 0;i < keta;i ++){
    printf("%d",ans[i]);
  }

  putchar('\n');

  int flag = 1;
  int x , hint[keta];
  int hit = 0 , bu = 0;
  while(flag == 1){
    /*読み込み*/
    scanf("%d",&x);
    count = 0;
    int  waru = pow(10,keta-1);
    while(count < keta){
      hint[count] = x/waru;
      x %= waru;
      waru /= 10;
      //printf("%d\n",hint[count]);
      count ++;
    }

  /*判定*/
  int buro[syu+1] = {0};
  for(int i = 0;i < keta;i ++){
    /*hit*/
    if(check[hint[i]] > buro[hint[i]]){
      bu ++;
      buro[hint[i]] ++;

    }
    /*buro*/
    if(hint[i] == ans[i]){
      bu --;
      hit ++;
      }
    }
  
    printf("%dhit%dburo\n",hit,bu);
    if(hit == 4){
      flag = 0;
      printf("正解！\n");
    }
    hit = 0 , bu = 0;
  }

	return 0;
}