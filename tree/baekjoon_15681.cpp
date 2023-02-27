#include <iostream>
#include <vector>
using namespace std;

// 백준 15681 - 트리와 쿼리
// tree, recursion
// 골드 5

// 트리 한번 순회하면서 내려가는 부분 엣지만 표시
// 서브트리 순회하면서 카운트
// 시간초과

// 입력 받을 때마다 순회 X
// 처음 순회할 때 서브트리의 카운트 기록해놓기

int n, r, q;
struct vertex
{
	int idx;
	int visit = -1;
	int cnt = 0;
};
struct edge
{
	int oppo;
	int flag = 0; // 1 : 내려가는 엣지
};
vector<vertex> V;
vector<vector<edge>> E;
int cnt;

// edge check
int traversal(int now)
{
	int tmp_cnt = 1;
	V[now].visit = 1;
	for (int i = 0; i < E[now].size(); i++)
	{
		if (V[E[now][i].oppo].visit == -1)
		{
			E[now][i].flag = 1;
			tmp_cnt += traversal(E[now][i].oppo);
		}
	}
	V[now].cnt = tmp_cnt;
	return tmp_cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> q;
	V.resize(n + 1);
	E.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		V[i].idx = i;
	}

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		E[u].push_back({ v });
		E[v].push_back({ u });
	}

	// 트리 루트부터 한번 순회
	// 내려가는 엣지만 표시
	traversal(r);

	for (int i = 0; i < q; i++)
	{
		cin >> u;
		cout << V[u].cnt << '\n';
	}

	return 0;
}