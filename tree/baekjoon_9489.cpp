#include <iostream>
#include <vector>
using namespace std;

// ���� 9489�� - ����
// Ʈ��

struct node
{
	int value = -1;
	node *parent = NULL;
	vector<node*> child;
};

int main()
{
	int n, k;
	while (true)
	{
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		node input[1000]{0};
		for (int i = 0; i < n; i++)
		{
			cin >> input[i].value;
		}
		node *root = &input[0];
		
		int start_idx, tmp_idx, next_idx;
		int prev_parent_idx = 0; // ���� ������ �θ� ���
		
		node *k_node;
		start_idx = 1; // ä������ �ϴ� �ε���(�ڽĵ�)�� ������
		for (int i = 1; i < n; i++)
		{
			tmp_idx = i; // ���� ���� �ִ� ���
			next_idx = i + 1; // ���� ����� ���� ���
			if (next_idx != n)
			{
				if (input[next_idx].value != input[tmp_idx].value + 1) // ���� ��尡 ���ӵ��� �ʴ´ٸ�
				{
					for (int j = start_idx; j <= tmp_idx; j++)
					{
						input[j].parent = &input[prev_parent_idx];
						input[prev_parent_idx].child.push_back(&input[j]); // �ڽĿ� �߰�						
					}
					prev_parent_idx++;
					start_idx = tmp_idx + 1;
				}
			}
			else // tmp_idx�� �� �������϶�
			{
				for (int j = start_idx; j <= tmp_idx; j++)
				{
					input[j].parent = &input[prev_parent_idx];
					input[prev_parent_idx].child.push_back(&input[j]); // �ڽĿ� �߰�
				}
			}
			if (input[i].value == k) k_node = &input[i];
		}
		// ���� ��� (�θ� ��Ʈ, ���� ��Ʈ�� ���� ����)
		node *k_parent = k_node->parent;
		if (k_parent == root || k_parent == NULL)
		{
			cout << "0\n";
		}
		else
		{
			node *k_grand_parent = k_parent->parent;
			int sib_num = 0;
			for (int i = 0; i < k_grand_parent->child.size(); i++)
			{
				sib_num += k_grand_parent->child[i]->child.size();
			}
			int brother_num = k_parent->child.size();
			cout << sib_num-brother_num << '\n';
		}
		
	}

	return 0;
}