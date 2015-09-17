#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((ll)v.size())
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)

#define pb                  push_back
#define MP                  make_pair
typedef long double ld;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<pair<double, double> > vdd;
typedef vector<pair<pair<int, int>, int> > viii;
typedef vector<pair<pair<int, int>, double> > viid;
typedef pair<pair<int, int>, int> iii;
typedef pair<pair<int, int>, double> iid;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

const ll oo = (ll) 1e9;
const double eps = 1e-9;
const ll mod = 1000000007;

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);


int main() {
    freopen("huffman.in","r",stdin);
    freopen("huffman.out","w",stdout);
    int n;
    scanf("%d",&n);
    ll res = 0;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d",&temp);
        q.push(-1*temp);

    }
    while (sz(q) > 1) {
        ll n1 = -1*q.top();
        q.pop();
        ll n2 = -1*q.top();
        q.pop();
        q.push(-1*(n1 + n2));
        res+=n1+n2;
    }
//  res+=q.top();
    cout<<res<<endl;
    return 0;
}