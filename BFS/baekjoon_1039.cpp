#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// 백준 1039 - 교환
// BFS, map
// 골드 3

// 반례
// 1000000 10 => 1000000이 나와야 함
// 중복 제거 필요

int n, m, k;
int max1 = -1;
unordered_map<string, int> map1; // 중복 제거 위해

struct node
{
    string val;
    int lv; // operator 횟수
};
queue<node> q;

void BFS()
{
    char c;
    int tmp_n;
    int prev_lv = 1;
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();

        if (tmp.lv > prev_lv)
        {
            prev_lv = tmp.lv;
            map1.clear();
        }

        if (tmp.lv == k)
        {
            tmp_n = stoi(tmp.val);
            if (tmp_n > max1) max1 = tmp_n;
            continue;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                //if (tmp.val[i] == tmp.val[j]) continue;
                c = tmp.val[i];
                tmp.val[i] = tmp.val[j];
                tmp.val[j] = c;
                if (tmp.val[0] != '0' && map1.find(tmp.val) == map1.end())
                {
                    q.push({ tmp.val, tmp.lv + 1 });
                    map1.insert({ tmp.val, 1 });                
                }
                // 다시 바꿔놓기 (원상태)
                c = tmp.val[i];
                tmp.val[i] = tmp.val[j];
                tmp.val[j] = c;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    string tmp = to_string(n);
    m = tmp.length();

    char c;

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            //if (tmp[i] == tmp[j]) continue;
            c = tmp[i];
            tmp[i] = tmp[j];
            tmp[j] = c;
            if (tmp[0] != '0') q.push({ tmp, 1 });
            // 다시 바꿔놓기 (원상태)
            c = tmp[i];
            tmp[i] = tmp[j];
            tmp[j] = c;
        }
    }

    BFS();

    cout << max1;

    return 0;
}