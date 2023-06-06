#include <iostream>
#include <queue>

using namespace std;

// 백준 25173 - 용감한 아리의 동굴 대탈출
// 구현, BFS
// 골드 1

// 시간 초과 -> 만약 석순 없다면 바로 패스

int n, m;
int board[51][51];
int y_mov[] = { -1, 0, 1, 0 };
int x_mov[] = { 0, 1, 0, -1 };
int ay, ax, adir; // 아리 위치, 방향
int prev_ay, prev_ax; // 이전 아리 위치
int ahp, apower; // 아리 체력, 공격력
int by, bx, bdir; // 보스 위치, 방향
int bhp, bpower; // 보스 체력, 공격력
int my, mx, mdir; // 부하 몬스터
int mhp; // 부하 몬스터 체력
int s_cnt = 0; // 석순 갯수

bool ari_attack() // 아리 공격
{
	bhp -= apower;
	if (bhp <= 0) return true;
	return false;
}
bool ari_mov() // 아리 이동
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

	// 이동 X, 제자리
	return false;
}

bool find_mon() // 석순 찾기
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
void monster_attack() // 부하 몬스터 공격 -> BFS
{
	// 초기화
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

		if (tmp.dir >= mhp) return; // 갈 수 없음, 체력 부족
		if (board[tmp.y][tmp.x] == 2) // 아리
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

bool boss_attack() // 보스 몬스터 공격
{
	if (!find_mon()) return false; // 석순 못 찾았을 때

	mhp = bpower;
	monster_attack();

	if (ahp <= 0) return true;
	return false;
}

void boss_mov() // 보스 이동
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
			else if (board[i][j] == 2) // 아리
			{
				ay = i;
				ax = j;
			}
			else if (board[i][j] == 3) // 보스
			{
				by = i;
				bx = j;
			}
		}
	}
	cin >> ahp >> apower >> bhp >> bpower;

	// 아리, 보스 초기 방향 설정
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