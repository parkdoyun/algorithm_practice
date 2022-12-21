#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// ���� 1797 - �������� �ټ���
// prefix sum
// ��� 2

// �̺� Ž��
// ���� ���� �� �ִ� -> �� ũ��
// ���� �� ���� -> �� �۰�
// 2 ������ �ؾ� ��

// mid�� 2 ������ ��ġ�� �������� Ž���� ���� �� �Ǵ� ���� ����� ��

// �̺� Ž������ �������� X
// �κ��� ����
// �� = -1, �� = 1�� �κ��� ���ϸ� ���� �� 0�� �κ��� ���ڿ� ���� �� ���� ����
// �κ��� ���� �κг����� �� �������� ���� �� �ִ�
// �κ��� ���� �κг��� ��� ���� �� ũ�� ����
// �κ��� ���� �κг��� ���� -> �ӵ� ���̱� ���Ͽ� map ���

// ***���� ���� : �� ó��(vec[1].n���� �����ϴ� ��, �κ��� 0)�� �־���� ��***

struct node
{
	int n;
	int sex;
};
bool cmp(node n1, node n2)
{
	if (n1.n < n2.n) return true;
	return false;
}
struct node2
{
	int start = 0;
	int end = -1;
};
vector<node> vec;
map<int, node2> map1;

int sumArr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int s, n1;
	vec.push_back({ -9999, 0 }); // 1�� idx���� ���� ����
	for (int i = 0; i < n; i++)
	{
		cin >> s >> n1;
		if (s == 0) s = -1;
		vec.push_back({ n1, s });
	}

	sort(vec.begin(), vec.end(), cmp);

	// ���� ���� : �� ó���� �־���� �� (�κ��� 0����)
	node2 tmp;
	tmp.start = vec[1].n;
	map1.insert({ 0, tmp });

	for (int i = 1; i <= n; i++)
	{
		sumArr[i] = sumArr[i - 1] + vec[i].sex;
		if (map1.find(sumArr[i]) == map1.end())
		{
			if (i == n) break;
			node2 tmp;
			tmp.start = vec[i + 1].n;
			map1.insert({ sumArr[i], tmp });
		}
		else
		{
			if (map1[sumArr[i]].end == -1)
			{
				map1[sumArr[i]].end = vec[i].n;
			}
			else if (map1[sumArr[i]].end < vec[i].n) map1[sumArr[i]].end = vec[i].n;
		}
	}
	
	int max1 = 0;
	for (auto e : map1)
	{
		if (e.second.start != -1 && e.second.end != -1)
		{
			if (max1 < e.second.end - e.second.start) max1 = e.second.end - e.second.start;
		}
	}
	cout << max1;

	return 0;
}