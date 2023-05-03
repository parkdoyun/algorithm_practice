#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2533 - 사회망 서비스(SNS)
// DP, tree
// 골드 3

// 맨 마지막 내려가서 올라오면서 확인 (post-traversal)
// now를 얼리아답터라고 하는 게 더 작을지 아니면 놔두는 게 나을지
// 이미 확정되면 (visit) 다시 방문 X
// 만약 leaf라면 일단 나로 정하고 올라가기

// 점화식 min(DP1[1], DP2[1])
// DP 두개
// 무조건 내가 비는 가짓수(DP1), 내가 무조건 채워지는 가짓수(DP2)
// DP1 = DP2[자식]의 합
// DP2 = min(DP1[자식], DP2[자식])의 합 + 1
// 나 밑에 애들은 조건 전부 성립한다 가정 -> 내 자식들이 전부 얼리어답터여야 함

// u가 v의 부모가 아닐 수도 있음 (자식일수도)

int n;
int total_cnt = 0;
int DP1[1000001]; // 내가 비는 가짓수
int DP2[1000001]; // 내가 채워지는 가짓수
int visit[1000001]; // 0 : 방문 X, 1 : 방문만, 2 : 확정
vector<vector<int>> E;

void traversal(int now)
{
	visit[now] = 1;

	for (auto e : E[now])
	{
		if (visit[e] == 1) continue;
		traversal(e);
		DP1[now] += DP2[e];
		DP2[now] += min(DP1[e], DP2[e]);
	}

	DP2[now]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	E.resize(n + 1);

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	// 순회
	traversal(1);

	cout << min(DP1[1], DP2[1]);
		
	return 0;
}