#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 11000 - ���ǽ� ����
// greedy
// ��� 5

// �ڷᱸ�� 2�� ���
// 1. ���ǽ� ����/���� �ð� ���� �迭
// 2. �̿� ������ ���ǽ� ���� ���� pq

// pq�� ���ǽ� ���� �ð��� ���� ������ ��´�.
// �迭���� ���� �ð��� ���� ������ ���� ��, ���� pq���� ���� ���� ���� �ð���
// �迭�� ���� �ð����� ���� ���(���� �ϴ� ����), �ش� ������ �� ���ǽ��� �����Ƿ� pq�� �ϳ� �� �߰��Ѵ�
// ���ǽ� ������ pq.size() ����ϸ� �ȴ�.

struct node
{
	int s;
	int t;
};
struct node2
{
	int t; // ���� �ð�
};

bool operator<(node2 n1, node2 n2)
{
	if (n1.t > n2.t) return true;
	return false;
}

bool cmp(node n1, node n2)
{
	if (n1.s < n2.s) return true;
	else if (n1.s == n2.s && n1.t < n2.t) return true;
	return false;
}

vector<node> vec; // ���ǽ� ����
priority_queue<node2> pq; // ���� ������ ���ǽ� (���� �ð� ��)

int main()
{
	int n;
	cin >> n;

	node tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.s >> tmp.t;
		vec.push_back(tmp);
	}

	// ���� �ð��� ���� ������ ����, ���ٸ� ���� �ð� ���� ��
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		if (pq.empty())
		{
			pq.push({ vec[i].t });
			continue;
		}

		if (pq.top().t > vec[i].s)
		{
			pq.push({ vec[i].t });
		}
		else
		{
			pq.pop();
			pq.push({ vec[i].t });
		}
		
	}

	cout << pq.size();

	return 0;
}