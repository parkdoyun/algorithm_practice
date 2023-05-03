#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// ���� 18240 - ���� Ž�� Ʈ�� �����ϱ� 
// tree
// ��� 2

// Ʈ�� ������ ���� ���߿� ��ȸ�ϸ鼭 �� ä���

// Ʈ�� Ž���ϰ� �� �� ����
// ���� Ʈ�� �����ϸ� �޸� ����

// ��� �������� ���� �� ����
// �ƹ� ���� ��� ���� �� ��

// ���� k + 1 -> ���� k���� �Ļ�
// ���� k �� ���� ���� ������ �ִ� �ֵ����� ���δ�

// ������ ���� ���� ���
// 1. 1�� 2�� �ʰ��� X, 2�� 2^2 �ʰ� X.... n�� 2^n�� �ʰ��� X
// 2. ���� k + 1�� ������ �� �տ� ���� k�� �ֵ��� ���� k + 1�� ������ k + 1�� �ֵ��� ���ݰ� ���ų� ���ƾ� ��
// �̰� �������� ������ ������ ���� ����

// �ð� �ʰ�
// �ڽ� �߰��� �� for�� �������� pq�� �ѹ��� �θ� ����

int n;
long long int depth_cnt[300001]; // �� ������ �� ���� ī��Ʈ
int num_arr[300001];

struct node
{
	int input_idx; // �Է� �� ��ȣ (���� �� ��ȣ)
	int arr_idx; // num_arr ��ȣ
	int idx = -1; // ���߿� �ٲ� ��ȣ
	int left = -1; // �ش� ���Ϳ����� ��ȣ
	int right = -1;
};
vector<vector<node>> vec; // tree

struct node2
{
	int idx;
	int cnt = 0; // �����ִ� �ڽ� ��
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

	// ��ȣ
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

		// Ʈ�� �߰�
		// �ִ� �ֵ� �� �ƹ��ų� �޾Ƶ� ��
		// ��ü�� �׻� �˻��ϰ� �ִ� �͵� �ð� ���� �ɸ�, �ѹ��� �� ���� ����?
		// pq���� top ������ ���� �� �ִ´�
		// �� pq�� ����
		node2 tmp = pq[a - 1].top();
		pq[a - 1].pop();

		int s = vec[a].size();
		vec[a].push_back({ s, i });
		pq[a].push({ s, 2 }); // �ڽ� ����ֱ�

		if (vec[a - 1][tmp.idx].left == -1) vec[a - 1][tmp.idx].left = s;
		else vec[a - 1][tmp.idx].right = s;

		// �θ� �ٽ� ����ֱ�
		if (tmp.cnt > 1)
		{
			pq[a - 1].push({ tmp.idx, tmp.cnt - 1 });
		}

	}

	if (flag == -1) // ���� ���� X
	{
		cout << -1;
		return 0;
	}

	// ��ȸ�ϸ鼭 ��ȣ �ű��
	traversal(vec[0][0], 0);

	// ��� ���
	for (int i = 0; i < n; i++) cout << num_arr[i] << ' ';

	return 0;
}