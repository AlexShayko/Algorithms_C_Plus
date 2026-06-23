#include <vector>
#include <iostream>
#include <set>

std::vector<std::vector<int>> gr;
std::vector<int> used;
bool is_Sep = true;

void dfs(int v, int color) {
    used[v] = color;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs(to, 3 - color);
        } else if (used[to] == color) {
            is_Sep = false;
        }
    }
}

int main() {
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
    for (int v = 0; v < n; ++v) {
        if (!used[v]) {
            dfs(v, 1);
        }
    }

    std::cout << ((is_Sep) ? "YES" : "NO");
    return 0;
}
