#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2098 - 외판원 순회
// DP, 외판원 순회(TSP) 문제
// 골드 1

// 순회이므로 처음 시작 정점을 0번으로 임의 설정

#define INF 999999999

int n;
int cost[17][17]; // cost[i][j] = i에서 j로 가는 비용
int DP[17][65536];
int visit_complete;

int dfs(int now, int visited) // now : 현재 위치, visited : visit flag
{
	if (visited == visit_complete) // 정점 다 방문했다면
	{
		if (cost[now][0] == 0) DP[now][visited] = INF; // 0번으로 가는 경로 없다면 (얘로 갱신 안 되도록)
		else DP[now][visited] = cost[now][0];
		return DP[now][visited]; // 0번과 지금(마지막 정점) 비용 반환
	}

	if (DP[now][visited] != 0)
	{
		return DP[now][visited]; // 이미 갱신된 적 있다면(방문한 적 있다면) 반환
	}
	
	int bit = 1;
	int tmp = INF;
	for (int i = 1; i < n; i++)
	{
		bit = bit << 1;
		if ((visited & bit) != 0 || cost[now][i] == 0) continue; // 이미 방문한 적 있다면 pass, 0번은 시작점이므로 1번부터 확인

		// now => i 간선 비용 + i번빼고 나머지 애들을 전부 최적으로 돌았을 때 거리
		// 최소인 애들로 갱신
		tmp = min(tmp, dfs(i, (visited | (1 << i))) + cost[now][i]);
	}
	DP[now][visited] = tmp;

	return DP[now][visited];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	visit_complete = (1 << n) - 1; // n이 4일 때 1111
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cin >> cost[i][j];
	}

	cout << dfs(0, 1);

	return 0;
}