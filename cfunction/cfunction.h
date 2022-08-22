#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::fixed;
using std::ios;
using std::setprecision;
const unsigned long long inf=0x7ffffffff;

template<typename T>long double maxof(T __firstInput,T __secondInput){		//返回两数中的较大值 
	return (__firstInput>__secondInput?__firstInput:__secondInput);
}
template<typename T>long double minof(T __firstInput,T __secondInput){		//返回两数中的较小值 
	return (__firstInput<__secondInput?__firstInput:__secondInput);
}
template<typename T>long double sumof(T N1,T N2){
	return N1+N2;
}
template<typename T>void swapp(T &a,T &b){
	T temp=a;a=b;b=temp;
}
template<typename T>int  comparee(T a,T b){
	return (a>b?1:(a==b?0:-1));
}
template<typename T>bool isEaqual(T a,T b){
	return a==b;
}

bool isLetter(char c){
	return (c>='a'&& c<='z' || c>='A' && c<='Z');
}
bool isLetterSmall(char c){
	return (c>='a' && c<='z');
}
bool isLetterBig(char c){
	return (c>='A' && c<='Z');
}
bool isNumber(char c){
	return (c>='0' && c<='9');
}

template<class XType,class YType>class crdinate{			//用于构建坐标系 
	private:
		XType __Xpos=0;				//用于存储X坐标，下为Y坐标 
		YType __Ypos=0;
		long double tmp_betw=0;
		long double err_return=0.00;
	public:
		crdinate(void){		}
		crdinate(XType __Give_X,YType __Give_Y){this->__Xpos=__Give_X;this->__Ypos=__Give_Y;}
		void set(XType __Give_X,YType __Give_Y){this->__Xpos=__Give_X;this->__Ypos=__Give_Y;}
		void set_X(XType __Give_X){this->__Xpos=__Give_X;}
		void set_Y(YType __Give_Y){this->__Ypos=__Give_Y;}
		XType get_X(void){return this->__Xpos;}
		YType get_Y(void){return this->__Ypos;}
		crdinate get(void){return *this;}
		long double distance_between(crdinate __other){tmp_betw=sqrt((this->__Xpos-__other.__Xpos)*(this->__Xpos-__other.__Xpos)+(this->__Ypos-__other.__Ypos)*(this->__Ypos-__other.__Ypos));return tmp_betw;}
		bool operator==(const crdinate __anthr){return (this->__Xpos==__anthr.__Xpos && this->__Ypos==__anthr.__Ypos);}
		bool operator<=(const crdinate __anthr){return (this->__Xpos<=__anthr.__Xpos && this->__Ypos<=__anthr.__Ypos);}
		bool operator>=(const crdinate __anthr){return (this->__Xpos>=__anthr.__Xpos && this->__Ypos>=__anthr.__Ypos);}
		XType operator[](int __get){
			if(__get>2 || __get<0) return 0;
			if(__get==0) return this->__Xpos;
			else return this->__Ypos;
		}
};

/*typedef int integer;
 *typedef double DoubleNumber;
 *typedef long long longinteger;
 *typedef char Letter;
 *typedef string Sentence;
 */

/*
 *The following part is a set of function to count.
 *
 *void counter_set(unsigned long long __setting){
 *    __inCounterr=__setting;
 *}
 */
unsigned long long __inCounterr=0;
void counter_reset(void){__inCounterr=0;}	//重置计数器为0 
void counter_startAt(unsigned long long __startAt){__inCounterr=__startAt;}		//设置计数器为输入的数 
void counter_plus(void){__inCounterr++;}	//将计数器加一
void counter_plus_step(int __step){__inCounterr+=__step;}	//将计数器加Step 
unsigned long long get_counter(void){return __inCounterr;}	//获取计数器累加的值 

