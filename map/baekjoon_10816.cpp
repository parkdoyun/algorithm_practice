#include <iostream>
#include <map>
using namespace std;

// 백준 10816 - 숫자 카드 2

map<int, int> card;

int arr_plus[10000001] = { 0 }; // 0부터
int arr_minus[10000000] = { 0 }; // -1부터

int main()
{
	/*
	// 맵 - 시간 초과
	// 입출력 시간 줄여주니까 통과

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (card.find(a) == card.end()) // 못 찾았다면 삽입
		{

			card.insert({ a, 1 });
		}
		else
		{
			card[a]++; // 카드 하나 더 추가
		}
	}

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		// 카드 찾고 없으면 0 출력
		cin >> a;
		if (card.find(a) == card.end()) // 없으면 0 출력
		{
			cout << 0 << ' ';
		}
		else cout << card[a] << ' ';
		
	}
	*/

	// 배열 -> 시간초과
	// 입출력 시간 줄여주니까 통과
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a >= 0)
		{
			arr_plus[a]++;
		}
		else
		{
			arr_minus[a * -1]++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (a >= 0)
		{
			cout << arr_plus[a] << ' ';
		}
		else
		{
			cout << arr_minus[a * -1] << ' ';
		}
	}

	return 0;
}