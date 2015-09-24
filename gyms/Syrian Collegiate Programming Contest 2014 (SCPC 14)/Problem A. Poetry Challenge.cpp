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
#include <iomanip>
#include <complex>

using namespace std;

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = 1e9 + 1;
const double eps = 1e-9;
const ll mod = 1000000007;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define clr(v, d) memset(v, d, sizeof(v))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).real(),(a).imag())
#define angle(a) atan2((a).imag() , (a).real())
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(v,m) (conj((v)/(m))*m)
#define dist(a,b) (sqrt(pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0)))
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int main() {
//  freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while (t--) {
        tc++;
        int n, m;
        scanf("%d", &n);
        bool adj[26][26];
        pair<int, int> arr[n];
        clr(adj, false);
        int cnt[26][26];
        clr(cnt, 0);
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            arr[i] = ii(s[0] - 'a', s[sz(s) - 1] - 'a');
        }
        scanf("%d", &m);
        getline(cin, s);
        for (int i = 0; i < m; i++) {
            getline(cin, s);
            adj[s[0] - 'a'][s[sz(s) - 1] - 'a'] = 1;
            cnt[s[0] - 'a'][s[sz(s) - 1] - 'a']++;
        }
        bool ok = false;
        sort(arr, arr + n);
        do {
            int temp[30][30];
            clr(temp, 0);
            int have = m;
            bool win2 = false;
            for (int i = 0; i < n; i++) {
                if (have) {
                    if (i + 1 < n) {
                        if (adj[arr[i].second][arr[i + 1].first]
                                && temp[arr[i].second][arr[i + 1].first]
                                        < cnt[arr[i].second][arr[i + 1].first]) {
                            temp[arr[i].second][arr[i + 1].first]++;
                            have--;
                        } else {
                            bool found = false;
                            for (int j = 0; j < 26; j++) {
                                if (adj[arr[i].second][j]
                                        && temp[arr[i].second][j]
                                                < cnt[arr[i].second][j]) {
                                    found = true;
                                    break;
                                }
                            }
                            if (found) {
                                win2 = true;
                            } else {
                                ok = true;
                            }
                        }
                    } else {
                        bool found = false;
                        for (int j = 0; j < 26; j++) {
                            if (adj[arr[i].second][j]
                                    && temp[arr[i].second][j]
                                            < cnt[arr[i].second][j]) {
                                found = true;
                                break;
                            }
                        }
                        if (found) {
                            win2 = true;
                        } else {
                            ok = true;
                        }
                    }
                } else {
                    ok = true;
                    break;
                }
                if (win2)
                    break;
            }
            if (ok)
                break;
        } while (next_permutation(arr, arr + n));
        if (ok) {
            printf("Game %d: player1\n", tc);
        } else {
            printf("Game %d: player2\n", tc);
        }
    }
    return 0;
}