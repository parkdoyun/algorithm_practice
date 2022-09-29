#include <iostream>

using namespace std;

// ���� 11054 - ���� �� ������� �κ� ����
// DP, LIS
// ��� 4

// �����ϴ� ���� �� �κ� ����(LIS) ���ϰ�
// �ں��� �����ϴ� ���� �� �κ� ���� ���Ѵ�
// �� �ε����� ������ ���Ͽ� �ִ� ����Ѵ�.

int arr[1001];
int DP_max[1001];
int DP_min[1001];

int main()
{
	int n;
	cin >> n;

	// ���� ���� : ���� �ִ� ���������� �ִ� ���� 1�̴�
	DP_max[0] = 1;
	DP_min[n-1] = 1;

	// �Է¹����鼭 LIS ���ϱ�
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		
		int tmp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (tmp < DP_max[j]) tmp = DP_max[j];
			}
		}

		DP_max[i] = tmp + 1;
	}

	// �� �ں��� �����ϴ� �κ� ���� ���ϱ�
	for (int i = n-1; i >= 0; i--)
	{
		int tmp = 0;
		for (int j = n-1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				if (tmp < DP_min[j]) tmp = DP_min[j];
			}
		}

		DP_min[i] = tmp + 1;
	}

	// �� �迭�� �ִ� ã��

	int max = DP_max[0] + DP_min[0];
	for (int i = 1; i < n; i++)
	{
		if (max < DP_max[i] + DP_min[i]) max = DP_max[i] + DP_min[i];
	}

	cout << max - 1;

	return 0;
}