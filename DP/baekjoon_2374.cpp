#include <iostream>

using namespace std;

// ���� 2374 - ���� ���� �����
// DP
// ��� 4

// �ִ��� �ǵ��� ������ ��

// ��ȭ�� 
// 1. ���� num[i] >= num[i - 1]�̸� ���� ������ ���� -> DP[i] = DP[i - 1];
// 2. num[i] <= num[i - 1]�̸� �� ���� �ø��� i - 1������ ���� �÷��� �� -> DP[i] = DP[i - 1] + (num[i - 1] - num[i]);

int n, max1;
int num[1001];
long long int DP[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	max1 = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		if (num[i] > max1) max1 = num[i];
	}

	// DP
	// ���� ����
	DP[1] = max1 - num[1];

	// DP
	for (int i = 2; i <= n; i++)
	{
		if (num[i] >= num[i - 1]) DP[i] = DP[i - 1];
		else
		{
			DP[i] = DP[i - 1] + (long long int)(num[i - 1] - num[i]);
		}
	}

	cout << DP[n];

	return 0;
}