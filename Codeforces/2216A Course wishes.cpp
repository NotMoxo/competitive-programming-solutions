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

void solve() {
    int n,k; cin >> n >> k;
    for (int i=1;i<=k;i++) {
        int val; cin >> val;
    }
    vector<vector<int>> v(k+2);
    for (int i=1;i<=n;i++) {
        int x; cin >> x;
        if (x > k) continue;
        v[x].emplace_back(i);
    }
    vector<int> ans;
    for (int i=k;i>=1;i--) {
        for (int j=v[i].size()-1;j>=0;j--) {
            int x = k - i +1;
            while (x > 0) {
                ans.emplace_back(v[i][j]);
                x--;
            }
        }
    }
    if (sz(ans) > 1000) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << ' ';
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
