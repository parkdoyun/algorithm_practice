#include <iostream>

using namespace std;

// ���� 2631 - �ټ����
// DP, LIS
// ��� 4

// LIS ����
// ��� ������ �� ���� ���� ��������?
// ���� ���� �������� ���ܵ� �ֵ� = �ڸ� ��ü�ϴ� �ֵ�

int arr[201];
int DP[201];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	// ��������
	DP[0] = 1;

	for (int i = 1; i < n; i++) {

		int tmp = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && tmp < DP[j]) tmp = DP[j];
		}
		DP[i] = tmp + 1;
	}

	int max = DP[0];
	for (int i = 1; i < n; i++)
	{
		if (max < DP[i]) max = DP[i];
	}
	cout << n - max;

	return 0;
}