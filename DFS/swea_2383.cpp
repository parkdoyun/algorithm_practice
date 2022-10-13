#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// swea 2383 - 점심 식사시간
// DFS, backtracking

// 계단 2개 이용하는 모든 가짓수 계산 -> 최솟값 출력
// 계단까지 이동 시간 계산 -> 배열 2개 0번 계단, 1번 계단
// 이동 시간 계산 -> pq (이동 시간 작은 애들부터 내려가야 함)
// while문 사용해서 이동 시간 pq, 계단에 있는 애들 pq 계산
// 계단 두개 값 중 큰 값이 이동 완료 시간

int n;
int board[11][11];
int min1;
struct stair
{
	int y;
	int x;
	int len;
};
stair st[2];
struct man
{
	int y;
	int x;
};
vector<man> vec_m;
int path[11]; // path (몇번 계단인지) 0 or 1
struct man2
{
	int time;
};
bool operator<(man2 m1, man2 m2)
{
	if (m1.time > m2.time) return true;
	return false;
}
priority_queue<man2> st0_wait; // 0번 계단 기다리는 애들
priority_queue<man2> st1_wait; // 1번 계단 기다리는 애들
vector<man2> st_wait_vec;

int cal() // 이동시간 계산
{
	while (!st0_wait.empty()) st0_wait.pop();
	while (!st1_wait.empty()) st1_wait.pop();
	
	// 계단까지의 시간 계산
	for (int i = 0; i < vec_m.size(); i++)
	{
		if (path[i] == 0)
		{
			int d = abs(st[0].y - vec_m[i].y) + abs(st[0].x - vec_m[i].x) + 1;
			st0_wait.push({ d });
		}
		else // 1
		{
			int d = abs(st[1].y - vec_m[i].y) + abs(st[1].x - vec_m[i].x) + 1;
			st1_wait.push({ d });
		}
	}
	st_wait_vec.clear();
	int res0 = 0;
	int res1 = 0;
	man2 tmp;
	int now_time;

	// 0번 계단부터
	if (!st0_wait.empty())
	{
		now_time = st0_wait.top().time;
		while (!st0_wait.empty())
		{
			if (st_wait_vec.size() == 3 && now_time < st_wait_vec[0].time) // 계단 다 찼고 나갈 애들 없다면
			{
				now_time++;
				continue;
			}

			// 나갈 애들 있으면 빼기
			while (!st_wait_vec.empty())
			{
				if (st_wait_vec[0].time > now_time) break;
				else if (st_wait_vec[0].time <= now_time)
				{
					res0 = st_wait_vec[0].time;
					st_wait_vec.erase(st_wait_vec.begin());
				}
			}

			// 계단에 넣기
			while (!st0_wait.empty() && st_wait_vec.size() < 3)
			{
				tmp = st0_wait.top();
				if (tmp.time > now_time) break;
				st_wait_vec.push_back({ now_time + st[0].len });
				st0_wait.pop();
			}

			now_time++;
		}

		// 계단에 남은 애들 중 가장 늦게 나오는 애
		if(!st_wait_vec.empty()) res0 = st_wait_vec[st_wait_vec.size() - 1].time;
	}
	

	// 1번 계단
	if (!st1_wait.empty())
	{
		st_wait_vec.clear();

		now_time = st1_wait.top().time;
		while (!st1_wait.empty())
		{
			if (st_wait_vec.size() == 3 && now_time < st_wait_vec[0].time) // 계단 다 찼고 나갈 애들 없다면
			{
				now_time++;
				continue;
			}

			// 나갈 애들 있으면 빼기
			while (!st_wait_vec.empty())
			{
				if (st_wait_vec[0].time > now_time) break;
				else if (st_wait_vec[0].time <= now_time)
				{
					res1 = st_wait_vec[0].time;
					st_wait_vec.erase(st_wait_vec.begin());
				}
			}

			// 계단에 넣기
			while (!st1_wait.empty() && st_wait_vec.size() < 3)
			{
				tmp = st1_wait.top();
				if (tmp.time > now_time) break;
				st_wait_vec.push_back({ now_time + st[1].len });
				st1_wait.pop();
			}

			now_time++;
		}
		// 계단에 남은 애들 중 가장 늦게 나오는 애
		if(!st_wait_vec.empty()) res1 = st_wait_vec[st_wait_vec.size() - 1].time;
	}
	

	return max(res0, res1);
}

void DFS(int lv)
{
	if (lv == vec_m.size())
	{
		// 계산 후 최소값 비교
		int res = cal();
		if (res < min1) min1 = res;
		return;
	}

	path[lv] = 0;
	DFS(lv + 1);
	path[lv] = 1;
	DFS(lv + 1);
}



int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		st[0].y = -1;
		st[1].y = -1;
		min1 = 1000000;
		vec_m.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 1)
				{
					vec_m.push_back({ i, j });
				}
				else if (board[i][j] > 1)
				{
					if (st[0].y == -1)
					{
						st[0].y = i;
						st[0].x = j;
						st[0].len = board[i][j];
					}
					else
					{
						st[1].y = i;
						st[1].x = j;
						st[1].len = board[i][j];
					}
				}
			}
		}

		path[0] = 0;
		DFS(1);
		path[0] = 1;
		DFS(1);

		cout << '#' << tc << ' ' << min1 << '\n';
		
	}

	return 0;
}