#include <iostream>
#include <queue>

using namespace std;

// ���� 1445 - �Ͽ��� ��ħ�� ����Ʈ
// djjkstra
// ��� 2

// *����* �����Ⱑ �����ų� S, F ĭ�� ������ �����⸦ ���� �ʴ´�

struct node
{
	int y;
	int x;
	int pass = 100; // �������� ������
	int incident = 100; // ������ ������
};

bool operator<(node n1, node n2)
{
	if (n1.pass > n2.pass) return true;
	else if (n1.pass == n2.pass && n1.incident > n2.incident) return true;
	return false;
}

int board[51][51];
int chk[51][51];
int arr_p[51][51];
int arr_i[51][51];
int n, m;
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

int cal_incident(int y, int x) // ���� ������ ����
{
	for (int i = 0; i < 4; i++)
	{
		if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < m &&
			board[y + y_mov[i]][x + x_mov[i]] == 3) return 1;
	}
	return 0;
}

priority_queue<node> pq;
void dijkstra(int y, int x)
{
	// ���� ������ ����
	pq.push({ y, x, 0, 0 });
	arr_i[y][x] = 0;
	arr_p[y][x] = 0;

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (chk[tmp.y][tmp.x] == 1) continue;
		chk[tmp.y][tmp.x] = 1;

		if (board[tmp.y][tmp.x] == 2)
		{
			cout << tmp.pass << ' ' << tmp.incident;
			break;
		}

		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];
			if (ty >= 0 && ty < n &&
				tx >= 0 && tx < m &&
				chk[ty][tx] == 0)
			{
				if (board[ty][tx] == 3) // ������ ���� ���
				{
					if (arr_p[ty][tx] > arr_p[tmp.y][tmp.x] + 1)
					{
						arr_p[ty][tx] = arr_p[tmp.y][tmp.x] + 1;
						arr_i[ty][tx] = arr_i[tmp.y][tmp.x];
						pq.push({ ty , tx , arr_p[ty][tx], arr_i[ty][tx] });
					}
				}
				else if(board[ty][tx] == 2)
				{
					if (arr_p[ty][tx] > arr_p[tmp.y][tmp.x])
					{
						arr_p[ty][tx] = arr_p[tmp.y][tmp.x];
						arr_i[ty][tx] = arr_i[tmp.y][tmp.x];
						pq.push({ ty , tx , arr_p[ty][tx], arr_i[ty][tx] });
					}
				}
				else
				{
					if (arr_p[ty][tx] > arr_p[tmp.y][tmp.x])
					{
						arr_p[ty][tx] = arr_p[tmp.y][tmp.x];
						arr_i[ty][tx] = arr_i[tmp.y][tmp.x] + cal_incident(ty, tx);
						pq.push({ ty , tx , arr_p[ty][tx], arr_i[ty][tx] });
					}
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


	cin >> n >> m;
	char c;
	int start_y, start_x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'S')
			{
				start_y = i;
				start_x = j;
				board[i][j] = 1;
			}
			else if (c == 'F') board[i][j] = 2; // ����
			else if (c == 'g') board[i][j] = 3;
			else board[i][j] = 0;

			arr_p[i][j] = 1000;
		}
	}

	dijkstra(start_y, start_x);

	return 0;
}