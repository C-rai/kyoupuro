#include <stdio.h>

#define Mod 1000000007

int main()
{
	int N;
	scanf("%d", &N);
	
	int i, j, k, l;
	long long dp[101][4][4][4] = {};
	for (j = 0; j < 4; j++) {
		for (k = 0; k < 4; k++) {
			for (l = 0; l < 4; l++) dp[3][j][k][l] = 1;
		}
	}
	dp[3][0][1][2] = 0;
	dp[3][0][2][1] = 0;
	dp[3][2][0][1] = 0;
	for (i = 4; i <= N; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				for (l = 0; l < 4; l++) {
					if (j == 0 && k == 1 && l == 2) continue;
					else if (j == 0 && k == 2 && l == 1) continue;
					else if (j == 2 && k == 0 && l == 1) continue;
					
					if ((k == 2 && l == 1) || (j == 2 && l == 1)) dp[i][j][k][l] = (dp[i-1][1][j][k] + dp[i-1][2][j][k] + dp[i-1][3][j][k]) % Mod;
					else dp[i][j][k][l] = (dp[i-1][0][j][k] + dp[i-1][1][j][k] + dp[i-1][2][j][k] + dp[i-1][3][j][k]) % Mod;
				}
			}
		}
	}
	
	long long ans = 0;
	for (j = 0; j < 4; j++) {
		for (k = 0; k < 4; k++) {
			for (l = 0; l < 4; l++) ans += dp[N][j][k][l];
		}
	}
	printf("%lld\n", ans % Mod);
	fflush(stdout);
	return 0;
}