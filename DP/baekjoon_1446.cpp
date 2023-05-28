#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1446 - 지름길
// DP
// 실버 1

// 점화식 DP[i] = min(DP[i - 1] + 1, (만약 i번째가 끝인 지름길 있을 경우 모든 지름길로부터 i까지))

struct road
{
	int s;
	int len;
};
vector<vector<road>> vec;

int n, d;
int DP[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d;

	vec.resize(d + 1);

	int ts, te, tlen;

	for (int i = 0; i < n; i++)
	{
		cin >> ts >> te >> tlen;
		if (te > d) continue;
		vec[te].push_back({ ts, tlen });
	}
	
	for (int i = 1; i <= d; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (vec[i].empty()) continue;

		for (int j = 0; j < vec[i].size(); j++)
		{
			DP[i] = min(DP[i], DP[vec[i][j].s] + vec[i][j].len);
		}
	}

	cout << DP[d];

	return 0;
}