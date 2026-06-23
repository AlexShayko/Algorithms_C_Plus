#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

std::vector<std::vector<int>> gr;
std::vector<int> used;
std::map<std::pair<int, int>, int> bridges;
std::vector<int> tin;
std::vector<int> tout;
std::vector<int> ans;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = 1;
    ++timer;
    tin[v] = tout[v] = timer;

    for (int to : gr[v]) {
        if (!used[to]) {
            dfs(to, v);
            tout[v] = std::min(tout[v], tout[to]);
            if (tin[v] < tout[to]) {
                ans.push_back(bridges[{v, to}]);
            }
        } else if (to != p) {
            tout[v] = std::min(tout[v], tin[to]);
        }
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

    int counter = 0;
    for (int i = 1; i < m; ++i) {
        counter += 1;
        int u = 0, v = 0;
        std::cin >> u >> v;
        bridges[{u, v}] = counter;
        bridges[{v, u}] = counter;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1);

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << '\n';
    }
}
