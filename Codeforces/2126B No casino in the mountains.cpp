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
    vector<int>v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int hikes = 0;
    int i = 0;
    while (i <= n - k) {
        bool ok = true;
        for (int j=i;j<i+k;j++) {
            if (v[j] == 1) {
                i = j + 1; // skip;
                ok = false;
                break;
            }
        }
        if (ok) {
            hikes++;
            i += k + 1;
        }
    }
    cout << hikes << endl;
}
signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}
