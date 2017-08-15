#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int n; scanf("%d",&n);
    if(!n)return !printf("YES\n%d\n%d\n%d\n%d",1,2,2,3);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    if(n==1)printf("YES\n%d\n%d\n%d",2*a[0],2*a[0],3*a[0]);
    else if(n==4)
    {
        if(3*a[0]==a[3]&&4*a[0]==a[1]+a[2])puts("YES");
        else puts("NO");
    }
    else if(n==3)
    {
        if(4*a[0]==a[1]+a[2])printf("YES\n%d",3*a[0]);//X4
        else if(3*a[0]==a[2])printf("YES\n%d",4*a[0]-a[1]);//X2|3
        else if((4*a[2]/3)==a[0]+a[1])printf("YES\n%d",a[2]/3);//X1
        else puts("NO");
    }
    else
    {
        if(3*a[0]==a[1])printf("YES\n%d\n%d",2*a[0],2*a[0]);//X2,3
        else if(a[1]<3*a[0])printf("YES\n%d\n%d",4*a[0]-a[1],3*a[0]);//X3,4
        else puts("NO");
    }

}
