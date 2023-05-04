#include <iostream>
#include <queue>

using namespace std;

// 백준 15653 - 구슬 탈출 4
// BFS
// 골드 1

int n, m;
char board[11][11];
int visit[11][11][11][11]; // 빨간 공, 파란 공 visit 둘다 같이 확인

struct node
{
	int ry = -1;
	int rx = -1;
	int by = -1;
	int bx = -1;
	int cnt; // 기울인 횟수
	int flag = -1; // 1이면 입구에 들어감
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
	// 위로
	if (r1 < b1) // 빨간 공 먼저
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') ry--;

		if (board[ry][rx] == '#')
		{
			board[ry + 1][rx] = 'R'; // 임시로
			while (board[by][bx] == '.') by--;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry + 1, rx, by + 1, bx, cnt + 1 });
			board[ry + 1][rx] = '.';
		}
		else if (board[ry][rx] == 'O') // 구멍에 들어감
		{
			while (board[by][bx] == '.') by--;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry + 1, rx, by + 1, bx, cnt + 1, 1 }); 
		}
	}
	else // 파란 공 먼저
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') by--;

		if (board[by][bx] == '#') // 파란 공 안 들어갔을 때만
		{
			board[by + 1][bx] = 'B'; // 임시로
			while (board[ry][rx] == '.') ry--;
			if (board[ry][rx] == 'O') pq.push({ ry + 1, rx, by + 1, bx, cnt + 1, 1 });
			else pq.push({ ry + 1, rx, by + 1, bx, cnt + 1 });
			board[by + 1][bx] = '.';
		}
	}

	// 아래로
	if (r1 > b1) // 빨간 공 먼저
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') ry++;

		if (board[ry][rx] == '#')
		{
			board[ry - 1][rx] = 'R'; // 임시로
			while (board[by][bx] == '.') by++;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry - 1, rx, by - 1, bx, cnt + 1 });
			board[ry - 1][rx] = '.';
		}
		else if (board[ry][rx] == 'O') // 구멍에 들어감
		{
			while (board[by][bx] == '.') by++;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry - 1, rx, by - 1, bx, cnt + 1, 1 });
		}
	}
	else // 파란 공
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') by++;

		if (board[by][bx] == '#') // 파란 공 안 들어갔을 때만
		{
			board[by - 1][bx] = 'B'; // 임시로
			while (board[ry][rx] == '.') ry++;
			if (board[ry][rx] == 'O') pq.push({ ry - 1, rx, by - 1, bx, cnt + 1, 1 });
			else pq.push({ ry - 1, rx, by - 1, bx, cnt + 1 });
			board[by - 1][bx] = '.';
		}
	}

	// 왼쪽
	if (r2 < b2) // 빨간 공 먼저
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') rx--;

		if (board[ry][rx] == '#')
		{
			board[ry][rx + 1] = 'R'; // 임시로
			while (board[by][bx] == '.') bx--;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry, rx + 1, by, bx + 1, cnt + 1 });
			board[ry][rx + 1] = '.';
		}
		else if (board[ry][rx] == 'O') // 구멍에 들어감
		{
			while (board[by][bx] == '.') bx--;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry, rx + 1, by, bx + 1, cnt + 1, 1 });
		}
	}
	else // 파란 공
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') bx--;

		if (board[by][bx] == '#') // 파란 공 안 들어갔을 때만
		{
			board[by][bx + 1] = 'B'; // 임시로
			while (board[ry][rx] == '.') rx--;
			if (board[ry][rx] == 'O') pq.push({ ry, rx + 1, by, bx + 1, cnt + 1, 1 });
			else pq.push({ ry, rx + 1, by, bx + 1, cnt + 1});
			board[by][bx + 1] = '.';
		}
	}

	// 오른쪽
	if (r2 > b2) // 빨간 공부터
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[ry][rx] == '.') rx++;

		if (board[ry][rx] == '#')
		{
			board[ry][rx - 1] = 'R'; // 임시로
			while (board[by][bx] == '.') bx++;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry, rx - 1, by, bx - 1, cnt + 1 });
			board[ry][rx - 1] = '.';
		}
		else if (board[ry][rx] == 'O') // 구멍에 들어감
		{
			while (board[by][bx] == '.') bx++;
			// 동시에 구멍에 빠지면 실패
			if (board[by][bx] != 'O') pq.push({ ry, rx - 1, by, bx - 1, cnt + 1, 1 });
		}
	}
	else // 파란 공부터
	{
		ry = r1; rx = r2;
		by = b1; bx = b2;

		while (board[by][bx] == '.') bx++;

		if (board[by][bx] == '#') // 파란 공 안 들어갔을 때만
		{
			board[by][bx - 1] = 'B'; // 임시로
			while (board[ry][rx] == '.') rx++;
			if (board[ry][rx] == 'O') pq.push({ ry, rx - 1, by, bx - 1, cnt + 1, 1 });
			else pq.push({ ry, rx - 1, by, bx - 1, cnt + 1 });
			board[by][bx - 1] = '.';
		}
	}
}
int BFS(int ry, int rx, int by, int bx)
{
	// 초기
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

	int ry, rx; // 빨간 공
	int by, bx; // 파란 공
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