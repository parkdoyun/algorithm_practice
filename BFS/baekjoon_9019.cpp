#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 백준 9019 - DSLR
// BFS
// 골드 4

// D, S, L, R 전부 수행해서 최소 찾는다
// pq -> q로 바꾸니까 됨
// pq 쓸 이유 없음 (pq는 빼는 데 O(logN), q는 O(1))

int chk_num[10001]; // 여기 체크해서 찾자

struct node
{
	int num;
	int order_n = 0;
	string order = "";
};
queue<node> pq;
int num_arr[4];

int rotate(int a, int dir) // dir 1 : 왼쪽 회전, dir 2 : 오른쪽 회전
{
	int ten = 1000;
	int remain = a;

	for (int i = 0; i < 4; i++)
	{
		num_arr[i] = remain / ten;
		remain = remain % ten;
		ten /= 10;
	}

	if (dir == 1) // 왼쪽 회전
	{
		int t = num_arr[0];
		for (int i = 0; i < 3; i++)
		{
			num_arr[i] = num_arr[i + 1];
		}
		num_arr[3] = t;
	}
	else // 오른쪽 회전
	{
		int t = num_arr[3];
		for (int i = 3; i >= 1; i--)
		{
			num_arr[i] = num_arr[i - 1];
		}
		num_arr[0] = t;
	}
	int res = 0;
	ten = 1;
	for (int i = 3; i >= 0; i--)
	{
		res += ten * num_arr[i];
		ten *= 10;
	}
	return res;
}

void chk(int a, int b)
{
	while (!pq.empty()) pq.pop();
	pq.push({ a });
	int t;

	while (!pq.empty())
	{
		node tmp = pq.front();
		pq.pop();

		if (tmp.num == b)
		{
			cout << tmp.order << '\n';
			break;
		}

		// DSLR
		// D
		if (chk_num[(tmp.num * 2) % 10000] == 0)
		{
			chk_num[(tmp.num * 2) % 10000] = 1;
			pq.push({ (tmp.num * 2) % 10000, tmp.order_n + 1, tmp.order + "D" });
		}

		// S
		if (tmp.num == 0)
		{
			if (chk_num[9999] == 0)
			{
				chk_num[9999] = 1;
				pq.push({ 9999, tmp.order_n + 1, tmp.order + "S" });
			}
		}
		else
		{
			if (chk_num[tmp.num - 1] == 0)
			{
				chk_num[tmp.num - 1] = 1;
				pq.push({ tmp.num - 1, tmp.order_n + 1, tmp.order + "S" });
			}
		}

		// L
		t = rotate(tmp.num, 1);
		if (chk_num[t] == 0)
		{
			chk_num[t] = 1;
			pq.push({ t, tmp.order_n + 1, tmp.order + "L" });
		}

		// R
		t = rotate(tmp.num, 2);
		if (chk_num[t] == 0)
		{
			chk_num[t] = 1;
			pq.push({ t, tmp.order_n + 1, tmp.order + "R" });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int a, b;
	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 0; i < 10000; i++) chk_num[i] = 0;
		cin >> a >> b;
		chk_num[a] = 1;
		chk(a, b);
	}

	return 0;
}