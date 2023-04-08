#include <iostream>

using namespace std;

// 백준 19582 - 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여
// greedy, 누적 합
// 골드 3

// 여태까지 합 > 상금 조건 합 => 참가 못 한다 (여태껏 수 중 최댓값 빼고 계산)
// 1. 이미 대회 하나 뺐는데 또 있을 경우 -> Zzz
// 2-1. 뺼 대회 없는 경우 -> Kkeo-eok
// 2-2. 하나만 빼고 통과한 경우 -> Kkeo-eok

// 3. 해당 대회를 빼는 경우의 수도 있음 (그 전 대회를 제외하는 게 아니라)

int n;
int price[100001]; // 상금
int cond[100001];
long long int sumArr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int x, p;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> p;
		cond[i] = x;
		price[i] = p;
		sumArr[i] = sumArr[i - 1] + (long long int)p;
	}

	int except = 0; // 뺄 상금 (이전 대회 상금 중 최댓값)
	int flag = 0;
	int max1 = price[1];
	int now; // 지금 상금 (조건 통과 못 할때 대회의 상금)
	for (int i = 1; i <= n; i++)
	{
		if (cond[i] < sumArr[i - 1] - except) // 초과할 경우
		{
			if (except == 0) // 처음인 경우
			{
				// 뺐는데도 못 가면 Zzz
				except = max1;
				now = price[i];
				if (i == n) break;
				if (cond[i] < sumArr[i - 1] - except) // 만약 제일 높은 애 빼도 통과 못 하면, 지금 상금을 뺴자
				{
					except = price[i];
				}
			}
			else
			{
				if (cond[i] < sumArr[i - 1] - now) // 지금 상금을 뻈을 때도 안 된다면
				{
					flag = 1; 
					break;
				}
				except = now;
			}
		}
		if (max1 < price[i]) max1 = price[i];
	}

	if (flag == 1) cout << "Zzz";
	else cout << "Kkeo-eok";	

	return 0;
}