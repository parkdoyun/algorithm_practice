#include <iostream>
#include <vector>
using namespace std;

int search_cab(vector<vector<int>>&c, int x, int y, int w, int h);

// ���� 1012�� - ����� ����
// recursion(���), DFS

int main()
{
	int w, h; // width, height
	int cabbage_n; // number
	int test_n;
	cin >> test_n;
	for (int i = 0; i < test_n; i++)
	{
		cin >> w >> h >> cabbage_n;
		vector<vector<int>>cab(w, vector<int>(h, 0));
		int *idx_arr = new int[cabbage_n * 2]; // ��ǥ ���� �迭
		int x, y;
		for (int j = 0; j < cabbage_n; j++)
		{
			cin >> x >> y;
			cab[x][y] = 1; // 1 �ֱ�
			idx_arr[j * 2] = x;
			idx_arr[j * 2 + 1] = y;
		}
		int bug_n = 0;
		for (int j = 0; j < cabbage_n; j++)
		{
			
			if (cab[idx_arr[j * 2]][idx_arr[j * 2 + 1]] == 1)
			{
				bug_n++;
				search_cab(cab, idx_arr[j * 2], idx_arr[j * 2 + 1], w, h);
			}
		}

		cout << bug_n << endl;
		w = 0;
		h = 0;

		delete[] idx_arr;
	}
	return 0;
}

int search_cab(vector<vector<int>>&c, int x, int y, int w, int h)
{
	c[x][y] = 0; // 0���� ����
	// ���� �̵�
	if (x > 0 && (c[x - 1][y] == 1))search_cab(c, x - 1, y, w, h);
	// �Ʒ��� �̵�
	if (x >= 0 && x < w-1 && (c[x + 1][y] == 1))search_cab(c, x + 1, y, w, h);
	// ����
	if (y > 0 && (c[x][y-1] == 1))search_cab(c, x , y-1, w, h);
	// ������
	if (y >= 0 && y < h-1 && (c[x][y + 1] == 1))search_cab(c, x, y + 1, w, h);
	// ���� ���� ����
	return 0; // ��� ����
}