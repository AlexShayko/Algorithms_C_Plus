#include <vector>
#include <iostream>
#include <set>

std::vector<std::vector<int>> gr;
std::vector<int> used;
bool is_Cycle = false;

void dfs_cycle(int v, int p) {
    used[v] = 1;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs_cycle(to, v);
        } else if (to != p) {
            is_Cycle = true;
        }
    }
}

int main() {
    bool is_Connected = true;
    int n = 0, m = 0;
    std::cin >> n >> m;
    gr.resize(n + 1);
    used.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int from = 0, to = 0;
        std::cin >> from >> to;
        gr[from].push_back(to);
        gr[to].push_back(from);
    }
    dfs_cycle(1, -1);
    for (int i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            is_Connected = false;
            break;
        }
    }

    for (int i = 2; i < n + 1; ++i) {
        if (!used[i]) {
            dfs_cycle(i, -1);
        }
    }

    std::cout << ((is_Connected && !is_Cycle) ? "YES" : "NO");
    return 0;
}
