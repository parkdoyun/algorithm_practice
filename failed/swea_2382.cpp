#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// swea 2382 - �̻��� �ݸ�

//���� �Ź� ���忡 �׸� �ʿ� X
//�ϴ� ǥ�ø� �ϰ�(vector�� ����, ��ġ, �� ����)
//�ð� �ٲ� ���� ���� ������ �ִ� �ֵ� �ִ� ã�Ƽ� ��ġ�� �� = >
//�ð� �ٲ� ������
//n ^ 2 �迭 �ϳ� �� �Ἥ �� ������ �̻��� ���� ����, �ְ� n�� dir ǥ��
//���� �� �� ����� �ϳ��� ����� ��

// �ð� �ٲ�� �������� -> �̹� �ִ� �ϸ� -> ���� ���� ��ȯ�� �ֿ� ���� ���ϰ� �ٽ� �� ��������� ��

int n, m, k, total;
int chk[102][102];
int x_mov[] = { 0, 0, 0, -1, 1 };
int y_mov[] = { 0, -1, 1, 0, 0 };

void chkClear()
{
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++) chk[i][j] = 0;
	}
}

struct node2
{
	int y;
	int x;
	int n;
	int dir;
	int time = 0;
};
vector<node2> vec;
bool cmp(node2 n1, node2 n2)
{
	if (n1.n > n2.n) return true;
	return false;
}

void BFS()
{
	int now_time = 0;
	while (!vec.empty())
	{
		node2 tmp = vec[0];
		if (tmp.time >= m) break;
		if (tmp.time > now_time) // time ����
		{
			now_time = tmp.time;
			chkClear();
			sort(vec.begin(), vec.end(), cmp);
		}

		tmp = vec[0];
		vec.erase(vec.begin());

		tmp.x += x_mov[tmp.dir];
		tmp.y += y_mov[tmp.dir];
		tmp.time++;
		if (chk[tmp.y][tmp.x] != 0) // ū �� ������ �׳� ���ϰ� ��
		{
			chk[tmp.y][tmp.x] += tmp.n;
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i].y == tmp.y && vec[i].x == tmp.x)
				{
					vec[i].n += tmp.n;
					break;
				}
			}
		}
		else
		{
			if (tmp.x == 0 || tmp.x == n + 1 ||
				tmp.y == 0 || tmp.y == n + 1) // ��ǰ�� ������
			{
				tmp.n = tmp.n / 2;

				if (tmp.dir == 1) tmp.dir = 2;
				else if (tmp.dir == 2) tmp.dir = 1;
				else if (tmp.dir == 3) tmp.dir = 4;
				else tmp.dir = 3;
			}
			if (tmp.n != 0)
			{
				vec.push_back(tmp);
				chk[tmp.y][tmp.x] = tmp.n;
			}
		}
	}
}

int main()
{
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> k;
		total = 0;
		vec.clear();
		int y, x, n, d;
		for (int i = 0; i < k; i++)
		{
			cin >> y >> x >> n >> d;
			vec.push_back({ y, x, n, d });
		}

		sort(vec.begin(), vec.end(), cmp);
		BFS();

		for (int i = 0; i < vec.size(); i++) total += vec[i].n;

		cout << '#' << tc << ' ' << total << '\n';
	}
	

	return 0;
}