#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 5052 - 전화번호 목록
// string, greedy, map
// 골드 4

// 제일 긴 애들부터 앞에서부터 접두사 확인 (맵에서 검색하여)

int n;
map<string, int> map_call; // 전화번호 목록
vector<string> vec;
bool cmp(string s1, string s2)
{
	return s1.length() > s2.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	string s;
	int min_len, flag;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> n;
		vec.clear();
		map_call.clear();
		min_len = 20000;
		flag = -1;

		for (int i = 0; i < n; i++)
		{
			cin >> s;
			if (s.length() < min_len) min_len = s.length();
			vec.push_back(s);
			map_call.insert({ s, 1 });
		}

		sort(vec.begin(), vec.end(), cmp);

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = min_len; j < vec[i].length(); j++)
			{
				if (map_call.find(vec[i].substr(0, j)) != map_call.end())
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}