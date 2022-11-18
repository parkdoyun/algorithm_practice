#include <string>
#include <vector>

using namespace std;

// programmers ��ô�ȸ
// backtracking 

int n;
vector<int> info = { 0,0,0,0,0,0,0,0,3,4,3 };
vector<int> answer;
int path[11];
int max_score = 0;

int apeach_score, lion_score;


void calScore()
{
	apeach_score = 0;
	lion_score = 0;

	for (int i = 0; i < 11; i++)
	{
		if (info[i] == 0 && path[i] == 0) continue;
		if (info[i] >= path[i]) apeach_score += 10 - i;
		else lion_score += 10 - i;
	}

}

void backtracking(int lv, int tmp_cnt)
{
	if (lv == 11)
	{
		if (tmp_cnt != n) return;
		// ���� ���
		calScore();
		// ���� �� ���

		// ����ġ�� �̰�ٸ� return (���� ���ų� �� ������)
		if (apeach_score >= lion_score) return;

		// �ִ�� ���� ���� ���� ���� ����ٸ� ����
		else if (lion_score - apeach_score == max_score)
		{
			// ���� ���� ���� ����ٸ� ����
			int flag = 0;
			for (int i = 10; i >= 0; i--)
			{
				if (path[i] > answer[i])
				{
					flag = 1;
					break;
				}
				if (path[i] < answer[i]) break;
			}

			if (flag == 1)
			{
				// ����
				max_score = lion_score - apeach_score;
				for (int i = 0; i < 11; i++) answer[i] = path[i];
			}
		}
		// �ִ뺸�� �� ���� ������� ����
		else if (lion_score - apeach_score > max_score)
		{
			max_score = lion_score - apeach_score;
			for (int i = 0; i < 11; i++) answer[i] = path[i];
		}


		return;
	}

	for (int i = 0; i <= n - tmp_cnt; i++)
	{
		path[lv] = i;
		backtracking(lv + 1, tmp_cnt + i);
	}
}

vector<int> solution(int n2, vector<int> info2) {

	info = info2;
	n = n2;

	answer.resize(11);
	answer = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	for (int i = 0; i <= n; i++)
	{
		path[0] = i;
		backtracking(1, i);
	}


	int flags = -1;
	for (int i = 0; i < 11; i++)
	{
		if (answer[i] != -1)
		{
			flags = 1;
			break;
		}
	}

	if (flags == -1)
	{
		answer = { -1 };
	}

	return answer;
}