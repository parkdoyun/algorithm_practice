#include <iostream>
#include <string>
using namespace std;

// ���� 5430�� - AC
// ��
// �迭�� �ް�, ���� �ε���, �� �ε���, ���� ���� �̿��Ͽ� �迭 ����

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int arr[100001]{ 0 };
		int order_n, n;
		int start_idx = 0; int end_idx; // ����, �� �ε���
		int direction = 1; // 1 : ������, -1 : ���� (����)
		
		string func;
		cin >> func;
		cin >> n;
		order_n = func.length();
		int idx = 1;
		char c;
		cin >> c; // '['
		int a;
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			arr[j] = a; // ���� �ٷ� �Է� ����
			cin >> c; // ',' or ']'
		}
		if (n == 0) cin >> c; // ������ ']' ó�� (���� n = 0 �̸� ������ ��ȣ ']' �Է� �� �޾����� ���� func�� ���� ��)
		// �迭�� ����ִµ� D�� ����� ��� ����
		int err_cnt = 0;
		end_idx = n-1; // �� ��
		for (int j = 0; j < order_n; j++)
		{
			if (func[j] == 'R')
			{
				direction = direction * -1;
				// ���۰� �� �ε��� ��ü
				int tmp = start_idx;
				start_idx = end_idx;
				end_idx = tmp;
			}
			else if (func[j] == 'D')
			{
				// �迭�� ����ִµ� D�� ����� ��� ����
				if((direction == 1 && start_idx > end_idx) || (direction == -1 && start_idx < end_idx))
				{
					err_cnt = 1;
					break;
				}
				if (direction == 1) start_idx++;
				else if (direction == -1) start_idx--;
			}
		}

		// ���
		if (err_cnt != 0) cout << "error" << endl;
		else
		{
			cout << '[';
			
			// ������ �������� ���� ��������
			if (direction == 1)
			{
				for (int j = start_idx; j <= end_idx; j++)
				{
					cout << arr[j];
					if (j != end_idx) cout << ',';
				}
			}
			else if (direction == -1)
			{
				for (int j = start_idx; j >= end_idx; j--)
				{
					cout << arr[j];
					if (j != end_idx) cout << ',';
				}
			}
			cout << ']' << endl;
		}


	}

	return 0;
}