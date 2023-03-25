#include <iostream>

using namespace std;

// ���� 2590 - ������
// greedy
// ��� 4

// 6�� �����̴� ������ �� 1�� ���
// 5�� �����̴� 1�� �����̿� ��� ����
// 4�� �����̴� 1��, 2�� �����̿� ��� ����
// 3�� �����̴� 1, 2, 3�� �����̿� ��� ���� 

int paper[7];
int total_cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 6; i++)
	{
		cin >> paper[i];
	}
	total_cnt = paper[6];

	// 5�� ������ ä���
	// �� �ǿ� 5�� ������ �Ѱ��� �ִ� 1�� ������ 11�� ����
	for (int i = 0; i < paper[5]; i++)
	{
		total_cnt++;
		if (paper[1] < 11) paper[1] = 0;
		else paper[1] -= 11;
	}

	// 4�� ������ ä���
	// �� �ǿ� 2�� ������ 5�� ����
	// 1�� �����̴� ���� ������ŭ ����
	int tmp;
	for (int i = 0; i < paper[4]; i++)
	{
		total_cnt++;
		if (paper[2] < 5)
		{
			tmp = (5 - paper[2]) * 4;
			paper[2] = 0;
			if (paper[1] > tmp) paper[1] -= tmp;
			else paper[1] = 0;
		}
		else paper[2] -= 5;
	}

	// 3�� ������ ä���
	while (paper[3] > 0)
	{
		total_cnt++;
		if (paper[3] <= 4) // ������ ��
		{
			if (paper[3] == 1) // 2�� �ִ� 5��
			{
				if (paper[2] >= 5)
				{
					paper[2] -= 5;
					if (paper[1] >= 7) paper[1] -= 7;
					else paper[1] = 0;
				}
				else
				{
					tmp = 27 - paper[2] * 4;
					paper[2] = 0;
					if (paper[1] >= tmp) paper[1] -= tmp;
					else paper[1] = 0;
				}
			}
			else if (paper[3] == 2) // 2�� �ִ� 3��
			{
				if (paper[2] >= 3)
				{
					paper[2] -= 3;
					if (paper[1] >= 6) paper[1] -= 6;
					else paper[1] = 0;
				}
				else
				{
					tmp = 18 - paper[2] * 4;
					paper[2] = 0;
					if (paper[1] >= tmp) paper[1] -= tmp;
					else paper[1] = 0;
				}
			}
			else if (paper[3] == 3) // 2�� �ִ� 1��
			{
				if (paper[2] >= 1)
				{
					paper[2] -= 1;
					if (paper[1] >= 6) paper[1] -= 6;
					else paper[1] = 0;
				}
				else
				{
					if (paper[1] >= 9) paper[1] -= 9;
					else paper[1] = 0;
				}
			}
			break;
		}
		paper[3] -= 4;
	}

	// 1��, 2�� �������� ä���
	while (paper[1] > 0 || paper[2] > 0)
	{
		total_cnt++;
		if (paper[2] >= 9)
		{
			paper[2] -= 9;
		}
		else
		{
			tmp = 36 - paper[2] * 4;
			paper[2] = 0;
			if (paper[1] >= tmp) paper[1] -= tmp;
			else paper[1] = 0;
		}
	}

	cout << total_cnt;

	return 0;
}