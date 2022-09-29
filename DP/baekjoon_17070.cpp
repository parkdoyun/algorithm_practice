#include <iostream>

using namespace std;

// ���� 17070 - ������ �ű��1
// DP
// ��� 5

// �ش� �������� ���η� �� �� �ִ� ������, ���η� �� �� �ִ� ������,
// �밢������ �� �� �ִ� �������� ����Ѵ�.
// �������� ����, ����, �밢�� ������ �� ���ؼ� ���

struct node {
	int row = 0; // ���η� �� Ƚ��
	int col = 0; // ���η� �� Ƚ��
	int diag = 0; // �밢������ �� Ƚ��
};

int board[17][17];
node DP[17][17];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}
	
	// �ʱ� ����
	DP[1][2].row = 1;

	for (int i = 3; i <= n; i++)
	{
		if (board[1][i] == 1) continue;
		DP[1][i] = DP[1][i - 1];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 1) continue;

			// ���η� ���� ��
			if (j - 1 >= 1)
			{
				// ���� : ����
				DP[i][j].row += DP[i][j - 1].row;

				// ���� : �밢��
				if (i - 1 >= 1) DP[i][j].row += DP[i][j - 1].diag;
			}
			// ���η� ���� ��
			DP[i][j].col += DP[i - 1][j].col;

			// ���� : �밢��
			if (j - 1 >= 1) DP[i][j].col += DP[i - 1][j].diag;

			// �밢������ ���� ��
			if (j - 1 >= 1 && board[i][j - 1] == 0 && board[i - 1][j] == 0)
			{
				// ���� : �밢��
				DP[i][j].diag += DP[i - 1][j - 1].diag;
				// ���� : ����
				DP[i][j].diag += DP[i - 1][j - 1].row;
				// ���� : ����
				DP[i][j].diag += DP[i - 1][j - 1].col;
			}
			
		}
	}

	cout << DP[n][n].row + DP[n][n].col + DP[n][n].diag;
	
	return 0;
}