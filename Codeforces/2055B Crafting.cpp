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
vector<int>adj[MAXN];
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
        for (int v : adj[u]) {
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
// upsolve
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    int bad = -1, diff = LLONG_MAX, need = 0;
    bool no = false;
    for (int i=0;i<n;i++) {
        if (a[i] < b[i]) {
            if (bad != -1) no = true;
            bad = i;
            need = b[i] - a[i];
        } else diff = min(diff, a[i] - b[i]);
    }
    if (no) {
        NO;
        return;
    }
    cout << (diff >= need ? "YES" : "NO") << endl;
}
signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}