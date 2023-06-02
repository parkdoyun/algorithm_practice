#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ���� 25691 - k�� Ʈ�� ��忡�� ����� �ִ�� ��Ȯ�ϱ�
// tree
// ��� 5

// leaf���� n - k��ŭ ���� �ȴ�

// ���� ���� �켱����
// 1. ������ �������� ��
// 2. 1 ���ٸ�, ����� ��� ���� 0�̾�� ��
// 3. 2 ���ٸ�, �θ��� ��� ���� 0�̾�� ��
// 4. 3 ���ٸ�, ���̰� �� Ŀ�� ��

vector<vector<int>> child;
struct apple
{
	int now; // ���� �� ����
	int par_n; // �θ��� ����
	int now_apple;
	int par = 2; // 0 : �θ� ��� 0, 1 : �θ� ��� 1, 2 : �θ� X (��Ʈ)
	int depth; // ����
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
int visit[18]; // �湮

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
		leaf_chk[p] = 1; // 1�̸� ���� X
		dep[c] = dep[p] + 1;
		child[p].push_back(c);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> apple_num[i];
		total_apple += apple_num[i];
	}

	// leaf�� ���
	for (int i = 1; i < n; i++)
	{
		if (leaf_chk[i] == 1) continue;
		pq.push({ i, parent[i], apple_num[i], apple_num[parent[i]], dep[i] });
	}

	// n - k��ŭ ����
	int cnt = 0;
	while (!pq.empty() && cnt < n - k)
	{
		apple tmp = pq.top();
		pq.pop();

		if (visit[tmp.now] == 1) continue;
		if (!child[tmp.now].empty()) // ���� �ƴ϶�� �ٽ� �ѱ��
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

		if (parent[tmp.now] == tmp.now) continue; // root��� �ѱ��
		pq.push({ tmp.par_n, parent[tmp.par_n], apple_num[tmp.par_n], apple_num[parent[tmp.par_n]], dep[tmp.par_n] });
	}

	cout << total_apple;

	return 0;
}