#include<cstdio>
#include<iostream>
#define MAX 500

using namespace std;

int map[MAX][MAX] = { 0, };
int dp[MAX][MAX] = { 0, };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0 , 0 };
int n;
int day = 0;

int solve(int x, int y) {
	if (dp[x][y])
		return dp[x][y];

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
			if (map[x][y] < map[nx][ny]) {
				dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
			}
		}
	}
	return dp[x][y];
}


int main()
{
	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			day = max(day, solve(i, j));
		}
	}
	printf("%d", day);

	return 0;
}
