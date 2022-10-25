#include <iostream>
#include <algorithm>

using namespace std;

// ���� 1461 - ������
// greedy
// ��� 5

// ���� �� ���, ���� ���� ���
// ��� ���� ū ���밪�� ���� ���� ū ���밪 �� �ϳ� ����.

int n, m;
int arr[10001];
int idx = 0;
int res = 0;

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0) idx++;
	}

	sort(arr, arr + n);

	for (int i = n - 1; i >= idx; i -= m)
	{
		res += (arr[i] * 2);
	}
	for (int i = 0; i < idx; i += m)
	{
		res += (abs(arr[i]) * 2);
	}

	res -= max(abs(arr[0]), arr[n - 1]);

	cout << res;

	return 0;
}