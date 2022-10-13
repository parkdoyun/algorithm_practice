#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// swea 2477 - ���� �����
// brute-force, bfs

// �켱 ����
// �����ϴ� ��� ����ȣ �ο�
// ���� â��
// 1. ���� ���� ��ٸ��� ��� �� ��ȣ�� ���� ������ -> (���� �� ������)
// 2. �� â���� ���� ���� ��� â����ȣ�� ���� ������ -> ���� ������ �׻� Ȯ��
// ���� â��
// 1. ���� ��ٸ��� ���� �켱 -> pq
// 2. �̿��ߴ� ���� â����ȣ�� ���� ���� �켱 -> pq
// 3. ���� â���� ���� ������ -> ���� ������ �׻� Ȯ��

// ���� ���, ���� ���, �� ��ȣ�� ����ؾ� �� => ���߿� Ȯ��
// pq 4�� -> ���� ���, ���� ���

// bfs (�ð��� ���� bfs)
// ���� �ð� ��� -> q
// ���� â������ ���� �� Ȯ��(a,b)

int n, m, k, a, b;
int recep[10]; // ���� â��
int repair[10]; // ���� â��
int total;

struct cust1 // ���� ���
{ // ����ȣ -> pq���� ���鼭 cnt �ؾ��� ��
	int arrive; // �����ð�
};

vector<cust1> wait_recep_vec;
struct cust_recep // ���� ��
{
	int use = -1; // 1 : ��� ��
	int num;
	int end_time; // ���� ������ �ð�
};
vector<cust_recep> vec_recep;

struct cust2 // ���� ���
{
	int num;
	int wait_time; // �������� ��ٷȴ���
	int recep;
};
bool operator<(cust2 c1, cust2 c2)
{
	if (c1.wait_time > c2.wait_time) return true;
	else if (c1.wait_time == c2.wait_time && c1.recep > c2.recep) return true;
	return false;
}
priority_queue<cust2> pq_repair;

struct cust_repair
{
	int use = -1;
	int num;
	int recep;
	int end_time; // ���� ������ �ð�
};
vector<cust_repair> vec_repair;

void BFS()
{
	int cust_num = 1; // ���� �� �� ��ȣ �ű��
	int now_time = 0;
	int recep_cnt = 0; // ���� ���� ���� �ֵ� �ִ���
	while (!wait_recep_vec.empty() || !pq_repair.empty() || recep_cnt > 0)
	{
		//cout << endl << "now time : " << now_time << endl;
		// ���� ���� �ֵ� ����
		//cout << endl <<  "===reception finish===" << endl;
		for (int i = 1; i <= n; i++)
		{
			if (vec_recep[i].use == -1) continue;
			if (vec_recep[i].end_time <= now_time)
			{
				cust2 cust_new;
				cust_new.num = vec_recep[i].num;
				cust_new.recep = i;
				cust_new.wait_time = now_time;
				vec_recep[i].use = -1;
				pq_repair.push(cust_new);
				recep_cnt--;
				//cout << cust_new.num << " ���� ���� �� => " << cust_new.recep << '\n';
			}
		}

		// ���� ��� �ֵ� ����
		//cout << endl << "===reception waiting finish===" << endl;
		for (int i = 1; i <= n; i++)
		{
			if (wait_recep_vec.empty()) break;
			cust1 tmp_c1 = wait_recep_vec[0];
			if (vec_recep[i].use == -1 && now_time >= tmp_c1.arrive) // �����
			{
				wait_recep_vec.erase(wait_recep_vec.begin());
				vec_recep[i].use = 1;
				vec_recep[i].num = cust_num;
				cust_num++;
				vec_recep[i].end_time = now_time + recep[i];
				recep_cnt++;
				//cout << i << " ���� ������ �� => " << vec_recep[i].num << '\n';
			}

		}
		

		// ���� ���� �ֵ� ����
		//cout << endl << "===repair finish===" << endl;
		for (int i = 1; i <= m; i++)
		{
			if (vec_repair[i].use == -1) continue;
			if (vec_repair[i].end_time <= now_time)
			{
				vec_repair[i].use = -1;
				//cout << vec_repair[i].num << " �� => recep : " << vec_repair[i].recep << " repair : " << i << '\n';
				if (vec_repair[i].recep == a && i == b)
				{
					total += vec_repair[i].num;
					//cout << "check " << vec_repair[i].num << ' ' << total << endl;
				}
			}
		}


		// ���� ��� �ֵ� ����
		//cout << endl << "===repair waiting finish===" << endl;
		for (int i = 1; i <= m; i++)
		{
			if (pq_repair.empty()) break;
			if (vec_repair[i].use == -1) // �����
			{
				cust2 tmp_c1 = pq_repair.top();
				pq_repair.pop();
				vec_repair[i].use = 1;
				vec_repair[i].num = tmp_c1.num;
				vec_repair[i].end_time = now_time + repair[i];
				vec_repair[i].recep = tmp_c1.recep;
				//cout << vec_repair[i].num << " �� => recep : " << vec_repair[i].recep << " repair : " << i << '\n';
			}

		}

		now_time++;
	}

	// ���� ���� �ֵ� �� �� â�� ��ȣ ��ġ�� �ֵ� ī��Ʈ
	//cout << endl << "===repair finish===" << endl;
	for (int i = 1; i <= m; i++)
	{
		if (vec_repair[i].use == -1) continue;
		//cout << vec_repair[i].num << " �� => recep : " << vec_repair[i].recep << " repair : " << i << '\n';
		if (vec_repair[i].recep == a && i == b)
		{
			total += vec_repair[i].num;
			//cout << "check " << vec_repair[i].num << ' ' << total << endl;
		}
	}
}

int main()
{
	vec_recep.resize(10);
	vec_repair.resize(10);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> k >> a >> b;

		total = 0;
		for (int i = 1; i <= n; i++)
		{
			vec_recep[i].use = -1;
		}
		for (int i = 1; i <= m; i++)
		{
			vec_repair[i].use = -1;
		}

		while (!pq_repair.empty()) pq_repair.pop();
		wait_recep_vec.clear();

		for (int i = 1; i <= n; i++)
		{
			cin >> recep[i];
		}
		for (int i = 1; i <= m; i++) cin >> repair[i];
		int a1;
		for (int i = 1; i <= k; i++)
		{
			cin >> a1;
			wait_recep_vec.push_back({ a1 });
		}

		// ����ȣ 1���� �ο�
		BFS();

		if (total == 0) total = -1;
		cout << '#' << tc << ' ' << total << '\n';
	}

	return 0;
}