#include <iostream>

using namespace std;

// swea 4008 - 숫자 만들기
// DFS, backtracking
// backtracking으로 모든 연산 가짓수 계산
// 마지막에 값 계산 후 최대, 최소 비교

int n;
int num[13];
int op[4]; // 0 :  + , 1 : -, 2 : *, 3 : /
int max1, min1;
int path[13];

int cal()
{
	int res = num[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (path[i] == 0) { // +
			res = res + num[i + 1];
		}
		else if (path[i] == 1) { // -
			res = res - num[i + 1];
		}
		else if (path[i] == 2) { // *
			res = res * num[i + 1];
		}
		else // /
		{
			res = res / num[i + 1];
		}
	}
	
	return res;
}

void DFS(int lv)
{
	if (lv == n - 1)
	{
		// 계산
		int tmp = cal();
		/*
		for (int i = 0; i < n - 1; i++)
		{
			cout << path[i] << ' ';
		}
		cout << " => " << tmp << endl;
		*/
		if (tmp > max1) max1 = tmp;
		if (tmp < min1) min1 = tmp;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i] <= 0) continue;
		op[i]--;
		path[lv] = i;
		DFS(lv + 1);
		op[i]++;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		max1 = -100000001;
		min1 = 100000001;

		cin >> n;
		for (int i = 0; i < 4; i++)
		{
			cin >> op[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}

		for (int i = 0; i < 4; i++)
		{
			if (op[i] <= 0) continue;
			op[i]--;
			path[0] = i;
			DFS(1);
			op[i]++;
		}
		cout << '#' << tc << ' ' << max1 - min1 << '\n';
	}
	return 0;
}