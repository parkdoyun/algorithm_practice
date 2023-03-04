#include <iostream>

using namespace std;

// 백준 16434 - 드래곤 앤 던전
// 이분탐색
// 골드 4

// 이분탐색으로 풀어보자

struct room
{
	int t;
	int a;
	int h;
};
room arr_room[123457];

int n, atk;
long long int min_hp = 9223372036854775807;
long long int end1;

bool chk(long long int sh)
{
	long long int t_atk = atk;
	long long int h = sh;
	for (int i = 1; i <= n; i++)
	{
		if (arr_room[i].t == 1) // monster
		{
			if(arr_room[i].h % t_atk == 0) h -= (long long int)((long long int)arr_room[i].h / t_atk - 1) * (long long int)arr_room[i].a;
			else h -= (long long int)((long long int)arr_room[i].h / t_atk) * (long long int)arr_room[i].a; // 딱 떨어지면 -1, 딱 떨어지지 않으면 그대로
		}
		else // potion
		{
			t_atk += (long long int)(arr_room[i].a);
			h += (long long int)(arr_room[i].h);
			if (sh < h) h = sh;
		}
		if (h <= 0) return false;
	}
	return true;
}

void binary_search()
{
	long long int start = 1;
	long long int mid;

	while (start <= end1)
	{
		mid = (start + end1) / 2;

		// mid 되는지 확인
		if (chk(mid))
		{
			if (mid < min_hp) min_hp = mid;
			end1 = mid - 1;
		}
		else start = mid + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> atk;

	end1 = 0; // 이분탐색 끝 (몬스터로 깎이는 것만 계산)

	int t, a, h;
	long long int tmp_atk = atk;
	for (int i = 1; i <= n; i++)
	{
		cin >> t >> a >> h;
		arr_room[i] = { t, a, h };
		if (t == 1) // monster
		{
			if (h % tmp_atk == 0) end1 += (long long int)(a * (h / tmp_atk - 1)); // 딱 떨어지면 -1, 딱 떨어지지 않으면 그대로
			else end1 += (long long int)(a * (h / tmp_atk));
		}
		else // 2, potion
		{
			tmp_atk += (long long int)a;
		}
	}
	end1 += (long long int)1;

	binary_search();

	cout << min_hp;

	return 0;
}