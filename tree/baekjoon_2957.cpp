#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// 백준 2957 - 이진 탐색 트리
// tree, map
// 플래티넘 5

// lower bound와 upper bound 중 더 depth 깊은 쪽으로 insert
// depth 더 작은 노드는 더 큰 노드의 부모이기 때문!

int n;
map<int, long long int> tree;
map<int, long long int>::iterator low_bound; // lower bound
map<int, long long int>::iterator upp_bound; // upper bound

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	long long int cnt = 0;

	// 경계선 만들기 (lower, upper bound 사용하므로)
	tree.insert({ 0, -1 });
	tree.insert({ 300001, -1 });

	long long int depth;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		low_bound = (--tree.lower_bound(tmp)); // temp와 인접한 노드 중 낮은 쪽
		upp_bound = tree.upper_bound(tmp); // temp와 인접한 노드 중 높은 쪽

		// 인접 노드 둘 중 depth 중 더 큰 것 고르기
		depth = max(low_bound->second, upp_bound->second) + 1; // depth 하나 더 커야 하므로
		
		// insert
		tree.insert({ tmp, depth });
		cnt += depth;

		// print
		cout << cnt << '\n';
	}

	return 0;
}