#include <iostream>
#include <queue>

using namespace std;

// ���� 15653 - ���� Ż�� 4
// BFS
// ��� 1

int n, m;
char board[11][11];
int visit[11][11][11][11]; // ���� ��, �Ķ� �� visit �Ѵ� ���� Ȯ��

struct node
{
	int ry = -1;
	int rx = -1;
	int by = -1;
	int bx = -1;
	int cnt; // ����� Ƚ��
	int flag = -1; // 1�̸� �Ա��� ��
};
bool operator<(node n1, node n2)
{
	if (n1.flag != 1 && n2.flag == 1) return true;
	else if (n1.flag == n2.flag && n1.cnt > n2.cnt) return true;
	return false;
}
priority_queue<node> pq;

void mov_biz(int r1, int r2, int b1, int b2, int cnt)
{
	int ry, rx, by, bx;
	// ����
	if (r1 < b1) // ���� �� ����
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') ry--;

		if (board[ry][rx] == '#')
		{
			board[ry + 1][rx] = 'R'; // �ӽ÷�
			while (board[by][bx] == '.') by--;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry + 1, rx, by + 1, bx, cnt + 1 });
			board[ry + 1][rx] = '.';
		}
		else if (board[ry][rx] == 'O') // ���ۿ� ��
		{
			while (board[by][bx] == '.') by--;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry + 1, rx, by + 1, bx, cnt + 1, 1 }); 
		}
	}
	else // �Ķ� �� ����
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') by--;

		if (board[by][bx] == '#') // �Ķ� �� �� ���� ����
		{
			board[by + 1][bx] = 'B'; // �ӽ÷�
			while (board[ry][rx] == '.') ry--;
			if (board[ry][rx] == 'O') pq.push({ ry + 1, rx, by + 1, bx, cnt + 1, 1 });
			else pq.push({ ry + 1, rx, by + 1, bx, cnt + 1 });
			board[by + 1][bx] = '.';
		}
	}

	// �Ʒ���
	if (r1 > b1) // ���� �� ����
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') ry++;

		if (board[ry][rx] == '#')
		{
			board[ry - 1][rx] = 'R'; // �ӽ÷�
			while (board[by][bx] == '.') by++;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry - 1, rx, by - 1, bx, cnt + 1 });
			board[ry - 1][rx] = '.';
		}
		else if (board[ry][rx] == 'O') // ���ۿ� ��
		{
			while (board[by][bx] == '.') by++;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry - 1, rx, by - 1, bx, cnt + 1, 1 });
		}
	}
	else // �Ķ� ��
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') by++;

		if (board[by][bx] == '#') // �Ķ� �� �� ���� ����
		{
			board[by - 1][bx] = 'B'; // �ӽ÷�
			while (board[ry][rx] == '.') ry++;
			if (board[ry][rx] == 'O') pq.push({ ry - 1, rx, by - 1, bx, cnt + 1, 1 });
			else pq.push({ ry - 1, rx, by - 1, bx, cnt + 1 });
			board[by - 1][bx] = '.';
		}
	}

	// ����
	if (r2 < b2) // ���� �� ����
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') rx--;

		if (board[ry][rx] == '#')
		{
			board[ry][rx + 1] = 'R'; // �ӽ÷�
			while (board[by][bx] == '.') bx--;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry, rx + 1, by, bx + 1, cnt + 1 });
			board[ry][rx + 1] = '.';
		}
		else if (board[ry][rx] == 'O') // ���ۿ� ��
		{
			while (board[by][bx] == '.') bx--;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry, rx + 1, by, bx + 1, cnt + 1, 1 });
		}
	}
	else // �Ķ� ��
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') bx--;

		if (board[by][bx] == '#') // �Ķ� �� �� ���� ����
		{
			board[by][bx + 1] = 'B'; // �ӽ÷�
			while (board[ry][rx] == '.') rx--;
			if (board[ry][rx] == 'O') pq.push({ ry, rx + 1, by, bx + 1, cnt + 1, 1 });
			else pq.push({ ry, rx + 1, by, bx + 1, cnt + 1});
			board[by][bx + 1] = '.';
		}
	}

	// ������
	if (r2 > b2) // ���� ������
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') rx++;

		if (board[ry][rx] == '#')
		{
			board[ry][rx - 1] = 'R'; // �ӽ÷�
			while (board[by][bx] == '.') bx++;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry, rx - 1, by, bx - 1, cnt + 1 });
			board[ry][rx - 1] = '.';
		}
		else if (board[ry][rx] == 'O') // ���ۿ� ��
		{
			while (board[by][bx] == '.') bx++;
			// ���ÿ� ���ۿ� ������ ����
			if (board[by][bx] != 'O') pq.push({ ry, rx - 1, by, bx - 1, cnt + 1, 1 });
		}
	}
	else // �Ķ� ������
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') bx++;

		if (board[by][bx] == '#') // �Ķ� �� �� ���� ����
		{
			board[by][bx - 1] = 'B'; // �ӽ÷�
			while (board[ry][rx] == '.') rx++;
			if (board[ry][rx] == 'O') pq.push({ ry, rx - 1, by, bx - 1, cnt + 1, 1 });
			else pq.push({ ry, rx - 1, by, bx - 1, cnt + 1 });
			board[by][bx - 1] = '.';
		}
	}
}
int BFS(int ry, int rx, int by, int bx)
{
	// �ʱ�
	pq.push({ ry, rx, by, bx, 0 });

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (tmp.flag == 1)
		{
			return tmp.cnt;
		}

		if (visit[tmp.ry][tmp.rx][tmp.by][tmp.bx] == 1) continue;
		visit[tmp.ry][tmp.rx][tmp.by][tmp.bx] = 1;

		mov_biz(tmp.ry, tmp.rx, tmp.by, tmp.bx, tmp.cnt);
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int ry, rx; // ���� ��
	int by, bx; // �Ķ� ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
			{
				board[i][j] = '.';
				ry = i;
				rx = j;
			}
			else if (board[i][j] == 'B')
			{
				board[i][j] = '.';
				by = i;
				bx = j;
			}
		}
	}

	cout << BFS(ry, rx, by, bx);

	return 0;
}