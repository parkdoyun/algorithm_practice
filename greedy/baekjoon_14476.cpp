#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 14476 - 최대공약수 하나 빼기
// 골드 2
// greedy

// 전체 최대공약수 구한다
// i) 최대 공약수가 K일 때 -> 최대공약수는 가장 작은 수 하나만 빼보면 됨
// 가장 작은 수 K 빼서 두번째로 작은 수와 K 사이에서 최대 공약수 나올 수 있는지 확인
// ii) 최대 공약수가 K의 약수일 때 -> 다른 수 빼서 K가 최대 공약수 될 수 있는지
// 이러려면 vec[1]부터 vec[n - 1]까지 K로 못 나누는 애가 하나여야 한다

// 예외 : K가 없어지고 K보다 작은 게 최대공약수일 수 있다 (K의 약수가 아닌)

int n, total_divisor;
vector<int> vec;
bool cmp(int a, int b)
{
	return a < b;
}

bool chk(int num)
{
	for (int i = 1; i < n; i++)
	{
		if (vec[i] % num != 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), cmp);

	// 전체 최대 공약수 구하기
	// K부터 K의 약수 전부 빼보면 됨

	// 예외 : K가 없어지고 K보다 작은 게 최대공약수일 수 있다 (K의 약수가 아닌)
	int total_divisor2 = -1;
	for (int i = vec[0]; i > 0; i--)
	{
		if (vec[0] % i != 0)
		{
			if (i < total_divisor2) continue;
			if (chk(i)) total_divisor2 = i;
			continue;
		}
		if (chk(i))
		{
			total_divisor = i;
			break;
		}
	}
	int flag = -1;

	for (int i = vec[1]; i > vec[0]; i--) // vec[0] + 1과 vec[1] 사이에 최대 공약수 있는지 확인
	{
		if (chk(i))
		{
			flag = i;
			break;
		}
	}

	if (flag != -1)
	{
		cout << flag << ' ' << vec[0];
		return 0;
	}

	// 수 하나씩 제외해서 K가 최대 공약수 될 수 있는지
	// 이러려면 vec[1]부터 vec[n - 1]까지 K로 못 나누는 애가 하나여야 한다
	int cnt = 0;
	int idx;
	for (int i = 1; i < n; i++)
	{
		if (vec[i] % vec[0] != 0)
		{
			cnt++;
			idx = i;
		}
	}

	if (cnt == 1)
	{
		cout << vec[0] << ' ' << vec[idx];
		return 0;
	}
	
	// 예외 : K가 없어지고 K보다 작은 게 최대공약수일 수 있다 (K의 약수가 아닌)
	if (total_divisor2 != -1) cout << total_divisor2 << ' ' << vec[0];
	else cout << -1;

	return 0;
}