#include <iostream>
#include <algorithm>

using namespace std;

// ���� 21758 - �� ����
// greedy, ���� ��
// ��� 5

// ��� ������ �� �غ��� -> �ð� �ʰ�

// 1. ������ ���� �ִٸ� -> �ϳ��� ���� �ΰ� �߰��� ������ ���� �д�
// 2. ������ �߰��� �ִٸ� -> �� ������ �� ���� �δ� �� �ִ��̴�
// �� �������� �� �غ��� ��

long long arr[100001];
long long sum[100001]; // ���� ��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	long long max1 = 0;
	// ������ ���� �ִٸ�
	// 1. ���� �� => ���� ��ġ : 1 �� ������ : i, n
	for (int i = 2; i < n; i++)
	{
		max1 = max(max1, sum[n] - arr[n] - arr[i] + sum[i - 1]);
	}

	// 2. ������ �� => ���� ��ġ : n, �� ������ : 1, i
	for (int i = 2; i < n; i++)
	{
		max1 = max(max1, sum[n] - arr[1] - arr[i] + (sum[n] - sum[i]));
	}

	// 3. �߰� => ���� ��ġ : i
	for (int i = 2; i < n; i++)
	{
		max1 = max(max1, (sum[i] - arr[1]) + (sum[n] - sum[i - 1] - arr[n]));
	}

	cout << max1;

	return 0;
}