#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*************************************************Input and Output***************************************************************/
template<typename T>void print(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<__outputTarget<<end;}
template<typename T>bool input(T &__inputTarget){ios::sync_with_stdio(false);if(cin>>__inputTarget) return true;else return false;}
template<typename T>void print_float(const T __outputTarget,const int __decimalplaces=2,const char end='\n'){ios::sync_with_stdio(false);cout<<fixed<<setprecision(__decimalplaces)<<__outputTarget<<end;}
template<typename T>void print_fixed(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<fixed<<setprecision(0)<<__outputTarget<<end;}
/***************************************************end line**********************************************************************/

class kw{
	private:
		string __kwlist="False None True and as assert break class continue def del elif else except finally for from global if import in is lambda nonlocal not or pass raise return try while with yield";
	public:
		string kwlist(void){return "['False', 'None', 'True', 'and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']";}
		inline bool isKeyword(const string __tag){
			if(this->__kwlist.find(__tag)==this->__kwlist.npos)  return false;
			else return true;
		}
};
kw keyword;

//python的math库
struct mt{
    const long double e=2.71828182845904523536;
    const long double inf=1.7969e+308;
    const long double nan=sqrt(-1.0);
    const long double pi=3.1415926535897932384;
    const long double tau=pi*2;
	
    template<typename T>long double exp(T __x){return (long double)pow(e,__x);}
//  template<typename T>long double abs(T __x){return abs(__x);}
//  改fabs
    template<typename T>long double Abs(T __x){return fabs(__x);} 
    template<typename T>long long   gcd(T __x,T __y){if(__y) while((__x%=__y) && (__y%=__x)); return __x+__y;}
    template<typename T>long long floor(T __x){return int(__x);}
    template<typename T>long long  ceil(T __x){if(int(__x)==__x) return __x;else return int(__x)+1;}
    long double factorial(short __x){long double __count=1;for(int j=__x;j>0;j--)__count*=j;return __count;}
//  template<typename T>long double sqrt(T __x){return sqrt(__x);}
//  ↑sqrt函数会卡死(Why??)
    template<typename _Tp>inline _GLIBCXX_CONSTEXPR typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, double>::__type Sqrt(_Tp __x)
    { return __builtin_sqrt(__x); }//生搬cmath库【doge】
//  template<typename T>inline long double fabs(T __x) {return fabs(__x);}
//  已将fabs作用于abs 
    long double pow(int __base,int __get){long double record=1;for(int i=1;i<=__get;i++)record*=__base;return record;}
};
mt math;

//通过宏定义来实现部分python语法 
#define elif else if
#define is ==
#define True true
#define False false
