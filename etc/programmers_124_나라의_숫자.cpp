#include <iostream>
#include <string>
#include <vector>
#include <math.h>

// ���α׷��ӽ� level 2 - 124 ������ ����

using namespace std;

int main()
{
	string answer = "";
	int n = 9;
	

	// 3�� ������ ���̿� �ִ��� (�ڸ���) Ȯ��
	int position_cnt = 0; // ���� ��(�ڸ���)
	long int sum = 0;
	for (int i = 1; sum <= 500000000; i++)
	{
		if (n >= sum && n <= sum + pow(3, i))
		{
			position_cnt = i;
			break;
		}
		sum += pow(3, i);
	}

	int tmp = n;
	tmp = tmp - sum - 1;
	// �� �� 3�� �� ��� �ڿ� �ִ���
	// ù° �ڸ� �� -> 3^(position_cnt-1)�� ����
	// ��° �ڸ� �� -> 3^(position_cnt-2)
	// ...
	int position = 0;
	int a;
	for (int i = position_cnt - 1; i >= 0; i--)
	{
		a = pow(3, i);
		position = tmp / a;
		if (position == 0) answer += "1";
		else if (position == 1) answer += "2";
		else answer += "4";
		tmp = tmp % a;
	}

	cout << answer << endl;
	return 0;
}