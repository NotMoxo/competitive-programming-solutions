#include <bits/stdc++.h>
using namespace std;
#define LOOP(i, x, n) for (int i = x; i < n; i++)
#define RLOOP(i, x, n) for (int i = x; i >= n; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define pf push_front
#define MOXO ios::sync_with_stdio(false); cin.tie(nullptr);
#define F first
#define S second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl '\n'
#define int long long
#define ull unsigned long long

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
                                 ███    ███  ██████   █   █   ██████
                                 ████  ████ ██    ██   █ █   ██    ██
                                 ██ ████ ██ ██ ██ ██    █    ██ ██ ██
                                 ██  ██  ██ ██    ██   █ █   ██    ██
                                 ██      ██  ██████   █   █   ██████
*/
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
int color[MAXN];

pair<bool, int> bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    int cnt = 1;
    bool bip = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
                cnt++;
            } else if (color[v] == color[u]) {
                bip = false;
            }
        }
    }
    return {bip, cnt};
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    int place = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0) {
            ans.push_back(digit * place);
        }
        n /= 10;
        place *= 10;
    }
    cout << ans.size() << endl;

    for (int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}