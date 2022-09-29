#include <iostream>

using namespace std;

// ���� 17404 - RGB �Ÿ�2
// DP
// ��� 4

// ù��° �� ���� �� (r/g/b) 
// ex ù��°�� r�� ��) �� ù��° �����κ��� ���� �� �ִ� ������ ����� �� ��� ���Ѵ�.(�� �������� g,b�� Ȯ���ϸ� ��)
// �� �� r���� ���� �� �ִ� �� �ΰ�(������ g, b) �� �ּ� ���� => r�� ������ ���� �ּҰ�
// �̷��� g, b���� �����ϴ� �ֵ鵵 ���ؼ�
// ���� �� �ּ� ���ϸ� �ȴ�.

int arr[1001][3];
int DP[1002][3];

int min_val[3]; // �ּ� ���� ����

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int r = 0; r < 3; r++)
	{
		for (int i = 0; i < 3; i++) // ù��° ��� �����ϰ� ū ������ ����� => ó���� ���� �� �ż� r�� ���۵� �ֵ鸸 DP �ǵ���
		{
			if (i == r) DP[0][i] = arr[0][i];
			else DP[0][i] = 10000001;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				
				if (j == 0)
				{
					DP[i][j] = arr[i][j] + (DP[i - 1][1] < DP[i - 1][2] ? DP[i - 1][1] : DP[i - 1][2]);
				}
				else if (j == 1)
				{
					DP[i][j] = arr[i][j] + (DP[i - 1][0] < DP[i - 1][2] ? DP[i - 1][0] : DP[i - 1][2]);
				}
				else // j == 2
				{
					DP[i][j] = arr[i][j] + (DP[i - 1][1] < DP[i - 1][0] ? DP[i - 1][1] : DP[i - 1][0]);
				}
			
			}
		}

		// �ּ� �ֱ�
		int min = 10000000;
		for (int i = 0; i < 3; i++)
		{
			if (i == r) continue;
			if (min > DP[n - 1][i]) min = DP[n - 1][i];
		}
		min_val[r] = min;
	}

	// �� �� �ּ� ���
	int min = 10000000;

	for (int i = 0; i < 3; i++)
	{
		if (min_val[i] < min) min = min_val[i];
	}

	cout << min;

	return 0;
}