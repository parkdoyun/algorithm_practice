#include <iostream>
#include <queue>

using namespace std;

// swea 5656 - ���� ����
// ��� ����� �� �� �غ��� ���� ���� �� �� ���
// ����� �� => DFS, backtracking
// ���������� ������ -> BFS �̿�

// 3�� �迭�� ���� -> ���ƾ� 4�ܰ� ���� ����
int board[16][13];
int board_cp[5][16][13]; // �̰ɷ� �ùķ��̼� ���
int n, w, h;
int max1; // n�ܰ� �� ���� ���� ���� ���� ���� ��

// ���߸��� ���� �Լ�
// ���ÿ� ���ŵǰ� -> ���߿� �� ������ ������
// ���߸� ���� �� ��ȯ
struct brick
{
	int y;
	int x;
	int size; // ����
};
queue<brick> q;

int startH(int x, int lv) // �� ��ġ���� ����߸��� ���� ��𿡼� ��������?
{
	int res_y = -1;
	for (int i = 0; i < h; i++)
	{
		if (board_cp[lv][i][x] != 0)
		{
			res_y = i;
			break;
		}
	}

	return res_y;
}

int removeBricks(int start_x, int start_y, int lv)
{
	int res = 0;

	// ���� �ܰ��� ���� ��� ������
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) board_cp[lv][i][j] = board_cp[lv - 1][i][j];
	}

	// ���߸��� (bfs)
	// �ʱ�ȭ
	while (!q.empty()) q.pop();
	q.push({ start_y, start_x, board_cp[lv][start_y][start_x] });
	res = 1;
	
	while (!q.empty())
	{
		brick tmp = q.front();
		q.pop();

		board_cp[lv][tmp.y][tmp.x] = 0;

		// �����¿� Ȯ��
		for (int i = 1; i < tmp.size; i++)
		{
			// ��
			if (tmp.y + i < h && board_cp[lv][tmp.y + i][tmp.x] != 0)
			{
				res++;
				if (board_cp[lv][tmp.y + i][tmp.x] == 1)
				{
					board_cp[lv][tmp.y + i][tmp.x] = 0;
				}
				else q.push({ tmp.y + i, tmp.x, board_cp[lv][tmp.y + i][tmp.x] });
			}
			// ��
			if (tmp.y - i >= 0 && board_cp[lv][tmp.y - i][tmp.x] != 0)
			{
				res++;
				if (board_cp[lv][tmp.y - i][tmp.x] == 1)
				{
					board_cp[lv][tmp.y - i][tmp.x] = 0;
				}
				else q.push({ tmp.y - i, tmp.x, board_cp[lv][tmp.y - i][tmp.x] });
			}
			// ��
			if (tmp.x + i < w && board_cp[lv][tmp.y][tmp.x + i] != 0)
			{
				res++;
				if (board_cp[lv][tmp.y][tmp.x + i] == 1)
				{
					board_cp[lv][tmp.y][tmp.x + i] = 0;
				}
				else q.push({ tmp.y, tmp.x + i, board_cp[lv][tmp.y][tmp.x + i] });
			}
			// ��
			if (tmp.x - i >= 0 && board_cp[lv][tmp.y][tmp.x - i] != 0)
			{
				res++;
				if (board_cp[lv][tmp.y][tmp.x - i] == 1)
				{
					board_cp[lv][tmp.y][tmp.x - i] = 0;
				}
				else q.push({ tmp.y, tmp.x - i, board_cp[lv][tmp.y][tmp.x - i] });
			}
		}
	}


	// ������ ������
	for (int i = 0; i < w; i++)
	{
		int arr_h[16] = { 0 };
		int idx = 0;
		for (int j = 0; j < h; j++)
		{
			if (board_cp[lv][j][i] != 0)
			{
				arr_h[idx] = board_cp[lv][j][i];
				idx++;
				board_cp[lv][j][i] = 0;
			}
		}

		// �ٽ� �ֱ�
		int k = 0;
		for (int j = h - idx; j < h; j++)
		{
			board_cp[lv][j][i] = arr_h[k];
			k++;
		}
	}

	return res;
}

void DFS(int lv)
{
	if (lv == n + 1)
	{
		// ���⼭ check
		int res = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board_cp[n][i][j] != 0) res++;
			}
		}
		if (max1 > res) max1 = res;
		return;
	}

	for (int i = 0; i < w; i++)
	{
		int start_y = startH(i, lv - 1);
		if (start_y == -1) continue;
		// ���߸���
		removeBricks(i, start_y, lv);
		
		DFS(lv + 1);
	}
}

int main()
{
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> w >> h;
		max1 = 10000; // ���� ���� �� ��
		int total_cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				board_cp[0][i][j] = board[i][j];
				if (board[i][j] != 0) total_cnt++;
			}
		}

		for (int i = 0; i < w; i++)
		{
			
			int start_y = startH(i, 0);

			if (start_y == -1) continue;

			// ���߸���
			removeBricks(i, start_y, 1);

			// DFS
			DFS(2);
		}

		if (max1 == 10000) max1 = 0; // �ƹ��͵� ���߸� �� ���ٸ�
		cout << '#' << tc << ' ' << max1 << '\n';
	}

	return 0;
}