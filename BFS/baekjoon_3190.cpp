#include <iostream>
#include <queue>

using namespace std;

// ���� 3190 - ��
// BFS, queue
// ��� 4

// ���� queue�� => head�� q.back(), tail�� q.front()

int n, k, l;
int board[101][101];
// ��, ��, ��, �� (���� Ŀ������ ������ �̵�, ���� �۾������� ���� �̵�)
int y_mov[] = { -1, 0, 1, 0 };
int x_mov[] = { 0, 1, 0, -1 };
int now_dir = 1; // ó���� ������

struct direction
{
	int time;
	int dir; // -1 : ����, 1 : ������
};
struct node
{
	int y;
	int x;
};
queue<direction> q_dir;
queue<node> snake; // ��

int BFS()
{
	snake.push({ 0, 0 });
	node head = snake.back();
	node tail = snake.front();
	board[head.y][head.x] = 1;

	int now_time = 1;

	while (!q_dir.empty()) // ���� ��ȯ
	{
		direction tmp = q_dir.front();
		q_dir.pop();

		// tmp�� �ð���ŭ �̵�
		// �� ���� ���̳� ������ �ε�ġ�� ������
		int out_flag = -1;
		for (int j = now_time; j <= tmp.time; j++)
		{
			if (head.y + y_mov[now_dir] >= 0 && head.y + y_mov[now_dir] < n && 
				head.x + x_mov[now_dir] >= 0 && head.x + x_mov[now_dir] < n &&
				board[head.y + y_mov[now_dir]][head.x + x_mov[now_dir]] != 1)
			{
				snake.push({ head.y + y_mov[now_dir], head.x + x_mov[now_dir] });
				if (board[head.y + y_mov[now_dir]][head.x + x_mov[now_dir]] != 2)
				{
					// ��� ���ٸ�, ���� �����̱�
					board[tail.y][tail.x] = 0;
					snake.pop();
				}
				board[head.y + y_mov[now_dir]][head.x + x_mov[now_dir]] = 1;
				head = snake.back();
				tail = snake.front();
			}
			else // ���� ���� �ε�ġ�� ������
			{
				now_time = j;
				out_flag = 0;
				break;
			}
		}
		if (out_flag == 0) break;

		// ���� ��ȯ�ϱ�
		now_time = tmp.time + 1;
		now_dir += tmp.dir;
		if (now_dir < 0) now_dir = 3;
		else if (now_dir > 3) now_dir = 0;
	}

	// ���� ��ȯ ���Ŀ� �� ������ �� �ִ��� Ȯ��
	if (q_dir.empty()) // �� ������ �� �ִ��� Ȯ��
	{
		while (true)
		{
			if (head.y + y_mov[now_dir] >= 0 && head.y + y_mov[now_dir] < n &&
				head.x + x_mov[now_dir] >= 0 && head.x + x_mov[now_dir] < n &&
				board[head.y + y_mov[now_dir]][head.x + x_mov[now_dir]] != 1)
			{
				snake.push({ head.y + y_mov[now_dir], head.x + x_mov[now_dir] });
				if (board[head.y + y_mov[now_dir]][head.x + x_mov[now_dir]] != 2)
				{
					// ��� ���ٸ�, ���� �����̱�
					board[tail.y][tail.x] = 0;
					snake.pop();
				}
				board[head.y + y_mov[now_dir]][head.x + x_mov[now_dir]] = 1;
				head = snake.back();
				tail = snake.front();
			}
			else // ���� ���� �ε�ġ�� ������
			{
				break;
			}
			now_time++;
		}
	}

	return now_time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> k;
	int y, x;
	for (int i = 0; i < k; i++)
	{
		cin >> y >> x;
		board[--y][--x] = 2; // ���
	}

	cin >> l;
	char c;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		if (c == 'L') q_dir.push({ x, -1 });
		else q_dir.push({ x, 1 });
	}

	cout << BFS();

	return 0;
}