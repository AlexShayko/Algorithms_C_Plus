#include <vector>
#include <iostream>

class Edges {
public:
    int to = 0;
    int w = 0;
};

std::vector<std::vector<int>> gr;
std::vector<int> neg;
std::vector<int> colors;
std::vector<int> parents;
bool found_cycle = false;
int cycle_start = -1;
int cycle_end = -1;

void dfs_find_cycle(int v, int p) {
    if (found_cycle) return;

    colors[v] = 1;
    parents[v] = p;

    for (int to : gr[v]) {
        if (found_cycle) return;
        if (neg[to] == 0) continue;

        if (colors[to] == 0) {
            dfs_find_cycle(to, v);
        } else if (colors[to] == 1) {
            found_cycle = true;
            cycle_start = to;
            cycle_end = v;
            return;
        }
    }

    colors[v] = 2;
}

int main() {
    int n = 0;
    std::cin >> n;
    gr.resize(n + 1);
    neg.assign(n + 1, 0);
    std::vector<std::vector<Edges>> edges(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num != 100000) {
                edges[i].push_back({j, num});
                gr[i].push_back(j);
            }
        }
    }

    int inf = 10000001;
    std::vector<int> dist(n + 1, inf);
    int start = 0;

    for (int i = 0; i < n; ++i) {
        if (!edges[i].empty()) {
            start = i;
            break;
        }
    }
    dist[start] = 0;
    bool isRelax = true;
    bool isCycle = false;
    for (int k = 1; (k <= n) && isRelax; ++k) {
        isRelax = false;
        for (int i = 0; i < n; ++i) {
            for (auto& v : edges[i]) {
                if (dist[i] == inf) continue;
                if ((dist[v.to] > dist[i] + v.w) && (k < n)) {
                    dist[v.to] = dist[i] + v.w;
                    isRelax = true;
                }
                if ((dist[v.to] > dist[i] + v.w) && (k == n)) {
                    isCycle = true;
                    dist[v.to] = dist[i] + v.w;
                    isRelax = true;
                    neg[v.to] = 1;
                    neg[i] = 1;
                }
            }
        }
    }

    parents.assign(n + 1, -1);
    colors.assign(n + 1, 0);
    if (isCycle) {
        for (int i = 0; i < n && !found_cycle; ++i) {
            if (neg[i] == 1 && colors[i] == 0) {
                dfs_find_cycle(i, -1);
            }
        }

        if (found_cycle) {
            std::vector<int> cycle;

            cycle.push_back(cycle_start);

            for (int v = cycle_end; v != cycle_start; v = parents[v]) {
                cycle.push_back(v);
            }

            cycle.push_back(cycle_start);

            std::cout << "YES" << '\n';
            std::cout << cycle.size() << '\n';

            for (int i = cycle.size() - 1; i >= 0; --i) {
                std::cout << cycle[i] + 1 << ' ';
            }
        }
    } else { std::cout << "NO"; }
    return 0;
}
