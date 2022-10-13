#include <iostream>
#include <algorithm>

using namespace std;

// swea 1952 - 수영장
// dp
// dp[0] : 1일 이용권만 사용
// dp[1] : 1달 추가
// dp[2] : 3달 추가
// dp[3] : 1년 추가
// -> 더할 때 어떤 게 더 작은지 비교하고 갱신
// 여태 가짓수 중 DP[i-1][n]이 가장 작은 가짓수 => 계속 이거로 할지 아니면 새로운 걸로 할지 결정
// 점화식 : DP[i][j] = min(DP[i-1][j], DP[i][j-1] + 일일 비용과 1달 비용 중 작은 값)

int cost[4]; // 1일, 1달, 3달, 1년 비용
int arr[13];
int DP[4][13];

int main()
{
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> cost[i];
		}
		for (int i = 1; i <= 12; i++) cin >> arr[i];

		// DP 초기화
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i <= 12; i++) DP[j][i] = 0;
		}

		// 1일
		for (int i = 1; i <= 12; i++)
		{
			if (arr[i] > 0) DP[0][i] = DP[0][i-1] + arr[i] * cost[0];
			else DP[0][i] = DP[0][i - 1];
		}

		// 1달
		for (int i = 1; i <= 12; i++)
		{
			
			if (arr[i] > 0)
			{
				int add_tmp = min(cost[1], cost[0] * arr[i]);
				DP[1][i] = min(DP[0][i], DP[1][i - 1] + add_tmp); // min() : #include <algorithm>
			}
			else DP[1][i] = min(DP[0][i], DP[1][i - 1]);
		}
		 
		// 3달까지만 하고 DP 내 최소랑 1년 비용이랑 비교하면 됨
		// 3달전 vs i번째까지 여태껏 가장 작았던 애 vs 가장 작았던 i-1번째와 비교
		DP[2][1] = DP[1][1];
		DP[2][2] = DP[1][2];
		for (int i = 3; i <= 12; i++)
		{
			int add_tmp = cost[0] * arr[i];
			if (add_tmp > cost[1]) add_tmp = cost[1];

			DP[2][i] = min(DP[1][i], DP[2][i - 3] + cost[2]);	
			DP[2][i] = min(DP[2][i], DP[2][i - 1] + add_tmp);
		}

		// 3달 11월, 12월도 확인
		int add_tmp = cost[0] * arr[11];
		if (add_tmp > cost[1]) add_tmp = cost[1];
		DP[2][12] = min(DP[2][12], DP[2][11] + cost[2]);
		DP[2][12] = min(DP[2][12], DP[2][12] + cost[2]);

		int res = min(DP[2][12], cost[3]);

		cout << '#' << tc << ' ' << res << '\n';

	}

	return 0;
}