#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 백준 1062 - 가르침
// 백트래킹(DFS)
// 골드 4

int chk[26] = { 0 };
vector<string> dict;
int n, k;
int max1 = 0;

int stringOk(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (chk[(int)(s[i] - 'a')] == 0) return -1;
	}
	return 1;
}
string path = "";
void DFS(int lv, int prev_idx)
{
	if (lv == k)
	{
		//cout << path << endl;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (stringOk(dict[i]) == 1) cnt++;
		}
		if (cnt > max1) max1 = cnt;
		return;
	}
	for (int i = prev_idx + 1; i < 26; i++)
	{
		if (chk[i] == 0)
		{
			chk[i] = 1;
			path += (char)('a' + i);
			DFS(lv + 1, i);

			path.erase(path.size() - 1, 1);
			chk[i] = 0;
		}
	}
}


int main()
{
	cin >> n >> k;
	k -= 5;
	chk[0] = 1;
	chk[(int)('n' - 'a')] = 1;
	chk[(int)('t' - 'a')] = 1;
	chk[(int)('i' - 'a')] = 1;
	chk[(int)('c' - 'a')] = 1;
	string s;
	for (int i = 0; i < n; i++)
	{
		int arr[26] = { 0 };
		cin >> s;
		string tmp = "";
		for (int j = 4; j < s.length() - 4; j++)
		{
			arr[(int)(s[j] - 'a')]++;
		}
		for (int j = 0; j < 26; j++)
		{
			if (arr[j] != 0)
			{
				tmp += (char)('a' + j);
			}
		}
		dict.push_back(tmp);
		
	}
	if (k < 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	else if (k == 0)
	{
		// 바로 검사
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (stringOk(dict[i]) == 1) cnt++;
		}
		cout << cnt << "\n";
		return 0;
	}

	for (int i = 0; i < 26; i++)
	{
		if (chk[i] == 0)
		{
			chk[i] = 1;
			path += (char)('a' + i);
			DFS(1, i);
			path = "";
			chk[i] = 0;
		}
	}

	cout << max1 << endl;
	return 0;
}