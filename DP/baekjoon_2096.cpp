#include <iostream>

using namespace std;

// ���� 2096 - ��������
// DP
// ��� 5

// �Ȱ��� �迭 �ϳ� ��������
// �������鼭 ��� �� ��� (�̹� ���� �ִٸ� �ּ�/�ִ��� ��� ����)
// �ִ�, �ּ� �� ��� �迭 �ϳ��� -> �޸��ʰ�

// ���� �Է� �� ������ �迭 �ʿ� X
// �ִ�, �ּ� �迭 �ΰ����� �־ ��! (�ٷ� �������� �̹��� ������ ����)
// for�� ���ư��鼭 �־��ֱ�

int DP_min[2][3];
int DP_max[2][3];

int main()
{
	int n;
	cin >> n;

	int a;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a;
			if (i == 0)
			{
				DP_min[0][j] = a;
				DP_max[0][j] = a;
			}
			else // i > 0
			{
				// max
				int tmp_max = DP_max[0][j];
				if (j - 1 >= 0 && tmp_max < DP_max[0][j - 1]) tmp_max = DP_max[0][j - 1];
				if (j + 1 < 3 && tmp_max < DP_max[0][j + 1]) tmp_max = DP_max[0][j + 1];
				DP_max[1][j] = tmp_max + a;

				// min
				int tmp_min = DP_min[0][j];
				if (j - 1 >= 0 && tmp_min > DP_min[0][j - 1]) tmp_min = DP_min[0][j - 1];
				if (j + 1 < 3 && tmp_min > DP_min[0][j + 1]) tmp_min = DP_min[0][j + 1];
				DP_min[1][j] = tmp_min + a;
			}

			
		}
		// ���ٷ� �����
		if (i != 0)
		{
			for (int r = 0; r < 3; r++)
			{
				DP_min[0][r] = DP_min[1][r];
				DP_max[0][r] = DP_max[1][r];
			}
		}
	}

	// �� ������ �� (n-1) �ִ�, �ּ� ���
	int max = DP_max[0][0];
	for (int i = 1; i < 3; i++)
	{
		if (max < DP_max[0][i]) max = DP_max[0][i];
	}

	int min = DP_min[0][0];
	for (int i = 1; i < 3; i++)
	{
		if (min > DP_min[0][i]) min = DP_min[0][i];
	}

	cout << max << ' ' << min;

	return 0;
}