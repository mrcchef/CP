#include <bits/stdc++.h>

using namespace std;

void helper(int n,int oper,int &worstCase,int rem)
{
    if(n==1)
    {
        worstCase=max(oper+(rem==2),worstCase);
        return;
    }

    if(n==2)
    {
        worstCase=max(oper+1,worstCase);
        return;
    }

    // stack1 : st1, stack2 : st2, stack3 : st3
    // rem=0
    // Now, comp(st1,st2)
    // case 1: if st1=st2
    //          -> st3
    // case 2: if st1!=st2
    //          if st1=st3
    //                 -> st2
    //             else 
    //                 -> st1

    // if rem=1
    // Now, comp(st1,st2)
    // case 1: if st1=st2
    //          if st2=st3
    //            -> rem
    //          else
    //            -> st3
    // case 2: if st1!=st2
    //          if st1=st3
    //                 -> st2
    //             else 
    //                 -> st1
    

    // rem=2
    // Now, comp(st1,st2)
    // case 1: if st1=st2
    //          if st2=st3
    //              taking one element from st2 and diving rem into one-one
    //              if back=rem1
    //                  -> rem2
    //              else
    //                  ->   rem1
    //          else
    //            -> st3
    // case 2: if st1!=st2
    //          if st1=st3
    //                 -> st2
    //             else 
    //                 -> st1
    int newCoins=n/3;
    int remCoins=n%3;
    helper(newCoins,oper+2,worstCase,remCoins);
}

void solve()
{
    int n=27;
    cin>>n;

    int worstCase=0;
    helper(n,0,worstCase,0);
    cout<<"Worst Case:"<<worstCase<<endl;
}

int main()
{
    solve();
    return 0;
}