#include <iostream>

using namespace std;

// ���� 15486 - ��� 2
// DP
// ��� 5

// �ں��� Ȯ��
// ���� ���ϴ� �� ������ �� �ϴ� �� ������?
// ��ȭ�� DP[i] = max(DP[i + 1] , DP[i + t[i]] + p[i])

int DP[1500002];
int t[1500002];
int p[1500002];

int main()
{
	int n;
	cin >> n;
	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; i--)
	{
		if (t[i] == 1) DP[i] = DP[i + 1] + p[i];
		else if (i + t[i] > n + 1) DP[i] = DP[i + 1];
		else if (DP[i + t[i]] + p[i] > DP[i + 1])
		{
			DP[i] = DP[i + t[i]] + p[i];
		}
		else DP[i] = DP[i + 1];
		if (max < DP[i]) max = DP[i];
	}

	cout << max;

	return 0;
}