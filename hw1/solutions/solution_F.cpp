#include <vector>
#include <iostream>
#include <set>

std::vector<std::vector<int>> gr;
std::vector<int> used;
bool is_Cycle = false;

void dfs_cycle(int v) {
    used[v] = 1;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs_cycle(to);
        } else if (used[to] == 1) {
            is_Cycle = true;
        }
    }
    used[v] = 2;
}

int main() {
    int n = 0;
    std::cin >> n;
    gr.resize(n);
    used.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num == 1) {
                gr[i].push_back(j);
            }
        }
    }
    for (int v = 0; v < n; ++v) {
        if (!used[v]) {
            dfs_cycle(v);
        }
    }

    std::cout << ((is_Cycle) ? 1 : 0);
    return 0;
}
