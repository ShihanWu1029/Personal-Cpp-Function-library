#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct fu{
	double real,unreal;
};
fu add(fu a,fu b){
	fu ans;
	ans.real=a.real+b.real;
	ans.unreal=a.unreal+b.unreal;
	return ans;
}
fu mul(fu a,fu b){
	fu ans;
	ans.real=a.real*b.real-a.unreal*b.unreal;
	ans.unreal=a.real*b.unreal+a.unreal*b.real;
	return ans;
}
double ab(fu a){
	return sqrt(a.real*a.real+a.unreal*a.unreal);
}
fu f(fu z,fu c){
	return add(mul(z,z),c);
}
int main(){
	fu c;
	cin>>c.real>>c.unreal;
	fu z;
	z.real=0;
	z.unreal=0;
	for(int i=1;i<=5;i++){
		z=f(z,c);
		if(ab(z)>4){
			cout<<"ESCAPES "<<i;
			return 0;
		}
		
	}
	cout<<fixed<<setprecision(3)<<ab(z);
	return 0;
}
