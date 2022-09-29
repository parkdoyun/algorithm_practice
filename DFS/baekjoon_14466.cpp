#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// 백준 14466 - 소가 길을 건너간 이유6
// DFS
// 나는 3 3 2 3 => "3323" 문자열로 해서 경로를 저장했는데
// 이렇게 되면 34 2 2 3과 3 42 2 3  이 "34223"으로 같은 경로로 인식되어 문제 생김
// 문자열 사이 공백으로 좌표 구분 해주자

struct cow
{
	int y;
	int x;
};

int visit[101][101] = { 0 };
map<string, int> map2;
vector<cow> cows;
int n, k, r;

void visitClear()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) visit[i][j] = 0;
	}
}

int x_mov[] = { 0, 1, 0, -1 };
int y_mov[] = { -1, 0, 1, 0 };

void DFS(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		string tmp_str1 = to_string(y) + " " + to_string(x) + " " + to_string(y + y_mov[i]) + " " + to_string(x + x_mov[i]);
		string tmp_str2 = to_string(y + y_mov[i]) + " " + to_string(x + x_mov[i]) + " " + to_string(y) + " " + to_string(x);

		if (y + y_mov[i] >= 1 && y + y_mov[i] <= n &&
			x + x_mov[i] >= 1 && x + x_mov[i] <= n &&
			visit[y + y_mov[i]][x + x_mov[i]] == 0 && 
			(map2.find(tmp_str1) == map2.end() && map2.find(tmp_str2) == map2.end()))
		{
			visit[y + y_mov[i]][x + x_mov[i]] = 1;
			DFS(y + y_mov[i], x + x_mov[i]);
		}
	}
}


int main()
{
	int r1, c1, r2, c2;
	cin >> n >> k >> r;
	
	for (int i = 0; i < r; i++)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		string tmp = "";
		tmp = to_string(r1) + " " + to_string(c1) + " " + to_string(r2) + " " + to_string(c2);
		map2.insert({ tmp, 1 });
	}

	int a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		cows.push_back({ a,b });

	}
	int cnt = 0;

	for (int i = 0; i < k - 1; i++)
	{
		// DFS 후 소 개수 확인
		visitClear();
		visit[cows[i].y][cows[i].x] = 1;
		DFS(cows[i].y, cows[i].x);
		for (int j = i + 1; j < cows.size(); j++)
		{
			if (visit[cows[j].y][cows[j].x] == 0)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	

	return 0;
}