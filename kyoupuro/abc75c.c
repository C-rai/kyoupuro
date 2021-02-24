#include<stdio.h>

int n , m , a[2000] , b[2000];
int pass[60][60] = {0} , ans = 0 , visit[60] = {0};

void bfs(int sumi){
  int flag = 1;
  while(flag != 0){
    flag = 0;
      for(int i = 1;i <= n;i ++){
        if(visit[i] == 1)
        for(int j = 1;j <= n;j ++){
          if(pass[i][j] == 1 && visit[j] == 0){
            visit[j] = 1;
            flag = 1;
          }
        }
      }
    }
}

int main(void){
  
  scanf("%d %d",&n,&m);
  for(int i = 0;i < m;i ++){
    scanf("%d %d",&a[i],&b[i]);
    pass[a[i]][b[i]] = 1;
    pass[b[i]][a[i]] = 1;
  }

  int flag = 0;
  for(int i = 0;i < m;i ++){
    pass[a[i]][b[i]] = 0;
    pass[b[i]][a[i]] = 0;
    visit[1] = 1;
    bfs(0);
    for(int j = 1;j <= n;j ++){
      if(visit[j] == 0){
        flag = 1;
      }
      visit[j] = 0;
    }
    if(flag){
      ans ++;
      flag = 0;
    }
    pass[a[i]][b[i]] = 1;
    pass[b[i]][a[i]] = 1;

  }

  

    printf("%d\n",ans);

    return 0;
  }