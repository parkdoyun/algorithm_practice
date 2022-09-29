#include <stdio.h>

// ���� 14241 - ������ ��ġ��
// �ּ� �� �̿�

int main()
{
	int n, x, arr_n;
	scanf("%d", &n); // n

	int arr[101];
	arr_n = 0; // ���� �ִ� ����� ����

	for (int i = 0; i < n; i++) // ������ ũ�� �Է�, ���� �ֱ�
	{
		scanf("%d", &x);
		// ���(������) �߰�
		arr_n++;
		arr[arr_n] = x;
		if (arr_n != 1)
		{
			int child_idx = arr_n;
			int parent_idx = child_idx / 2;
			while (child_idx != 1 && (arr[child_idx] < arr[parent_idx]))
			{
				int tmp = arr[child_idx];
				arr[child_idx] = arr[parent_idx];
				arr[parent_idx] = tmp;
				child_idx = parent_idx;
				parent_idx = parent_idx / 2;
			}
		}

	}
	int score = 0; // ����
	int slime_size = arr[1];
	for (int i = 0; i < n; i++) // ������ ������ ���� �ִ� ���
	{
		if (i == 0)
		{
			slime_size = arr[1];
		}
		else
		{
			score += slime_size * arr[1];
			slime_size += arr[1];
		}
		if (arr_n == 1)
		{
			arr[1] = 0;
			arr_n--;
		}
		else
		{
			arr[1] = arr[arr_n];
			arr[arr_n] = 0;
			arr_n--;
			int parent_idx = 1;
			int child_left_idx, child_right_idx;

			// �����ϰ� ��Ʈ�ۿ� �� ������ �� (parent�� ���� ������� Ȯ��)
			while (!(parent_idx * 2 > arr_n))
			{ // �ڽ� ��� Ȯ��
				child_left_idx = parent_idx * 2;
				child_right_idx = child_left_idx + 1;
				// 1. �ڽ��� �θ� -> �� ���� �ڽ� ��� ��, ū �ڽ� ��� ��, �Ѵ� ũ�� ����
				if (parent_idx * 2 + 1 <= arr_n)
				{
					int big_child_idx = (arr[child_left_idx] > arr[child_right_idx] ? child_left_idx : child_right_idx);
					int small_child_idx = (big_child_idx == child_left_idx ? child_right_idx : child_left_idx);
					if (arr[small_child_idx] < arr[parent_idx])
					{
						// �θ� ���� �ڽ� ��� �ٲٱ�
						int tmp = arr[small_child_idx];
						arr[small_child_idx] = arr[parent_idx];
						arr[parent_idx] = tmp;
						parent_idx = small_child_idx;
					}
					else if (arr[big_child_idx] < arr[parent_idx])
					{
						// �θ� ���� �ڽ� ��� �ٲٱ�
						int tmp = arr[big_child_idx];
						arr[big_child_idx] = arr[parent_idx];
						arr[parent_idx] = tmp;
						parent_idx = big_child_idx;
					}
					else break;
				}
				else // 2. �ڽ��� �Ѹ�(����) -> �ڽ� ��� ��, ũ�� ����
				{
					if (arr[child_left_idx] < arr[parent_idx])
					{
						int tmp = arr[child_left_idx];
						arr[child_left_idx] = arr[parent_idx];
						arr[parent_idx] = tmp;
						parent_idx = child_left_idx;
					}
					else break;
				}
			}
		}

	}
	printf("%d\n", score); // ���� ���

	return 0;
}
