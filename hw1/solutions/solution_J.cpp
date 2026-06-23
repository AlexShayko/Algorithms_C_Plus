#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

std::vector<std::vector<int>> gr;
std::vector<int> used;
std::vector<int> tin;
std::vector<int> tout;
std::vector<int> ans;
std::vector<bool> is_sohl;
int timer = 0;

void dfs(int v, int p = -1) {
    int children = 0;
    used[v] = 1;
    ++timer;
    tin[v] = tout[v] = timer;

    for (int to : gr[v]) {
        if (!used[to]) {
            ++children;
            dfs(to, v);
            tout[v] = std::min(tout[v], tout[to]);
            if (p != -1 && tout[to] >= tin[v]) {
                is_sohl[v] = true;
            }
        } else if (to != p) {
            tout[v] = std::min(tout[v], tin[to]);
        }
    }

    if (p == -1 && children > 1) {
        is_sohl[v] = true;
    }
}

int main() {

    int n = 0, m = 0;
    std:: cin >> n >> m;
    ++n; ++m;

    gr.resize(n);
    used.resize(n);
    tin.resize(n);
    tout.resize(n);
    is_sohl.resize(n, false);

    for (int i = 1; i < m; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1);

    for (int v = 1; v < n; ++v) {
        if (is_sohl[v]) ans.push_back(v);
    }

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << '\n';
    }
}
