#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
using std::string;
using std::cout;
using std::cin;
using std::fixed;
using std::ios;
using std::setprecision;
using std::istream;
using std::ostream;
using std::__is_integer;
using std::stack;
using std::queue;
const unsigned long long inf=0x7ffffffff;

template<typename T>inline long double maxof(T __firstInput,T __secondInput){		//返回两数中的较大值 
	return (__firstInput>__secondInput?__firstInput:__secondInput);
}
template<typename T>inline long double minof(T __firstInput,T __secondInput){		//返回两数中的较小值 
	return (__firstInput<__secondInput?__firstInput:__secondInput);
}
template<typename T>inline long double sumof(T N1,T N2){
	return N1+N2;
}
template<typename T>inline void swapp(T &a,T &b){
	T temp=a;a=b;b=temp;
}
template<typename T>inline int  comparee(T a,T b){
	return (a>b?1:(a==b?0:-1));
}
template<typename T>inline bool isEaqual(T a,T b){
	return a==b;
}

inline bool isLetter(char c){
	return (c>='a'&& c<='z' || c>='A' && c<='Z');
}
inline bool isLetterSmall(char c){
	return (c>='a' && c<='z');
}
inline bool isLetterBig(char c){
	return (c>='A' && c<='Z');
}
inline bool isNumber(char c){
	return (c>='0' && c<='9');
}

