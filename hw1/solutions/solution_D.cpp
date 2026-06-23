#include <vector>
#include <iostream>
#include <set>

std::vector<std::vector<int>> gr;
std::vector<int> used;
int counter = 1;

void dfs(int v) {
    used[v] = counter;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs(to);
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
    for (int i = 1; i < n + 1; ++i) {
        if (!used[i]) {
            dfs(i);
            counter += 1;
        }
    }
    std::cout << counter - 1 << '\n';
    for (int i = 1; i < n + 1; ++i) {
        std::cout << used[i] << ' ';
    }
    return 0;
}
