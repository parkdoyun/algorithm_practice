#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

// 백준 14431 - 소수마을
// dijkstra
// 골드 3

// 90퍼에서 틀림
// 범위 떄문인가 해서 long long int cast => 시간초과
// 왜 90퍼에서 틀려!!!!!

int n;
struct vertex
{
	int y;
	int x;
	int idx;
	int visit = -1;
	int dist = 999999999;
};
bool operator<(vertex v1, vertex v2)
{
	return v1.dist > v2.dist;
}
vector<vertex> vec; // 0번 소수마을, 1번 목적지
priority_queue<vertex> pq;

// 소수 판별
bool chkPrime(int a)
{
	// 1이 들어올수도 있음!!!
	if (a <= 1) return false;
	else if (a == 2) return true;
	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}

void dijkstra(int a)
{
	vec[a].dist = 0;
	pq.push(vec[a]);
	int tmp_len;

	while (!pq.empty())
	{
		vertex tmp = pq.top();
		pq.pop();

		if (vec[tmp.idx].visit == 1) continue;
		vec[tmp.idx].visit = 1;

		if (tmp.idx == 1) return;

		for (int i = 1; i < n + 2; i++)
		{
			if (i == tmp.idx || vec[i].visit == 1) continue;
			tmp_len = sqrt((vec[i].y - tmp.y) * (vec[i].y - tmp.y) + (vec[i].x - tmp.x) * (vec[i].x - tmp.x));
			if (chkPrime(tmp_len) && vec[i].dist > tmp.dist + tmp_len)
			{
				vec[i].dist = tmp.dist + tmp_len;
				pq.push(vec[i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2 >> n;

	vec.resize(n + 2);
	vec[0].x = x1; vec[0].y = y1; vec[0].idx = 0;
	vec[1].x = x2; vec[1].y = y2; vec[1].idx = 1;

	for (int i = 2; i < n + 2; i++)
	{
		cin >> vec[i].x >> vec[i].y;
		vec[i].idx = i;
	}

	dijkstra(0);

	if (vec[1].dist == 999999999) cout << -1;
	else cout << vec[1].dist;

	return 0;
}