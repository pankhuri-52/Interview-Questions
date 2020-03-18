#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int min(int a,int b){
    if(a>b)
     return b;
    else
     return a;
}
double cal_angle(double h,double m){
    if(h<0 || h>12 || m<0 || m>60)
      cout<<"Wrong Input"<<endl;
     
    if(h==12)
     h=0;
    if(m==60)
      m=0;
      
    double hour_hand=(h*60+m)*0.5;
    double minute_hand=m*6;
    
    double angle=abs(hour_hand-minute_hand);
    return min(360-angle,angle);
}
int main() {
	int t;
	cin>>t;
	while(t!=0){
	    double hour;
	    cin>>hour;
	    double minute;
	    cin>>minute;
	    double angle=cal_angle(hour,minute);
	    cout<<floor(angle)<<endl;
	    t--;
	}
	return 0;
}
