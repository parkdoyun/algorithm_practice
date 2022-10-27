#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// ���� 1202 - ���� ����
// greedy
// ��� 2

// �� ���濡 ���� �� �ִ� �ֵ� ����
// 1���� ���� 2���� ���Է� ����
// ���� �ִ� ���� ���ſ� ������ ����
// 1������ ���濡 ����

// pq�� �ְ�(���� ���濡 ���� �� �ִ� �ֵ�) �� �� ���� ���� �ֵ��� �ִ´�
// �ڷᱸ�� 2�� �ʿ�

// ���� ���� ���� �� ���ϴ� pq (���� ���� �� �켱����)
// ��� ������ �� ���� pq (���� ���� �ֵ�)
// ���� ���� �ֵ���� Ȯ��

struct jewel
{
	long long m;
	long long v;
};

struct jewel2
{
	long long m;
	long long v;
};

bool operator<(jewel j1, jewel j2)
{
	if (j1.m > j2.m) return true;
	return false;
}

bool operator<(jewel2 j1, jewel2 j2)
{
	if (j1.v < j2.v) return true;
	return false;
}

priority_queue<jewel> pq;
priority_queue<jewel2> pq_cmp;
long long bag[300001];

bool cmp2(long long a, long long b)
{
	if (a < b) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, k;
	cin >> n >> k;
	jewel j;
	for (int i = 0; i < n; i++)
	{
		cin >> j.m >> j.v;
		pq.push(j);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> bag[i];
	}

	long long total = 0;
	sort(bag, bag + k, cmp2);

	for (int i = 0; i < k; i++) {
		jewel2 tmp;
		while (!pq.empty() && pq.top().m <= bag[i])
		{
			tmp.m = pq.top().m;
			tmp.v = pq.top().v;
			pq_cmp.push(tmp);
			pq.pop();
		}
		if (pq_cmp.empty()) continue; // �̰� �� ������ double free error
		total += pq_cmp.top().v;
		pq_cmp.pop();
		/*
		jewel tmp1;
		while (!pq_cmp.empty()) // �ٽ� �� �ʿ� X => ������ �� ū ������ Ȯ���ϹǷ�
		{
			tmp1.m = pq_cmp.top().m;
			tmp1.v = pq_cmp.top().v;
			pq.push(tmp1);
			pq_cmp.pop();
		}
		*/
	}

	cout << total;

	return 0;
}