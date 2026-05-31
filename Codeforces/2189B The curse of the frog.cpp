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
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                cnt++;
            }
        }
    }
    return cnt;
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

/*
                                 ███    ███  ██████   █   █   ██████
                                 ████  ████ ██    ██   █ █   ██    ██
                                 ██ ████ ██ ██ ██ ██    █    ██ ██ ██
                                 ██  ██  ██ ██    ██   █ █   ██    ██
                                 ██      ██  ██████   █   █   ██████
*/
// ups
void solve() {
    int n,x; cin >> n >> x;
    vector<int>a(n),b(n),c(n);
    for (int i=0;i<n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int start = 0;
    int mx = LLONG_MIN;
    for (int i=0;i<n;i++) {
        mx = max(mx, a[i] * b[i] - c[i]);
        start += a[i] * (b[i] - 1);
    }
    x -= start;

    if (x <= 0) {
        cout << 0 << endl;
        return;
    }
    if (mx <= 0) {
        cout << -1 << endl;
        return;
    }
    cout << (x + mx - 1) / mx << endl;
}

signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}