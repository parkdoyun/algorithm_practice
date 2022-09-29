#include <iostream>

using namespace std;

// ���� 2579 - ��� ������
// DP
// �ǹ� 3

// ������ �ΰ� ��� ������ �ƴ϶� �Ѱ� ��� ���� ���� => no�� one, two �ִ� �ֱ�

int no[301]; // �� ��� �� ���� ��
int one[301]; // �� ����� ù��°�� ���� ��
int two[301]; // �� ����� �ι�°�� ���� ��

// ��� ��
int arr[301];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// ���� ����
	one[1] = arr[1];

	two[2] = arr[1] + arr[2];
	one[2] = arr[2];
	no[2] = arr[1];

	for (int i = 3; i <= n; i++)
	{
		no[i] = max(two[i - 1], one[i-1]);
		one[i] = no[i - 1] + arr[i];
		two[i] = one[i - 1] + arr[i];
	}

	cout << max(one[n], two[n]);


	return 0;
}