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
int n, k, s, t;
int parent[110], cap[110][110], cost[110][110];

int agumentPath(int mi) {
	int i = t;
	int total = 0;
	while (parent[i] != -1) {
		cap[parent[i]][i] -= mi;
		total += mi * cost[parent[i]][i];
		cap[i][parent[i]] += mi;
		i = parent[i];
	}
	return total;
}

int bf(int sz) {
	vd d(sz, oo);
	vi f(sz, 0);
	d[s] = 0;
	f[s] = oo;
	clr(parent, -1);
	queue<int> q;
	q.push(s);
	bool inqueue[sz];
	clr(inqueue, false);
	inqueue[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inqueue[u] = false;
		for (int v = 0; v < sz; v++) {
			if (cap[u][v] > 0 && d[u] + cost[u][v] < d[v]) {
				d[v] = d[u] + cost[u][v];
				f[v] = min(f[u], cap[u][v]);
				parent[v] = u;
				if (!inqueue[v]) {
					inqueue[v] = true;
					q.push(v);
				}
			}
		}
	}
	return f[t];
}

int MCMF(int sz) {
	int total = 0;
	while (1) {
		int current = bf(sz);
		if (current == 0)
			return total;
		total += agumentPath(current);
	}
	return total;
}

int main() {
//  freopen("in.txt", "r", stdin);
	freopen("assignment.in","r",stdin);
	freopen("assignment.out","w",stdout);
	scanf("%d %d", &n, &k);
	s = 2 * n;
	t = 2 * n + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j + n]);
			cost[j + n][i] = -cost[i][j + n];
			cap[i][j + n] = 1;
		}
		cost[s][i] = 0;
		cap[s][i] = k;
		cost[i+n][t] = 0;
		cap[i+n][t] = k;
	}
	int sz = 2*n+2;
	printf("%d\n",MCMF(sz));
	return 0;
}

