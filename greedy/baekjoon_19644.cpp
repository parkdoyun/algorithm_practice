#include <iostream>

using namespace std;

// 백준 19644 - 좀비 떼가 기관총 진지에도 오다니
// greedy
// 골드 4

// 시간 초과

// 사거리 => 해당 길이만큼 mk번 쏠 수 있다는 거임
// 한바퀴 돌면서 mk * ml보다 큰 애들 갯수가 bomb_n보다 크면 NO
// 폭탄 맞으면 해당 사거리들은 줄어야 함

int L, ml, mk, bomb_n;
int road[3000001];
int chk[3000001]; // 현재 얼마나 성능 떨어지는지 카운트, 1이면 올라가고 -1이면 떨어짐, 0이면 그대로

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> ml >> mk;
	cin >> bomb_n;

	int now_n = 1; // 현재 몇배해서 갈 수 있는지
	int cnt = 0; // 폭탄 최소 사용 개수
	int flag = 0;
	for (int i = 1; i <= L; i++)
	{
		cin >> road[i];
		if (road[i] > mk * now_n)
		{
			cnt++;
			chk[i]--; // 지금은 내려가고
			if (i + ml <= L) chk[i + ml]++; // 올라간다
		}
		if (i < ml)
		{
			now_n++;
		}
		now_n += chk[i];
		if (now_n < 0) flag = -1; // 사용 불가능
		if (ml == 1) // 예외 : ml 1일 때 폭탄 항상 써도 다음날 기관총 가능
		{
			now_n = 1;
		}
	}

	if (cnt > bomb_n || flag == -1) cout << "NO";
	else cout << "YES";	

	return 0;
}