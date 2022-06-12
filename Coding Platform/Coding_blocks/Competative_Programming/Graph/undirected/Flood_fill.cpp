#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
const ll mod = 1e9+7;

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

ll msum(ll a,ll b,ll m) { return (a%m+b%m)%m; }
ll msub(ll a,ll b,ll m) { return (a%m-b%m)%m; }
ll mpro(ll a,ll b,ll m) { return ((a%m)*(b%m))%m; }
ll m_m(ll a,ll b,ll m);
ll fxp(ll a,ll b,ll m);
void swap(ll &a,ll &b){ ll t=a; a=b; b=t;}

// 15 30
// ..............................
// .............#####............
// .............#...#............
// .....#########...#######......
// ....###.....######.....###....
// ...##....................##...
// ...##....................#.... 
// ...###..................##....  
// ....####..............###.....
// ......####.........###........
// .........###.....###..........
// ...........#######............
// ..............................         
// ...........A.P.P.L.E..........
// ..............................
// O/p:-
// ..............................
// .............#####............
// .............#...#............
// .....#########...#######......
// ....###rrrrr######rrrrr###....
// ...##rrrrrrrrrrrrrrrrrrrr##...
// ...##rrrrrrrrrrrrrrrrrrrr#....
// ...###rrrrrrrrrrrrrrrrrr##....
// ....####rrrrrrrrrrrrrr###.....
// ......####rrrrrrrrr###........
// .........###rrrrr###..........
// ...........#######............
// ..............................
// ...........A.P.P.L.E..........
// ..............................

// Flood Fill is a simple variant of BFS/DFS that can be use to label(color) the various "connected" component present in the graph
// It is generally performed in inplicit graphs i.e 2-D matrix
// Now stating from a particular cell it call DFS on the nebihouring cell to color them. It can call 4 (R,L,U,D) 
// or 8 if diagonals are also included

ll R,C;

void Print_mat(char mat[][50])
{
    for(ll i=0;i<R;i++)
    {
        for(ll j=0;j<C;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

void Flood_fill(char mat[][50],ll i,ll j,char ch,char color)
{
    // base case
    if(i<0 || j<0 || i>R || i>C)
        return;
    
    // Boundry condition for coloring
    if(mat[i][j]!=ch)
        return;

    // Recursive
    mat[i][j]=color;
    for(ll k=0;k<4;k++)
        Flood_fill(mat,i+dx[k],j+dy[k],ch,color);
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll i,j;
        cin>>R>>C;
        char mat[20][50];
        fo(i,R)
        {
            fo(j,C)
                cin>>mat[i][j];
        }

        Flood_fill(mat,7,15,'.','r');
        Print_mat(mat);

    }
 return 0;
}
ll fxp(ll a,ll b,ll m) {
    if(b==0)
        return 1;
    if(b%2==0)
        return fxp(m_m(a,a,m),b/2,m);
    return m_m(fxp(a,b-1,m),a,m);
}
ll m_m(ll a,ll b,ll m) 
{
    ll res=0;
    a=a%m;
    while(b)
    {
        if(b&1)
        {
            res+=a; 
            res=res%m;
        }
        a=(a*2)%m;
        b=b/2;
    }
    return res;
}