template<class type>class list{
	private:
		type *__a;
		unsigned __SSize=0;
	public:
		bool isSet=false;
		list(){		}
		list(int __size){this->__a=new type[__size+1];isSet=true;this->__SSize=__size;}
		void set_length(int __size){if(!isSet){this->__a=new type[__size+1];isSet=true;this->SSize=__size;}}
		type operator[](const unsigned __at){return this->__a[__at];}
		void set(type __at,type __value=0){this->__a[__at]=__value;}
		type at(unsigned __at){return this->__a[__at];}
		void reset_list(void){for(int __ii=0;__ii<=this->__SSize;__ii++)this->__a[__ii]=0;}
};

class str{
	private:
		string __inStr="";
	public:
		unsigned long long npos;
		str(){this->npos=this->__inStr.npos;}
		str(const string __give){this->__inStr=__give;this->npos=this->__inStr.npos;}
		str(const string __give,const int __times){for(int __ii=0;__ii<__times;__ii++)for(int __jj=0;__jj<__give.size();__jj++)this->__inStr.push_back(__give[__jj]);}
		void refresh_npos(void){this->npos=this->__inStr.npos;}
		void set(const string __given){this->__inStr=__given;}
		string get(void){return this->__inStr;}
		size_t size(void){return this->__inStr.size();}
		size_t length(void){return this->__inStr.length();}
		void push_back(const char __c){this->__inStr.push_back(__c);}
		char at(size_t __at){return this->__inStr.at(__at);}
		string substrOf(size_t __spos=0,size_t __epos=0){return this->__inStr.substr(__spos,__epos-__spos+1);}
		string substr(size_t __spos=0,size_t __len=1){return this->__inStr.substr(__spos,__len);}
		string upper(void){string __temp;for(int __ii = 0;__ii < this->__inStr.size();__ii++){if(this->__inStr[__ii]<='z' && this->__inStr[__ii]>='a')	__temp.push_back(this->__inStr[__ii]-32);else	__temp.push_back(this->__inStr[__ii]);}return __temp;}
		string smaller(void){string __temp;for(int __ii = 0;__ii < this->__inStr.size();__ii++){if(this->__inStr[__ii]<='Z' && this->__inStr[__ii]>='A')	__temp.push_back(this->__inStr[__ii]+32);else	__temp.push_back(this->__inStr[__ii]);}return __temp;}
};

template<typename T>void print(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<__outputTarget<<end;}
template<typename T>bool input(T &__inputTarget){ios::sync_with_stdio(false);if(cin>>__inputTarget) return true;else return false;}
template<typename T>void print_float(const T __outputTarget,const int __decimalplaces=2,const char end='\n'){ios::sync_with_stdio(false);cout<<fixed<<setprecision(__decimalplaces)<<__outputTarget<<end;}
template<typename T>void print_fixed(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<fixed<<setprecision(0)<<__outputTarget<<end;}

template<class __type1,class __type2>class dictionary{
	private:
		__type1 *name;
		__type2 *data;
		string __noFounError_msg="[Error]In class dictionary: Can not find element with such name";
		long long __searching_in_dictionary(__type1 __at){for(int i=0;i<size;i++)if(this->name[i]==__at) return i;return -1;}
	public:
		unsigned size=0;
		unsigned MAX_SIZE=0;
		dictionary(){this->name=new __type1[10000];this->data=new __type2[10000];MAX_SIZE=10000;}
		dictionary(int __make_size){this->name=new __type1[__make_size];this->data=new __type2[__make_size];MAX_SIZE=__make_size;}
		void make_word(__type1 __Name,__type2 __Data){this->name[size]=__Name;this->data[size++]=__Data;}
		__type2 operator[](const __type1 __at){long long __res_of_searching=this->__searching_in_dictionary(__at);if(__res_of_searching==-1)  cout<<this->__noFounError_msg;else return this->data[__res_of_searching];}
		__type2 at(const __type1 __at){return this->operator[](__at);}
		__type2 at_subscript(const int __at){return this->data[__at];}
};
