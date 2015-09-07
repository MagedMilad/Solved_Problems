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

int n;
ii tree[100001];
int parent[100001];


ii get_ans(int y) {
	ii res = ii(0, 0);
	while (y) {
		if (tree[y].first > res.first) {
			res = tree[y];
		}
		y -= LSOne(y);
	}
	return res;
}

void update(int val, int sol, int id) {
	while (val <= n) {
		if (tree[val].first < sol) {
			tree[val].first = sol;
			tree[val].second = id;
		}
		val += LSOne(val);
	}
}

struct node {
	int x, y, id;

	node() {
	}
	node(int x, int y, int id) :
			x(x), y(y), id(id) {
	}
	bool operator <(const node &other) const {
		if (x == other.x)
			return y > other.y;
		return x < other.x;
	}
};

node arr[100001];

void print(int u) {
	if (parent[u] == -1) {
//		printf("%d", arr[u].id);
		return;
	}
	print(parent[u]);
	printf("%d ",  arr[u].id);
}

int main() {
	freopen("people.in","r",stdin);
	freopen("people.out","w",stdout);
	scanf("%d", &n);

	int hash[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
		arr[i].id = i;
		hash[i] = arr[i].y;
	}
	sort(arr + 1, arr + 1 + n);
	sort(hash + 1, hash + 1 + n);
	int sz = unique(hash + 1, hash + 1 + n) - hash;
	for (int i = 1; i <= n; i++)
		arr[i].y = lower_bound(hash + 1, hash + 1 + sz, arr[i].y) - hash;

	int mx = -1, idx = -1;

	clr(parent, -1);
	for (int i = 1; i <= n; i++) {
		ii sol = get_ans(arr[i].y - 1);
		update(arr[i].y, sol.first + 1, i);
		if (sol.first+1 > mx) {
			mx = sol.first + 1;
			idx = i;
		}
		parent[i] = sol.second;
	}
	printf("%d\n", mx);
	print(idx);
	return 0;
}

