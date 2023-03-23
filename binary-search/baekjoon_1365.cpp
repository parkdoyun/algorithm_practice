#include <iostream>

using namespace std;

// ���� 1365 - ���� ������
// binary search, LIS
// ��� 2

// LIS (Longest Increasing Subsequence, ���� ���� ����) - �̺�Ž��
// LIS�� DP�� Ǫ�� ���, O(n^2)�̹Ƿ� �ð� �ʰ�
// ���� ���� ���� ���� ã�� ��
// ��ü n���� ����

int n;
int sub_size; // ���� ���� ���� ����
int arr[100001];
int subsequence[100001];

void binary_search(int num)
{
	int start = 1;
	int end = sub_size;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (subsequence[mid] > num)
		{
			end = mid - 1;
		}
		else // subsequence[mid] < num
		{
			start = mid + 1;
		}
	}
	if (subsequence[mid] > num)
	{
		subsequence[mid] = num;
	}
	else // subsequence[mid] < num
	{
		subsequence[mid + 1] = num;
		if (mid + 1 > sub_size) sub_size = mid + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	subsequence[1] = arr[1];
	sub_size = 1;

	for (int i = 2; i <= n; i++)
	{
		binary_search(arr[i]);
	}

	cout << n - sub_size;

	return 0;
}