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

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

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

string face[] = { "front", "back", "left", "right", "top", "bottom" };
int num[3001], pos[3001], top[3001], bot[3001] , dp[3001] , parent[3001];

void print(int u){
	if(parent[u]==-1){
		printf("%d %s\n",num[u] ,face[pos[u]].c_str());
		return;
	}
	print(parent[u]);
	printf("%d %s\n",num[u] ,face[pos[u]].c_str());
}

int main() {
	freopen("in.txt", "r", stdin);
	int n,tc=0;
	bool started=false;
	while (cin >> n && n) {
		if(started)
			printf("\n");
		else
			started = true;
		tc++;
		int color[6];
		int m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> color[j];
			}
			for (int j = 0; j < 6; j++) {
				num[m] = i + 1;
				pos[m] = j;
				top[m] = color[j];
				if (j % 2)
					bot[m] = color[j - 1];
				else
					bot[m] = color[j + 1];
				m++;
			}
		}
		clr(dp,0);
		clr(parent,-1);
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				if(num[j] > num[i] && bot[i]==top[j] && dp[j] < dp[i]+1){
					dp[j] = dp[i]+1;
					parent[j]=i;
				}
			}
		}
		int mx=-oo;
		int idx=-1;
		for(int i=0;i<m;i++){
			if(dp[i]>mx){
				mx=dp[i];
				idx=i;
			}
		}
		printf("Case #%d\n%d\n",tc,mx+1);
		print(idx);
	}
	return 0;
}

