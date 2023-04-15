#include <iostream>
#include <string>

using namespace std;

// 백준 4889 - 안정적인 문자열
// greedy, string
// 실버 1

// 포인터 넘기다가 안 맞으면 바꾸기

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int tc = 1;

	while (true)
	{
		cin >> s;
		if (s[0] == '-') break;

		int open_n = 0;
		int cnt = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '{')
			{
				open_n++;
			}
			else
			{
				if (open_n == 0) // 잘못되었음
				{
					cnt++; // '{'로 바꾸자
					open_n++;
				}
				else
				{
					open_n--;
				}
			}
		}

		if (open_n > 0) // 잘못되었음
		{
			cnt += open_n / 2;
		}

		cout << tc << ". " << cnt << '\n';

		tc++;

	}
	
	return 0;
}