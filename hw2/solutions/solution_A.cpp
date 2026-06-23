#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

int main() {
    int m = 0;
    std::cin >> m;
    std::vector<std::vector<int>> gr;
    int counter = 0;
    std::map<std::string, int> tr;
    for (int i = 0; i < m; ++i) {
        std::string from, arrow, to;
        std::cin >> from >> arrow >> to;
        if (!tr.contains(from)) {
            tr[from] = counter;
            ++counter;
            gr.emplace_back();
        }
        if (!tr.contains(to)) {
            tr[to] = counter;
            ++counter;
            gr.emplace_back();
        }
        gr[tr[from]].push_back(tr[to]);
    }
    std::string start, end;
    std::cin >> start >> end;

    if (!tr.contains(start) || !tr.contains(end)) {
        std::cout << -1;
        return 0;
    }
    int st = tr[start];
    int en = tr[end];
    if (st == en) {
        std::cout << 0;
        return 0;
    }

    std::queue<int> q;
    std::vector<int> dist(tr.size(), -1);
    dist[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : gr[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    std::cout << ((dist[en] == -1) ? -1 : dist[en]);

    return 0;
}
