#include <iostream>
#include <cmath>

using namespace std;

// 백준 9764 - 서로 다른 자연수의 합
// DP
// 실버 1

// 모든 i는 ceil(i / 2)까지 확인하면 됨
// DP[k][i] = i번째 수, 해당 식을 이루는 가장 작은 수가 k
// i - k번째에서 식을 이루는 가장 작은 수가 무조건 k 초과여야 함  

// 점화식
// DP[k][i] = sum(DP[k 초과][i - k]);

int n;
int DP[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 먼저 DP 수행

	// 기저 조건
	DP[1][1] = 1;

	// DP
	for (int i = 2; i <= 2000; i++)
	{
		for (int j = i - 1; j >= ceil(i / 2); j--)
		{
			for (int k = i - j + 1; k <= j; k++)
			{
				DP[i - j][i] = (DP[i - j][i] + DP[k][j]) % 100999;
			}
		}
		DP[i][i] = 1;
		//if (i % 100 == 0) cout << i << '\n';
	}
	

	int T;
	long long int res;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		res = 0;
		for (int i = 1; i <= n; i++)
		{
			res = (res + DP[i][n]) % 100999;
		}
		cout << res << '\n';
	}

	return 0;
}