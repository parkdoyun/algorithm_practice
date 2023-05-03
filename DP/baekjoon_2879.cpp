#include <iostream>

using namespace std;

// ���� 2879 - �ڵ��� ���ڰ�
// DP
// ��� 3

// ������ ũ�ٸ� ū ��ŭ �߰� DP[i] = DP[i - 1] + abs(arr[i] - arr[i - 1]);
// ������ �۴ٸ� DP[i] = DP[i - 1];

// ���̿� �ִ� �� ���� �ʿ� X -> ���� �����ؼ� ���ϳ� ���� �ϳ� ����
// i��°����
// ���̿� �ִ� ������ �� ũ�ٸ� -> DP[i + k] = DP[i - 1] + arr[i + k];
// ���� �۴ٸ� ���� �÷������� -> DP[i + k] = DP[i - 1] + arr[i - 1];

int n;
int arr1[1001];
int arr2[1001];
int arr[1001]; // ���� ��
int DP_minus[1001]; // ����
int DP_plus[1001]; // ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr1[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> arr2[i];
		arr[i] = arr1[i] - arr2[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] >= 0)
		{	
			// �ϴ� ���̳ʽ� ã��
			int now_idx = i + 1;
			while (now_idx <= n && arr[now_idx] >= 0) now_idx++;
			if (now_idx > n)
			{
				DP_minus[n] = DP_minus[i - 1]; // ��� ����
				break; // ���̳ʽ� ���ٸ� ������
			}

			DP_minus[now_idx] = DP_minus[i - 1] + abs(arr[now_idx]);
			i = now_idx;
		}
		else
		{
			if (arr[i] < arr[i - 1])
			{
				DP_minus[i] = DP_minus[i - 1] + abs(arr[i] - arr[i - 1]);
			}
			else
			{
				DP_minus[i] = DP_minus[i - 1];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] <= 0)
		{
			// �ϴ� �÷��� ã��
			int now_idx = i + 1;
			while (now_idx <= n && arr[now_idx] <= 0) now_idx++;
			if (now_idx > n)
			{
				DP_plus[n] = DP_plus[i - 1];
				break; // �÷��� ���ٸ� ������
			}

			DP_plus[now_idx] = DP_plus[i - 1] + arr[now_idx];
			i = now_idx;
		}
		else
		{
			if (arr[i] > arr[i - 1])
			{
				DP_plus[i] = DP_plus[i - 1] + arr[i] - arr[i - 1];
			}
			else
			{
				DP_plus[i] = DP_plus[i - 1];
			}
		}
	}

	cout << DP_minus[n] + DP_plus[n];

	return 0;
}