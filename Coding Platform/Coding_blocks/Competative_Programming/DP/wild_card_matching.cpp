// Question:- 
// You are given a text and a wildcard pattern. A text contains lowercase English letters only. A wildcard pattern can contain, along with lowercase English letters, '?' and '*' characters.

// 1. '?' matches any single character. For example, Text = "aaba" and Pattern = "aa?a", then they are matched.
// 2. ' * ' matches any subsegment of characters(including empty sub-segment). For example, Text = "aaba" and Pattern = "a*", then they are matched. Find out if the pattern and text matches or not.
// Input Format
// First line contains the Text and the second line contains the Pattern.

// Constraints
// 1<= |Text|, |Pattern| <=1000

// Each occurrence of ‘?’ character in wildcard pattern can be replaced with any other character and each occurrence of ‘*’ with a sequence of characters such that the wildcard pattern becomes identical to the input string after replacement.

// Let’s consider any character in the pattern.

// Case 1: The character is ‘*’ Here two cases arise

// We can ignore ‘’ character and move to next character in the Pattern. ‘’ character matches with one or more characters in Text. Here we will move to next character in the string. Case 2: The character is ‘?’ We can ignore current character in Text and move to next character in the Pattern and Text.

// Case 3: The character is not a wildcard character If current character in Text matches with current character in Pattern, we move to next character in the Pattern and Text. If they do not match, wildcard pattern and Text do not match.

// We can use Dynamic Programming to solve this problem – Let T[i][j] is true if first i characters in given string matches the first j characters of pattern.


#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
        int slen = s.length(),plen = p.length();
        int idx1 = 0,idx2 = 0;
        int stInd = -1,Tmpidx = -1;
        while(idx1 < slen)
        {
            if(idx2<plen && (p[idx2]=='?' || p[idx2]==s[idx1]))
            {
                idx1++;
                idx2++;
            }
            else if(idx2 < plen && p[idx2] == '*')
            {
                stInd = idx2;
                Tmpidx = idx1;
                idx2++;
            }
            else if(stInd == -1)
                return false;
            else
            {
                idx1 = Tmpidx + 1;
                idx2 = stInd + 1;
                Tmpidx++;
            }
        }

        for(int i=idx2;i<plen;i++)
            if(p[i]!='*')
                return false;
        return true;
    }

int main() {
    string s,p;
    cin>>s>>p;
    if(isMatch(s,p)){
        cout<<"MATCHED";
    }
    else{
        cout<<"NOT MATCHED";
    }
}
}
