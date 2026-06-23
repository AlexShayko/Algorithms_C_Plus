#include <vector>
#include <iostream>
#include <set>

std::vector<std::set<int>> gr;
std::vector<int> used;

void dfs(int v) {
    used[v] = 1;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs(to);
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
        if (from != to) {
            gr[from].insert(to);
            gr[to].insert(from);
        }
    }
    dfs(1);
    for (int i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            is_Connected = false;
            break;
        }
    }

    std::cout << (is_Connected ? "YES" : "NO");
    return 0;
}
