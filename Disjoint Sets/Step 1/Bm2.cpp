#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long 
#define MOD 1000000007
#define MOD2 1000000014000000049L
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define bs binary_search
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;
#define debug(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************

vector<int> p;
vector<int> sz;
vector<int> mx;
vector<int> mn;
int get(int a){
    if(p[a]!=a){
        p[a]=p[p[a]];
        a=p[a];
    }
    return a;
}
void query(int a){
    a=get(a);
    cout<<mn[a]<<" "<<mx[a]<<" "<<sz[a]<<endl;
}
void unify(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b){
        return;
    }
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    
    sz[a]+=sz[b];
    mn[a]=min(mn[a],mn[b]);
    mx[a]=max(mx[a],mx[b]);
    p[b]=a;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    p.resize(n+1);
    mn.resize(n+1);
    mx.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;i++){
        p[i]=i;sz[i]=1;
        mx[i]=i;mn[i]=i;
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        int x,y;
        if(s=="union"){
            cin>>x>>y;
            unify(x,y);
        }
        else{
            // find max and min of this set
            cin>>x;
            query(x);
        }
    }    
}
signed main() 
{ 
    FAST;
    solve();
    return 0; 
} 



// Paste for reading from input file
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif




int power(int base, int exp) {
   int res=1;
   while(exp>0) {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
   }
   return res%MOD;
}






// sometimes I believe compiler ignores all my comments