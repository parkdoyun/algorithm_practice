#include <iostream>

using namespace std;

// ���� 14925 - ���� �Ǽ��ϱ�
// DP
// ��� 4

// board[i][j]�� �� �ִٸ� -> DP[i][j] = 0;
// board[i][j]�� �� ���� DP[i-1][j], DP[i][j-1], DP[i - 1][j-1] �߿� ���� ���� �� + 1
// ���� �´� ���ٸ� DP[i][j] = DP[i-1][j-1] + 1;
// �̷� ���� �߿� �ִ� ����ϸ� ��

int m, n;
int board[1001][1001];
int DP[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	// DP
	// �ʱ� ����
	for (int i = 0; i < n; i++)
	{
		if (board[0][i] == 0) DP[0][i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (board[i][0] == 0) DP[i][0] = 1;
	}

	// DP
	int max_cnt = 0;
	if (board[0][0] == 0) max_cnt = 1;
	int a, b, c;
	int tmp_min;
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (board[i][j] != 0) continue;
			a = DP[i - 1][j];
			b = DP[i][j - 1];
			c = DP[i - 1][j - 1];
			if (a == b && b == c)
			{
				DP[i][j] = a + 1;
				if (DP[i][j] > max_cnt) max_cnt = DP[i][j];
			}
			else
			{
				tmp_min = a;
				if (tmp_min > b) tmp_min = b;
				if (tmp_min > c) tmp_min = c;
				DP[i][j] = tmp_min + 1;
			}
		}
	}

	cout << max_cnt;
	

	return 0;
}