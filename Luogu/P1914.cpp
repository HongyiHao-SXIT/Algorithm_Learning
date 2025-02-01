#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[200];
    int n,i,la,b[200];
    cin>>n>>a;
    la=strlen(a);
    for(i=0;i<la;i++)
        b[i]=a[i];
    for(i=0;i<la;i++)
        b[i]=b[i]+n;
    for(i=0;i<la;i++)
    {
        if(b[i]>122)
            b[i]=b[i]%122+96;
    }
    for(i=0;i<la;i++)
    {
        a[i]=b[i];
        cout<<a[i];
    }
    return 0;
}