#include <iostream>
#include <string>

using namespace std;

// 백준 1790 - 수 이어 쓰기 2
// DP
// 골드 5

int tmp_len, prefix;
int calLen(int a)
{
	int ten = 10;
	int res = 1;
	while (ten <= a)
	{
		res++;
		ten *= 10;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int point = 0;
	int flag = -1;
	if (k < 10 && n < k)
	{
		cout << -1;
	}
	else if (k < 10)
	{
		cout << k;
	}
	else
	{
		point = 10;
		prefix = 1;
		tmp_len = 1;	
		while (point <= k)
		{
			tmp_len = calLen(prefix);
			for (int i = 0; i < 10; i++)
			{
				if (prefix * 10 + i > n) // n이 너무 작을 때
				{
					cout << -1;
					flag = 1;
					break;
				}
				if (k >= point && k < point + tmp_len)
				{
					string res = to_string(prefix);
					cout << res[k - point];
					flag = 1;
					break;
				}

				point += tmp_len;
				if (k == point)
				{
					flag = 1;
					cout << i;
					break;
				}
				point++;
			}
			if (flag == 1) break;
			prefix++;
		}
		if (flag != 1) cout << -1;
	}

	return 0;
}