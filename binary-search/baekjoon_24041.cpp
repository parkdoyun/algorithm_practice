#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 24041 - 성싶당 밀키트
// binary search
// 골드 4

int n, g, k;
struct ingre
{
	int s;
	int l;
	int o;
};
vector<ingre> vec;

struct germ
{
	long long int n; // 세균
};
bool operator<(germ g1, germ g2)
{
	return g1.n < g2.n;
}
priority_queue<germ> pq;

int max_date = 0;
int min_s = 1000000001;
int max_l = 0;

bool chk(long long int m) // 뺄 수 있는 애들 중 큰 순서대로 최대 K개 빼자
{
	int mid = m;
	while (!pq.empty()) pq.pop();
	long long int tmp_G = 0;
	long long int tmp;

	for (int i = 0; i < n; i++)
	{
		tmp = (long long int)max(1, mid - vec[i].l) * (long long int)vec[i].s;
		if (vec[i].o == 1)
		{
			pq.push({ tmp });
		}
		tmp_G += tmp;
	}

	int idx = 0;
	while (!pq.empty() && idx < k)
	{
		germ tmp2 = pq.top();
		pq.pop();

		tmp_G -= tmp2.n;
		idx++;
	}

	if (tmp_G > g) return false;
	return true;
}

void binary_search()
{
	long long int start = 1;
	long long int end = max_l + (g / min_s) + 1;
	long long int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (chk(mid)) // 되면
		{
			if (mid > max_date) max_date = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> g >> k;

	int s, l, o;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> l >> o;
		vec.push_back({ s, l, o });
		if (min_s > s) min_s = s;
		if (max_l < l) max_l = l;
	}

	binary_search();

	cout << max_date;

	return 0;
}