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
    int n, m;
    cin >> n >> m;
    vector<int> shari(n), neta(m);
    LOOP(i, 0, n) cin >> shari[i];
    LOOP(i, 0, m) cin >> neta[i];
    sort(all(shari));
    sort(all(neta));
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (neta[j] <= 2 * shari[i]) {
            ans++;
            i++;j++;
        } else {
            i++;
        }
    }
    cout << ans << endl;
}

signed main() {
    file();
    MOXO
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
