#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// ���� 1774 - ���ֽŰ��� ����
// union-find
// ��� 3

// ��°�ڸ����� ����� �ݿø� �϶�� ���̾���

int n, m;
int root[1001];
double res = 0.0;

struct node
{
	int x;
	int y;
};
node arr[1001];
int find(int a)
{
	if (root[a] == a) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b, double w)
{
	int a_r = find(a);
	int b_r = find(b);
	if (a_r == b_r) return;
	res += w;
	root[b_r] = a_r;
}

struct node2
{
	int a;
	int b;
	double val;
};
bool operator<(node2 n1, node2 n2)
{
	if (n1.val > n2.val) return true;
	return false;
}
priority_queue<node2> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
		cin >> arr[i].x >> arr[i].y;
		for (int j = 1; j < i; j++)
		{
			pq.push({ j, i, (double)sqrt((double)((long long int)(((long long int)(arr[i].y - arr[j].y) * (long long int)(arr[i].y - arr[j].y)))) +
				(double)((long long int)((long long int)(arr[i].x - arr[j].x) * (long long int)(arr[i].x - arr[j].x)))) });
		}
	}
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Union(a, b, 0);
	}

	while (!pq.empty())
	{
		node2 tmp = pq.top();
		pq.pop();

		Union(tmp.a, tmp.b, tmp.val);
	}

	// ���
	// ���� : 0
	
	// ��°�ڸ����� �ݿø�
	res = res * (double)100;
	res = round(res);
	res = res / (double)100;

	// �Ҽ��� ���ڸ����� ����ϱ�
	cout << fixed;
	cout.precision(2);
	cout << (double)res;

	return 0;
}