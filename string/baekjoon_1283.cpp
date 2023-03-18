#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 1283 - 단축키 지정
// 문자열
// 실버 1

int n;
int choice[26]; // 단축키로 지정된다면 1

struct word
{
	string s;
	int idx = -1; // s에서 단축키 위치, 단축키 없다면 -1
};
vector<word> vec;

string makeUpper(string s) // 전부 대문자로 변환
{
	string tmp_s = s;
	for (int i = 0; i < s.length(); i++)
	{
		if (tmp_s[i] >= 'a' && tmp_s[i] <= 'z') tmp_s[i] -= 32;
	}
	return tmp_s;
}

int makeHotkey(string s)
{
	// 단어 첫 글자 확인
	int i = 0;
	if (s[i] != ' ' && choice[(int)(s[i] - 'A')] == 0)
	{
		choice[(int)(s[i] - 'A')] = 1;
		return i;
	}
	while (i < s.length())
	{
		if (s[i] == ' ')
		{
			i++;
			if (i == s.length()) break;
			else if (choice[(int)(s[i] - 'A')] == 0)
			{
				choice[(int)(s[i] - 'A')] = 1;
				return i;
			}
		}
		i++;
	}

	// 왼쪽부터 단축키 지정
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') continue;
		if (choice[(int)(s[i] - 'A')] == 0)
		{
			choice[(int)(s[i] - 'A')] = 1;
			return i;
		}
	}

	// 없다면
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	n = stoi(s);

	int res;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s); // 한줄 입력
		res = makeHotkey(makeUpper(s));
		vec.push_back({ s, res });
	}

	// 출력
	for (int i = 0; i < n; i++)
	{
		if (vec[i].idx == -1) cout << vec[i].s;
		else
		{
			for (int j = 0; j < vec[i].s.length(); j++)
			{
				if (vec[i].idx == j) cout << '[' << vec[i].s[j] << ']';
				else cout << vec[i].s[j];
			}
		}
		cout << '\n';
	}

	return 0;
}