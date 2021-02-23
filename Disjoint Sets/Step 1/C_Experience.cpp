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

vector<int> p(200005,-1);
vector<int> v(200005,0);
vector<int> extra(200005,0);
vector<int> sz(200005,0);
int get(int a){
    if(p[a]==a){
        return a;
    }
    return get(p[a]);
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
    extra[b]=v[a];   
    p[b]=a;
     
}
void add(int a,int val){
    int b=get(a);
    v[b]+=val;
}
int query(int a){
    int b=get(a);
    int res=0;
    if(b==a){
        return v[a];
    }
    else{
        return v[a]-extra[a]+query(b);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i; sz[i]=1; v[i]=0;extra[i]=0;
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        if(s[0]=='j'){
            int x,y;
            cin>>x>>y;
            unify(x,y);
        }
        else if(s[0]=='a'){
            int x,v;
            cin>>x>>v;
            add(x,v);
        }
        else{
            int x;
            cin>>x;
            cout<<query(x)<<endl;
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