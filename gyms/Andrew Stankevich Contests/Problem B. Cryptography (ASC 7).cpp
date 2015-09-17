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
const double eps = 1e-6;
const ll mod = 1234567;

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

struct rect {
	int a, b, c, d;
};

rect tree[40010 << 1];
int n, rr, m, sz;

rect prod(rect l, rect r) {
	rect ret;
	ret.a = (l.a * r.a + l.b * r.c) % rr;
	ret.b = (l.a * r.b + l.b * r.d) % rr;
	ret.c = (l.c * r.a + l.d * r.c) % rr;
	ret.d = (l.c * r.b + l.d * r.d) % rr;
	return ret;
}

rect get(int rt, int L, int R, int l, int r) {
	if (l == L && r == R)
		return tree[rt];
	int mid = (L + R) >> 1;
	if (r <= mid)
		return get(rt << 1, L, mid, l, r);
	else if (l >= mid)
		return get((rt << 1) ^ 1, mid, R, l, r);
	rect ret = prod(get(rt << 1, L, mid, l, mid),
			get((rt << 1) ^ 1, mid, R, mid, r));
	return ret;
}

int main() {
	freopen("crypto.in","r",stdin);
	freopen("crypto.out","w",stdout);
	scanf("%d %d %d", &rr, &n, &m);
	sz = 1;
	while (sz < n)
		sz <<= 1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &tree[sz + i].a, &tree[sz + i].b, &tree[sz + i].c,
				&tree[sz + i].d);
	}
	for (int i = sz - 1; i >= 1; i--) {
		tree[i] = prod(tree[i << 1], tree[i << 1 ^ 1]);
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		rect ret = get(1, 0, sz, l - 1, r);
		if(i)
			printf("\n");
		printf("%d %d\n%d %d\n", ret.a, ret.b, ret.c, ret.d);
	}
	return 0;
}

