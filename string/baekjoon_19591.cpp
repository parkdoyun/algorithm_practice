#include <iostream>
#include <deque>
#include <string>

using namespace std;

// 백준 19591 - 독특한 계산기
// string, deque
// 골드 3

// 1. 수식 정리해서 deque에 삽입
// 2. 양끝 비교하며 연산

deque<char> deq_ch;
deque<long long int> deq_num;

long long int cal(long long int a, long long int b, char op)
{
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else return a / b;
}

long long int tmp1, tmp2;
bool chk()
{
	tmp1 = cal(deq_num.front(), deq_num[1], deq_ch[0]);
	tmp2 = cal(deq_num[deq_num.size() - 2], deq_num.back(), deq_ch.back());

	if ((deq_ch.front() == '+' || deq_ch.front() == '-') && ((deq_ch.back() == '*' || deq_ch.back() == '/'))) return false;
	else if ((deq_ch.front() == '*' || deq_ch.front() == '/') && ((deq_ch.back() == '+' || deq_ch.back() == '-'))) return true;

	// 연산자 우선순위 같음
	if (tmp1 > tmp2) return true;
	else if (tmp1 < tmp2) return false;

	// 값도 같음
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string expr, tmp_num;
	cin >> expr;

	// 파싱
	int idx = 1;
	tmp_num = "";
	tmp_num += expr[0];
	long long int tmp_n;
	int expr_len = expr.length();

	while (idx < expr_len)
	{
		while (expr[idx] >= '0' && expr[idx] <= '9' && idx < expr_len)
		{
			tmp_num += expr[idx];
			idx++;
		}

		if(idx < expr_len) deq_ch.push_back(expr[idx]);

		if (tmp_num[0] == '-')
		{
			tmp_num.erase(tmp_num.begin());
			tmp_n = stoll(tmp_num) * (long long int)-1;
		}
		else tmp_n = stoll(tmp_num);

		deq_num.push_back(tmp_n);

		idx++;
		tmp_num = "";
	}

	// 연산
	while (deq_num.size() > 1)
	{
		if (chk()) // 앞부터 계산
		{
			deq_num.pop_front();
			deq_num.pop_front();
			deq_ch.pop_front();
			deq_num.push_front(tmp1);
		}
		else // 뒤부터 계산
		{
			deq_num.pop_back();
			deq_num.pop_back();
			deq_ch.pop_back();
			deq_num.push_back(tmp2);
		}
	}
	
	if (expr_len == 1) cout << expr; // 예외 처리
	else cout << deq_num.front();

	return 0;
}