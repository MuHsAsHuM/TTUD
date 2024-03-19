#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length() < s2.length()) swap(s1,s2);
    while(s2.length() != s1.length()){
        string tmp = "0";
        tmp += s2;
        s2 = tmp;
    }
    unsigned carry = 0;
    stack<unsigned> res;
    unsigned tmp;
    for(unsigned i = s1.length() - 1; i >= 0; i--){
        tmp = s1[i] + s2[i] + carry - '0' - '0';
        res.push(tmp%10); 
        carry = tmp/10;
    }
    if(carry) res.push(1);
    while (!res.empty()){
        cout<<res.top();
        res.pop();
    }
}