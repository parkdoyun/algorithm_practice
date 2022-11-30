#include <iostream>
#include <string>

using namespace std;

// ���� 2602 - ���ٸ� �ǳʱ�
// DP
// ��� 4

// ù���� ���� üũ
// �ι�° ���� -> ������ �ٸ����� ������ ���� ù��° �ֵ� �� ���ϱ�
// ������ ���� �� ������ �� ���ؼ� ���
// 3���� �迭

int bridge[21][2][101]; // bridge[][0] : �Ǹ� �ٸ�, bridge[][1] : õ�� �ٸ�

int main()
{
	string magic, devil, angel;

	cin >> magic >> devil >> angel;

	// ù ����
	for (int j = 0; j < devil.length(); j++)
	{
		if (magic[0] == devil[j])
		{
			bridge[0][0][j]++;
		}
		if (magic[0] == angel[j])
		{
			bridge[0][1][j]++;
		}
	}

	for (int i = 1; i < magic.length(); i++)
	{
		for (int j = 0; j < devil.length(); j++)
		{
			if (magic[i] == devil[j]) // ������ �� ���� ���� �͵� ������
			{
				for (int k = 0; k < j; k++)
				{
					if (bridge[i - 1][1][k] > 0) bridge[i][0][j] += bridge[i - 1][1][k];
				}
			}
			if (magic[i] == angel[j]) // ������ �� ���� ���� �͵� ������
			{
				for (int k = 0; k < j; k++)
				{
					if (bridge[i - 1][0][k] > 0) bridge[i][1][j] += bridge[i - 1][0][k];
				}
			}
		}
	}

	// ��� ���
	int total_cnt = 0;
	int t_len = magic.length() - 1;
	for (int i = 0; i < angel.length(); i++)
	{
		total_cnt += bridge[t_len][0][i];
		total_cnt += bridge[t_len][1][i];
	}

	cout << total_cnt;

	return 0;
}