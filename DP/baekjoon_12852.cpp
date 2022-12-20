#include <iostream>
#include <string>

using namespace std;

// 백준 12852 - 1로 만들기 2
// DP
// 실버 1

// 점화식
// if(DP[i / 3]이 DP[i] + 1보다 클 때) DP[i / 3] = DP[i] + 1;
// if(DP[i / 2]이 DP[i] + 1보다 클 때) DP[i / 2] = DP[i] + 1;
// if(DP[i - 1]이 DP[i] + 1보다 클 때) DP[i - 1] = DP[i] + 1;

int DP[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) DP[i] = 1000000;

	// 초기 조건
	DP[n] = 0;
	if (n % 3 == 0) DP[n / 3] = 1;
	if (n % 2 == 0) DP[n / 2] = 1;
	DP[n - 1] = 1;

	// 점화식
	for (int i = n - 1; i >= 1; i--)
	{
		if (i % 3 == 0 && DP[i / 3] > DP[i] + 1)
		{
			DP[i / 3] = DP[i] + 1;
		}
		if (i % 2 == 0 && DP[i / 2] > DP[i] + 1)
		{
			DP[i / 2] = DP[i] + 1;
		}
		if (DP[i - 1] > DP[i] + 1)
		{
			DP[i - 1] = DP[i] + 1;
		}
	}

	cout << DP[1] << '\n';
	int res[100001];

	int cnt = 0;
	int idx = 1;
	while (idx <= n)
	{
		if (idx == n)
		{
			res[cnt] = n;
			break;
		}
		res[cnt] = idx;
		cnt++;
		if (idx * 3 <= n && DP[idx * 3] == DP[idx] - 1)
		{
			idx = idx * 3;
		}
		else if (idx * 2 <= n && DP[idx * 2] == DP[idx] - 1)
		{
			idx = idx * 2;
		}
		else
		{
			idx++;
		}
	}

	for (int i = cnt; i >= 0; i--)
	{
		cout << res[i] << ' ';
	}

	return 0;
}