#include <iostream>
using namespace std;

// ���� 4673 - ���� �ѹ�

int main()
{
	// ������ ���� Ȯ�� [N - (A+B+C) = ABC]?
	// 2�ڸ��� : 0,1 ~  (���� ���ϴ� �� �߿�)
	// ������ ������ ��� pass
	// ������ �� ������ �� ���
	// abcd (�ڸ� ��ġ)
	int i_a;
	//int i_b, i_c, i_d;
	int j_a, j_b, j_c, j_d;
	// 1�ڸ� ���
	cout << 1 << endl << 3 << endl << 5 << endl << 7 << endl << 9 << endl;
	
	for (int i = 10; i < 100; i++) // 2�ڸ�, ab
	{
		i_a = i / 10;
		//i_b = i - (i_a * 10);
		for (int j = i - (i_a + 9); j <= i; j++)
		{
			j_a = j / 10;
			j_b = j - (j_a * 10);
			if (j == i)
			{
				cout << i << endl;
				break;
			}
			if (j + j_a + j_b == i) break;
		}
	}
	
	for (int i = 100; i < 1000; i++) // 3�ڸ�, abc
	{
		i_a = i / 100;
		//i_b = (i - (i_a * 100)) / 10;
		for (int j = i - (i_a + 18); j <= i; j++) // 9 + 9
		{
			j_a = j / 100;
			j_b = (j - (j_a * 100)) / 10;
			j_c = j - (j_a * 100) - (j_b * 10);
			if (j == i)
			{
				cout << i << endl;
				break;
			}
			if (j + j_a + j_b + j_c == i) break;
		}
	}

	for (int i = 1000; i < 10000; i++) // 4�ڸ�, abcd
	{
		i_a = i / 1000;
		//i_b = (i - (i_a * 100)) / 10;
		for (int j = i - (i_a + 27); j <= i; j++) // 9 + 9 + 9
		{
			j_a = j / 1000;
			j_b = (j - (j_a * 1000)) / 100;
			j_c = (j - (j_a * 1000) - (j_b * 100)) / 10;
			j_d = j - (j_a * 1000) - (j_b * 100) - (j_c * 10);
			if (j == i)
			{
				cout << i << endl;
				break;
			}
			if (j + j_a + j_b + j_c + j_d == i) break;
		}
	}
	
	return 0;
}