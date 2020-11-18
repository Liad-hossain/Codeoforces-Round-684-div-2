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
        lld n, m, i, j;
        cin >> n >> m;
        string a[n + 1], s;
        fo(i, 1, n)
        {
            a[i]='0';
            cin>>s;
            a[i]+=s;
        }


        vll ans;
        bool flag = false;
        fo(i, 1, n - 1)
        {
            fl(j, 1, m)
            {
                if (i == n - 1 && j == m - 1)
                {
                    flag = true;
                    break;
                }

                if (i == n - 1)
                {
                    if (a[i][j] == '1')
                    {
                        ans.pb({i, j});
                        ans.pb({i + 1, j});
                        ans.pb({i + 1, j + 1});

                        if (a[i + 1][j] == '0')
                            a[i + 1][j] = '1';
                        else
                            a[i + 1][j] = '0';

                        if (a[i + 1][j + 1] == '0')
                            a[i + 1][j + 1] = '1';
                        else
                            a[i + 1][j + 1] = '0';
                    }

                    if (a[i + 1][j] == '1')
                    {
                        ans.pb({i + 1, j});
                        ans.pb({i, j + 1});
                        ans.pb({i + 1, j + 1});

                        if (a[i][j + 1] == '0')
                            a[i][j + 1] = '1';
                        else
                            a[i][j + 1] = '0';

                        if (a[i + 1][j + 1] == '0')
                            a[i + 1][j + 1] = '1';
                        else
                            a[i + 1][j + 1] = '0';
                    }
                }

                else
                {
                    if (j == m)
                    {

                        if (a[i][j] == '1')
                        {
                            ans.pb({i, j});
                            ans.pb({i + 1, j});
                            ans.pb({i + 1, j - 1});

                            if (a[i + 1][j] == '0')
                                a[i + 1][j] = '1';
                            else
                                a[i + 1][j] = '0';

                            if (a[i + 1][j - 1] == '0')
                                a[i + 1][j - 1] = '1';
                            else
                                a[i + 1][j - 1] = '0';
                        }
                    }
                    else
                    {
                        if(a[i][j]=='1')
                        {
                        ans.pb({i, j});
                        ans.pb({i + 1, j});
                        ans.pb({i + 1, j + 1});

                        if (a[i + 1][j] == '0')
                            a[i + 1][j] = '1';
                        else
                            a[i + 1][j] = '0';

                        if (a[i + 1][j + 1] == '0')
                            a[i + 1][j + 1] = '1';
                        else
                            a[i + 1][j + 1] = '0';

                        }
                    }
                    
                }
            }

            if (flag)
                break;
        }

        lld cnt = 0;
        if (a[n - 1][m - 1] == '1')
            cnt++;
        if (a[n - 1][m] == '1')
            cnt++;
        if (a[n][m - 1] == '1')
            cnt++;
        if (a[n][m] == '1')
            cnt++;
        if (cnt == 4)
        {
            ans.pb({n - 1, m - 1});
            ans.pb({n - 1, m});
            ans.pb({n, m - 1});
            ans.pb({n, m});
            ans.pb({n - 1, m - 1});
            ans.pb({n - 1, m});
            ans.pb({n - 1, m - 1});
            ans.pb({n, m - 1});
            ans.pb({n, m});
            ans.pb({n - 1, m});
            ans.pb({n, m - 1});
            ans.pb({n, m});
        }

        if (cnt == 3)
        {
            if (a[n - 1][m - 1] == '1')
                ans.pb({n - 1, m - 1});
            if (a[n - 1][m] == '1')
                ans.pb({n - 1, m});
            if (a[n][m - 1] == '1')
                ans.pb({n, m - 1});
            if (a[n][m] == '1')
                ans.pb({n, m});
        }

        if (cnt == 2)
        {
            if (a[n - 1][m - 1] == '0')
                ans.pb({n - 1, m - 1});
            if (a[n - 1][m] == '0')
                ans.pb({n - 1, m});
            if (a[n][m - 1] == '0')
                ans.pb({n, m - 1});
            if (a[n][m] == '0')
                ans.pb({n, m});

            if (a[n - 1][m - 1] == '1')
                ans.pb({n - 1, m - 1});
            elif (a[n - 1][m] == '1') ans.pb({n - 1, m});
            elif (a[n][m - 1] == '1') ans.pb({n, m - 1});
            elif (a[n][m] == '1') ans.pb({n, m});

            lld c = 0;
            if (a[n - 1][m - 1] == '0')
                a[n - 1][m - 1] = '1';
            elif (c == 0) c++, a[n - 1][m - 1] = '0';
            if (a[n - 1][m] == '0')
                a[n - 1][m] = '1';
            elif (c == 0) c++, a[n - 1][m] = '0';
            if (a[n][m - 1] == '0')
                a[n][m - 1] = '1';
            elif (c == 0) c++, a[n][m - 1] = '0';
            if (a[n][m] == '0')
                a[n][m] = '1';
            elif (c == 0) a[n][m] = '0';

            if (a[n - 1][m - 1] == '1')
                ans.pb({n - 1, m - 1});
            if (a[n - 1][m] == '1')
                ans.pb({n - 1, m});
            if (a[n][m - 1] == '1')
                ans.pb({n, m - 1});
            if (a[n][m] == '1')
                ans.pb({n, m});
        }

        if (cnt == 1)
        {
            if (a[n - 1][m - 1] == '1')
            {
                ans.pb({n - 1, m - 1});
                ans.pb({n, m - 1});
                ans.pb({n, m});
                ans.pb({n, m - 1});
                ans.pb({n - 1, m - 1});
                ans.pb({n - 1, m});
                ans.pb({n - 1, m - 1});
                ans.pb({n - 1, m});
                ans.pb({n, m});
            }

            if (a[n - 1][m] == '1')
            {
                ans.pb({n - 1, m});
                ans.pb({n, m - 1});
                ans.pb({n, m});
                ans.pb({n, m - 1});
                ans.pb({n - 1, m - 1});
                ans.pb({n - 1, m});
                ans.pb({n - 1, m - 1});
                ans.pb({n - 1, m});
                ans.pb({n, m});
            }

            if (a[n][m - 1] == '1')
            {
                ans.pb({n, m - 1});
                ans.pb({n - 1, m - 1});
                ans.pb({n - 1, m});
                ans.pb({n - 1, m - 1});
                ans.pb({n, m - 1});
                ans.pb({n, m});
                ans.pb({n, m});
                ans.pb({n - 1, m});
                ans.pb({n, m - 1});
            }

            if (a[n][m] == '1')
            {
                ans.pb({n, m});
                ans.pb({n - 1, m - 1});
                ans.pb({n - 1, m});
                ans.pb({n - 1, m - 1});
                ans.pb({n, m - 1});
                ans.pb({n, m});
                ans.pb({n, m});
                ans.pb({n - 1, m});
                ans.pb({n, m - 1});
            }
        }
        cout<<ans.size()/3<<endl;

        lld c=0;
        for(i=0;i<ans.size();i++)
        {
            c++;
            cout<<ans[i].ff<<" "<<ans[i].ss<<" ";
            if(c==3)cout<<endl,c=0;
        }

        ans.clear();
    }
    return 0;
}
