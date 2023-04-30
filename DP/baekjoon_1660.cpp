#include <iostream>
#include <algorithm>

using namespace std;

// 백준 1660 - 캡틴 이다솜
// DP (동전 유형)
// 실버 1

// DP[i] = i개로 만들 수 있는 사면체들
// DP[i] = min(i개로 만들 수 있는 사면체들 갯수)
// DP[i] = min(DP[i - tetra[1]], DP[i - tetra[2]], ... DP[i - tetra[tetra_idx]]) + 1

int triangle[1000];
int tetra[1000]; // 사면체를 이루는 대포알의 갯수들
int DP[300001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, max_n, tetra_idx;
	cin >> n;

	triangle[1] = 1;
	tetra[1] = 1;
	max_n = 1; // n개 이내에서 만들 수 있는 가장 큰 사면체
	if (n == 1) // 예외
	{
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		triangle[i] = triangle[i - 1] + i;
		tetra[i] = tetra[i - 1] + triangle[i];
		if (n < tetra[i])
		{
			max_n = i - 1;
			break;
		}
	}
	
	// 기저 조건
	DP[1] = 1;

	// DP
	tetra_idx = 1;
	for (int i = 2; i <= n; i++)
	{
		if (tetra[tetra_idx + 1] <= i) tetra_idx++;
		DP[i] = DP[i - 1];
		for (int j = 2; j <= tetra_idx; j++)
		{
			DP[i] = min(DP[i], DP[i - tetra[j]]);
		}
		DP[i]++;
	}

	cout << DP[n];

	return 0;
}