unsigned long long to_num(string __tag){
	unsigned long long __record=0;
	for(int i=0;i<__tag.size();i++)  __record+=pow(10,__tag.size()-1-i)*(__tag[i]-'0');
	return __record;
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
		inline XType get_X(void){return this->__Xpos;}
		inline YType get_Y(void){return this->__Ypos;}
		crdinate get(void){return *this;}
		inline long double distance_between(crdinate __other){tmp_betw=sqrt((this->__Xpos-__other.__Xpos)*(this->__Xpos-__other.__Xpos)+(this->__Ypos-__other.__Ypos)*(this->__Ypos-__other.__Ypos));return tmp_betw;}
		inline bool operator==(const crdinate __anthr){return (this->__Xpos==__anthr.__Xpos && this->__Ypos==__anthr.__Ypos);}
		inline bool operator<=(const crdinate __anthr){return (this->__Xpos<=__anthr.__Xpos && this->__Ypos<=__anthr.__Ypos);}
		inline bool operator>=(const crdinate __anthr){return (this->__Xpos>=__anthr.__Xpos && this->__Ypos>=__anthr.__Ypos);}
		inline XType operator[](int __get){if(__get>2 || __get<0) return 0;if(__get==0) return this->__Xpos;else return this->__Ypos;}
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
class counter{
	private:
		unsigned long long __inCounterr;
	public:
		counter(){this->__inCounterr=0;}
		inline void counter_reset(void){this->__inCounterr=0;}	//重置计数器为0 
		inline void counter_startAt(unsigned long long __startAt){this->__inCounterr=__startAt;}		//设置计数器为输入的数 
		inline void counter_plus(void){this->__inCounterr++;}	//将计数器加一
		inline void counter_plus_step(int __step){this->__inCounterr+=__step;}	//将计数器加Step 
		inline unsigned long long get_counter(void){return this->__inCounterr;}	//获取计数器累加的值
};

template<class type>class list{
	private:
		type *__a;
		unsigned __SSize=0;
	public:
		bool isSet=false;
		list(){		}
		list(int __size){this->__a=new type[__size+1];isSet=true;this->__SSize=__size;}
		void set_length(int __size){if(!isSet){this->__a=new type[__size+1];isSet=true;this->SSize=__size;}}
		inline type operator[](const unsigned __at){return this->__a[__at];}
		inline void set(type __at,type __value=0){this->__a[__at]=__value;}
		inline type at(unsigned __at){return this->__a[__at];}
		void reset_list(void){for(int __ii=0;__ii<=this->__SSize;__ii++)this->__a[__ii]=0;}
		void clear(void){delete this->__a;delete this;}
};

class str{
	private:
		string __inStr="";
	public:
		unsigned long long npos;
		str(){this->npos=this->__inStr.npos;}
		str(const string __give){this->__inStr=__give;this->npos=this->__inStr.npos;}
		str(const string __give,const int __times){for(int __ii=0;__ii<__times;__ii++)for(int __jj=0;__jj<__give.size();__jj++)this->__inStr.push_back(__give[__jj]);}
		inline void refresh_npos(void){this->npos=this->__inStr.npos;}
		inline void set(const string __given){this->__inStr=__given;}
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

template<typename T>void cprint(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<__outputTarget<<end;}
template<typename T>bool cinput(T &__inputTarget){ios::sync_with_stdio(false);if(cin>>__inputTarget) return true;else return false;}
template<typename T>void cprint_float(const T __outputTarget,const int __decimalplaces=2,const char end='\n'){ios::sync_with_stdio(false);cout<<fixed<<setprecision(__decimalplaces)<<__outputTarget<<end;}
template<typename T>void cprint_fixed(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<fixed<<setprecision(0)<<__outputTarget<<end;}

typedef string error_msg;
template<class __type1,class __type2>class dictionary{//字典 
	private:
		__type1 *name;//存储key
		__type2 *data;//存储数据
		const error_msg __noFounError_msg="[Error]In class dictionary: Can not find element with such name.\n";
		const error_msg __overloadError_msg="[Error]In class dictionary: Try to push elements after size comes to the max_size.Overload.\n";
		long long __searching_in_dictionary(__type1 __at){for(int i=0;i<size;i++)if(this->name[i]==__at) return i;return -1;}//用于在字典中查找__at并返回下标 (O(size))
	public:
		unsigned size=0;//存字典大小
		unsigned MAX_SIZE=0;//存最大大小 
		dictionary(){this->name=new __type1[10000];this->data=new __type2[10000];MAX_SIZE=10000;}//默认大小10000 
		dictionary(int __make_size){this->name=new __type1[__make_size];this->data=new __type2[__make_size];MAX_SIZE=__make_size;}//构造 
		void make_word(__type1 __Name,__type2 __Data){this->name[size]=__Name;this->data[size++]=__Data;}//添加成员 
		void append_dictionary(dictionary __rec){int __lenof=__rec.size;for(int i=0;i<__lenof;i++){if(size>=MAX_SIZE){cout<<this->__overloadError_msg;return;}this->make_word(__rec.get_name(i),__rec.at_subscript(i));}}//用于在字典中添加另一字典类 
		__type2 operator[](const __type1 __at){long long __res_of_searching=this->__searching_in_dictionary(__at);if(__res_of_searching==-1)  cout<<this->__noFounError_msg;else return this->data[__res_of_searching];}//重载下标运算符 
		__type2 at(const __type1 __at){return this->operator[](__at);}//at函数 
		__type2 at_subscript(const int __at){if(__at>=size){return __type2(0);}return this->data[__at];}//通过下标找元素 
		__type1 get_name(const int __at){if(__at>=size){return __type1(0);}return this->name[__at];}//获取key
		long long finding(const __type1 __what){return this->__searching_in_dictionary(__what);}//找__what的下标
		ostream &print(ostream &os,const char end='\n'){os<<"{";for(int i=0;i<size;i++){os<<this->get_name(i)<<": "<<this->at_subscript(i);if(i!=size-1)  cout<<" , ";}os<<"}"<<end;}
		istream &read(istream &is,const unsigned __tag_size,const bool __colon_input=false){int __tag=(__tag_size+size>MAX_SIZE?MAX_SIZE:__tag_size);char rec_colon;__type1 __rec1;__type2 __rec2;for(int i=size;i<__tag;i++){if(__colon_input) is>>__rec1>>rec_colon>>__rec2;else is>>__rec1>>__rec2;this->make_word(__rec1,__rec2);}}
		void clear(void){delete this->name;delete this->data;delete this;}
};
template<typename _T1,typename _T2>dictionary<_T1,_T2> make_dictionary(_T1 __name,_T2 __data){
	dictionary<_T1,_T2> __res(1);
	__res.make_word(__name,__data);
	return __res;
}//用于制造字典
template<typename _T1,typename _T2>dictionary<_T1,_T2> make_dictionary(_T1 __name,_T2 __data,_T1 __name1,_T2 __data1){
	dictionary<_T1,_T2> __res(2);
	__res.make_word(__name,__data);
	__res.make_word(__name1,__data1);
	return __res;
}//用于制造字典

struct math{
	const long double e=2.71828182845904523536;
	const long double inf=1.7969e+308;
	const long double nan=sqrt(-1.0);
	const long double pi=3.1415926535897932384;
	const long double tau=pi*2;
	
	template<typename T>long double exp(T __x){return (long double)pow(e,__x);}
//	template<typename T>long double abs(T __x){return abs(__x);}
// 	改fabs
	template<typename T>long double Abs(T __x){return fabs(__x);} 
	template<typename T>long long   gcd(T __x,T __y){if(__y) while((__x%=__y) && (__y%=__x)); return __x+__y;}
	template<typename T>long long floor(T __x){return int(__x);}
	template<typename T>long long  ceil(T __x){if(int(__x)==__x) return __x;else return int(__x)+1;}
	long double factorial(short __x){long double __count=1;for(int j=__x;j>0;j--)__count*=j;return __count;}
//	template<typename T>long double sqrt(T __x){return sqrt(__x);}
//	↑sqrt函数会卡死(Why??)
 	template<typename _Tp>inline _GLIBCXX_CONSTEXPR typename __gnu_cxx::__enable_if<__is_integer<_Tp>::__value, double>::__type Sqrt(_Tp __x)
	{ return __builtin_sqrt(__x); }
//	template<typename T>inline long double fabs(T __x) {return fabs(__x);}
//	已将fabs作用于abs 
	long double pow(int __base,int __get){long double record=1;for(int i=1;i<=__get;i++)record*=__base;return record;}
	long double CmtoIn(float __Cm){return (long double)__Cm*0.3937;}
//	将厘米转换英尺
};

template<typename T>ostream &display_array(ostream &os,T *__arr,unsigned __sizeof,unsigned __startat=0,const char split=' ',const char end=' '){
	ios::sync_with_stdio(false);
	for(int i=0;i<__sizeof;i++)  os<<__arr[i]<<((i==__sizeof-1)?end:split);
}

template<class type>class Stack{
	private:
		stack<type> __stack;
	public:
		inline void push(type __data){this->__stack.push(__data);}
		inline type pop(void){type __tmp=this->__stack.top();this->__stack.pop();return __tmp;}
		inline type top(void){return this->__stack.top();}
		inline bool empty(void){return this->__stack.empty;}
		const size_t size=this->__stack.size();
};

template<class type>class Queue{
	private:
		queue<type> __queue;
	public:
		inline void push(type __data){this->__queue.push(__data);}
		inline type pop(){type tmp=this->__queue.front();this->__queue.pop();return tmp;}
		inline type front(){return this->__queue.front();}
		inline bool empty(){return this->__queue.empty();}
		inline size_t size(){return this->__queue.size();}
		inline type back(){return this->__queue.back();}
}; 
