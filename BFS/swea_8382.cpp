#include <iostream>

using namespace std;

// swea 8382 - ���� ��ȯ
// BFS, dijkstra -> �ð� �ʰ�
// ���� �׶����� ����ؼ� ���ϴ� ������ ��ġ �̵�

int x_mov[] = { -1, 1, -1, 1 };
int y_mov[] = { -1, -1, 1, 1 }; // ���κ��ͳ� ���κ��ͳ� ��� ����, ����

int calDir(int tmp_x, int tmp_y, int x2, int y2)
{
	if (tmp_x > x2)
	{
		if (tmp_y > y2)
		{
			return 0;
		}
		else return 2;
	}
	else
	{
		if (tmp_y > y2)
		{
			return 1;
		}
		else return 3;
	}

	return -1;
}

int main()
{
	int T, x1, y1, x2, y2;
	int x_dist, y_dist;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		int cnt = 0;
		int tmp_x = x1;
		int	tmp_y = y1;


		// �Ÿ� 1 ���ų� ��ġ ����������
		// ���⿡ ���� �̵�
		while (abs(tmp_x - x2) + abs(tmp_y - y2) > 1)
		{
			int idx = calDir(tmp_x, tmp_y, x2, y2);
			cnt += 2;
			tmp_x = tmp_x + x_mov[idx];
			tmp_y = tmp_y + y_mov[idx];
		}

		if (abs(tmp_x - x2) + abs(tmp_y - y2) == 1) cnt++;

		cout << '#' << tc << ' ' << cnt << '\n';

	}


	return 0;
}