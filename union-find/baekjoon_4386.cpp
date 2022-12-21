#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// ���� 4386 - ���ڸ� �����
// union-find
// ��� 3

// �Ÿ��� �Ǽ��� �ؼ� union-find

struct node
{
	int a;
	int b;
	double dist;
};
bool operator<(node n1, node n2)
{
	if (n1.dist > n2.dist) return true;
	return false;
}
priority_queue<node> pq;

struct star
{
	double x;
	double y;
};
int root[101];
star arr[101];

int find(int a)
{
	if (root[a] == a) return a;
	return find(root[a]);
}

bool Union(int a, int b)
{
	int a_r = find(a);
	int b_r = find(b);
	if (a_r == b_r) return false;

	root[b_r] = a_r;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	double x, y, tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		root[i] = i;
		arr[i].x = x;
		arr[i].y = y;

		// pq�� �� �ֱ�
		for (int j = 1; j < i; j++)
		{
			tmp = sqrt((x - arr[j].x)*(x - arr[j].x) + (y - arr[j].y)*(y - arr[j].y));
			
			pq.push({ j, i, tmp });
		}
	}

	double res = 0;

	// union-find
	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (Union(tmp.a, tmp.b))
		{
			res += tmp.dist;
		}
	}

	// ��°�ڸ����� �Ҽ��� �ڸ���
	// ���� ���̱� ����
	res *= 100;
	int res2 = res;
	double total_res = (double)((double)res2 / 100);
	cout << total_res;

	return 0;
}