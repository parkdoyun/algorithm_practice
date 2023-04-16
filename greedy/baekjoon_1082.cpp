#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 백준 1082 - 방 번호
// greedy
// 골드 3

// 자릿수 많은 게 더 크다 (여러 장 살 수 있는 게)
// 자릿수 같다면 숫자 큰 게 더 크다
// 제일 작은 거 일단 살 수 있는 만큼 산다
// 처음 자릿수부터 바꿀 수 있는 가장 큰 수로 바꾼다

struct room
{
	int num;
	int price;
};
vector<room> info; // 인덱스 = 방번호
vector<room> vec; // 가격 낮은 순서대로
vector<room> vec2; // 방번호 큰 순서대로

bool cmp(room r1, room r2)
{
	if (r1.price < r2.price) return true;
	else if (r1.price == r2.price && r1.num > r2.num) return true;
	return false;
}
bool cmp2(room r1, room r2)
{
	return r1.num > r2.num;
}

int n, m;
int room_num[52];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 52; i++) room_num[i] = -1;

	cin >> n;
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vec.push_back({ i, p });
	}
	cin >> m;
	
	info = vec;
	sort(vec.begin(), vec.end(), cmp);
	vec2 = vec;
	sort(vec2.begin(), vec2.end(), cmp2);

	// 구매
	// 만약 0만 있는 거 아니라면
	// 0으로 시작하면 안 된다
	int pos_n = m / vec[0].price; // 자릿수

	// 예외 : 0만 있을 경우 => 무조건 0
	if (n == 1 && vec[0].num == 0)
	{
		cout << 0;
		return 0;
	}

	// 첫번째 수는 0 아니어야 함
	if (pos_n > 1 && vec[0].num == 0)
	{
		room_num[0] = vec[1].num;
		if (m - vec[1].price < 0) // 만약 0 아닌 수 첫번쨰로 안 되면 -> 무조건 그냥 0
		{
			cout << 0;
			return 0;
		}
		else
		{
			m -= vec[1].price;
			pos_n = 1;
			while (m > 0)
			{
				if (m - vec[0].price < 0) break;
				room_num[pos_n] = 0;
				m -= vec[0].price;
				pos_n++;
			}
		}
	}
	else
	{
		for (int i = 0; i < pos_n; i++)
		{
			room_num[i] = vec[0].num;
			m -= vec[0].price;
		}
	}

	// 바꾸기
	for (int i = 0; i < pos_n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec2[j].num == room_num[i]) break; // 어차피 이 다음부터 나보다 수 작음
			if (m >= (vec2[j].price - info[room_num[i]].price))
			{
				m -= (vec2[j].price - info[room_num[i]].price);
				room_num[i] = vec2[j].num;
				break;
			}
		}
	}

	for (int i = 0; i < pos_n; i++) cout << room_num[i];

	return 0;
}