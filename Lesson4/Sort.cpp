#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001],c[100001];

void mSort(int x, int y)
{
    if (x==y)
        return ;
    
    int i=0,j;
    int p,q,m;
    
    m=(x+y)/2;
    p=x;q=m+1;
    
    mSort(p,m);mSort(q,y);
    
    while(p<=m && q<=y)
    {
        if (a[p]<=a[q])
        {
	i++;
    	c[i]=a[p];
    	p++;
        }
        else
        {
        	i++;
    	c[i]=a[q];
    	q++;
        }
    }
    
    while (p<=m)
    {
        i++;
        c[i]=a[p];
        p++;	
    }
    
    while (q<=y)
    {
        i++;
        c[i]=a[q];
        q++;	
    }
    
    for (j=1;j<=i;j++)
	a[x-1+j]=c[j];

    return ;	
}

int main() {
    
    int i;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];

    mSort(1,n);
    
    for (i=1;i<=n;i++)
        cout<<a[i]<<'\n';
    
    return 0;
}