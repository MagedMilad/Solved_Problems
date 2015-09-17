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

int n, m, cap[203][203], lower[203][203], demand[203], exp_source = 0,
		exp_sink = 0, mi = oo, graph[203][203], s, t;
vi parent;
ii edge[41209];

void calc(int u, int minEdge) {
	if (u == s) {
		mi = minEdge;
		return;
	} else if (parent[u] != -1) {
		calc(parent[u], min(minEdge, graph[parent[u]][u]));
		graph[parent[u]][u] -= mi;
		graph[u][parent[u]] += mi;
	}
}

int flow() {
	int ans = 0;
	while (true) {
		mi = 0;
		vi dest(n, oo);
		dest[s] = 0;
		queue<int> q;
		q.push(s);
		parent.assign(n, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < n; i++) {
				if (graph[u][i] > 0 && dest[i] == oo) {
					dest[i] = dest[u] + 1;
					q.push(i);
					parent[i] = u;
				}
			}

		}
		calc(t, oo);
		if (mi == 0)
			break;
		ans += mi;
	}
	return ans;
}

int main() {
	freopen("cooling.in", "r", stdin);
	freopen("cooling.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, l, c;
		scanf("%d %d %d %d", &u, &v, &l, &c);
		u--;
		v--;
		cap[u][v] = c;
		lower[u][v] = l;
		demand[u] += l;
		demand[v] -= l;
		edge[i] = ii(u, v);
		graph[u][v] = c - l;
	}
	s = n;
	t = n + 1;
	for (int i = 0; i < n; i++) {
		if (demand[i] < 0) {
			exp_source -= demand[i];
			graph[s][i] -= demand[i];
		} else {
			exp_sink += demand[i];
			graph[i][t] = demand[i];
		}
	}
	n += 2;
	int res = flow();
	if (res != exp_source || exp_sink != exp_source) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0, j = 0; i < 2 * m; i += 2, j++) {
		printf("%d\n",graph[edge[j].second][edge[j].first] +lower[edge[j].first][edge[j].second]);
	}
	return 0;
}

