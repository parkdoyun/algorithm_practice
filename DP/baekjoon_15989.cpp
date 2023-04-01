#include <iostream>

using namespace std;

// ���� 15989 - 1,2,3 ���ϱ� 4
// DP
// �ǹ� 1

// ��ȭ�� : 1 ���� �� �ִ� �ֵ� + 2 ���� �� �ִ� �ֵ� + 3 ���� �� �ִ� �ֵ�
// DP[0][i] = DP[0][i-1] + DP[1][i-1] + DP[2][i-1]; // 1 ���ϸ� ���ο� ����
// DP[1][i] = DP[1][i-2] + DP[2][i-2]; // 2�� 3���θ� ������� �ֵ� + 2
// DP[2][i] = DP[2][i-3]; // 3���θ� ������� �ֵ� + 3

// ��ġ�� �� �����ؾ� ��

int n;
int DP[3][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		// DP �ʱ�ȭ
		for (int i = 1; i <= n; i++)
		{
			DP[0][i] = 0;
			DP[1][i] = 0;
			DP[2][i] = 0;
		}

		// �ʱ� ����
		DP[0][1] = 1;
		DP[0][2] = 1; DP[1][2] = 1;
		DP[0][3] = 2; DP[2][3] = 1;

		// DP
		for (int i = 4; i <= n; i++)
		{
			DP[0][i] = DP[0][i - 1] + DP[1][i - 1] + DP[2][i - 1];
			DP[1][i] = DP[1][i - 2] + DP[2][i - 2];
			DP[2][i] = DP[2][i - 3];
		}

		cout << DP[0][n] + DP[1][n] + DP[2][n]  << '\n';
	}

	return 0;
}