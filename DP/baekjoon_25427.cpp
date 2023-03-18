#include <iostream>
#include <string>

using namespace std;

// 백준 25427 - DKSH를 찾아라
// DP
// 골드 5

// 변수 크기 잘 확인하자 (int로 터지는 지 확인)

// 점화식
// i) D일 때 DP[0][i] = DP[0][i-1] + 1
// ii) K일 때 DP[1][i] = DP[1][i-1] + DP[0][i-1]
// iii) S일 때 DP[2][i] = DP[2][i-1] + DP[1][i-1]
// iv) H일 때 DP[3][i] = DP[3][i-1] + DP[2][i-1]
// v) 아닐 때 DP[n][i] = DP[n][i-1]

int n;
string s;
long long int DP[4][100001]; // 0 : D, 1 : K, 2 : S, 3 : H

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	// 초기조건
	if (s[0] == 'D')
	{
		DP[0][0] = 1;
	}

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == 'D') DP[0][i] = DP[0][i - 1] + (long long int)1;
		else DP[0][i] = DP[0][i - 1];
		if (s[i] == 'K') DP[1][i] = DP[1][i - 1] + DP[0][i - 1];
		else DP[1][i] = DP[1][i - 1];
		if (s[i] == 'S') DP[2][i] = DP[2][i - 1] + DP[1][i - 1];
		else DP[2][i] = DP[2][i - 1];
		if (s[i] == 'H') DP[3][i] = DP[3][i - 1] + DP[2][i - 1];
		else DP[3][i] = DP[3][i - 1];
	}

	cout << DP[3][n - 1];

	return 0;
}