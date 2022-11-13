#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� 15686 - ġŲ ���
// dfs, exhaustive search
// ��� 5

// m�� ���� ���� ġŲ �Ÿ� �� -> ���� ���� ġŲ �Ÿ� ���
// backtracking���� �ִ� m�� ���� (m���� �ƴ� ���� �ִ�)
// ���� ������ ġŲ �Ÿ� -> BFS => �ð��ʰ� => for�� 2�� ������ ���

int n, m;
int board[51][51];
int path[14];
int min1 = 1000000000;

struct h
{
	int y;
	int x;
	int d;
};

vector<h> house; // ��
vector<h> chicken; // ġŲ ��


int tmp;

void cal2()
{
	tmp = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int tmp_y = house[i].y;
		int tmp_x = house[i].x;

		int tmp_min = 100000000000;
		int tmp_now;
		for (int j = 0; j < chicken.size(); j++)
		{
			if (path[j] == 0) continue;
			tmp_now = abs(chicken[j].y - tmp_y) + abs(chicken[j].x - tmp_x);
			if (tmp_now < tmp_min) tmp_min = tmp_now;
		}
		tmp += tmp_min;
	}
}


void backtracking(int lv, int cnt)
{
	if (lv == chicken.size())
	{
		if (cnt == 0) return; // ���� ������ѹ�����

		// ġŲ �Ÿ� ���
		cal2();
		if (tmp < min1) min1 = tmp;
		return;
	}

	if (cnt != m)
	{
		path[lv] = 1;
		backtracking(lv + 1, cnt + 1);
		path[lv] = 0;
		backtracking(lv + 1, cnt);
	}
	else
	{
		path[lv] = 0;
		backtracking(lv + 1, cnt);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				house.push_back({ i, j });
			}
			else if (board[i][j] == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	path[0] = 0;
	backtracking(1, 0);
	path[0] = 1;
	backtracking(1, 1);

	cout << min1;


	return 0;
}