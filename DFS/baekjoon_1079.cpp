#include <iostream>
#include <vector>

using namespace std;

// ���� 1079 - ���Ǿ�
// DFS
// ��� 2

// �㿡 ���̴� �� ��� ����� ���� �� �غ��� (���� Ž��)

int n;
int guilty_point[17]; // ���� ����
int R[17][17]; // R �迭
int me; // ����
int max_cnt = 0;

void DFS(int kill_n, int night, vector<int> g_arr, int num) // kill_n��° ��� ���̱�, ���� ��� g_arr[i] = -1
{
    if (kill_n == me || num == 1) // �״� �� �����
    {
        if (night > max_cnt) max_cnt = night;
        return;
    }

    vector<int> tmp_arr;

    // ��
    g_arr[kill_n] = -1; // ����

    // �������� ����
    for (int i = 0; i < n; i++)
    {
        if (g_arr[i] == -1) continue;
        g_arr[i] += R[kill_n][i];
    }
    // ���� ���� ��� ����
    int tmp_max = -999999999;
    int tmp_idx;
    for (int i = 0; i < n; i++)
    {
        if (g_arr[i] == -1) continue;
        if (g_arr[i] > tmp_max)
        {
            tmp_max = g_arr[i];
            tmp_idx = i;
        }
    }
    
    if (tmp_idx == me) // ���̷��� �� ����
    {
        if (night + 1 > max_cnt) max_cnt = night + 1;
        return;
    }
    g_arr[tmp_idx] = -1; // ���� (��)

    // ���� �㿡 ���� ���
    for (int i = 0; i < n; i++)
    {
        if (g_arr[i] == -1 || i == me) continue;
        tmp_arr = g_arr;
        DFS(i, night + 1, tmp_arr, num - 2); // ���̱�
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> guilty_point[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> R[i][j];
    }

    cin >> me;
    vector<int> g_cp;
    g_cp.resize(n + 1);

    if (n % 2 == 0) // ¦�� ���϶� => ����� ����
    {
        for (int i = 0; i < n; i++)
        {
            if (i == me) continue;
            for (int j = 0; j < n; j++) g_cp[j] = guilty_point[j];
            DFS(i, 0, g_cp, n);
        }
    }
    else // Ȧ�� ���� �� => ������ ����
    {
        int tmp_max = -999999999;
        int tmp_idx;
        for (int i = 0; i < n; i++)
        {
            if (guilty_point[i] > tmp_max)
            {
                tmp_max = guilty_point[i];
                tmp_idx = i;
            }
        }
        if (tmp_idx != me)
        {
            guilty_point[tmp_idx] = -1;

            // �� ����
            for (int i = 0; i < n; i++)
            {
                if (i == me) continue;
                for (int j = 0; j < n; j++) g_cp[j] = guilty_point[j];
                DFS(i, 0, g_cp, n - 1);
            }
        }
    }

    cout << max_cnt;

    return 0;
}