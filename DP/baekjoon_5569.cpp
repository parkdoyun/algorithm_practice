#include <iostream>

using namespace std;

// ���� 5569 - ��� ���
// DP
// ��� 4

// �� ���� 2���� ���� ���� ��
// DP1[i][j] : i, j�κ��� ���� ���� �ֵ�
// DP2[i][j] : i, j�κ��� ���������� ���� �ֵ�
// DP1[i][j] = DP1[i - 1][j] + DP2[i][j - 2]
// DP2[i][j] = DP2[i][j - 1] + DP1[i - 2][j]

int w, h;
int DP1[101][101];
int DP2[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h;

	// ����
	if (w == 1 && h == 1)
	{
		cout << 1;
		return 0;
	}

	// ���� ����
	for (int i = 1; i <= w; i++)
	{
		DP1[1][i] = 1;
	}
	for (int j = 1; j <= h; j++)
	{
		DP2[j][1] = 1;
	}

	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			if (i == h && j == w)
			{
				DP1[i][j] = DP1[i - 1][j];
				DP2[i][j] = DP2[i][j - 1];
				break;
			}
			DP1[i][j] = (DP1[i - 1][j] + DP2[i][j - 2]) % 100000;
			DP2[i][j] = (DP2[i][j - 1] + DP1[i - 2][j]) % 100000;
		}
	}

	cout << (DP1[h][w] + DP2[h][w]) % 100000; // ������ ��� �� �ߺ��Ǵ� �� ���� ��

	return 0;
}