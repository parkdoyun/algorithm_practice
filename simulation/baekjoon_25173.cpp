#include <iostream>
#include <queue>

using namespace std;

// ���� 25173 - �밨�� �Ƹ��� ���� ��Ż��
// ����, BFS
// ��� 1

// �ð� �ʰ� -> ���� ���� ���ٸ� �ٷ� �н�

int n, m;
int board[51][51];
int y_mov[] = { -1, 0, 1, 0 };
int x_mov[] = { 0, 1, 0, -1 };
int ay, ax, adir; // �Ƹ� ��ġ, ����
int prev_ay, prev_ax; // ���� �Ƹ� ��ġ
int ahp, apower; // �Ƹ� ü��, ���ݷ�
int by, bx, bdir; // ���� ��ġ, ����
int bhp, bpower; // ���� ü��, ���ݷ�
int my, mx, mdir; // ���� ����
int mhp; // ���� ���� ü��
int s_cnt = 0; // ���� ����

bool ari_attack() // �Ƹ� ����
{
	bhp -= apower;
	if (bhp <= 0) return true;
	return false;
}
bool ari_mov() // �Ƹ� �̵�
{
	int ty, tx;
	for (int i = 0; i < 4; i++)
	{
		if (i != 0) ahp--;
		if (ahp <= 0) return true;

		ty = ay + y_mov[(adir + i) % 4];
		tx = ax + x_mov[(adir + i) % 4];
		if (ty >= 0 && ty < n && tx >= 0 && tx < m && board[ty][tx] == 0)
		{
			prev_ay = ay;
			prev_ax = ax;

			board[ty][tx] = 2;
			board[ay][ax] = 0;
			ay = ty;
			ax = tx;
			adir = (adir + i) % 4;
			return false;
		}
	}

	ahp--;
	if (ahp <= 0) return true;

	// �̵� X, ���ڸ�
	return false;
}

bool find_mon() // ���� ã��
{
	int find_cnt = 1;
	int board_cnt = 0;
	int tmp_dir = bdir;
	int len = 1;
	int ty = by;
	int tx = bx;

	ty += y_mov[tmp_dir];
	tx += x_mov[tmp_dir];
	if (ty >= 0 && ty < n && tx >= 0 && tx < m)
	{
		board_cnt++;
		if (board[ty][tx] == 1)
		{
			my = ty;
			mx = tx;
			return true;
		}
	}

	while (board_cnt < n * m)
	{
		tmp_dir = (tmp_dir + 1) % 4;
		if (find_cnt % 2 == 0) len++;
		for (int i = 0; i < len; i++)
		{
			ty += y_mov[tmp_dir];
			tx += x_mov[tmp_dir];
			if (ty >= 0 && ty < n && tx >= 0 && tx < m)
			{
				board_cnt++;
				if (board[ty][tx] == 1)
				{
					my = ty;
					mx = tx;
					return true;
				}
				if (board_cnt >= n * m) break;
			}
		}
		find_cnt++;
	}
	return false;
}

int visit[51][51];
struct node
{
	int y;
	int x;
	int dir;
};
bool operator<(node n1, node n2)
{
	return n1.dir > n2.dir;
}
queue<node> pq;
void monster_attack() // ���� ���� ���� -> BFS
{
	// �ʱ�ȭ
	while (!pq.empty()) pq.pop();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) visit[i][j] = 0;
	}

	// BFS
	pq.push({ my, mx, 0 });
	int ty, tx;
	while (!pq.empty())
	{
		node tmp = pq.front();
		pq.pop();

		if (visit[tmp.y][tmp.x] == 1) continue;
		visit[tmp.y][tmp.x] = 1;

		if (tmp.dir >= mhp) return; // �� �� ����, ü�� ����
		if (board[tmp.y][tmp.x] == 2) // �Ƹ�
		{
			ahp -= (mhp - tmp.dir);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];
			if (ty >= 0 && ty < n && tx >= 0 && tx < m && (board[ty][tx] == 0 || board[ty][tx] == 2))
			{
				pq.push({ ty, tx, tmp.dir + 1 });
			}
		}
	}
}

bool boss_attack() // ���� ���� ����
{
	if (!find_mon()) return false; // ���� �� ã���� ��

	mhp = bpower;
	monster_attack();

	if (ahp <= 0) return true;
	return false;
}

void boss_mov() // ���� �̵�
{
	if (prev_ay == ay && prev_ax == ax) return;
	board[by][bx] = 0;
	by = prev_ay;
	bx = prev_ax;
	bdir = adir;
	board[by][bx] = 3;
}

bool simulation()
{
	while (true)
	{
		if (ari_attack()) break;		
		if (ari_mov()) break;
		if (s_cnt > 0 && boss_attack()) break;
		boss_mov();
	}

	if (bhp <= 0) return true;
	else return false;
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
			if (board[i][j] == 1) s_cnt++;
			else if (board[i][j] == 2) // �Ƹ�
			{
				ay = i;
				ax = j;
			}
			else if (board[i][j] == 3) // ����
			{
				by = i;
				bx = j;
			}
		}
	}
	cin >> ahp >> apower >> bhp >> bpower;

	// �Ƹ�, ���� �ʱ� ���� ����
	if (ay == by)
	{
		if (ax < bx)
		{
			adir = 3;
			bdir = 3;
		}
		else
		{
			adir = 1;
			bdir = 1;
		}
	}
	else // ax == bx
	{
		if (ay < by)
		{
			adir = 0;
			bdir = 0;
		}
		else
		{
			adir = 2;
			bdir = 2;
		}
	}

	prev_ay = ay;
	prev_ax = ax;

	if (simulation()) cout << "VICTORY!";
	else cout << "CAVELIFE...";

	return 0;
}