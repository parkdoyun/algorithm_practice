#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ���� 20160 - ����Ʈ ���ܸ� ����Ʈ �ּ���
// dijkstra
// ��� 3

// dijkstra�� �ϰ�
// �ּ� ���� ã��

// ����Ʈ ���ܸ� 9�� dijkstra ����
// �� dijkstra�� Ȯ��

#define INF 999999999999999999
int v, e;
struct vertex
{
    int idx;
    int visit = -1;
    long long int dist = INF;
    long long int time = -1; // ����Ʈ �� �� �ִٸ� �ð� ǥ��
};
bool operator<(vertex v1, vertex v2)
{
    return v1.dist > v2.dist;
}
struct edge
{
    int oppo;
    long long int weight;
};
vector<vertex> V;
vector<vector<edge>> E;
priority_queue<vertex> pq;
int order[11];
int min_vertex = 99999;

void dijkstra(int start)
{
    for (int i = 1; i <= v; i++)
    {
        V[i].dist = INF;
        V[i].visit = -1;
    }
    while (!pq.empty()) pq.pop();

    V[start].dist = 0;
    pq.push(V[start]);

    while (!pq.empty())
    {
        vertex tmp = pq.top();
        pq.pop();

        if (V[tmp.idx].visit == 1) continue;
        V[tmp.idx].visit = 1;

        // ����Ʈ �� �� �ִٸ�
        if (tmp.time != -1 && tmp.time >= V[tmp.idx].dist)
        {
            if (tmp.idx < min_vertex) min_vertex = tmp.idx;
        }

        for (int i = 0; i < E[tmp.idx].size(); i++)
        {
            if (V[E[tmp.idx][i].oppo].dist > E[tmp.idx][i].weight + tmp.dist)
            {
                V[E[tmp.idx][i].oppo].dist = E[tmp.idx][i].weight + tmp.dist;
                pq.push(V[E[tmp.idx][i].oppo]);
            }
        }
    }
}

void dijkstra2(int s) // ����Ʈ ���ܸ� dijkstra
{
    for (int i = 1; i <= v; i++)
    {
        V[i].dist = INF;
        V[i].visit = -1;
    }
    while (!pq.empty()) pq.pop();

    V[s].dist = 0;
    pq.push(V[s]);

    while (!pq.empty())
    {
        vertex tmp = pq.top();
        pq.pop();

        if (V[tmp.idx].visit == 1) continue;
        V[tmp.idx].visit = 1;

        for (int i = 0; i < E[tmp.idx].size(); i++)
        {
            if (V[E[tmp.idx][i].oppo].dist > E[tmp.idx][i].weight + tmp.dist)
            {
                V[E[tmp.idx][i].oppo].dist = E[tmp.idx][i].weight + tmp.dist;
                pq.push(V[E[tmp.idx][i].oppo]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    V.resize(v + 1);
    E.resize(v + 1);

    for (int i = 1; i <= v; i++) V[i].idx = i;

    int u, v_;
    long long int w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v_ >> w;
        E[u].push_back({ v_, w });
        E[v_].push_back({ u, w });
    }

    // ����Ʈ �Ĵ� 10��
    for (int i = 1; i <= 10; i++)
    {
        cin >> order[i];
        //V[order[i]].time = i;
    }

    // ����Ʈ 10���� �ð� ���
    long long total_time = 0;
    V[order[1]].time = 0;
    int prev;
    for (int i = 1; i <= 9;)
    {
        dijkstra2(order[i]);
        prev = i;
        i++;
        while (V[order[i]].dist == INF && i <= 10) i++;
        if (i > 10) break;
        total_time += V[order[i]].dist;
        V[order[i]].time = total_time;
    }

    // �� dijkstra ����
    int start;
    cin >> start;

    // dijkstra
    dijkstra(start);

    if (min_vertex == 99999) cout << -1;
    else cout << min_vertex;

    return 0;
}