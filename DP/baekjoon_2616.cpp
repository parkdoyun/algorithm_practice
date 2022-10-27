#include <iostream>
#include <algorithm>

using namespace std;

// ���� 2616 - ���������
// DP
// ��� 3

// �ٷ� ������ �� ������ vs �ٷ� ���� ������ ��ģ �Ű� �� ������
// DP[0] : ù��° ���� ���� ū �ֵ�
// DP[1] : ���� 2�� ���� ū �ֵ�
// DP[2] : ���� 3�� ���� ū �ֵ�
// ��ȭ�� : DP[n][i] = max(DP[n][i-1], DP[n-1][i-m] + i��°���� ���� ���� ��)


int train[50002];
int sum[50002]; // sum[i] : i��°������ �� ���� ��
int DP[3][50002];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> train[i];
		sum[i] = sum[i - 1] + train[i];
	}
	cin >> m;

	// ù��° ���� ���� ū �ֵ� ã��
	DP[0][1] = sum[1 + m - 1] - sum[1 - 1];
	for (int i = 2; i <= n - m + 1; i++)
	{
		DP[0][i] = max(DP[0][i - 1], sum[i + m - 1] - sum[i - 1]);
	}

	// �ι�° ����
	// ������ M + 1���� ���� (�� �������� ���� 1��)
	DP[1][m + 1] = DP[0][1] + sum[m + m] - sum[m];
	for (int i = m + 2; i <= n - m + 1; i++)
	{
		DP[1][i] = max(DP[1][i - 1], DP[0][i - m] + sum[i + m - 1] - sum[i - 1]);
	}

	// ����° ����
	int max1 = 0;
	DP[2][m * 2 + 1] = DP[1][m + 1] + sum[m * 2 + 1 + m - 1] - sum[m * 2];
	max1 = DP[2][m * 2 + 1];
	for (int i = m * 2 + 2; i <= n - m + 1; i++)
	{
		DP[2][i] = max(DP[2][i - 1], DP[1][i - m] + sum[i + m - 1] - sum[i - 1]);
		if (DP[2][i] > max1) max1 = DP[2][i];
	}

	cout << max1;

	return 0;
}