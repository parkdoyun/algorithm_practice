#include <iostream>

using namespace std;

// swea 4013 - Ư���� �ڼ�
// brute-force

// pointer 6��
// arr[0] 1�� + 1�� (������ ȭ��ǥ)
// arr[1] 2�� + 1��
// arr[2] 2�� + 1
// arr[3] 1�� + 1

int arr[4][9];
int point[4][3]; // idx 0 : ������ ȭ��ǥ, idx 1 : 3��, idx 2 : 9��
int point_cp[4][3];
int sco[4] = { 1, 2, 4, 8 };

void rotation(int num, int dir) // �ð� 1, �ݽð� -1
{
	// ���纻 �������ٰ� point�� �ѹ��� �����Ű��

	// arr[num] ȸ��
	for (int i = 0; i < 3; i++)
	{
		point_cp[num][i] = point_cp[num][i] - dir;
		// 0���� �۰ų� 7���� ũ�ٸ�
		if (point_cp[num][i] < 0) point_cp[num][i] = 7;
		else if (point_cp[num][i] > 7) point_cp[num][i] = 0;
	}
	
	// num �յ� ���� Ȯ��
	int tmp_dir = dir;
	for (int i = num - 1; i >= 0; i--)
	{
		if (arr[i + 1][point[i + 1][2]] == arr[i][point[i][1]]) break;
		tmp_dir = tmp_dir * -1; // �ݴ� ����
		for (int j = 0; j < 3; j++)
		{
			point_cp[i][j] = point_cp[i][j] - tmp_dir;
			// 0���� �۰ų� 7���� ũ�ٸ�
			if (point_cp[i][j] < 0) point_cp[i][j] = 7;
			else if (point_cp[i][j] > 7) point_cp[i][j] = 0;
		}
	}

	tmp_dir = dir;
	for (int i = num + 1; i < 4; i++)
	{
		if (arr[i-1][point[i - 1][1]] == arr[i][point[i][2]]) break;
		tmp_dir = tmp_dir * -1; // �ݴ� ����
		for (int j = 0; j < 3; j++)
		{
			point_cp[i][j] = point_cp[i][j] - tmp_dir;
			// 0���� �۰ų� 7���� ũ�ٸ�
			if (point_cp[i][j] < 0) point_cp[i][j] = 7;
			else if (point_cp[i][j] > 7) point_cp[i][j] = 0;
		}
	}

	// point�� �ѹ��� ����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++) point[i][j] = point_cp[i][j];
	}
}

int main()
{
	int T, k, score;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> k;

		for (int i = 0; i < 4; i++)
		{
			// �ʱ�ȭ
			point[i][0] = 0;
			point[i][1] = 2;
			point[i][2] = 6;
			
			for (int j = 0; j < 3; j++)
			{
				point_cp[i][j] = point[i][j];
			}

			for (int j = 0; j < 8; j++)
			{
				cin >> arr[i][j];
			}
		}

		int num, dir;
		for (int i = 0; i < k; i++)
		{
			cin >> num >> dir; // �ٷ� ȸ��
			num--;

			rotation(num, dir);

			for (int i = 0; i < 4; i++)
			{
				//cout << i << ':' << arr[i][point[i][0]] << ' ' << arr[i][point[i][1]] << ' ' << arr[i][point[i][2]] << '\n';
			}
		}

		score = 0;
		for (int i = 0; i < 4; i++)
		{
			if (arr[i][point[i][0]] == 1) score += sco[i];
		}

		cout << '#' << tc << ' ' << score << '\n';
	}


	return 0;
}