#include <iostream>

using namespace std;

// ���� 2156 - ������ �ý�
// DP
// �ǹ� 1

// �ٷ� ���̶� �̾ ���ô� �� �� ū�� �ƴϸ� �����ؼ� ���ô� �� ū��?
// ���� �Ұ��� �ƴ���

// �ݷ� : ������ �ѹ� �϶�� ���� ������

int wine[10001];

int DP1[10001]; // �����ָ� ù��°�� ���ô� �迭, ���� �ֵ��� ������ ù��°�� ���� ����
int DP2[10001]; // �����ָ� �ι�°�� ���ô� �迭

int DP_no[10001]; // �����ָ� ������ �ʴ� �迭

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> wine[i];
	}

	// ���� ����
	DP1[0] = wine[0];
	DP2[0] = 0;
	DP_no[0] = 0;

	for (int i = 1; i < n; i++) // i��°���� ������ ��, ù��° ������ ��, �ι�° ������ ��
	{
		int tmp_max = DP_no[i - 1];
		if (tmp_max < DP1[i - 1]) tmp_max = DP1[i - 1];
		if (tmp_max < DP2[i - 1]) tmp_max = DP2[i - 1];
		DP_no[i] = tmp_max;
		DP1[i] = DP_no[i - 1] + wine[i];
		DP2[i] = DP1[i - 1] + wine[i];
	}


	int max = DP1[n - 1];
	if (max < DP2[n - 1]) max = DP2[n - 1];
	if (max < DP_no[n - 1]) max = DP_no[n - 1];

	cout << max;

	return 0;
}