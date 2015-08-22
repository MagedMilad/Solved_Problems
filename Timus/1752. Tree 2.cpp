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

vvi adj;
int n, q, kth[2][20001][20], dist[20001], mx[20001];

int bfs(int s, int k) {
	clr(dist, -1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				kth[k][v][0] = u;
				q.push(v);
			}
		}
	}
	int far = s, d = 0;
	for (int i = 1; i <= n; i++) {
		mx[i] = max(mx[i], dist[i]);
		if (dist[i] > d) {
			d = dist[i];
			far = i;
		}
	}
	return far;
}

int get(int u, int d, int k) {
	int pow = 19;
	while (d) {
		while ((1 << pow) > d)
			pow--;
		u = kth[k][u][pow];
		d -= (1 << pow);
	}
	return u;
}

void init() {
	for (int k = 0; k < 2; k++) {
		for (int j = 1; j < 20; j++) {
			for (int i = 1; i <= n; i++) {
				kth[k][i][j] = kth[k][kth[k][i][j - 1]][j - 1];
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &q);
	adj.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int far1 = bfs(1, 0);
	int far2 = bfs(far1, 0);
	bfs(far2, 1);
	init();
	for (int i = 0; i < q; i++) {
		int u, k;
		scanf("%d %d", &u, &k);
		if (k > mx[u])
			printf("0\n");
		else if (mx[u] == dist[u])
			printf("%d\n", get(u, k, 1));
		else
			printf("%d\n", get(u, k, 0));
	}
	return 0;
}

