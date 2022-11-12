#include <iostream>
#include <cmath>
using namespace std;
int main(){
  long long a,b,ret;
  cin>>ret>>b;
  for(int i=2;i<=b;i++){
    a=pow(ret,i);
    if(a>1000000000LL){
      cout<<-1;
      return 0;
    }
  }
  cout<<a;
  return 0;
}
