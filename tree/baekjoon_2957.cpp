#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// ���� 2957 - ���� Ž�� Ʈ��
// tree, map
// �÷�Ƽ�� 5

// lower bound�� upper bound �� �� depth ���� ������ insert
// depth �� ���� ���� �� ū ����� �θ��̱� ����!

int n;
map<int, long long int> tree;
map<int, long long int>::iterator low_bound; // lower bound
map<int, long long int>::iterator upp_bound; // upper bound

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	long long int cnt = 0;

	// ��輱 ����� (lower, upper bound ����ϹǷ�)
	tree.insert({ 0, -1 });
	tree.insert({ 300001, -1 });

	long long int depth;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		low_bound = (--tree.lower_bound(tmp)); // temp�� ������ ��� �� ���� ��
		upp_bound = tree.upper_bound(tmp); // temp�� ������ ��� �� ���� ��

		// ���� ��� �� �� depth �� �� ū �� ����
		depth = max(low_bound->second, upp_bound->second) + 1; // depth �ϳ� �� Ŀ�� �ϹǷ�
		
		// insert
		tree.insert({ tmp, depth });
		cnt += depth;

		// print
		cout << cnt << '\n';
	}

	return 0;
}