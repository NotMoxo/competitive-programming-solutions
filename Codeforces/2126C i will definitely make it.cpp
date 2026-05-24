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
    k--;
    vector<int>v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int waterLevel = 1;
    int pos = v[k];
    int time = 0;
    sort(all(v));
    for (int i=0;i<n;i++) {
        if (v[i] <= pos) continue;

        int cnt = v[i] - pos;

        if (time + cnt > pos) {
            NO;
            return;
        }
        time += cnt;
        waterLevel += cnt;
        pos = v[i];
        if (time + 1 > pos) {
            NO;
            return;
        }
    }
    YES;

}
signed main() {
    file();
    MOXO
    int T = 1;
    cin >> T;
    while (T--) solve();
}
