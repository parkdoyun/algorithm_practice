#include <iostream>

using namespace std;

// 백준 5569 - 출근 경로
// DP
// 골드 4

// 내 전의 2개의 정점 봐야 함
// DP1[i][j] : i, j로부터 위로 가는 애들
// DP2[i][j] : i, j로부터 오른쪽으로 가는 애들
// DP1[i][j] = DP1[i - 1][j] + DP2[i][j - 2]
// DP2[i][j] = DP2[i][j - 1] + DP1[i - 2][j]

int w, h;
int DP1[101][101];
int DP2[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h;

	// 예외
	if (w == 1 && h == 1)
	{
		cout << 1;
		return 0;
	}

	// 기저 조건
	for (int i = 1; i <= w; i++)
	{
		DP1[1][i] = 1;
	}
	for (int j = 1; j <= h; j++)
	{
		DP2[j][1] = 1;
	}

	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			if (i == h && j == w)
			{
				DP1[i][j] = DP1[i - 1][j];
				DP2[i][j] = DP2[i][j - 1];
				break;
			}
			DP1[i][j] = (DP1[i - 1][j] + DP2[i][j - 2]) % 100000;
			DP2[i][j] = (DP2[i][j - 1] + DP1[i - 2][j]) % 100000;
		}
	}

	cout << (DP1[h][w] + DP2[h][w]) % 100000; // 마지막 출력 시 중복되는 것 빼야 함

	return 0;
}