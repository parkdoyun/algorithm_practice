#include <iostream>
#include <vector>

using namespace std;

// ���� 17281 - �߱���
// ��� 4
// DFS, backtracking

// ��� ����� �� �� �ϰ� �ִ����� ���
// backtracking ���
// 1�� ������ ������ 4��

int n;
int path[10];
int checked[10];

vector<vector<int>> vec; // ���� ���
int max1 = 0;

int base[3] = { -1, -1, -1 };

int cal() // ���� ��� �Լ�
{
	int res = 0;
	int out;
	int now_player = 1;
	base[2] = -1;
	base[1] = -1;
	base[0] = -1;


	for (int i = 1; i <= n; i++)
	{
		out = 0;
		base[2] = -1;
		base[1] = -1;
		base[0] = -1;

		while (out < 3)
		{
			if (vec[i][path[now_player]] == 0) // �ƿ�
			{
				out++;
			}
			else if (vec[i][path[now_player]] == 1) // ��Ÿ (1��Ÿ)
			{
				if (base[2] != -1)
				{
					res++;
				}
				// 1�羿 ����
				for (int i = 2; i >= 1; i--)
				{
					base[i] = base[i - 1];
				}
				base[0] = 1;
			}
			else if (vec[i][path[now_player]] == 2) // 2��Ÿ
			{
				if (base[2] != -1)
				{
					res++;
				}
				if (base[1] != -1)
				{
					res++;
				}
				base[2] = base[0];
				base[1] = 1;
				base[0] = -1;
				
			}
			else if (vec[i][path[now_player]] == 3) // 3��Ÿ
			{
				if (base[2] != -1)
				{
					res++;
				}
				if (base[1] != -1)
				{
					res++;
				}
				if (base[0] != -1)
				{
					res++;
				}
				base[2] = 1;
				base[1] = -1;
				base[0] = -1;
			}
			else // Ȩ��
			{
				if (base[2] != -1)
				{
					res++;
				}
				if (base[1] != -1)
				{
					res++;
				}
				if (base[0] != -1)
				{
					res++;
				}
				res++;
				base[2] = -1;
				base[1] = -1;
				base[0] = -1;
			}
			now_player++;
			if (now_player == 10) now_player = 1;
		}

	}

	return res;
}

void DFS(int lv)
{
	if (lv == 4) // pass
	{
		DFS(lv + 1);
		return;
	}
	if (lv == 10)
	{
		// ���� ���
		int tmp = cal();
		if (tmp > max1) max1 = tmp;
		return;
	}

	for (int i = 2; i <= 9; i++)
	{
		if (checked[i] == 0)
		{
			checked[i] = 1;
			path[lv] = i;
			DFS(lv + 1);
			path[lv] = 0;
			checked[i] = 0;
		}
	}
}

int main()
{
	path[4] = 1;
	checked[1] = 1;

	cin >> n;

	vec.resize(n + 1);

	int a;

	for (int i = 1; i <= n; i++)
	{
		vec[i].push_back(-1); // 0��° �ƹ��ų� ����ֱ�
		for (int j = 0; j < 9; j++)
		{
			cin >> a;
			vec[i].push_back(a);
		}
	}

	for (int i = 2; i <= 9; i++)
	{
		if (checked[i] == 0)
		{
			checked[i] = 1;
			path[1] = i;
			DFS(2);
			path[1] = 0;
			checked[i] = 0;
		}
	}

	cout << max1;

	return 0;
}