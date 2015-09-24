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
        unsigned long long n, m;
        cin >> n >> m;
//      n--;
        unsigned long long lo = 1, hi = n;
        bool ok = false;
        while (lo + 1 < hi) {
            unsigned long long mid = (hi + lo) / 2;
            if ((mid * (mid + 1)) / 2 > m) {
                hi = mid;
            } else if ((mid * (mid + 1)) / 2 < m) {
                lo = mid;
            } else {
                cout << "Case " << tc << ": " << mid - 1 << " " << mid - 1
                        << endl;
                ok = 1;
                break;
            }
        }
        if(ok)
            continue;
        if((hi * (hi + 1)) / 2 == m){
            cout << "Case " << tc << ": " << hi - 1 << " " << hi - 1
                                    << endl;
        }
        else if((lo * (lo+1)) / 2 == m){
            cout << "Case " << tc << ": " << lo - 1 << " " << lo - 1
                                    << endl;
        }
        //cout<<"Case "<<tc<<": "<<lo-1<<" "<<lo-1<<endl;
        else if ((hi * (hi + 1)) / 2 < m) {
            cout << "Case " << tc << ": " << hi << " "
                    << m - (hi * (hi + 1)) / 2 - 1 << endl;
        } else {
            cout << "Case " << tc << ": " << lo << " "
                    << m - (lo * (lo + 1)) / 2 - 1 << endl;
        }
    }
    return 0;
}