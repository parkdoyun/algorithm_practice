#include <iostream>
#include <queue>

using namespace std;

// swea 5653 - �ٱ⼼�� ���

// bfs�� ������
// 300�ð��̹Ƿ� �ִ� �� �������� 150 ����
// board ũ�� 500 * 500
// ������ (225, 225) ~ (275, 275)
// pq ��� -> ������ �ϴ� ������ ���� ���� �ֵ���� ������
// �ʱ���� : ���� 0

int board[500][500];
int chk[500][500];
int dead_time[500][500]; // �״� �ð� ��� => ���߿� �̰� Ȯ���ؼ� 0 �ƴϰ� �ð� ���� �� ���� �ֵ� ī��Ʈ
int n, m, k;

struct node
{
	int y;
	int x;
	int life; // �����
	int time = 0; // ����
};

bool operator<(node n1, node n2)
{
	if (n1.time > n2.time) return true;
	else if (n1.time == n2.time && n1.life < n2.life) return true; // ����� �� ���� �� �켱����
	return false;

}

// pq���� ������ �͵� �� k + 1 �ð��� �ֵ� ������ break
priority_queue<node> pq;
int x_mov[] = { 0 ,0, -1, 1 };
int y_mov[] = { 1, -1, 0, 0 };
int now_time = 0;
void BFS()
{
	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (tmp.time > k)
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y_mov[i] >= 0 && tmp.y + y_mov[i] < 500 &&
				tmp.x + x_mov[i] >= 0 && tmp.x + x_mov[i] < 500 &&
				chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0 &&
				board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0)
			{
				chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = 1;
				board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = tmp.life;
				dead_time[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = tmp.time + tmp.life * 2;
				pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.life, tmp.time + tmp.life + 1});
			}
		}

	}
}

void boardInit()
{
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			board[i][j] = 0;
			chk[i][j] = 0;
			dead_time[i][j] = 0;
		}
	}
}

int chkTime()
{
	int cnt = 0;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			if (dead_time[i][j] != 0 && dead_time[i][j] > k) cnt++;
		}
	}
	return cnt;
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		boardInit();
		while (!pq.empty()) pq.pop();

		cin >> n >> m >> k;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[i + 225][j + 225];
				if (board[i + 225][j + 225] != 0)
				{
					// queue�� �ֱ�
					chk[i + 225][j + 225] = 1;
					dead_time[i + 225][j + 225] = board[i + 225][j + 225] * 2;
					pq.push({ i + 225, j + 225, board[i + 225][j + 225], 1 + board[i + 225][j + 225] });

				}
			}
		}

		BFS();

		cout << '#' << tc << ' ' << chkTime() << '\n';
	}

	return 0;
}