#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 백준 1941 - 소문난 칠공주
// BFS
// 골드 3

struct pos
{
	int y = -1;
	int x = -1;
};
struct node
{
	int y = 0; // 임도연파
	int s = 0; // 이다솜파
	pos _p[7]; // 각 위치
	string visit[5] = { "-----", "-----", "-----", "-----", "-----" };
};
int cnt = 0;
map<vector<string>, int> map1; // 마지막 확인
string origin_board[5];
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

bool cmp(pos p1, pos p2)
{
	if (p1.y < p2.y) return true;
	else if (p1.y == p2.y && p1.x < p2.x) return true;
	return false;
}

queue<node> q;
void BFS(int sy, int sx)
{
	while (!q.empty()) q.pop();

	node tmp;
	tmp._p[0].y = sy;
	tmp._p[0].x = sx;
	if (origin_board[sy][sx] == 'Y') tmp.y = 1;
	else tmp.s = 1;
	tmp.visit[sy][sx] = '.';
	q.push(tmp);

	int ty, tx, tlv;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if (tmp.y >= 4) continue;

		tlv = tmp.y + tmp.s;
		if (tlv == 7)
		{
			vector<string> s;
			for (int i = 0; i < 5; i++) s.push_back(tmp.visit[i]);
			if (map1.find(s) == map1.end())
			{
				cnt++;
				map1.insert({ s, 1 });
			}
			continue;
		}

		for (int i = 0; i < tlv; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				ty = tmp._p[i].y + y_mov[j];
				tx = tmp._p[i].x + x_mov[j];
				if (ty >= 0 && ty < 5 && tx >= 0 && tx < 5 && tmp.visit[ty][tx] == '-')
				{
					tmp._p[tlv].y = ty;
					tmp._p[tlv].x = tx;
					tmp.visit[ty][tx] = '.';
					if (origin_board[ty][tx] == 'Y') tmp.y++;
					else tmp.s++;
					q.push(tmp);
					if (origin_board[ty][tx] == 'Y') tmp.y--;
					else tmp.s--;
					tmp.visit[ty][tx] = '-';
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) origin_board[i] = "-----";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> origin_board[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			BFS(i, j);
		}
	}

	cout << cnt;

	return 0;
}