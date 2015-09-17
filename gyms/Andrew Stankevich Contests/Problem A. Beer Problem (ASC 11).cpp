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
const double eps = 1e-7;
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

const int MAXN = 120;
const int MAXM = MAXN * MAXN;

struct edge {
	int v, c, w;
	edge() {
	}
	edge(int v, int c, int w) :
			v(v), c(c), w(w) {
	}
};

struct MCMF {
	int n, m, source, sink;
	vector<int> e[MAXN];
	edge edges[MAXM * 2];

	void init(int n, int source, int sink) {
		this->n = n;
		this->source = source;
		this->sink = sink;
		for (int i = 0; i < n; i++)
			e[i].clear();
	}

	void add_edge(int u, int v, int c, int w) {
		edges[m] = edge(v, c, w);
		e[u].push_back(m++);
		edges[m] = edge(u, 0, -w);
		e[v].push_back(m++);
	}

	bool mark[MAXN];
	int maxc[MAXN];
	int minw[MAXN];
	int pre[MAXN];
	int d[MAXN];

	bool spfa() {
		queue<int> q;

		fill(mark, mark + n, false);
		fill(maxc, maxc + n, 0);
		fill(minw, minw + n, oo);
		fill(pre, pre + n, -1);
		fill(d, d + n, 0);

		mark[source] = true;
		maxc[source] = oo;
		minw[source] = 0;

		q.push(source);

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			mark[u] = false;
			for (size_t i = 0; i < e[u].size(); i++) {
				int id = e[u][i];
				int v = edges[id].v;
				int c = min(maxc[u], edges[id].c);
				if (c == 0)
					continue;
				int w = minw[u] + edges[id].w;
				if (minw[v] > w || (minw[v] == w && c > maxc[v])) {
					maxc[v] = c;
					minw[v] = w;
					pre[v] = id;
					d[v] = d[u] + 1;
					if (d[v] >= n)
						return false;
					if (!mark[v]) {
						mark[v] = true;
						q.push(v);
					}
				}
			}
		}
		return true;
	}

	pair<int, int> flow() {
		int sumc = 0, sumw = 0;
		while (spfa()) {
			if (maxc[sink] == 0 || minw[sink] >= 0)
				break;
			int c = maxc[sink];
			sumc += c;
			sumw += c * minw[sink];
			int cur = sink;
			while (cur != source) {
				int id = pre[cur];
				edges[id].c -= c;
				edges[id ^ 1].c += c;
				cur = edges[id ^ 1].v;
			}
		}
		return ii(sumc, sumw);
	}

};

int main() {
	freopen("beer.in","r",stdin);
	freopen("beer.out","w",stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	MCMF flow;
	flow.init(n + 5, 1, n + 1);
	for (int i = 2; i <= n; i++) {
		int cost;
		scanf("%d", &cost);
		flow.add_edge(i, n + 1, oo, -cost);
	}
	for (int i = 0; i < m; i++) {
		int u, v, c, w;
		scanf("%d %d %d %d", &u, &v, &c, &w);
		flow.add_edge(u, v, c, w);
		flow.add_edge(v, u, c, w);
	}
	printf("%d\n", -flow.flow().second);
	return 0;
}

