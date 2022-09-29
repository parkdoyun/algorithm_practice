#include <iostream>
#include <string>

using namespace std;

// 백준 1541 - 잃어버린 괄호
// 문자열
// 무조건 괄호는 뺄셈 뒤에부터 다시 뺄셈 나올 때까지
// 덧셈으로만 묶여야 최대로 뺀다
// 반례 잘 확인

int main()
{
	string s, tmp;
	cin >> s;

	// 처음 수 무조건 더하고
	tmp = "";
	int idx = 0;
	for (int i = 0; s[i] != '-' && s[i] != '+' && i < s.length(); i++)
	{
		tmp += s[i];
		idx++;
	}

	int res = 0;

	// 그 후부터의 수는 괄호 -> 일단 넣어놓음
	int chk_minus = 0; // 1이면 뺄셈, 0이면 덧셈
	int tmp_num;
	while (idx < s.length())
	{
		if (s[idx] == '+')
		{
			if(tmp != "") res += stoi(tmp);
			tmp = "";
			idx++;
			chk_minus = 0;
		}
		else if (s[idx] == '-')
		{
			if (tmp != "") res += stoi(tmp);
			tmp = "";
			idx++;
			chk_minus = 1;
			// 괄호 안의 수
			tmp_num = 0;
			while (s[idx] != '-' && idx < s.length())
			{
				if (s[idx] == '+')
				{
					tmp_num += stoi(tmp);
					tmp = "";
				}
				else tmp += s[idx];
				idx++;
			}
			if (tmp != "")
			{
				tmp_num += stoi(tmp);
				tmp = "";
			}
			res -= tmp_num;
			//idx++;
		}
		else
		{
			tmp += s[idx];
			idx++;
		}
	}
	if (tmp != "" && chk_minus == 0)
	{
		int num = stoi(tmp);
		res += num;
	}
	else if (tmp != "" && chk_minus == 1)
	{
		int num = stoi(tmp);
		res -= num;
	}

	cout << res;

	return 0;
}