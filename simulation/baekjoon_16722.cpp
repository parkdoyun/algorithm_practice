#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// ���� 16722 - ��! ��!
// simulation
// ��� 4

using namespace std;

struct pic
{
	int shape; // 0 CIRCLE, 1 TRIANGLE, 2 SQUARE
	int color; // 0 YELLOW, 1 RED, 2 BLUE
	int background; // 0 GRAY, 1 WHITE, 2 BLACK
};
vector<pic> vec;
int score = 0;

// ��ȣ ������������ 3�� ���̱� (��� ��)
// int 1�̸� �� ��ģ ����
int path[4];
map<string, int> map1;

int isH(int a, int b, int c)
{
	if (vec[a].shape == vec[b].shape && vec[b].shape == vec[c].shape);
	else if (vec[a].shape != vec[b].shape && vec[b].shape != vec[c].shape && vec[a].shape != vec[c].shape);
	else return -1;

	if (vec[a].color == vec[b].color && vec[b].color == vec[c].color);
	else if (vec[a].color != vec[b].color && vec[b].color != vec[c].color && vec[a].color != vec[c].color);
	else return -1;

	if (vec[a].background == vec[b].background && vec[b].background == vec[c].background);
	else if (vec[a].background != vec[b].background && vec[b].background != vec[c].background && vec[a].background != vec[c].background);
	else return -1;

	return 1;
}

void backtracking(int lv, int num)
{
	if (lv == 3)
	{
		// ������ �Ǵ� �� ���̸� map1�� �ֱ�
		if (isH(path[0], path[1], path[2]) == 1)
		{
			string res = "";
			res = res + (char)('0' + path[0]) + " " + (char)('0' + path[1]) + " " + (char)('0' + path[2]);
			map1.insert({ res, 0 });
		}
		return;
	}

	for (int i = num + 1; i <= 9; i++)
	{
		path[lv] = i;
		backtracking(lv + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, c, b;
	vec.resize(10);

	for (int i = 1; i <= 9; i++)
	{
		cin >> s >> c >> b;
		if (s == "CIRCLE") vec[i].shape = 0;
		else if (s == "TRIANGLE") vec[i].shape = 1;
		else vec[i].shape = 2;

		if (c == "YELLOW") vec[i].color = 0;
		else if (c == "RED") vec[i].color = 1;
		else vec[i].color = 2;

		if (b == "GRAY") vec[i].background = 0;
		else if (b == "WHITE") vec[i].background = 1;
		else vec[i].background = 2;
	}
	// ��� �� ���ؼ� map�� �ֱ�
	// backtracking
	for (int i = 1; i <= 7; i++)
	{
		path[0] = i;
		backtracking(1, i);
	}

	int n;
	cin >> n;
	char answer;

	string tmp;
	int g_flag = 0; // ���� ���� 3�� ���� �� �ִٸ� 1
	int tmp_input[3];
	for (int i = 0; i < n; i++)
	{
		cin >> answer;
		if (answer == 'H') // ��
		{
			cin >> tmp_input[0] >> tmp_input[1] >> tmp_input[2];
			// �ִ��� Ȯ��
			// ������������ ���
			sort(tmp_input, tmp_input + 3);
			tmp = "";
			tmp = tmp + (char)('0' + tmp_input[0]) + " " + (char)('0' + tmp_input[1]) + " " + (char)('0' + tmp_input[2]);
			if (map1.find(tmp) == map1.end()) score--;
			else if (map1[tmp] == 1) score--;
			else
			{
				map1[tmp] = 1;
				score++;
			}
		}
		else // ��
		{
			if (g_flag == 1)
			{
				score--;
				continue;
			}
			int flag = 0;
			for (auto e : map1)
			{
				if (e.second == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1) score--;
			else
			{
				score += 3;
				g_flag = 1;
			}
		}
	}

	cout << score;

	return 0;
}