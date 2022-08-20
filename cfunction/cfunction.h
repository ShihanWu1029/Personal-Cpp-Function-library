#include <cmath>
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
		friend bool operator<(const crdinate __self,const crdinate __anthr);
		friend bool operator>(const crdinate __self,const crdinate __anthr);
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
