#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 17124 - �� ���� �迭
// binary search + map
// �ǹ� 3

// map -> �ð� �ʰ�
// �̺�Ž������ ã��
// vector�� �����صΰ�
// �̺�Ž���� �ð��ʰ� => ó���� ���� �� ���� Ž������ ���� ������ �ߺ� ����

int a[1000001];
map<int, int> map1; // b�� �ֱ� ���� ���� �꿡 �ֱ�
vector<int> b;
int b_len;

int binary_search(int goal)
{
	int start = 0;
	int end = b_len;
	int mid;
	int res = b[0];
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (b[mid] == goal)
		{
			return b[mid];
		}
		else if (b[mid] < goal)
		{
			start = mid + 1;
			if (goal - b[mid] <= abs(res - goal)) res = b[mid];
		}
		else
		{
			end = mid - 1;
			if (b[mid] - goal < abs(res - goal)) res = b[mid];
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int n, m;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int tmp;
		for (int i = 0; i < m; i++)
		{
			cin >> tmp;
			if (map1.find(tmp) == map1.end()) map1.insert({ tmp, 1 });
		}

		// map1 -> b�� �ű��
		for (auto e : map1)
		{
			b.push_back(e.first);
		}

		sort(b.begin(), b.end());
		b_len = b.size() - 1;

		// �̺�Ž������ ã��
		long long int res = 0;
		for (int i = 0; i < n; i++)
		{
			tmp = binary_search(a[i]);
			res = (long long int)(res + (long long int)tmp);
		}		
		cout << res << '\n';

		b.clear();
		map1.clear();
	}

	return 0;
}