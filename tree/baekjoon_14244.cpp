#include <iostream>
using namespace std;

// ���� 14244�� - Ʈ�� �����
// ������ �κ� ����� ���� ���߱�
// Ʈ��, ������

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	cout << "0 1\n";
	a = 1;
	b = 2;

	for (int i = 2; i <= n - 1; i++)
	{
		cout << a << ' ' << i << '\n';
		if (n - 1 - i > (m-2))
		{
			a = i;
		}
	}
	return 0;
}