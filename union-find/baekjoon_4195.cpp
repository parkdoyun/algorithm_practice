#include <iostream>
#include <string>
#include <map>

using namespace std;

// ���� 4195 - ģ�� ��Ʈ��ũ
// union-find
// ��� 2

// ũ�� ����
// ���ٿ� �θ� -> 10�����̸� �ִ� 20����

int n, m;
int root[200002];
int people[200002]; // �� �׷쿡 ����ִ���, root�� ����
map<string, int> names;

int find(int a)
{
	if (root[a] == a) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b)
{
	int a_r = find(a);
	int b_r = find(b);
	if (a_r == b_r) return;
	root[b_r] = a_r;
	// �׷�� �� �̵�
	people[a_r] += people[b_r];
	people[b_r] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, f, idx, a_n, b_n;
	string a, b;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		// �ʱ�ȭ
		for (int i = 1; i <= 200001; i++)
		{
			root[i] = i;
			people[i] = 1;
		}
		idx = 1;
		names.clear();

		cin >> f;
		for (int i = 0; i < f; i++)
		{
			cin >> a >> b;
			if (names.find(a) == names.end())
			{
				names.insert({ a, idx });
				a_n = idx;
				idx++;
			}
			else a_n = names[a];
			if (names.find(b) == names.end())
			{
				names.insert({ b, idx });
				b_n = idx;
				idx++;
			}
			else b_n = names[b];
			Union(a_n, b_n);

			cout << people[find(a_n)] << '\n';
		}
	}

	return 0;
}