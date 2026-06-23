#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main() {

    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> gr(m + 2, std::vector<int> (n + 2, -1));
    int inf = 1e8;
    int counter = 0;

    for (int i = 1; i <=m; ++i) {
            std::string symb;
            std::cin >> symb;
            for (int j = 1; j <=n; ++j){
                if (symb[j - 1] == '#') {
                    gr[i][j] = -1;
                } else {
                    gr[i][j] = inf;
                    ++counter;
                }
            }
        }

    std::vector<std::vector<int>> gr_copy = gr;
    
    bool b_fl = false;

    std::queue<std::pair<int, int>> q;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (gr[i][j] == inf) {
                gr[i][j] = 0;
                q.emplace(i, j);
                b_fl = true;
                break;
            }
        }
        if (b_fl) {
            break;
        }
    }

    std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


    int max = -1;
    std::pair<int, int> max_v;
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();

        for (auto[dx, dy] : dirs) {
            if (gr[x + dx][y + dy] > gr[x][y] + 1) {
                gr[x + dx][y + dy] = gr[x][y] + 1;
                if (gr[x + dx][y + dy] > max) {
                    max = gr[x + dx][y + dy];
                    max_v = {x+dx, y+dy};
                }
                q.emplace(x + dx, y + dy);
            }
        }
    }

    q.emplace(max_v.first, max_v.second);
    gr_copy[max_v.first][max_v.second] = 0;

    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();

        for (auto[dx, dy] : dirs) {
            if (gr_copy[x + dx][y + dy] > gr_copy[x][y] + 1) {
                gr_copy[x + dx][y + dy] = gr_copy[x][y] + 1;
                if (gr_copy[x + dx][y + dy] > max) {
                    max = gr_copy[x + dx][y + dy];
                }
                q.emplace(x + dx, y + dy);
            }
        }
    }

    std::cout << max;
    return 0;
}
