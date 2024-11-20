#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<string> st;
    for (int i = 0; i < n - 1; ++i)
        st.insert(s.substr(i, 2));
    cout << st.size() << '\n';
}

int main() {
    int _; cin >> _;
    while (_--) {
        solve();
    }
}
