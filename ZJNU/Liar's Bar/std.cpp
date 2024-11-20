#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)


struct Player {
    bool alive;
    vector<string> pokerOrder; // 出牌的顺序
    string pokerOnDeck;        // 现在被放在桌子上的牌
    string questionSeq;        // 质疑序列
    string bulletSeq;          // 子弹序列
    int used;                  // 已经使用掉的空弹

    Player() {}

    Player(const string &bullet) {
        alive = 1, used = 0;
        bulletSeq = bullet;
        reverse(all(bulletSeq));
    }

    void set(const vector<string> &pokers, const string &que) {
        pokerOnDeck = "";
        pokerOrder = pokers;
        questionSeq = que;
        reverse(all(pokerOrder));
        reverse(all(questionSeq));
    }

    int question(char table, Player &lastPlayer, int forceQuestion) {
        char que = questionSeq.back();
        questionSeq.pop_back();
        if (que == '?' || forceQuestion) {
            int cnt = 0;
            auto lastPlayerDeck = lastPlayer.pokerOnDeck;
            for (auto c : lastPlayerDeck)
                cnt += (c == table || c == '*');
            if (cnt == lastPlayerDeck.length()) {
                this->shot();
                return 0;
            } else {
                lastPlayer.shot();
                return 1;
            }
        }
        return -1;
    }

    void play() {
        pokerOnDeck = pokerOrder.back();
        pokerOrder.pop_back();
    }

    void shot() {
        int flag = bulletSeq.back() - '0';
        if (flag) {
            alive = 0;
            return;
        }
        bulletSeq.pop_back(); // 最后的状态是(已知空弹的数量 / 6)
        used++;
    }
};

const string name[4]{"shui", "bai", "ri", "xin"};

int isEnd(const vector<Player> &players) {
    int cnt = 0;
    for (const auto &p : players)
        cnt += p.alive;
    return cnt;
}

int havePokers(const vector<Player> &players) {
    int cnt = 0;
    for (const auto &p : players) {
        cnt += p.alive && !p.pokerOrder.empty();
    }
    return cnt;
}

int findNextValid(const vector<Player> &players, int id) {
    for (int i = 1; i <= 4; ++i) {
        if (players[(id + i) % 4].alive &&
            !players[(id + i) % 4].pokerOrder.empty()) {
            return (id + i) % 4; }
    }
    return -1;
}

void solve() {

    string tables;
    cin >> tables;
    vector<Player> players(4);

    for (int i = 0; i < 4; ++i) {
        string bullet;
        cin >> bullet;
        players[i] = Player(bullet);
    }

    vector pokers(24, vector<vector<string>>(4));
    vector question(24, vector<string>(4));

    for (int i = 0; i < 24; ++i) {
        for (int p = 0; p < 4; ++p) {
            int k;
            cin >> k;
            vector<string> tmp(k);
            for (int j = 0; j < k; ++j)
                cin >> tmp[j];
            pokers[i][p] = tmp;
            string que;
            cin >> que;
            question[i][p] = que;
        }
    }

    int curId = -1;
    // id 是先手玩家编号
    for (int i = 0; i < 24 && isEnd(players) > 1; ++i) {
        char table = tables[i];
        // 初始化
        for (int j = 0; j < 4; ++j)
            players[j].set(pokers[i][j], question[i][j]);
        if (curId == -1) curId = findNextValid(players, -1);
        int flag = -1, lastId = -1;
        while (1) {
            if (lastId != -1) {
                int forceQuestion = havePokers(players) == 1; // 如果只剩两人且上家手牌为空，则强制质疑
                flag = players[curId].question(table, players[lastId], forceQuestion);
            }
            if (flag != -1) break;
            players[curId].play();
            lastId = curId;
            curId = findNextValid(players, curId);
        }
        curId = (flag ? lastId : curId);
        if (!players[curId].alive) curId = -1;
    }

    int winner = -1;
    for (int i = 0; i < 4; ++i)
        if (players[i].alive)
            winner = i;
    cout << name[winner] << " is the winner!\n";

    for (int i = 0; i < 4; ++i)
        cout << name[i] << " (" << players[i].used << "/6)\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
