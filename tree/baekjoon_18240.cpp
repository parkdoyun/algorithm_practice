#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// 백준 18240 - 이진 탐색 트리 복원하기 
// tree
// 골드 2

// 트리 생성해 놓고 나중에 순회하면서 값 채우기

// 트리 탐색하고 그 값 리턴
// 실제 트리 구현하면 메모리 터짐

// 모든 정점에서 만들 수 있음
// 아무 정점 찍고 만들어도 될 듯

// 깊이 k + 1 -> 깊이 k에서 파생
// 깊이 k 중 뻗지 않은 가지가 있는 애들한테 붙인다

// 가능한 수열 없는 경우
// 1. 1이 2개 초과면 X, 2가 2^2 초과 X.... n이 2^n개 초과면 X
// 2. 깊이 k + 1이 나왔을 때 앞에 깊이 k인 애들이 현재 k + 1을 포함한 k + 1인 애들의 절반과 같거나 많아야 함
// 이거 만족하지 않으면 가능한 수열 없음

// 시간 초과
// 자식 추가할 때 for문 돌지말고 pq로 한번에 부모 선택

int n;
long long int depth_cnt[300001]; // 각 깊이의 총 갯수 카운트
int num_arr[300001];

struct node
{
	int input_idx; // 입력 시 번호 (벡터 내 번호)
	int arr_idx; // num_arr 번호
	int idx = -1; // 나중에 바뀔 번호
	int left = -1; // 해당 벡터에서의 번호
	int right = -1;
};
vector<vector<node>> vec; // tree

struct node2
{
	int idx;
	int cnt = 0; // 남아있는 자식 수
};
bool operator<(node2 n1, node2 n2)
{
	return n1.cnt < n2.cnt;
}
vector<priority_queue<node2>> pq;

int now_num = 1;
void traversal(node &tmp, int depth) // in-order traversal
{
	if (tmp.left != -1) traversal(vec[depth + 1][tmp.left], depth + 1);

	// 번호
	tmp.idx = now_num;
	num_arr[tmp.arr_idx] = now_num;
	now_num++;

	if (tmp.right != -1) traversal(vec[depth + 1][tmp.right], depth + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vec.resize(n + 1);
	pq.resize(n + 1);

	vec[0].push_back({ 0, 0 }); // root
	pq[0].push({ 0, 2 });

	int a;
	int flag = 1;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a;
		if (flag == -1) continue;

		depth_cnt[a] = depth_cnt[a] + (long long int)1;
		if (depth_cnt[a] > powl((long long int)2, (long long int)a))
		{
			flag = -1; // cond 1
			continue;
		}
		if (a != 1 && depth_cnt[a] == 1 && depth_cnt[a - 1] == 0)
		{
			flag = -1;
			continue;
		}
		else if (a != 1 && depth_cnt[a - 1] < (depth_cnt[a] + (long long int)1) / (long long int)2)
		{
			flag = -1; // cond 2
			continue;
		}

		// 트리 추가
		// 있는 애들 중 아무거나 달아도 됨
		// 전체를 항상 검사하고 넣는 것도 시간 많이 걸림, 한번만 할 수는 없나?
		// pq에서 top 꺼내서 갱신 후 넣는다
		// 내 pq도 넣음
		node2 tmp = pq[a - 1].top();
		pq[a - 1].pop();

		int s = vec[a].size();
		vec[a].push_back({ s, i });
		pq[a].push({ s, 2 }); // 자식 집어넣기

		if (vec[a - 1][tmp.idx].left == -1) vec[a - 1][tmp.idx].left = s;
		else vec[a - 1][tmp.idx].right = s;

		// 부모 다시 집어넣기
		if (tmp.cnt > 1)
		{
			pq[a - 1].push({ tmp.idx, tmp.cnt - 1 });
		}

	}

	if (flag == -1) // 조건 성립 X
	{
		cout << -1;
		return 0;
	}

	// 순회하면서 번호 매기기
	traversal(vec[0][0], 0);

	// 결과 출력
	for (int i = 0; i < n; i++) cout << num_arr[i] << ' ';

	return 0;
}