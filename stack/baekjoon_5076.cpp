#include <iostream>
#include <string>
#include <stack>

using namespace std;

// ���� 5076 - Web Pages
// ���ڿ�
// ��� 4

stack<string> st;

int main()
{
	string s, tmp_s;
	while (true)
	{
		getline(cin, s);
		while (!st.empty()) st.pop();

		if (s == "#") break;

		int idx = 0;
		int chk = -1;
		while (idx < s.length())
		{			
			while (s[idx] != '<' && idx < s.length()) idx++;
			if (idx == s.length()) break;

			idx++;
			if (s[idx] == '/') // st���� ����
			{
				idx++;
				if (st.size() == 0) // ���� �Ǵµ� ������ ����� ��
				{
					chk = 1;
					break;
				}
				tmp_s = "";
				while (s[idx] != '>' && idx < s.length())
				{
					tmp_s += s[idx];
					idx++;
					
				}
				if (st.top() == tmp_s) st.pop();
				else // ������ top�̶� ��ȣ �� ���ڿ� �ٸ� ��
				{
					chk = 1;
					break;
				}
			}
			else // ���ڿ� ���, '/'�� ������ pass
			{
				tmp_s = "";
				while (s[idx] != '>' && s[idx] != ' ' && idx < s.length())
				{
					tmp_s += s[idx];
					idx++;
				}
				if (s[idx + 1] != '/') // st�� �ֱ�
				{
					st.push(tmp_s);
					idx++;
				}
			}
			idx++;

		}
		if (chk == -1 && st.size() == 0) cout << "legal\n";
		else cout << "illegal\n";
	}
	return 0;
}