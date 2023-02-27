#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 백준 23294 - 웹 브라우저 1
// 구현
// 골드 4

int n, q, c;
int cash_cap; // 전체 캐시 용량
int back_cap = 0; // 뒤로 가기 용량
int front_cap = 0; // 앞으로 가기 용량
vector<int> cap; // 용량
vector<int> back_q; // 뒤로 가기
stack<int> front_q; // 앞으로 가기
int now = -1; // 현재 보는 페이지
int chkWeb[2001]; // 웹페이지 중복 확인 위해

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q >> c;
	cap.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> cap[i];
	}

	char cmd;
	int p, tmp;
	for (int i = 0; i < q; i++)
	{

		cin >> cmd;
		if (cmd == 'B') // 뒤로 가기
		{
			if (back_q.empty()) continue;
			front_q.push(now);
			front_cap += cap[now];
			now = back_q[back_q.size() - 1];
			back_cap -= cap[now];
			back_q.pop_back();
		}
		else if (cmd == 'F') // 앞으로 가기
		{
			if (front_q.empty()) continue;
			back_q.push_back(now);
			back_cap += cap[now];
			now = front_q.top();
			front_cap -= cap[now];
			front_q.pop();
		}
		else if (cmd == 'A') // 접속
		{
			cin >> p;

			while (!front_q.empty()) front_q.pop();
			front_cap = 0;

			if (now != -1)
			{
				back_q.push_back(now);
				back_cap += cap[now];
			}
			now = p;
			cash_cap = back_cap + cap[p];

			// 최대 캐시 용량 초과
			if (cash_cap > c)
			{
				while (cash_cap > c)
				{
					tmp = back_q[0];
					back_cap -= cap[tmp];
					cash_cap -= cap[tmp];
					back_q.erase(back_q.begin());
				}
			}
		}
		else // C, 압축, 뒤에서부터 삭제해야 함, 연속일때만 삭제!!
		{
			for (int i = 1; i <= n; i++) chkWeb[i] = 0;

			for (int i = back_q.size() - 2; i >= 0;)
			{
				if (back_q[i] == back_q[i + 1])
				{
					// 삭제
					back_cap -= cap[back_q[i]];
					back_q.erase(back_q.begin()+ i);
					i -= 1;
				}
				else i--;
			}
		}
	}

	// 출력
	cout << now << '\n';
	if (back_q.empty()) cout << -1 << '\n';
	else
	{
		for (int i = back_q.size() - 1; i >= 0; i--)
		{
			cout << back_q[i] << ' ';
		}
		cout << '\n';
	}
	if (front_q.empty()) cout << -1 << '\n';
	else
	{
		while (!front_q.empty())
		{
			cout << front_q.top() << ' ';
			front_q.pop();
		}
	}

	return 0;
}
