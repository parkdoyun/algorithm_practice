#include <iostream>

using namespace std;

// ���� 4811 - �˾�
// DP
// ��� 4

// ���� 1 : ���� ������ W�� ������ H���� �տ� �־�� �Ѵ�.
// ���� 2 : W�� H�� ���� N�� �־�� �Ѵ�.
// ���� 3 : �� ó���� W, �� �������� H

// ��ȭ�� DP[w][h] = DP[w-1][h] + DP[w][h-1]
// w���� W, h���� H�� �̷���� ���ڿ� = w-1���� W, h���� H�� �̷���� ���ڿ� + 'W' 
// w���� W, h���� H�� �̷���� ���ڿ� = w���� W, h-1���� H�� �̷���� ���ڿ� + 'H'
// h > w�� ��Ȳ�� �����Ƿ� continue (H ������ �ִ��� W ����)

long long DP[31][31];

int main()
{
	// DP ���� ä���
	// ���� ����
	DP[0][0] = 0;
	DP[1][0] = 1;

	for (int w = 1; w <= 30; w++)
	{
		// W�θ� �̷���� ���ڿ� 1
		DP[w][0] = 1;
		for (int h = 1; h <= 30; h++)
		{
			if (h > w) break;
			DP[w][h] = DP[w - 1][h] + DP[w][h - 1];
		}
	}

	int t;
	while (true)
	{
		cin >> t;
		if (t == 0) break;

		cout << DP[t][t] << '\n';

	}

	return 0;
}