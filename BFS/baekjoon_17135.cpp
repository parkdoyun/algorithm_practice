#include <iostream>
#include <queue>

using namespace std;

// ���� 17135 - ĳ�� ���潺
// ��� 3

// bfs
// sliding window

int board_origin[31][16];
int board[31][16]; // 15������ ~ (15 + n - 1)�� : sliding window
int chk[31][16];

// �ü��� �׻� 3��
// for�� 3�� ������ �ü� ��ġ (�ü��� ������ n + 1 �࿡)
// BFS ������ ��� ���� �� �ִ��� Ȯ��
// n��ŭ �ü��� 1��ŭ �÷��� Ȯ���ϸ� ��(�ִ� 15)
// ���� �Ÿ��� ���� ������ ��� -> ���� ���� -> pq ���

// �ݷ� : *���ÿ�* �� �ü��� ���� ���־� �Ѵ�
// �̸��̸� ���ָ� �ü��� ���� �� ���ִ� ��� ������ ���� 
// �������� ���� �� ���ִ� ��� ����

int n, m, d;
int tmp_cnt; // ����
int max1 = 0; // �ִ밪
int x_mov[] = { -1, 1, 0, 0 };
int y_mov[] = { 0, 0, -1, 1 };

struct archer
{
	int y = -1;
	int x = -1;
	int dist;
};

archer arc_arr[3]; // �ü� ����
archer goal[3]; // ���� ���ÿ� ���־� �ϴ� �ֵ� ��

void chkClear()
{
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < m; j++) chk[i][j] = 0;
	}
}

void copyBoard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			board[i + 15][j] = board_origin[i + 15][j];
		}
	}
}

int now_y_start, now_y_end; // ���� �̵��� �� ��
// BFS -> �ü��� �̵�

bool operator<(archer a1, archer a2)
{
	if (a1.dist > a2.dist) return true;
	else if (a1.dist == a2.dist && a1.x > a2.x) return true;
	return false;
}

priority_queue<archer> pq;

void BFS(int start_y, int start_x, int idx)
{
	chkClear();
	while (!pq.empty()) pq.pop();

	chk[start_y][start_x] = 1;
	pq.push({ start_y, start_x, 0 });

	while (!pq.empty())
	{
		archer tmp = pq.top();
		pq.pop();
		if (board[tmp.y][tmp.x] == 1)
		{
			//board[tmp.y][tmp.x] = 0;
			//tmp_cnt++;
			goal[idx].y = tmp.y;
			goal[idx].x = tmp.x;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y_mov[i] >= now_y_start && tmp.y + y_mov[i] < now_y_end &&
				tmp.x + x_mov[i] >= 0 && tmp.x + x_mov[i] < m &&
				chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0 && 
				tmp.dist < d)
			{
				chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = 1;
				pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1 });
			}
		}
	}
}


int main()
{
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board_origin[i + 15][j];
		}
	}

	// �ü� ���� for�� ������ ���� ��
	// �ü� ��ġ�� ���ʷ� ���� �÷����� tmp �� ����
	// tmp ���� max �� ��
	
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			for (int r = j + 1; r < m; r++)
			{
				arc_arr[0].y = 15 + n;
				arc_arr[1].y = 15 + n;
				arc_arr[2].y = 15 + n;

				arc_arr[0].x = i;
				arc_arr[1].x = j;
				arc_arr[2].x = r;

				tmp_cnt = 0;

				copyBoard();
				//chkClear();
				now_y_start = 15;
				now_y_end = 15 + n;

				goal[0].y = -1;
				goal[0].x = -1;
				goal[1].y = -1;
				goal[1].x = -1;
				goal[2].y = -1;
				goal[2].x = -1;


				for (int k = 0; k < n; k++)
				{
					for (int r = 0; r < 3; r++)
					{
						BFS(arc_arr[r].y, arc_arr[r].x, r);
					}

					// ���ÿ� ���ֱ�
					// ���� y�� x -1�̶�� pass
					// �̹� �������ٸ� pass
					for (int r = 0; r < 3; r++)
					{
						if (goal[r].y == -1 && goal[r].x == -1) continue;
						if (board[goal[r].y][goal[r].x] == 1)
						{
							board[goal[r].y][goal[r].x] = 0;
							tmp_cnt++;
						}
					}

					now_y_start--;
					now_y_end--;
					arc_arr[0].y--;
					arc_arr[1].y--;
					arc_arr[2].y--;
				}
				if (max1 < tmp_cnt) max1 = tmp_cnt;
			}
		}
	}


	cout << max1;
	
	return 0;
}