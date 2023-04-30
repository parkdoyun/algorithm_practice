#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 16925 - 문자열 추측
// string
// 골드 5

int n;

struct node
{
	string s;
	int flag; // 접두사인지 접미사인지
	int idx; // 원래 위치
};
bool cmp(node s1, node s2)
{
	return s1.s.length() > s2.s.length();
}
bool cmp2(node s1, node s2)
{
	return s1.idx < s2.idx;
}
vector<node> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, origin;

	cin >> n;
	for (int i = 0; i < 2*n - 2; i++)
	{
		cin >> s;
		vec.push_back({ s, 0, i });
	}
	sort(vec.begin(), vec.end(), cmp);

	origin = vec[0].s + vec[1].s.back();

	int total_flag = -1;

	string tmp_h = vec[0].s;
	string tmp_t = vec[1].s;
	int n_idx = n - 2;

	for (int i = 0; i < vec.size(); i+= 2)
	{
		if (vec[i].s == tmp_h && vec[i + 1].s == tmp_t)
		{
			vec[i].flag = 1;
			vec[i + 1].flag = 2;
		}
		else if(vec[i].s == tmp_t && vec[i + 1].s == tmp_h)
		{
			vec[i].flag = 2;
			vec[i + 1].flag = 1;
		}
		else
		{
			total_flag = 1;
			break;
		}
		tmp_h.erase(n_idx, 1);
		tmp_t.erase(0, 1);
		n_idx--;
	}
	if (total_flag == 1) // 반대로 해야 함
	{
		origin = vec[1].s + vec[0].s.back();

		tmp_h = vec[1].s;
		tmp_t = vec[0].s;
		n_idx = n - 2;

		for (int i = 0; i < vec.size(); i += 2)
		{
			if (vec[i].s == tmp_h && vec[i + 1].s == tmp_t)
			{
				vec[i].flag = 1;
				vec[i + 1].flag = 2;
			}
			else if (vec[i].s == tmp_t && vec[i + 1].s == tmp_h)
			{
				vec[i].flag = 2;
				vec[i + 1].flag = 1;
			}
			else
			{
				total_flag = 1;
				break;
			}
			tmp_h.erase(n_idx, 1);
			tmp_t.erase(0, 1);
			n_idx--;
		}
	}

	sort(vec.begin(), vec.end(), cmp2);

	cout << origin << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].flag == 1) cout << 'P';
		else cout << 'S';
	}

	return 0;
}