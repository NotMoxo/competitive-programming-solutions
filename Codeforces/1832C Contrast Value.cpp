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
    int n; cin >> n;
    vector<int>v(n);
    for (auto &x :v) cin >> x;
    int x = unique(v.begin(), v.end()) - v.begin();
    int mansr = x;
    for (int i=0;i<x-2;i++) {
        mansr -= (v[i] < v[i + 1] && v[i + 1] < v[i+2]);
        mansr -= (v[i] > v[i + 1] && v[i + 1] > v[i+2]);
    }
    cout << mansr << endl;

}

signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}