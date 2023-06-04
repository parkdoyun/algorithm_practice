#include <iostream>
#include <algorithm>

using namespace std;

// 백준 2240 - 자두나무
// DP
// 골드 5

// 건너느냐 안 건너느냐
// 점화식
// i회 건넘, j초 
// i) 건너는 경우 1 -> 2 : DP2[i][j] = max(DP2[i][j], DP1[i - 1][j - 1] + apple[1][j]);
// ii) 건너는 경우 2 -> 1 : DP1[i][j] = max(DP1[i][j], DP2[i - 1][j - 1] + apple[0][j]);
// iii) 안 건너는 경우 1 : DP1[i][j] = max(DP1[i][j], DP1[i][j - 1] + apple[0][j]);
// iv) 안 건너는 경우 2 : DP2[i][j] = max(DP2[i][j], DP2[i][j - 1] + apple[1][j]);

// 예외 : 1초에도 다른 자두나무로 건널 수 있음

int t, w;
int apple[2][1001];
int DP1[31][1001];
int DP2[31][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t >> w;

	int a;
	for (int i = 1; i <= t; i++)
	{
		cin >> a;
		if (a == 1) apple[0][i] = 1;
		else apple[1][i] = 1;
	}

	// DP
	// 기저 조건
	DP1[0][1] = apple[0][1];
	DP2[1][1] = apple[1][1]; // 예외 처리

	for (int i = 2; i <= t; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (j >= 1)
			{
				DP2[j][i] = max(DP2[j][i], DP1[j - 1][i - 1] + apple[1][i]);
				DP1[j][i] = max(DP1[j][i], DP2[j - 1][i - 1] + apple[0][i]);
			}
			DP1[j][i] = max(DP1[j][i], DP1[j][i - 1] + apple[0][i]);
			DP2[j][i] = max(DP2[j][i], DP2[j][i - 1] + apple[1][i]);
		}
	}

	int res = 0;
	for (int i = 0; i <= w; i++)
	{
		res = max(res, DP1[i][t]);
		res = max(res, DP2[i][t]);
	}

	cout << res;

	return 0;
}