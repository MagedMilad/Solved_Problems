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

const ll oo = 0x3f3f3f3f;
const double eps = 1e-6;
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
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<1e-4)
#define LSOne(S) (S & (-S))
////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int tree[32111 * 4];

void update(int rt, int l, int r, int idx, int val) {
	if (l == r) {
		tree[rt] += val;
		return;
	}
	if (idx < l || idx > r)
		return;
	int mid = (l + r) >> 1;
	if (idx <= mid)
		update(rt << 1, l, mid, idx, val);
	else
		update(rt << 1 | 1, mid + 1, r, idx, val);
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

int query(int rt, int l, int r, int L, int R) {
	if (l >= L && r <= R)
		return tree[rt];
	if (l > R || r < L)
		return 0;
	int mid = (l + r) >> 1;
	return query(rt << 1, l, mid, L, R) + query(rt << 1 | 1, mid + 1, r, L, R);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int ans[n];
	clr(ans, 0);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ans[query(1, 0, 32111, 0, x)]++;
		update(1, 0, 32111, x, 1);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}

