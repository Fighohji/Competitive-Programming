#include <cassert>
#include <iostream>
#include <vector>
const std::string s[4] = {"shui", "bai", "ri", "xin"};

void solve() {
    std::string tables;
    std::cin >> tables;
    assert(tables.size() == 24);
    std::vector<std::string> bullets(4);
    for (auto &s : bullets) {
        std::cin >> s;
        assert(s.size() == 6);
    }
    std::vector<int> now(4), vis(4);
    int la = -1;
    for (auto ch : tables) {
        std::vector<std::vector<std::string>> vec(4);
        std::vector<int> vecid(4);
        std::vector<std::string> q(4);
        for (int i = 0; i < 4; ++i) {
            int k;
            std::cin >> k;
            int sum = 0;
            while (k--) {
                std::string x;
                std::cin >> x;
                vec[i].emplace_back(x);
                sum += x.size();
                assert(x.size() >= 1 && x.size() <= 3);
            }
            std::cin >> q[i];
            assert(sum == 5);
            assert(q[i].size() == 5);
        }
        std::string las = "";
        int laspeople = -1;
        std::vector<int> zhiyitime(4);
        int livepeople = 0;
        for (int i = 0; i < 4; ++i) {
            if (vis[i] == 0) livepeople++;
        }
        if (livepeople == 1) continue;
        auto zhiyi = [&]() -> bool {
            for (int j = 0; j < las.size(); ++j) {
                if (las[j] != ch && las[j] != '*') return 1;
            }
            return 0;
        };
        auto kaiqiang = [&](int i) -> void {
            if (bullets[i][now[i]] == '0') {
                ++now[i];
            } else {
                vis[i] = 1;
                --livepeople;
            }
            la = i;
        };
        int op = la;
        if(la == -1 || vis[la] == 1) {
        	for(int i = 0; i <= 3; ++i) {
        		if(vis[i] == 0) {
        			op = i;
        			break;
        		}
        	}
        }
        while (1) {
            if (vis[op] == 1) {
                op = (op + 1) % 4;
                continue;
            }
            if (vecid[op] == vec[op].size()) {
                op = (op + 1) % 4;
                continue;
            }
            if (laspeople == -1) {
                las = vec[op][vecid[op]];
                laspeople = op;
                ++vecid[op];
            } else {
                if (vecid[laspeople] == vec[laspeople].size()) {
                    --livepeople;
                    if (livepeople == 1) {
                        if (zhiyi()) {
                            kaiqiang(laspeople);
                        } else {
                            kaiqiang(op);
                        }
                        break;
                    }
                }
                if (q[op][zhiyitime[op]] == '.') {
                    zhiyitime[op]++;
                    las = vec[op][vecid[op]];
                    laspeople = op;
                    ++vecid[op];
                } else {
                    if (zhiyi()) {
                        kaiqiang(laspeople);
                    } else {
                        kaiqiang(op);
                    }
                    break;
                }
            }
            op = (op + 1) % 4;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (vis[i] == 0) {
            std::cout << s[i] << " is the winner!" << '\n';
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        std::cout << s[i] << ' ' << "(" << now[i] << "/6)\n";
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}
