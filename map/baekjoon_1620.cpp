#include <iostream>
#include <string>
#include <map>

using namespace std;

// ���� 1620�� - ���¾� ���ϸ� ������ �̴ټ�
// C++���� cin, cout �ð� ���� ��ƸԴ´� -> ���� 15552�� ���� A+B ����
// 1. C ���
// 2. ���๮�� \n ��� & line 17 ~ 19 �ֱ�
// �� ����

string list1[100001];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int>list;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;

		list.insert(make_pair(s, i)); // name, num (pair)
		list1[i] = s;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] >= 'A' && s[0] <= 'Z') // list search
		{
			cout << list.find(s)->second << '\n'; // first : key, second -> value
		}
		else // list1 search
		{
			cout << list1[stoi(s)] << '\n'; // endl�� �������� �ð� ���� ��Ƹ���
		}
	}
	return 0;
}