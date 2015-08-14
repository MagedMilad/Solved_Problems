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

int n, m, s, vis[101], a[101][101] , parent[101];
bool ok;

void init(){
	for(int i=1;i<=n;i++)
		parent[i]=i;
}

int find(int i){
	if(parent[i]==i)
		return i;
	return parent[i]=find(parent[i]);
}

bool union_find(int i , int j){
	int ri = find(i);
	int rj = find(j);
	if(ri == rj)
		return false;
	parent[ri]=rj;
	return true;
}

void dfs(int u, int len) {
	if (len >= s)
		ok = true;
	vis[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && a[u][i])
			dfs(i, len + a[u][i]);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> m >> s;
	ok = false;
	init();
	for (int i = 0; i < m; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		if (!union_find(u,v))
			ok = true;
		if (!a[u][v])
			a[u][v] = a[v][u] = len;
		else
			ok = true;

	}
	if (ok) {
		printf("YES\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		clr(vis, 0);
		dfs(i, 0);
		if (ok) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}

