#include <iostream>
#include <queue>

using namespace std;

// ���� 17836 - ���ִ��� ���ض�!
// BFS
// ��� 5

// �׶��� ������ ���� �ķ� chk ������
// �ִ� �ð��� �ð� T�� ���Ƶ� �� (���ų� ���� ��)

int n, m, t;
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int board[101][101];
int chk[101][101];
int chk_gram[101][101]; // �׶� ���� ��

struct node
{
	int y;
	int x;
	int dist;
	int gram = 0; // 1 : �׶� ����
};

bool operator<(node n1, node n2)
{
	if (n1.dist > n2.dist) return true;
	else if (n1.dist == n2.dist && n1.gram == 0 && n2.gram == 1) return true;
	return false;
}

priority_queue<node> pq;
int min_time = 1000000000;
void BFS()
{
	pq.push({ 0, 0, 0 });

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();
		
		if (tmp.gram == 0 && chk[tmp.y][tmp.x] == 1) continue;
		else if(tmp.gram == 0) chk[tmp.y][tmp.x] = 1;
		if (tmp.gram == 1 && chk_gram[tmp.y][tmp.x] == 1) continue;
		else if (tmp.gram == 1) chk_gram[tmp.y][tmp.x] = 1;
		
		if (tmp.dist > t) // �ð� T�� ���Ƶ� �ȴ�, fail
		{
			return;
		}
		if (tmp.y == n - 1 && tmp.x == m - 1)
		{
			min_time = tmp.dist;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y_mov[i] >= 0 && tmp.y + y_mov[i] < n &&
				tmp.x + x_mov[i] >= 0 && tmp.x + x_mov[i] < m)
			{
				if (tmp.gram == 0 && chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0) // �׶� ���� ��
				{
					if (board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 1) continue;
					else if (board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0)
					{
						pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1, 0 });
					}
					else pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1, 1 });
				}
				else if(tmp.gram == 1 && chk_gram[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0)// �׶� ���� ��
				{
					pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1, tmp.gram });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	BFS();

	if (min_time == 1000000000) cout << "Fail";
	else cout << min_time;

	return 0;

}