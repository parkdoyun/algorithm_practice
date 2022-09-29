#include <iostream>
#include <string>
#include <map>
using namespace std;

// ���� 14425�� - ���ڿ� ����
// �� STL ���

int main()
{
	map<string, int> set;
	string s;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		set.insert(make_pair(s, i));
	}
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (set.find(s) != set.end()) count++;
	}
	
	cout << count << '\n';
	return 0;
}