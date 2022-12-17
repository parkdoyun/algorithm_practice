#include <iostream>
#include <queue>

using namespace std;

// 백준 13549 - 숨바꼭질 3
// BFS, dijkstra
// 골드 5

// pq 이용해서 BFS 한다

int DP[100001];
int n, k;

struct node
{
	int idx;
	int time;
};
bool operator<(node n1, node n2)
{
	if (n1.time > n2.time) return true;
	return false;
}
priority_queue<node> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= 100000; i++)
	{
		DP[i] = 10000001;
	}

	DP[n] = 0;
	q.push({ n, 0 });

	while (!q.empty())
	{
		node tmp = q.top();
		q.pop();


		if (DP[tmp.idx] < tmp.time) continue;

		DP[tmp.idx] = tmp.time;

		if (tmp.idx == k) break;

		if (tmp.idx - 1 >= 0 && DP[tmp.idx  - 1] > tmp.time + 1)
		{
			DP[tmp.idx - 1] = tmp.time + 1;
			q.push({ tmp.idx - 1, tmp.time + 1 });
		}
		if (tmp.idx + 1 <= 100000 && DP[tmp.idx + 1] > tmp.time + 1)
		{
			DP[tmp.idx + 1] = tmp.time + 1;
			q.push({ tmp.idx + 1, tmp.time + 1 });
		}
		if (tmp.idx * 2 <= 100000 && DP[tmp.idx * 2] > tmp.time)
		{
			DP[tmp.idx * 2] = tmp.time;
			q.push({ tmp.idx * 2, tmp.time});
		}
		
	}

	cout << DP[k];

	return 0;
}