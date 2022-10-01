#include <iostream>

using namespace std;

// ���� 2343 - ��Ÿ ����
// �̺� Ž��
// �ǹ� 1

int arr[100001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 1;
	int end = 1000000000;
	int mid;
	int min = 1000000000;

	while (start <= end)
	{
		mid = (start + end) / 2;

		int idx = 0;
		int chk = -1;
		for (int i = 0; i < m; i++)
		{
			int tmp = 0;
			while ((tmp + arr[idx]) <= mid && idx < n) // ������ idx ���� ��� �� �� ���� ����
			{
				tmp += arr[idx];
				idx++;
				if (i == m - 1 && idx == n - 1 && tmp + arr[idx] > mid) chk = 1;
			}
		}

		if (idx < n - 1 || chk == 1) // �� �� ���� -> mid �ʹ� �۴�
		{
			start = mid + 1;
		}
		else // �� ����
		{
			if (mid < min) min = mid;
			end = mid - 1;
		}
	}

	cout << min;

	return 0;
}