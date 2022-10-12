#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// swea 5650 핀볼게임
// DFS => 스택 터짐
// BFS
// 핀볼 -> 배열로 관리
// 끝까지 간 수들의 최댓값 출력
// 맨 끝 테두리 블록 5로 설정 (튕겨나오게) => 벽은 카운트 한번만 해야 하므로 따로 설정 
//  방향 => 1 : 상, -1 : 하, 2 : 좌, -2 : 우

// 가다가 start_y, start_x 있으면 나와야 함
// 돌아오게 됨

int board[103][103];
int n;
int max1;
int s_y, s_x;

struct node
{
	int y;
	int x;
};
vector<vector<node>> wormhole; // 6 ~ 10 : idx 0 ~ idx 4

void chkClear()
{
	for (int i = 1; i < 103; i++)
	{
		for (int j = 0; j < 103; j++) board[i][j] = 0;
	}
}

int findNext(int start_y, int start_x, int dir, int& y, int& x)
{
	// 이 방향으로 0 아닌 곳 만날때까지 계속-> 어차피 테두리 전부 5
	y = start_y;
	x = start_x;
	int res = 1;
	if (dir == 1)
	{
		y--;
	}
	else if (dir == -1)
	{
		y++;
	}
	else if (dir == -2)
	{
		x++;
	}
	else
	{
		x--;
	}
	while (true)
	{
		if ((y == s_y && x == s_x) || board[y][x] == -1)
		{
			res = -1; // 가는 길에 출발지 있으면
			break;
		}
		if (board[y][x] != 0)
		{
			break;
		}

		if (dir == 1) y--; // 상
		else if (dir == -1) y++; // 하
		else if (dir == 2) x--; // 좌
		else x++; // -2 , 우
	}
	return res;
}


struct node2
{
	int y;
	int x;
	int start_y;
	int start_x;
	int score;
	int dir;
};

queue<node2> q;

void DFS(int y, int x, int start_y, int start_x, int score, int dir) // 사실 bfs
{
	while (!q.empty()) q.pop();
	q.push({ y, x, start_y, start_x, score, dir });

	int new_dir;
	while (!q.empty())
	{
		node2 tmp = q.front();
		q.pop();
		new_dir = tmp.dir;

		if (tmp.x == tmp.start_x && tmp.y == tmp.start_y || board[tmp.y][tmp.x] == -1)
		{
			if (max1 < tmp.score) max1 = tmp.score;
			continue;
		}

		if (board[tmp.y][tmp.x] == 1)
		{
			if (tmp.dir == 1) new_dir = -1;
			else if (tmp.dir == -1) new_dir = -2;
			else if (tmp.dir == 2) new_dir = 1;
			else new_dir = 2;
		}
		else if (board[tmp.y][tmp.x] == 2)
		{
			if (tmp.dir == 1) new_dir = -2;
			else if (tmp.dir == -1) new_dir = 1;
			else if (tmp.dir == 2) new_dir = -1;
			else new_dir = 2;
		}
		else if (board[tmp.y][tmp.x] == 3)
		{
			if (tmp.dir == 1) new_dir = 2;
			else if (tmp.dir == -1) new_dir = 1;
			else if (tmp.dir == 2) new_dir = -2;
			else new_dir = -1;
		}
		else if (board[tmp.y][tmp.x] == 4)
		{
			if (tmp.dir == 1) new_dir = -1;
			else if (tmp.dir == -1) new_dir = 2;
			else if (tmp.dir == 2) new_dir = -2;
			else new_dir = 1;
		}
		else if (board[tmp.y][tmp.x] == 5) // 무조건 반대로 검사
		{
			if (tmp.dir == 1) new_dir = -1;
			else if (tmp.dir == -1) new_dir = 1;
			else if (tmp.dir == 2) new_dir = -2;
			else new_dir = 2;
		}
		else // wormhole => 나가서 한번 더 간 후에 다음 BFS 가야됨
		{
			int new_y, new_x;
			if (wormhole[board[tmp.y][tmp.x] - 6][0].y == tmp.y && wormhole[board[tmp.y][tmp.x] - 6][0].x == tmp.x)
			{
				new_y = wormhole[board[tmp.y][tmp.x] - 6][1].y;
				new_x = wormhole[board[tmp.y][tmp.x] - 6][1].x;
			}
			else
			{
				new_y = wormhole[board[tmp.y][tmp.x] - 6][0].y;
				new_x = wormhole[board[tmp.y][tmp.x] - 6][0].x;
			}

			int new_y1, new_x1;
			int res = findNext(new_y, new_x, tmp.dir, new_y1, new_x1);
			//if (tmp.score == 1) tmp.score = 0; // 바로 웜홀로 들어왔을 때 
			if (res == -1)
			{
				if (max1 < tmp.score) max1 = tmp.score;
				continue;
			}

			q.push({ new_y1, new_x1, tmp.start_y, tmp.start_x, tmp.score, tmp.dir });
			continue;
		}

		int new_y, new_x;
		int res = findNext(tmp.y, tmp.x, new_dir, new_y, new_x);
		if (res == -1) // 가는 길에 출발지 있음
		{
			if (max1 < tmp.score) max1 = tmp.score;
			continue;
		}

		q.push({ new_y, new_x, tmp.start_y, tmp.start_x,  tmp.score + 1, new_dir });

	}

}

int main()
{

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		chkClear();
		wormhole.clear();
		wormhole.resize(5);
		max1 = 0;

		for (int i = 0; i < 103; i++)
		{
			board[0][i] = 5;
			board[i][0] = 5;
		}

		for (int i = 0; i < n + 1; i++)
		{
			board[n + 1][i] = 5;
			board[i][n + 1] = 5;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) {
				cin >> board[i][j];
				if (board[i][j] >= 6 && board[i][j] <= 10)
				{
					// wormhole
					wormhole[board[i][j] - 6].push_back({ i, j });
				}
			}
		}

		// 4방향으로 bfs
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (board[i][j] == 0)
				{
					// 위치 찾고
					s_y = i;
					s_x = j;

					int new_y = i;
					int new_x = j;
					// DFS
					int res = findNext(i, j, 1, new_y, new_x);

					if (res == 1 && board[new_y][new_x] > 5) DFS(new_y, new_x, i, j, 0, 1);
					else if(res == 1) DFS(new_y, new_x, i, j, 1, 1);


					new_y = i;
					new_x = j;

					res = findNext(i, j, -1, new_y, new_x);

					if (res == 1 && board[new_y][new_x] > 5) DFS(new_y, new_x, i, j, 0, -1);
					else if (res == 1) DFS(new_y, new_x, i, j, 1, -1);

					new_y = i;
					new_x = j;
					res = findNext(i, j, -2, new_y, new_x);

					if (res == 1 && board[new_y][new_x] > 5) DFS(new_y, new_x, i, j, 0, -2);
					else if (res == 1) DFS(new_y, new_x, i, j, 1, -2);


					new_y = i;
					new_x = j;
					res = findNext(i, j, 2, new_y, new_x);

					if (res == 1 && board[new_y][new_x] > 5) DFS(new_y, new_x, i, j, 0, 2);
					else if (res == 1) DFS(new_y, new_x, i, j, 1, 2);

				}
			}
		}

		cout << '#' << tc << ' ' << max1 << '\n';
	}

	return 0;
}