#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 백준 1759 - 암호 만들기
// 백트래킹 (DFS)
// 골드5

vector<char> ch_vec;
int l;
bool cmp(char c1, char c2)
{
	if (c1 < c2) return true;
	return false;
}
string path = "";

int cons = 0; // 자음
int vowel = 0; // 모음

char arr_v[] = { 'a', 'e', 'i', 'o', 'u' };
int isVowel(char c)
{
	for (int i = 0; i < 5; i++)
	{
		if (arr_v[i] == c) return 1;
	}
	return -1;
}
int chk[16] = { 0 };
void DFS(int lv, int prev_idx)
{

	if (lv == l)
	{
		if(vowel >= 1 && cons >= 2) cout << path << "\n";
		return;
	}
	for (int i = prev_idx + 1; i < ch_vec.size(); i++)
	{
		if (chk[i] == 0)
		{
			chk[i] = 1;
			path += ch_vec[i];
			if (isVowel(ch_vec[i]) == 1) vowel++;
			else cons++;

			DFS(lv + 1, i);
			path.erase(path.size() - 1, 1);

			if (isVowel(ch_vec[i]) == 1) vowel--;
			else cons--;
			chk[i] = 0;
		}
		
	}
}

int main()
{
	int c;
	cin >> l >> c;

	char c1;
	for (int i = 0; i < c; i++)
	{
		cin >> c1;
		ch_vec.push_back(c1);
	}
	sort(ch_vec.begin(), ch_vec.end(), cmp);

	for (int i = 0; i < ch_vec.size(); i++)
	{
		if (isVowel(ch_vec[i]) == 1) vowel++;
		else cons++;
		chk[i] = 1;
		path += ch_vec[i];
		DFS(1, i);
		path = "";
		chk[i] = 0;
		if (isVowel(ch_vec[i]) == 1) vowel--;
		else cons--;
	}

	return 0;
}