#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���� 1283 - ����Ű ����
// ���ڿ�
// �ǹ� 1

int n;
int choice[26]; // ����Ű�� �����ȴٸ� 1

struct word
{
	string s;
	int idx = -1; // s���� ����Ű ��ġ, ����Ű ���ٸ� -1
};
vector<word> vec;

string makeUpper(string s) // ���� �빮�ڷ� ��ȯ
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
	// �ܾ� ù ���� Ȯ��
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

	// ���ʺ��� ����Ű ����
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') continue;
		if (choice[(int)(s[i] - 'A')] == 0)
		{
			choice[(int)(s[i] - 'A')] = 1;
			return i;
		}
	}

	// ���ٸ�
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
		getline(cin, s); // ���� �Է�
		res = makeHotkey(makeUpper(s));
		vec.push_back({ s, res });
	}

	// ���
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