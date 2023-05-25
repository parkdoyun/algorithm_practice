#include <iostream>

using namespace std;

// 백준 12785 - 토쟁이의 등굣길
// DP
// 실버 1

// 집에서 토스트 가게까지의 가짓수 * 토스트 가게부터 학교까지의 가짓수
// DP[i][j] = DP[i - 1][j] + DP[i][j - 1];

int w, h;
int ty, tx; // 토스트 가게 위치
long long int DP[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h >> tx >> ty;
	
	// 기저 조건
	DP[1][1] = 1;

	// 집에서 토스트 가게까지
	for (int i = 1; i <= ty; i++)
	{
		for (int j = 1; j <= tx; j++)
		{
			if (i == 1 && j == 1) continue;
			DP[i][j] = (long long int)(DP[i][j - 1] + DP[i - 1][j]) % (long long int)(1000007);
		}
	}

	// 토스트 가게부터 학교까지
	for (int i = ty; i <= h; i++)
	{
		for (int j = tx; j <= w; j++)
		{
			if (i == ty && j == tx) continue;
			DP[i][j] = (long long int)(DP[i][j - 1] + DP[i - 1][j]) % (long long int)(1000007);
		}
	}

	cout << DP[h][w];

	return 0;
}