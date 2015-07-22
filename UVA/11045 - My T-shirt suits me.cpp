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

int n, m, mi, s, t;
vi parent;
int graph[100][100];

void init() {
	n /= 6;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			graph[i][j] = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			string s;
			cin >> s;
			if (s == "XXL")
				graph[1][7 + i] = 1;
			else if (s == "XL")
				graph[2][7 + i] = 1;
			else if (s == "L")
				graph[3][7 + i] = 1;
			else if (s == "M")
				graph[4][7 + i] = 1;
			else if (s == "S")
				graph[5][7 + i] = 1;
			else
				graph[6][7 + i] = 1;
		}
	}
	for (int i = 1; i <= 6; i++)
		graph[0][i] = n;
	for (int i = 7; i < 7 + m; i++)
		graph[i][7 + m] = 1;
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
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		init();
		s = 0;
		t = 7 + m;
		int match = MF(t+1);
		if(match == m)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

