#include <iostream>
#include <algorithm>

using namespace std;

// swea 1952 - ������
// dp
// dp[0] : 1�� �̿�Ǹ� ���
// dp[1] : 1�� �߰�
// dp[2] : 3�� �߰�
// dp[3] : 1�� �߰�
// -> ���� �� � �� �� ������ ���ϰ� ����
// ���� ������ �� DP[i-1][n]�� ���� ���� ������ => ��� �̰ŷ� ���� �ƴϸ� ���ο� �ɷ� ���� ����
// ��ȭ�� : DP[i][j] = min(DP[i-1][j], DP[i][j-1] + ���� ���� 1�� ��� �� ���� ��)

int cost[4]; // 1��, 1��, 3��, 1�� ���
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

		// DP �ʱ�ȭ
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i <= 12; i++) DP[j][i] = 0;
		}

		// 1��
		for (int i = 1; i <= 12; i++)
		{
			if (arr[i] > 0) DP[0][i] = DP[0][i-1] + arr[i] * cost[0];
			else DP[0][i] = DP[0][i - 1];
		}

		// 1��
		for (int i = 1; i <= 12; i++)
		{
			
			if (arr[i] > 0)
			{
				int add_tmp = min(cost[1], cost[0] * arr[i]);
				DP[1][i] = min(DP[0][i], DP[1][i - 1] + add_tmp); // min() : #include <algorithm>
			}
			else DP[1][i] = min(DP[0][i], DP[1][i - 1]);
		}
		 
		// 3�ޱ����� �ϰ� DP �� �ּҶ� 1�� ����̶� ���ϸ� ��
		// 3���� vs i��°���� ���²� ���� �۾Ҵ� �� vs ���� �۾Ҵ� i-1��°�� ��
		DP[2][1] = DP[1][1];
		DP[2][2] = DP[1][2];
		for (int i = 3; i <= 12; i++)
		{
			int add_tmp = cost[0] * arr[i];
			if (add_tmp > cost[1]) add_tmp = cost[1];

			DP[2][i] = min(DP[1][i], DP[2][i - 3] + cost[2]);	
			DP[2][i] = min(DP[2][i], DP[2][i - 1] + add_tmp);
		}

		// 3�� 11��, 12���� Ȯ��
		int add_tmp = cost[0] * arr[11];
		if (add_tmp > cost[1]) add_tmp = cost[1];
		DP[2][12] = min(DP[2][12], DP[2][11] + cost[2]);
		DP[2][12] = min(DP[2][12], DP[2][12] + cost[2]);

		int res = min(DP[2][12], cost[3]);

		cout << '#' << tc << ' ' << res << '\n';

	}

	return 0;
}