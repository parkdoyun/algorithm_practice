#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 백준 25691 - k개 트리 노드에서 사과를 최대로 수확하기
// tree
// 골드 5

// leaf부터 n - k만큼 빼면 된다

// 빼는 노드들 우선순위
// 1. 무조건 리프여야 함
// 2. 1 같다면, 노드의 사과 수가 0이어야 함
// 3. 2 같다면, 부모의 사과 수가 0이어야 함
// 4. 3 같다면, 깊이가 더 커야 함

vector<vector<int>> child;
struct apple
{
	int now; // 지금 내 숫자
	int par_n; // 부모의 숫자
	int now_apple;
	int par = 2; // 0 : 부모 사과 0, 1 : 부모 사과 1, 2 : 부모 X (루트)
	int depth; // 깊이
};
bool operator<(apple a1, apple a2)
{
	if (child[a1.now] > child[a2.now]) return true;
	else if (child[a1.now] == child[a2.now] && a1.now_apple > a2.now_apple) return true;
	else if (child[a1.now] == child[a2.now] && a1.now_apple == a2.now_apple && a1.par > a2.par) return true;
	else if (child[a1.now] == child[a2.now] && a1.now_apple == a2.now_apple && a1.par == a2.par && a1.depth < a2.depth) return true;
	return false;
}
priority_queue<apple> pq;

int n, k;
int total_apple = 0;
int parent[18];
int apple_num[18];
int leaf_chk[18];
int dep[18];
int visit[18]; // 방문

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	child.resize(n);

	int p, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> p >> c;
		parent[c] = p;
		leaf_chk[p] = 1; // 1이면 리프 X
		dep[c] = dep[p] + 1;
		child[p].push_back(c);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> apple_num[i];
		total_apple += apple_num[i];
	}

	// leaf만 담기
	for (int i = 1; i < n; i++)
	{
		if (leaf_chk[i] == 1) continue;
		pq.push({ i, parent[i], apple_num[i], apple_num[parent[i]], dep[i] });
	}

	// n - k만큼 빼기
	int cnt = 0;
	while (!pq.empty() && cnt < n - k)
	{
		apple tmp = pq.top();
		pq.pop();

		if (visit[tmp.now] == 1) continue;
		if (!child[tmp.now].empty()) // 리프 아니라면 다시 넘기기
		{
			pq.push(tmp);
			continue;
		}
		visit[tmp.now] = 1;

		cnt++;
		total_apple -= apple_num[tmp.now];

		for (int i = 0; i < child[tmp.par_n].size(); i++)
		{
			if (child[tmp.par_n][i] == tmp.now)
			{
				child[tmp.par_n].erase(child[tmp.par_n].begin() + i);
				break;
			}
		}

		if (parent[tmp.now] == tmp.now) continue; // root라면 넘기기
		pq.push({ tmp.par_n, parent[tmp.par_n], apple_num[tmp.par_n], apple_num[parent[tmp.par_n]], dep[tmp.par_n] });
	}

	cout << total_apple;

	return 0;
}