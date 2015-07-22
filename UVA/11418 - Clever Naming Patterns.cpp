//============================================================================
// Name        : Practice.cpp
// Author      :
// Version     :
// Copyri   :
// Description :
//============================================================================

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
typedef pair<ll, ll> ii;
typedef vector<vector<ii> > vii;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > matrix;
typedef complex<double> point;
typedef complex<long long> pointINT;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int DX[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int DY[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

double PI = 3.1415926535897932384626433832795;

const ll oo = (ll) 1e9 + 1;
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
//#define distsqr(a,b) (((a)*(conj(a))).real())
#define distsqr(a,b) (pow((a).real()-(b).real(),2.0)+pow((a).imag()-(b).imag(),2.0))
#define normalize(a) ((a)/length(a))
#define ccw(a,b,c) (cross(vec((a),(b)),vec((a),(c)))>=0)
#define collinear(a,b,c) (fabs(cross(vec((a),(b)),vec((a),(c))))<eps)

////////////////////////////////////////////////////////////////////////

//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

int n, mi, s, t, flow = 0;
vi parent;
int graph[60][60];
vector<vector<string> > a;

void init() {
	flow = 0;
	for(int i=0;i<60;i++)
		for(int j=0;j<60;j++)
			graph[i][j]=0;
//	clr(graph, 0);
	s = 0;
	t = n + 27;
	a.resize(n + 5);
	for (int i = 1; i <= n; i++)
		a[i].clear();
	for (int i = 1; i <= n; i++) {
		graph[s][i] = 1;
		int size;
		cin >> size;
		for (int j = 0; j < size; j++) {
			string s;
			cin >> s;
			a[i].push_back(s);
			graph[i][toupper(s[0]) - 'A' + n + 1] = 1;
			graph[toupper(s[0]) - 'A' + n + 1][t] = 1;
		}
	}
}

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

int MF(int size) {
	int ans = 0;
	while (true) {
		mi = 0;
		vi dest(size, oo);
		dest[s] = 0;
		queue<int> q;
		q.push(s);
		parent.assign(size, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < size; i++) {
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
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	int tc,test=0;;
	cin >> tc;
	while (tc--) {
		test++;
		cin >> n;
		init();
		MF(t + 1);
		vs res;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 26; j++) {
				if (!graph[i][n + j + 1] && graph[n + j + 1][i]) {
					for (int k = 0; k < sz(a[i]); k++) {
						if (j == toupper(a[i][k][0]) - 'A') {
							res.push_back(a[i][k]);
							break;
						}
					}
				}
			}
		}
		cout<<"Case #"<<test<<":"<<endl;
		for (int i = 0; i < sz(res); i++){
			transform(all(res[i]) , res[i].begin() , ::tolower);
			res[i][0] = toupper(res[i][0]);
		}
		sort(all(res));
		for(int i=0;i<sz(res);i++)
			cout<<res[i]<<endl;
	}
	return 0;
}

