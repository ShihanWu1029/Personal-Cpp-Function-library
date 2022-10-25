#include <iostream>
#include <cstring>
#pragma optimize(2)
#define MAXS 10001000

using namespace std;

int nextn[MAXS];
bool isnok[MAXS];

void init(){
//	memset(isok,true,sizeof(isok));
	string a;
//	isok[1]=isok[2]=isok[3]=true;
	for(int j=7;j<MAXS;j+=7){
		isnok[j]==true;
	}
	for(int i=8;i<MAXS;i++){
		if(isnok[i]==true) continue;
		a=to_string(i);
		if(a.find('7') != a.npos){
//			isok[i]=false;
			for(int j=i;j<MAXS;j+=i){
				isnok[j]=true;
			}
		}
	}
	bool flag=false;
	for(int i=1;i<MAXS;i++){
		if(isnok[i]) nextn[i]=-1;
		else{
			flag=false;
			for(int j=i+1;j<MAXS;j++){
				if(isnok[j]==false){
					nextn[i]=j,flag=true;
					break;
				}
			}
			if(flag) ;
			else nextn[i]=-1;
		}
	}
}

int main(){
	int n,r_says;
	init();
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>r_says;
		cout<<nextn[r_says]<<endl;
	}
	return 0;
} 
