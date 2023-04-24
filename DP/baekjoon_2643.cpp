#include <iostream>
#include <algorithm>

using namespace std;

// 백준 2643 - 색종이 올려 놓기
// DP
// 골드 4

// 색종이 크기로 DP
// 점화식
// i * j 크기까지의 색종이 갯수 = max((i-1)*(j-1) 크기까지의 갯수, (i)*(j-1) 크기까지의 갯수, (i-1)*(j) 크기까지의 갯수)
// 만약 i*j 크기의 색종이가 존재한다면 DP[i][j]++

int n;
int DP[1001][1001];
int paper[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		paper[a][b] = 1;
		paper[b][a] = 1;
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			DP[i][j] = max(DP[i - 1][j - 1], DP[i][j - 1]);
			DP[i][j] = max(DP[i][j], DP[i - 1][j]);
			if (paper[i][j] == 1) // 종이 있다면
			{
				DP[i][j]++;
			}
		}
	}

	cout << DP[1000][1000];

	return 0;
}