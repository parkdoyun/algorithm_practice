#include <iostream>

using namespace std;

// ���� 2688 - �پ���� �ʾ�
// DP
// �ǹ� 1

// ��ȭ�� 
// i�� �̷���� K �ڸ����� ���� = 0���� i���� K-1 �ڸ����� ������ ��
// DP[i][k] = sum(DP[0][k - 1], ... , DP[i][k - 1]);

long long int DP[10][65];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// DP ���� ����
	for (int i = 0; i <= 9; i++) DP[i][1] = 1;

	// DP
	long long int a;
	for (int i = 2; i <= 64; i++)
	{
		a = 0;
		for (int j = 0; j <= 9; j++)
		{
			a += DP[j][i - 1];
			DP[j][i] = a;
		}
	}

	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		a = 0;
		for (int j = 0; j <= 9; j++) a += DP[j][n];
		cout << a << '\n';
	}

	return 0;
}