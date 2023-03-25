#include <iostream>
#include <algorithm>

using namespace std;

// 백준 4883 - 삼각 그래프
// DP
// 실버 1

// 비용 음수도 들어갈 수 있음 => 더 길어보이는 경로도 다 해봐야 함

// 점화식
// DP[i][0] = min(DP[i-1][0], DP[i-1][1]) + arr[i][0];
// DP[i][1] = min(DP[i-1][0], DP[i-1][1], DP[i-2][2], DP[i][0]) + arr[i][1];
// DP[i][2] = min(DP[i-1][1], DP[i-2][2], DP[i][1]) + arr[i][2];

int n;
int arr[100001][3];
int DP[100001][3];

int main()
{
	int tc = 1;
	while(true)
	{	
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);

		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			DP[i][0] = 0;
			DP[i][1] = 0;
			DP[i][2] = 0;
		}

		// 기저 조건
		DP[0][1] = arr[0][1];
		DP[0][2] = arr[0][1] + arr[0][2];

		DP[1][0] = arr[0][1] + arr[1][0];
		DP[1][1] = min(min(arr[0][1], DP[1][0]), DP[0][2]) + arr[1][1];
		DP[1][2] = min(min(arr[0][1], DP[0][2]), DP[1][1]) + arr[1][2];

		// DP
		int tmp_min;
		for (int i = 2; i < n; i++)
		{
			tmp_min = min(min(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]);
			DP[i][0] = min(DP[i - 1][0], DP[i - 1][1]) + arr[i][0];
			DP[i][1] = min(DP[i][0], tmp_min) + arr[i][1];
			DP[i][2] = min(min(DP[i - 1][1], DP[i - 1][2]), DP[i][1]) + arr[i][2];
		}

		cout << tc << ". " << DP[n - 1][1] << '\n';

		tc++;
	}

	return 0;
}