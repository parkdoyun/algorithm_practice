#include <iostream>
#include <string>

using namespace std;

// ���� 15927 - ȸ���� ȸ�� �ƴϾ�!
// greedy, ���ڿ�
// ��� 5

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
	for (int i = 1; i < s.length(); i++) // ���� : ��� ���� ��
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
		if (chk()) // ȸ�� �ƴϸ� ���
		{
			cout << s.length();
		}
		else cout << s.length() - 1; // ȸ���̸� 1 �� �� ������ ȸ�� �ƴ�
	}

	return 0;
}