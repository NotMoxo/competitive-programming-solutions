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
    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x,y,z; cin >> x >> y >> z;
        v[i] = {x, y, z};
    }
    sort(all(v));
    bool win = true;
    while (win) {
        win = false;
        for (auto &[l,r,real] : v) {
            if (k >= l && k <= r && real > k) {
                k = real;
                win = true;
            }
        }
    }
    cout << k << endl;
}
signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}
