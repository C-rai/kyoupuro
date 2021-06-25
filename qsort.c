#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100	/* N個のデータをソート */

void disp_a( int a[] )
{
	int i;

	for ( i = 0; i < N; ++i ) {
		printf( "%4d", a[ i ] );
	}
	printf( "\n" );
}

void disp_a2( int a[], int n )
{
	int i;

	for ( i = 0; i < n; ++i ) {
		printf( "%4d", a[ i ] );
	}
	printf( "\n" );
}


void q_sort(int a[],int n,int min,int max){
  int big[n],small[n];
  int aind = 0,bind = 0,sind = 0;
  int mid = (min+max)/2;
/*midより大きいのはbig 小さいのは*/
  for(int i = 0;i < n;i ++){
    if(a[i] >= mid){
      big[bind] = a[i];
      bind ++;
    }
    else{
      small[sind] = a[i];
      sind ++;
    }
  }
  /*再起部分*/
  if(bind > 1 && max-mid > 1){
    q_sort(big,bind,mid,max);
  }
  if(sind > 1 && mid-min > 1){
    q_sort(small,sind,min,mid);
  }
  /*ソート部分*/
  for(aind = 0;aind < bind;aind ++){
    a[aind] = big[aind];
  }
  for(aind;aind < (bind+sind);aind ++){
    a[aind] = small[aind-bind];
  }
  /*printf("----  sort ------\n");
	disp_a2(a,n);*/

}

int main()
{
	int a[N];
	int i;

	/* 乱数の初期化 */
	srand( (unsigned)time( NULL ) );

	/* 初期値の代入と表示 */
	for ( i = 0; i < N; ++i ) {
		a[ i ] = rand()%100 + 1;
	}
	disp_a( a );

	/* ここにソートの本体を書く */
  q_sort(a,N,0,100);
	
	/* 結果の表示 */
	disp_a( a );
}
