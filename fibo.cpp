#include<bits/stdc++.h>

using namespace std;;
int memo[10000]={0};
int fibo(int i){
    if(i==0|| i==1) return i;
    if(memo[i]==0)
        memo[i]=fibo(i-1)+fibo(i-2);

    return memo[i];
}
int main(){
        int n;
        cin>>n;
        cout<<"Fibo  "<<n <<" : "<<fibo(n);

}
