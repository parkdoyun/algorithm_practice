#include <iostream>
#include <string>

using namespace std;

// 백준 15927 - 회문은 회문 아니야!
// greedy, 문자열
// 골드 5

string s;
bool chk()
{
	int start = 0;
	int end = s.length() - 1;
	while (start < end)
	{
		if (s[start] != s[end]) return true;
		start++;
		end--;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	char c = s[0];
	int flag = 0;
	for (int i = 1; i < s.length(); i++) // 예외 : 모두 같을 때
	{
		if (c != s[i])
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0) cout << -1;
	else
	{
		if (chk()) // 회문 아니면 출력
		{
			cout << s.length();
		}
		else cout << s.length() - 1; // 회문이면 1 뺀 거 무조건 회문 아님
	}

	return 0;
}