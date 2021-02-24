#include<stdio.h>

typedef long long ll;

ll min(ll a,ll b){
  if(a < b){
    return a;
  }
  else{
    return b;
  }
}

ll ab(ll a){
  if(a > 0){
    return a;
  }
  else{
    return -a;
  }
}


int main(void){
  int a,b,q;
  scanf("%d %d %d",&a,&b,&q);

  ll s[100010],t[100010],x[100010];
  for(int i = 0;i < a;i ++){
    scanf("%lld",&s[i]);
  }
  for(int i = 0;i < b;i ++){
    scanf("%lld",&t[i]);
  }
  for(int i = 0;i < q;i ++){
    scanf("%lld",&x[i]);
  }

  ll ans,ans1,ans2,sl,sr,smid,tl,tr,tmid,mid,goal,stop;
  for(int i = 0;i < q;i ++){
    /*先に神社*/
    sr = 0,sl = a-1;
    while(sl-sr < 1){
      smid = (sr+sl)/2;
      if(s[smid] < x[i]){
        sr = smid;
      }
      else{
        sl = smid;
      }
    }
    
    if(ab(s[sr]-x[i]) < ab(s[sl]-x[i])){
      mid = ab(s[sr]-x[i]);
      stop = s[sr];
    }
    else{
    	mid = ab(s[sl]-x[i]);
      stop = s[sl];
    }
    
    tr = 0; tl = b-1;
    while(tl-tr < 1){
      tmid = (tr+tl)/2;
      if(t[tmid] < mid){
        tr = tmid;
      }
      else{
        tl = tmid;
      }
    }
    goal = min(ab(stop-t[tr]),ab(stop-t[tl]));
    ans1 = mid + goal;

    /*先に寺*/
    tr = 0,tl = b-1;
    while(tl-tr < 1){
      tmid = (tr+tl)/2;
      if(t[tmid] < x[i]){
        tr = tmid;
      }
      else{
        tl = tmid;
      }
    }
   
     if(ab(t[tr]-x[i]) < ab(t[tl]-x[i])){
      mid = ab(t[tr]-x[i]);
      stop = t[tr];
      }
    else{
    	mid = ab(t[tl]-x[i]);
      stop = t[tl];
      }
    
    sr = 0; sl = a-1;
    while(sl-sr < 1){
      smid = (sr+sl)/2;
      if(s[smid] < mid){
        sr = smid;
      }
      else{
        sl = smid;
      }
    }
    goal = min(ab(stop-s[sr]),ab(stop-s[sl]));
    ans2 = mid+goal;
    /*答え*/
    ans = min(ans1,ans2);
    printf("%lld\n",ans);
  }

  return 0;
}