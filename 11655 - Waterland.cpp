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
#define sz(v) ((ll)v.size())
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

int n , m;
vector<vector<int> > a;
vector<bool>vis;
vector<int>s;

void tls(int u){
	vis[u]=1;
	for(int i=0;i<sz(a[u]);i++){
		int v = a[u][i];
		if(!vis[v])
			tls(v);
	}
	s.push_back(u);
}

int main() {
	freopen("in.txt", "r", stdin);
	int t,tc=0;
	cin>>t;
	while(t--){
		tc++;
		cin>>n>>m;
		a.resize(n);
		for(int i=0;i<n;i++)
			a[i].clear();
		for(int i=0;i<m;i++){
			int u , v;
			cin>>u>>v;
			u--;
			v--;
			a[u].push_back(v);
		}
		s.resize(n);
		s.clear();
		vis.assign(n,false);
		for(int i=0;i<n;i++)
			if(!vis[i])
				tls(i);
		reverse(all(s));
		ll dp1[n] , dp2[n];
		clr(dp1,0);
		clr(dp2,0);
		dp1[0]=1;
		for(int i=0;i<sz(s);i++){
			int u = s[i];
			for(int j=0;j<sz(a[u]);j++){
				int v = a[u][j];
				dp1[v] += dp1[u];
				dp2[v] +=dp2[u]+dp1[u];
				dp1[v]%=100000;
				dp2[v]%=100000;
			}
		}
		printf("Case %d: %lld %lld\n",tc,dp2[n-1],dp1[n-1]);
	}
	return 0;
}





















