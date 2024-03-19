#include<bits/std++.h>
using namespace std;

//Manacher's Algorithm
vector<int> pal_array(string s)
{
    string t=s;
    s="#";
    for(auto c:t)s+=c,s+="#";
    s="@"+s+"$";
    int n = s.size();
    vector<int> len(n + 1);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++)
    {
        len[i] = min(r - i, len[l + (r - i)]);
        while(s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if(i + len[i] > r)
        {
            l = i - len[i];
            r = i + len[i];
        }
    }
   
return len;
}


int main(){

return 0;
}
