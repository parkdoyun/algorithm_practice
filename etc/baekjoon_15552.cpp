#include <iostream>

using namespace std;

// ���� 15552�� - ���� A+B
// C++���� cin, cout �ð� ���� ��ƸԴ´�
// 1. C ���
// 2. ���๮�� \n ��� & line 17 ~ 19 �ֱ�
// ����� �׽�Ʈ

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}