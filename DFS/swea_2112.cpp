#include <iostream>

using namespace std;

// swea 2112 - ��ȣ �ʸ�
// DFS, backtracking
// ��ǰ �����ϴ� ��� ������ ���� (���� �� �ϴ� �� ����)
// ���ɰ˻� ��� -> �ּ� ��ǰ �� ����
// �ð� �ʰ� -> DFS �߰��� ���� & chk �Լ� �߰��� ����

int d, w, k;
int film[14][21];
int film_cp[14][21]; // arr copy

int path[14];// -1 : ��ǰ X, 0 : 0���� , 1 : 1�� ó��
int min1 = 10000000000;

void arrCp()
{
	for (int i = 0; i < d; i++) 
	{
		for (int j = 0; j < w; j++)
		{
			if (path[i] == -1) film_cp[i][j] = film[i][j];
			else if (path[i] == 0) film_cp[i][j] = 0;
			else film_cp[i][j] = 1;
		}
	}
}

int chk()
{
	int res = 0;
	for (int i = 0; i < w; i++)
	{
		int idx = 0;
		int max_cnt = 0;
		int cnt;
		while (idx < d - 1)
		{
			cnt = 1;
			while (idx < d - 1 && film_cp[idx][i] == film_cp[idx + 1][i])
			{
				cnt++;
				idx++;
			}
			idx++;
			if (max_cnt < cnt) max_cnt = cnt;
		}
		if (max_cnt >= k) res++;
		else return -1;
	}
	return res;
}

// ��ǰ ī��Ʈ�� min1���� Ŭ ��� ������ return
void DFS(int lv, int med_cnt)
{
	if (med_cnt >= min1 || min1 == 0) return;
	if (lv == d)
	{
		// ��ȣ�ʸ� ���
		arrCp();
		int tmp_res = chk();

		// �հ����� ���
		if (tmp_res == w)
		{
			int tmp_cnt = 0;
			for (int i = 0; i < d; i++)
			{
				if (path[i] != -1) tmp_cnt++;
			}
			if (tmp_cnt < min1)
			{
				min1 = tmp_cnt;
			}
		}

		return;
	}
	
	path[lv] = -1;
	DFS(lv + 1, med_cnt);

	path[lv] = 0;
	DFS(lv + 1, med_cnt + 1);

	path[lv] = 1;
	DFS(lv + 1, med_cnt + 1);

}


int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> d >> w >> k;
		min1 = 10000000000;

		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++) cin >> film[i][j];
		}

		// ��ǰ �� �ְ� �Ǵ��� ���� Ȯ��
		for (int i = 0; i < w; i++) path[i] = -1;
		arrCp();
		if (chk() == w)
		{
			cout << '#' << tc << ' ' << 0 << '\n';
			continue;
		}

		path[0] = -1;
		DFS(1, 0);

		path[0] = 0;
		DFS(1, 1);

		path[0] = 1;
		DFS(1, 1);

		cout << '#' << tc << ' ' << min1 << '\n';
	}

	return 0;
}