#include <iostream>
#include <queue>
using namespace std;

// ���� 1715 - ī�� �����ϱ�
// greedy
// ��� 4

// ���� ���� �� �� ������ ���� �� �ٽ� pq�� ������ �ȴ�
// ���� ���� �� ��(�� ��)�� ���� ���� ������ ��� ���ϴ� ��

// �ּ� ��
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	int n;
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		pq.push(a);

	}

	int tmp = 0;
	while (!pq.empty())
	{
		if (pq.size() == 1)
		{
			cout << tmp;
			break;
		}
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		tmp += a + b;
		pq.push(a + b);
	}


	return 0;
}