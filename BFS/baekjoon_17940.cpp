#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 백준 17940 - 지하철
// BFS
// 골드 2

int n, m;
struct node
{
	int dist;
	int company; // 현재 지하철역 번호
	int cnt; // 환승한 갯수
};
bool operator<(node n1, node n2)
{
	if (n1.cnt > n2.cnt) return true;
	else if (n1.cnt == n2.cnt && n1.dist > n2.dist) return true;
	return false;
}
priority_queue<node> pq;

int com_n[1001]; // 회사 정보
int visit[1001]; // visit
vector<vector<int>> connect_info; // 연결 정보

void BFS()
{
	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (visit[tmp.company] == 1) continue;
		visit[tmp.company] = 1;
		if (tmp.company == m)
		{
			cout << tmp.cnt << ' ' << tmp.dist;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (connect_info[tmp.company][i] == 0 || visit[i] == 1) continue;
			if (com_n[i] != com_n[tmp.company]) pq.push({ tmp.dist + connect_info[tmp.company][i] , i, tmp.cnt + 1 });
			else pq.push({ tmp.dist + connect_info[tmp.company][i] , i, tmp.cnt});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	connect_info.resize(n + 1);
	
	for (int i = 0; i < n; i++)
	{
		cin >> com_n[i];
	}

	for (int i = 0; i < n; i++)
	{
		connect_info[i].resize(n + 1);
		for (int j = 0; j < n; j++)
		{
			cin >> connect_info[i][j];
		}
	}

	// BFS
	pq.push({ 0, 0, 0 });
	BFS();

	return 0;
}