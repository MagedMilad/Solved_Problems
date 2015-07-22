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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef long double ld;
typedef vector<vector<ll> > grix;
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

vvii adj(30);
vi dist;
priority_queue<ii, vii, greater<ii> > pq;

void init() {
	for (int i = 0; i < 30; i++)
		adj[i].clear();
}

int main() {
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
	string s;
	while (cin >> s) {
		init();
		int u = s[0] - 'a';
		int v = s[sz(s) - 1] - 'a';
		adj[u].push_back( { v, sz(s) });
		adj[v].push_back( { u, sz(s) });
		int total = sz(s);
		while (cin >> s) {
			if (s == "deadend")
				break;
			u = s[0] - 'a';
			v = s[sz(s) - 1] - 'a';
			adj[u].push_back( { v, sz(s) });
			adj[v].push_back( { u, sz(s) });
			total += sz(s);
		}
		int start = -1, end = -1;
		for (int i = 0; i < 30; i++) {
			if (sz(adj[i]) % 2) {
				if (start == -1)
					start = i;
				else {
					end = i;
					break;
				}
			}
		}
		if (start == -1) {
			printf("%d\n", total);
		} else {
			dist.assign(30, oo);
			dist[start] = 0;
			pq.push(ii(0, start));
			while (!pq.empty()) {
				ii front = pq.top();
				pq.pop();
				int d = front.first;
				int u = front.second;
				if (d == dist[u]) {
					for (int j = 0; j < sz(adj[u]); j++) {
						ii v = adj[u][j];
						if (dist[v.first] > dist[u] + v.second) {
							dist[v.first] = dist[u] + v.second;
							pq.push(ii(dist[v.first], v.first));
						}
					}
				}
			}
			printf("%d\n",total + dist[end]);
		}

	}
	return 0;
}

