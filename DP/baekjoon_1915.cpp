#include <iostream>

using namespace std;

// ���� 1915 - ���� ū ���簢��
// DP
// ��� 4

// (i,j) ���� ������ �� ������ ������ ���簢���� �ִ� ũ�� = (i-1, j-1) ���� ������ ������ ���簢�� �ִ� ũ���� + 1
// ���� : (i-1, j-1) ���� ������ �ϴ� ���簢���� ������, �� �� �� 1�̶��

int board[1001][1001];
int DP[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			board[i][j] = (int)(c - '0');
		}
	}

	// ���� ����
	int max = 0;
	for (int i = 0; i < m; i++)
	{
		DP[0][i] = board[0][i];
		if (max < DP[0][i]) max = DP[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		DP[i][0] = board[i][0];

		if (max < DP[i][0]) max = DP[i][0]; // �ݷ� ó��

		for (int j = 1; j < m; j++)
		{


			if (board[i][j] == 0)
			{
				DP[i][j] = 0;
				continue;
			}

			if (DP[i - 1][j - 1] == 0) DP[i][j] = board[i][j];
			else if (j < i)
			{
				int chk = -1;
				int width_cnt = 1;
				int height_cnt = 1;
				for (int r = j - 1; r >= j - DP[i-1][j-1]; r--) {
					if (DP[i][r] == 0)
					{
						chk = 1;
						break;
					}
					width_cnt++;
				}
				for (int r = 1; r <= DP[i-1][j-1]; r++) {
					if (DP[i - r][j] == 0)
					{
						chk = 1;
						break;
					}
					height_cnt++;
				}
				if (chk == 1)
				{
					DP[i][j] = min(width_cnt, height_cnt);
				}
				else DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else // j >= i
			{
				int chk = -1;
				int width_cnt = 1;
				int height_cnt = 1;
				for (int r = i - 1; r >= i - DP[i-1][j-1]; r--) {
					if (DP[r][j] == 0)
					{
						chk = 1;
						break;
					}
					height_cnt++;
				}
				for (int r = 1; r <= DP[i-1][j-1]; r++) {
					if (DP[i][j - r] == 0)
					{
						chk = 1;
						break;
					}
					width_cnt++;
				}
				if (chk == 1)
				{
					DP[i][j] = min(width_cnt, height_cnt);
				}
				else DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			if (DP[i][j] > max) max = DP[i][j];
			
		}
	}

	cout << max * max;

	return 0;

}