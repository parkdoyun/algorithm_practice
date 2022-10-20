#include <iostream>

using namespace std;

// ���� 13398 - ���� ��
// DP
// ��� 5

// ���������� �������� �����̸� ������ ���� ����
// �ƴϸ� ���ϱ� (���� �� �� ����)
// �ش� �ε��� �ڸ� ������ ����

int num[100001];
int DP[100001]; // �Ϲ� ������
int DP1[100001]; // �ϳ� �����ϴ� ������

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	DP[0] = num[0];
	DP1[0] = num[0];

	int max = num[0];
	for (int i = 1; i < n; i++)
	{
		// ū �� �ֱ�
		if (DP[i - 1] + num[i] > num[i]) DP[i] = DP[i - 1] + num[i];
		else DP[i] = num[i];
		
		// �ǳʶ� ��
		// �� �ǳʶ� ���� �Ͱ� �ǳʶ� ���¿��� ���� �� ��
		if (DP[i - 1] > DP1[i - 1] + num[i])
		{
			DP1[i] = DP[i - 1];
		}
		else DP1[i] = DP1[i - 1] + num[i];


		if (max < DP[i]) max = DP[i];
		if (max < DP1[i]) max = DP1[i];
	}
	cout << max;

	return 0;
}