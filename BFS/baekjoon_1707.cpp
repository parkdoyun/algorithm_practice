#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� 1707 - �̺� �׷���
// bfs
// ��� 4

// ��� �ѷ� ���� ���� �� ���Ѵ� => backtracking
// �������� �ʵ��� ���ҵǴ��� Ȯ�� => DFS
// 0�� ��, 1�� ��
// �ð� �ʰ�

// bfs�� �ϸ鼭 ���� ������ �ֵ��� �ٸ� ������ üũ
// �̹� �湮�ǰ� �����ѵ� ���� ���� ���� �ִٸ� -> NO
// �� üũ�ȴٸ� -> YES

// ������ �� : �׷����� ������ ���� �� ���� -> visitChk�� �˻�
// ��� ��������� �� �غ��� ��
// �ð� �ʰ� => while���� �ѹ� �� �ؼ� => �ذ�

int visit[20001];
int team[20001]; // 1, -1
int v;

struct edge
{
	int oppo;
};

vector<vector<edge>> E;

void visitClr(int v)
{
	for (int i = 1; i <= v; i++) visit[i] = 0;
}

int visitChk(int v)
{
	for (int i = 1; i <= v; i++)
	{
		if (visit[i] == 0) return i;
	}
	return -1;
}

// visit �� �� �� �� ���� ���� team ���� �ֵ� ������ chk = 1
int total_chk;
int chk;

struct node
{
	int num;
	int prev;
};
queue<node> q;
void BFS(int start)
{
	while (!q.empty()) q.pop();

	q.push({ start, 1 });

	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();

		if (visit[tmp.num] == 1) continue;
		visit[tmp.num] = 1;

		team[tmp.num] = tmp.prev * -1;
		
		for (int i = 0; i < E[tmp.num].size(); i++)
		{
			if (visit[E[tmp.num][i].oppo] == 1 && (team[E[tmp.num][i].oppo] == team[tmp.num]))
			{
				chk = 1;
				return;
			}
			else if (visit[E[tmp.num][i].oppo] == 1) continue;
			q.push({E[tmp.num][i].oppo, team[tmp.num]});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, e;
	cin >> T;
	E.resize(20001);
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> v >> e;
		total_chk = -1;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			E[a].push_back({ b });
			E[b].push_back({ a });
		}

		visitClr(v);
		chk = -1;
		for (int i = 1; i <= v; i++)
		{
			// ���� �� while() �� �ʿ䰡 X

			//visitClr(v);
			//chk = -1;
			/*
			while (true)
			{
				int s = visitChk(v);
				if (s == -1 || chk == 1) // �� �湮�ߴٸ�
				{
					break;
				}
				BFS(s);
			}
			*/
			int s = visitChk(v);
			if (s == -1) break;
			BFS(s);

		}

		if (chk == -1) total_chk = 1;

		if (total_chk == -1) cout << "NO\n";
		else cout << "YES\n";

		// �ʱ�ȭ
		for (int i = 0; i <= v; i++) E[i].clear();
		//E.clear();
	}

	return 0;
}