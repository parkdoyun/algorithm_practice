#include <iostream>

using namespace std;

// ���� 3079 - �Ա��ɻ�
// ����Ž��
// ��� 5

// �ּ� 1, �ִ� �ɻ� �ð� * �ο� ��
// ����Ž���� �ϴ� �� �ȿ� �ɻ� ��ĥ �� �ִ���?

int arr[100001];

int main()
{
	int n, m;
	cin >> n >> m;

	int max = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}

	unsigned long long start = 1;
	// int �������� ��� ���� ũ�� long long���� �޾Ƶ� ������
	// ����ȯ �ʿ�
	unsigned long long end = (long long)max * (long long)m;
	unsigned long long mid;

	unsigned long long min = end;

	
	while (start <= end)
	{
		mid = (start + end) / 2;

		// �˻�
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += mid / arr[i];
		}

		if (cnt >= m) // ���� -> �� �ð� �ٿ��� ��
		{
			if (min > mid) min = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	cout << min;

	return 0;
}