//Author:MD. Liad Hossain
//KUET ECE 2k18
 
#include <bits/stdc++.h>
//using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
#define lld long long int
#define ulld unsigned long long int
#define vl vector<lld>
#define vll vector<pair<lld, lld>>
#define SIZE 5 * 1000000 + 10
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define pof pop_front
#define pob pop_back
#define mp make_pair
#define fbo find_by_order
#define ofk order_of_key
#define fo(i, a, b) for (lld i = a; i <= b; i++)
#define fl(j, c, d) for (lld j = c; j <= d; j++)
#define FOR(i, n) for (lld i = 0; i < n; i++)
#define F0R(j, n) for (lld j = 0; j < n; j++)
#define ROF(i, n) for (lld i = n - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define rs random_shuffle
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define mod 1000000007
#define setbit __builtin_popcount
#define elif else if
#define pi 2 * acos(0.0)
#define inf 9000000000000000000
#define T            \
    int t;           \
    scanf("%d", &t); \
    while (t--)
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;

int main()
{
    T
    {
        lld n,m,i,j;
        cin>>n>>m;
        string a[n];
 
        FOR(i,n)
        {
            cin>>a[i];
        }
 
        vll ans;
 
        FOR(i,n-1)
        {
            F0R(j,m-1)
            {
                lld cnt=0;
                if(a[i][j]=='1')cnt++;
                if(a[i+1][j]=='1')cnt++;
                if(a[i+1][j+1]=='1')cnt++;
                if(a[i][j+1]=='1')cnt++;
                if(cnt>=3)
                {
                    lld c=0;
                    if(a[i][j]=='1')
                    {
                        a[i][j]='0';
                        ans.pb({i+1,j+1});
                        c++;
                    }
                    if(a[i+1][j]=='1')
                    {
                        a[i+1][j]='0';
                        ans.pb({i+2,j+1});
                        c++;
                    }
 
                    if(a[i+1][j+1]=='1')
                    {
                        a[i+1][j+1]='0';
                        ans.pb({i+2,j+2});
                        c++;
                    }
                    if(c<3)
                    {
                        a[i][j+1]='0';
                        ans.pb({i+1,j+2});
                    }
                }
            }
        }
 
 
        FOR(i,n-1)
        {
            F0R(j,m-1)
            {
                lld cnt=0;
                if(a[i][j]=='1')cnt++;
                if(a[i+1][j]=='1')cnt++;
                if(a[i+1][j+1]=='1')cnt++;
                if(a[i][j+1]=='1')cnt++;
                if(cnt==1)
                {
                    if(a[i][j]=='1')
                    {
                        ans.pb({i+1,j+1});
                        ans.pb({i+2,j+1});
                        ans.pb({i+2,j+2});
                        ans.pb({i+2,j+2});
                        ans.pb({i+1,j+1});
                        ans.pb({i+1,j+2});
                        ans.pb({i+1,j+1});
                        ans.pb({i+2,j+1});
                        ans.pb({i+1,j+2});
                    }
 
                    elif(a[i][j+1]=='1')
                    {
                        ans.pb({i+1,j+2});
                        ans.pb({i+2,j+1});
                        ans.pb({i+2,j+2});
                        ans.pb({i+2,j+2});
                        ans.pb({i+1,j+1});
                        ans.pb({i+1,j+2});
                        ans.pb({i+1,j+1});
                        ans.pb({i+2,j+1});
                        ans.pb({i+1,j+2});
                    }
 
                    elif(a[i+1][j+1]=='1')
                    {
                        ans.pb({i+2,j+2});
                        ans.pb({i+2,j+1});
                        ans.pb({i+1,j+1});
                        ans.pb({i+1,j+1});
                        ans.pb({i+1,j+2});
                        ans.pb({i+2,j+2});
                        ans.pb({i+1,j+2});
                        ans.pb({i+2,j+2});
                        ans.pb({i+2,j+1});
                    }
 
                    elif(a[i+1][j]=='1')
                    {
                        ans.pb({i+2,j+1});
                        ans.pb({i+1,j+1});
                        ans.pb({i+2,j+2});
                        ans.pb({i+1,j+1});
                        ans.pb({i+1,j+2});
                        ans.pb({i+2,j+1});
                        ans.pb({i+1,j+2});
                        ans.pb({i+2,j+1});
                        ans.pb({i+2,j+2});
                    }
 
                    a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]='0';
                }
 
                elif(cnt==2)
                {
                    lld count=0;
                    if(a[i][j]=='0')
                    {
                        ans.pb({i+1,j+1});
                       // a[i][j]='1';
                    }
 
                    if(a[i+1][j]=='0')
                    {
                        ans.pb({i+2,j+1});
                       // a[i+1][j]='1';
                    }
 
                    if(a[i][j+1]=='0')ans.pb({i+1,j+2});
 
                    if(a[i+1][j+1]=='0')
                    {
                        ans.pb({i+2,j+2});
                        //a[i+1][j+1]='1';
                    }
 
                    if(a[i+1][j]=='1' && count==0)
                    {
                        ans.pb({i+2,j+1});
                        count++;
                        //a[i+1][j]='0';
                    }
 
                    if(a[i+1][j+1]=='1' && count==0)
                    {
                        ans.pb({i+2,j+2});
                        count++;
                        //a[i+1][j+1]='0';
                    }
 
                    if(a[i][j]=='1' && count==0)
                    {
                        ans.pb({i+1,j+1});
                        //a[i][j]='0';
                        count++;
                    }
                    //else a[i][j]='1';
 
                    if(a[i][j+1]=='1' && count==0)
                    {
                        ans.pb({i+1,j+2});
                        count++;
                        //a[i][j+1]='0';
                    }
                    //else a[i][j+1]='1';
                    count=0;
                    if(a[i+1][j]=='0')a[i+1][j]='1';elif(count==0)a[i+1][j]='0',count++;
                    if(a[i+1][j+1]=='0')a[i+1][j+1]='1';elif(count==0)a[i+1][j+1]='0',count++;
                    if(a[i][j]=='0')a[i][j]='1';elif(count==0)a[i][j]='0',count++;
                    if(a[i][j+1]=='0')a[i][j+1]='1';elif(count==0)a[i][j+1]='0';
                    
                    if(a[i][j]=='1')ans.pb({i+1,j+1}),a[i][j]='0';
                    if(a[i][j+1]=='1')ans.pb({i+1,j+2}),a[i][j+1]='0';
                    if(a[i+1][j]=='1')ans.pb({i+2,j+1}),a[i+1][j]='0';
                    if(a[i+1][j+1]=='1')ans.pb({i+2,j+2}),a[i+1][j+1]='0';
                }
            }
        }

        cout<<ans.size()/3<<endl;
        lld c=0;
        for(int i=0;i<ans.size();i++)
        {
            c++;
            cout<<ans[i].ff<<" "<<ans[i].ss<<" ";
            if(c==3)cout<<endl,c=0;
        }
 
        ans.clear();
    }
    return 0;
}
