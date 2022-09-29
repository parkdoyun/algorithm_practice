#include <iostream>

using namespace std;

// ���� 9084 - ����
// DP
// ��� 5

// �� �������� �������� ���� ������ ���Ѵ�
// ���� ������ ���� ũ�Ƿ� ������ �������� �ٸ� ���ο� �������̴�
// ��ȭ�� : DP[i][j] = DP[i-1][j] + DP[i][j - coin[i]]; 

int coin[21];
int DP[21][10001];

int main()
{
	int T, n, m;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];
		}

		cin >> m;


		// 0��° ���� (���� ����)
		for (int j = coin[0]; j <= m; j+=coin[0])
		{
			DP[0][j] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				if (j < coin[i]) DP[i][j] = DP[i - 1][j];
				else if (j == coin[i]) DP[i][j] = DP[i - 1][j] + 1; // ���� ���� 1���θ� �̷���� ���
				else DP[i][j] = DP[i - 1][j] + DP[i][j - coin[i]];
			}
		}
		cout << DP[n - 1][m] << '\n';

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= m; j++) // ���� ����
			{
				DP[i][j] = 0;
			}
		}
	}
	return 0;
}