#include <iostream>

using namespace std;

// 백준 2688 - 줄어들지 않아
// DP
// 실버 1

// 점화식 
// i로 이루어진 K 자릿수의 갯수 = 0부터 i까지 K-1 자릿수의 갯수의 합
// DP[i][k] = sum(DP[0][k - 1], ... , DP[i][k - 1]);

long long int DP[10][65];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// DP 기저 조건
	for (int i = 0; i <= 9; i++) DP[i][1] = 1;

	// DP
	long long int a;
	for (int i = 2; i <= 64; i++)
	{
		a = 0;
		for (int j = 0; j <= 9; j++)
		{
			a += DP[j][i - 1];
			DP[j][i] = a;
		}
	}

	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		a = 0;
		for (int j = 0; j <= 9; j++) a += DP[j][n];
		cout << a << '\n';
	}

	return 0;
}