#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// 백준 7576 - 토마토
// bfs

typedef struct tomato
{
	int y;
	int x;
	int date = 0;
};

int arr[1001][1001] = { 0 };
queue<tomato> q; // bfs queue

int main()
{
	int x[] = { 0, 1, 0, -1 };
	int y[] = { -1, 0, 1, 0 };

	int n, m;
	cin >> m >> n;

	int res = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) res = 0;
			if (arr[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	// 처음부터 토마토 다 익어있으면
	if (res != 0)
	{
		cout << 0;
		return 0;
	}


	// bfs
	while (q.size() > 0)
	{
		tomato tmp = q.front();
		q.pop();
		if (res < tmp.date) res = tmp.date;

		// 상하좌우 확인
		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y[i] >= 0 && tmp.y + y[i] < n &&
				tmp.x + x[i] >= 0 && tmp.x + x[i] < m &&
				arr[tmp.y + y[i]][tmp.x + x[i]] == 0)
			{
				arr[tmp.y + y[i]][tmp.x + x[i]] = 1;
				q.push({ tmp.y + y[i] , tmp.x + x[i], tmp.date + 1 });
			}
		}
	}

	// 마지막에 토마토 익은 거 전부 확인
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			if (arr[i][j] == 0)
			{
				res = -1;
				break;
			}
		}
		if (res == -1) break;
	}

	cout << res;

	return 0;
}