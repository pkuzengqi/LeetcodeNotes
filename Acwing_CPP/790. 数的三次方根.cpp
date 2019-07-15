#include<iostream>
using namespace std;
const double eps=1e-8;
int main(){
    double n;
    cin>>n;
    double l=-100,r=100;
    while(r-l>eps){
        double mid = (l+r)/2;
        if(mid*mid*mid<=n) l=mid;
        else r=mid;
    }
    printf("%.6lf\n", l);
    return 0;
}