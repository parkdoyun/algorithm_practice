#include <iostream>
#include <string>

using namespace std;

// ���� 2138 - ������ ����ġ
// greedy
// ��� 5

// ������ ù��°���� �Ӱ��� �ƴ���
// �ΰ� �� �غ��� �Ѵ� �Ǹ� �ּҰ� ��
// �� �� �Ǹ� -1
// ����� �� 1) ù��°���� �ѱ� -> ������ �ѱ� / �ٸ� ���� �ѱ�
//           2) �ι�°���� �ѱ� -> ������ �ѱ� / �ٸ� ���� �ѱ� => �� 4���� ��

// ���� ���� �ٸ��� �ٲ���

int main()
{
	string input, output, tmp;
	int n;
	cin >> n >> output >> input;
	int min = 999999999;

	// ù��°���� �Ѵ� �� ��
	int cnt = 0;
	tmp = output;
	
	if (tmp[0] != input[0]) // Ȯ���ϰ� �ѱ�
	{
		cnt++;
		tmp[0] = (tmp[0] == '0' ? '1' : '0');
		tmp[1] = (tmp[1] == '0' ? '1' : '0');
	}

	for (int i = 1; i < n - 1; i++)
	{
		if (tmp[i - 1] != input[i - 1])
		{
			cnt++;
			tmp[i-1] = (tmp[i-1] == '0' ? '1' : '0');
			tmp[i] = (tmp[i] == '0' ? '1' : '0');
			tmp[i + 1] = (tmp[i + 1] == '0' ? '1' : '0');
		}
	}
	if (tmp[n - 2] != input[n - 2])
	{
		cnt++;
		tmp[n - 2] = (tmp[n - 2] == '0' ? '1' : '0');
		tmp[n - 1] = (tmp[n - 1] == '0' ? '1' : '0');
	}
	if (tmp == input)
	{
		if (cnt < min) min = cnt;
	}

	// ������ �ѱ�
	cnt = 0;
	tmp = output;

	
	cnt++;
	tmp[0] = (tmp[0] == '0' ? '1' : '0');
	tmp[1] = (tmp[1] == '0' ? '1' : '0');
	

	for (int i = 1; i < n - 1; i++)
	{
		if (tmp[i - 1] != input[i - 1])
		{
			cnt++;
			tmp[i - 1] = (tmp[i - 1] == '0' ? '1' : '0');
			tmp[i] = (tmp[i] == '0' ? '1' : '0');
			tmp[i + 1] = (tmp[i + 1] == '0' ? '1' : '0');
		}
	}
	if (tmp[n - 2] != input[n - 2])
	{
		cnt++;
		tmp[n - 2] = (tmp[n - 2] == '0' ? '1' : '0');
		tmp[n - 1] = (tmp[n - 1] == '0' ? '1' : '0');
	}
	if (tmp == input)
	{
		if (cnt < min) min = cnt;
	}


	// �ι�°���� �Ѵ� �� ��
	cnt = 0;
	tmp = output;
	if (tmp[0] != input[0]) // Ȯ�� �� �ѱ�
	{
		cnt++;
		tmp[0] = (tmp[0] == '0' ? '1' : '0');
		tmp[1] = (tmp[1] == '0' ? '1' : '0');
		tmp[2] = (tmp[2] == '0' ? '1' : '0');
	}

	for (int i = 2; i < n - 1; i++)
	{
		if (tmp[i - 1] != input[i - 1])
		{
			cnt++;
			tmp[i - 1] = (tmp[i - 1] == '0' ? '1' : '0');
			tmp[i] = (tmp[i] == '0' ? '1' : '0');
			tmp[i + 1] = (tmp[i + 1] == '0' ? '1' : '0');
		}
	}
	if (tmp[n - 2] != input[n - 2])
	{
		cnt++;
		tmp[n - 2] = (tmp[n - 2] == '0' ? '1' : '0');
		tmp[n - 1] = (tmp[n - 1] == '0' ? '1' : '0');
	}
	if (tmp == input)
	{
		if (cnt < min) min = cnt;
	}

	// �ι�°���� �ѱ�
	// ������ �ѱ�
	cnt = 0;
	tmp = output;
	
	cnt++;
	tmp[0] = (tmp[0] == '0' ? '1' : '0');
	tmp[1] = (tmp[1] == '0' ? '1' : '0');
	tmp[2] = (tmp[2] == '0' ? '1' : '0');
	

	for (int i = 2; i < n - 1; i++)
	{
		if (tmp[i - 1] != input[i - 1])
		{
			cnt++;
			tmp[i - 1] = (tmp[i - 1] == '0' ? '1' : '0');
			tmp[i] = (tmp[i] == '0' ? '1' : '0');
			tmp[i + 1] = (tmp[i + 1] == '0' ? '1' : '0');
		}
	}
	if (tmp[n - 2] != input[n - 2])
	{
		cnt++;
		tmp[n - 2] = (tmp[n - 2] == '0' ? '1' : '0');
		tmp[n - 1] = (tmp[n - 1] == '0' ? '1' : '0');
	}
	if (tmp == input)
	{
		if (cnt < min) min = cnt;
	}

	if (input == output) cout << 0;
	else if (min == 999999999) cout << -1;
	else cout << min;

	return 0;
}