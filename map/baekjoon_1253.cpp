#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 1253 - ����
// map
// ��� 4

// �ٸ� �� �ΰ��� �� => �� + 0�� �� ��
// �ʿ� ���� ���� (� �ֵ�� �̷���� ���� ������ ����)

struct node // a��°�� b��°�� ���ؼ� �������
{
	int a;
	int b;
};

map<long long int, vector<node>> m;
vector<long long int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long int a;
	for (int i = 0; i < n; i++)
	{
		vector<node> vec2;
		cin >> a;
		vec.push_back(a);
		if (m.find(a) == m.end())
		{
			m.insert({ a, vec2 });
		}
	}

	sort(vec.begin(), vec.end());

	// �ΰ� �� ���
	long long int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			tmp = (long long int)(vec[i] + vec[j]);
			if (m.find(tmp) != m.end())
			{
				m[tmp].push_back({ i, j });
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (m.find(vec[i]) != m.end() && m[vec[i]].size() != 0)
		{
			for (int j = 0; j < m[vec[i]].size(); j++)
			{
				// ���� ���� �̷���� �ֵ鸻�� �ִٸ� cnt++
				if (m[vec[i]][j].a != i && m[vec[i]][j].b != i)
				{
					cnt++;
					break;
				}
			}

		}
	}

	cout << cnt;

	return 0;
}