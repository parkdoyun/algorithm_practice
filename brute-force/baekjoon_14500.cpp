#include <iostream>

using namespace std;

// ���� 14500 - ��Ʈ�ι̳�
// brute-force
// ��� 4

// �ϳ�(������)�� ��� �����ؼ� ���ϸ� ��, �������� DFS�� �ڵ� �������

int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int max1 = 0;
int n, m;
int board[501][501];
int chk[501][501];

void DFS(int lv, int y, int x, int score)
{
	if (lv == 4)
	{
		if (score > max1) max1 = score;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < m &&
			chk[y + y_mov[i]][x + x_mov[i]] == 0)
		{
			chk[y + y_mov[i]][x + x_mov[i]] = 1;
			DFS(lv + 1, y + y_mov[i], x + x_mov[i], score + board[y + y_mov[i]][x + x_mov[i]]);
			chk[y + y_mov[i]][x + x_mov[i]] = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int last_score[4];
	int last_cnt, total_last_score;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			chk[i][j] = 1;
			DFS(1, i, j, board[i][j]);
			chk[i][j] = 0;

			// ������ ��� Ȯ��
			last_cnt = 0; // -1 ī��Ʈ
			total_last_score = board[i][j];
			for (int k = 0; k < 4; k++)
			{
				if (i + y_mov[k] >= 0 && i + y_mov[k] < n &&
					j + x_mov[k] >= 0 && j + x_mov[k] < m)
				{
					last_score[k] = board[i + y_mov[k]][j + x_mov[k]];
					total_last_score += last_score[k];
				}
				else
				{
					last_score[k] = -1;
					last_cnt++;
				}
			}
			if (last_cnt >= 2) continue;
			if (last_cnt == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (total_last_score - last_score[k] > max1) max1 = total_last_score - last_score[k];
				}
			}
			else if (last_cnt == 1)
			{
				if (total_last_score > max1) max1 = total_last_score;
			}
		}
	}

	cout << max1;
	return 0;
}