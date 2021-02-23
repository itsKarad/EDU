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

struct Stack{
    vector<int> s,mn={LLONG_MAX},mx={LLONG_MIN};
    void push(int x){
        s.pb(x);
        mx.pb(max(mx.back(),x));
        mn.pb(min(mn.back(),x));
    }
    int pop(){
        int x=s.back();
        s.pop_back();
        mn.pop_back();
        mx.pop_back();
        return x;
    }
    bool empty(){
        return s.empty();
    }
    int min1(){
        return mn.back();
    }
    int max1(){
        return mx.back();
    }
};
int n,k;
Stack s1,s2;
void add(int x){
    s2.push(x);
}
void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool valid(){
    int mx1=max(s1.max1(),s2.max1());
    int mn1=min(s1.min1(),s2.min1());
    return (mx1-mn1<=k);
}
void solve()
{
    cin>>n>>k;
    vector<int> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int l=0,answer=0;
    for(int r=0;r<n;r++){
        add(a[r]);
        while(!valid()){
            remove();
            l++;
        }
        answer+=r-l+1;
    }
    cout<<answer<<endl;    
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