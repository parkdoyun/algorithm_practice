#include <iostream>

using namespace std;

// ���� 20057 - ������ ���� ����̵�
// simulation
// ��� 3

// ������ ������ �̵��� �� = ����̵� �𳯸��� �� �� �� - ���� ��

int n;
int sand[501][501];

int y_mov[] = { 0, 1, 0, -1 }; // 0 ��, 1 ��, 2 ��, 3 ��
int x_mov[] = { -1, 0, 1, 0 };

// �� ����
int sand_proposition[9] = { 2, 10, 7, 1, 5, 10, 7, 1, 2 };

// �̵��ϴ� �� ����
int sand_dir_x[4][9] =
{
	{0, -1, 0, 1, -2, -1, 0, 1, 0}, // ��
	{2, 1, 1, 1, 0, -1, -1, -1, -2}, // ��
	{0, 1, 0, -1, 2, 1, 0, -1, 0}, // ��
	{2, 1, 1, 1, 0, -1, -1, -1, -2} // ��
};

int sand_dir_y[4][9] =
{
	{-2, -1, -1, -1, 0, 1, 1, 1, 2}, // ��
	{0, 1, 0, -1, 2, 1, 0, -1, 0}, // ��
	{-2, -1, -1, -1, 0, 1, 1, 1, 2}, // ��
	{0, -1, 0, 1, -2, -1, 0, 1, 0}, // ��
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> sand[i][j];
			total += sand[i][j];
		}
	}

	int sy = n / 2;
	int sx = n / 2;
	int dir = 0;


	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int r = 0; r < i; r++)
			{
				sy += y_mov[dir];
				sx += x_mov[dir];

				// �� �𳯸���
				int now = sand[sy][sx];
				int tmp = sand[sy][sx]; // alpha�� ���� ��
				for (int r = 0; r < 9; r++)
				{
					if (sy + sand_dir_y[dir][r] >= 0 && sy + sand_dir_y[dir][r] < n &&
						sx + sand_dir_x[dir][r] >= 0 && sx + sand_dir_x[dir][r] < n)
					{
						sand[sy + sand_dir_y[dir][r]][sx + sand_dir_x[dir][r]] += (int)(now * sand_proposition[r] / 100);
						//tmp -= (int)(now * sand_proposition[r] / 100);
					}
					tmp -= (int)(now * sand_proposition[r] / 100);
				}
				sand[sy][sx] = 0;
				if (sy + y_mov[dir] >= 0 && sy + y_mov[dir] < n &&
					sx + x_mov[dir] >= 0 && sx + x_mov[dir] < n)
				{
					sand[sy + y_mov[dir]][sx + x_mov[dir]] += tmp;
				}
			}
			dir++;
			dir = dir % 4;
		}
	}

	// ���������� �ѹ� �� ������

	for (int r = 0; r < n - 1; r++)
	{
		sy += y_mov[dir];
		sx += x_mov[dir];

		// �� �𳯸���
		int now = sand[sy][sx];
		int tmp = sand[sy][sx]; // alpha�� ���� ��
		for (int r = 0; r < 9; r++)
		{
			if (sy + sand_dir_y[dir][r] >= 0 && sy + sand_dir_y[dir][r] < n &&
				sx + sand_dir_x[dir][r] >= 0 && sx + sand_dir_x[dir][r] < n)
			{
				sand[sy + sand_dir_y[dir][r]][sx + sand_dir_x[dir][r]] += (int)(now * sand_proposition[r] / 100);
				//tmp -= (int)(now * sand_proposition[r] / 100);
			}
			tmp -= (int)(now * sand_proposition[r] / 100);
		}
		sand[sy][sx] = 0;
		if (sy + y_mov[dir] >= 0 && sy + y_mov[dir] < n &&
			sx + x_mov[dir] >= 0 && sx + x_mov[dir] < n)
		{
			sand[sy + y_mov[dir]][sx + x_mov[dir]] += tmp;
		}
	}

	int minus_val = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			minus_val += sand[i][j];
		}
	}
	
	cout << total - minus_val;


	return 0;
}