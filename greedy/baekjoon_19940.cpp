#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 백준 19940 - 피자 오븐
// greedy
// 골드 5

// 연산을 해서 양수가 되는 경우와 음수 되는 경우 나눠서 생각

struct node
{
	int addh = 0;
	int addt = 0;
	int mint = 0;
	int addo = 0;
	int mino = 0;
	
	int total()
	{
		return this->addh + this->addt + this->mint + this->addo + this->mino;
	}
};
bool cmp(node n1, node n2)
{
	if (n1.total() < n2.total()) return true;
	else if (n1.total() > n2.total()) return false;

	if (n1.addh < n2.addh) return true;
	else if (n1.addh == n2.addh && n1.addt < n2.addt) return true;
	else if (n1.addh == n2.addh && n1.addt == n2.addt && n1.mint < n2.mint) return true;
	else if (n1.addh == n2.addh && n1.addt == n2.addt && n1.mint == n2.mint && n1.addo < n2.addo) return true;
	else if (n1.addh == n2.addh && n1.addt == n2.addt && n1.mint == n2.mint && n1.addo == n2.addo && n1.mino < n2.mino) return true;
	return false;
}
vector<node> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, n, tmp;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		vec.clear();	

		// ex) 45

		// 60 단위
		node n1; // 양수, 45
		n1.addh = n / 60; // 어차피 60 이상은 전부 addh로 채워야 함
		int n1_val = n % 60; // 45

		// 60 빼자
		node n2; // 음수, -15
		n2.addh = n1.addh + 1;
		int n2_val = (n % 60) - 60; // -15

		// 10 단위
		node n11 = n1; // n1 양수
		n11.addt = abs(n1_val / 10);
		int n11_val = n1_val % 10; // 5 (10 * 4 + 5)
		n11.addo = abs(n11_val);

		node n12 = n1; // n1 음수
		n12.addt = n11.addt + 1;
		int n12_val = (n1_val % 10) - 10; // -5 (10 * 5 - 5)
		n12.mino = abs(n12_val);

		node n21 = n2; // n2 양수
		n21.mint = abs(n2_val / 10);
		int n21_val = n2_val % 10; // -5 (-10 * 1 - 5)
		n21.mino = abs(n21_val);

		node n22 = n2; // n2 음수
		n22.mint = n21.mint + 1;
		int n22_val = n21_val + 10; // 5 (-10 * 2 + 5)
		n22.addo = abs(n22_val);

		vec.push_back(n11); vec.push_back(n12);
		vec.push_back(n21); vec.push_back(n22);

		// 정렬 후 가장 조건에 맞는 결과 출력
		sort(vec.begin(), vec.end(), cmp);
		cout << vec[0].addh << ' ' << vec[0].addt << ' ' << vec[0].mint << ' ' << vec[0].addo << ' ' << vec[0].mino << '\n';
	}

	return 0;
}