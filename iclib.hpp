//Maybe you can read 'BeforeUsingIclib.md'first
//你也许可以先阅读“BeforeUsingIclib.md”
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstring>
#include <algorithm>
using namespace std;

/*
icLib
	Author: iNeverNobody
*/
long long pow(int __firstnumber,int __powernumber){//返回a的b次方（不支持小数） 
	long long record=1;
	for(int i=1;i<=__powernumber;i++){
		record*=__firstnumber;
	}
	return record;
}
void pass(){	}//跳过 
void over(){//代码结束模板 
	cout<<"\n\n";
	system("pause");
}
void delay(int time_ms){//等待time_ms毫秒 
	Sleep(time_ms);
}
void ldelay(int time_sec){//等待time_sec秒 
	Sleep(time_sec*1000);
}
void sdelay(double time_us){//等待time_us微秒 
	Sleep(time_us/1000);
}
float BMI(float height_cm,float weight_kg,bool ReturnOrNot){                    //求BMI指数 
	float height_m=height_cm/100.0;
	double BMI=weight_kg*1.0/(height_m*height_m);
	if(ReturnOrNot){
		if(BMI<=18.4){
			return 0;
		}else if(BMI<23.9){
			return 1;
		}else if(BMI<27.9){
			return 0;
		}else{
			return 0;
		}
	}else{
		return BMI;
	}
}
unsigned long long factorial(int i){//返回整数阶乘 
	unsigned long long count=1;
	for(int j=i;j>0;j--){
		count*=j;
	}
	return count;
}
long double factorial(float i,int step){//返回小数阶乘，每次减step 
	long double count=1;
	for(int j=i;j>0;j-=step){
		count*=j;
	}
	return count;
}
float CmToIn(float a){//厘米转英尺 
	return a*0.3937;
}
long long to_num(string a){//将字符串转换为数字 
	long long record_=0;
	int len=a.size()-1;
	for(int i=0;i<=len;i++){
		record_+=pow(10,len-i)*(a[i]-'0');
	}
	return record_;
}
long long to_num(char a[]){// 将C风格字符串转换为数字 
	long long record_=0;
	int len=strlen(a)-1;
	for(int i=0;i<=len;i++){
		record_+=pow(10,len-i)*(a[i]-'0');
	}
	return record_;
}
int to_num(char a){
	return a-'0';
}
void sort_bubble(int a[],int __size){//冒泡排序 
	int time=__size-1;
	for(int i=0;i<__size-1;i++){
		for(int j=0;j<time;j++){
			if(a[j]>a[j+1]){//检测到相邻逆序对 
				swap(a[j],a[j+1]);//交换 
			}
		}
		time--;
	}
}
void sort_choise(int a[],int __size){//选择排序 
	int rec=0;
	for(int i=0;i<__size-1;i++){
		rec=i;
		for(int j=i;j<__size;j++){
			if(a[j]<a[rec]){
				rec=j;
			}
		}//寻找最小值 
		if(rec!=i){
			swap(a[i],a[rec]);
		}//交换 
	}
}
void display(int a[],int num,bool IsNeedToPlusSpaceInTheEnd){
	for(int i=0;i<num;i++){
		if(i==num-1 && IsNeedToPlusSpaceInTheEnd==false)  cout<<a[i];
		else  cout<<a[i]<<' ';
	}
}//显示数组 
void display(float a[],int num,bool IsNeedToPlusSpaceInTheEnd){
	for(int i=0;i<num;i++){
		if(i==num-1 && IsNeedToPlusSpaceInTheEnd==false)  cout<<a[i];
		else  cout<<a[i]<<' ';
	}
}//同上 
void insertion_sort(int a[],int __size){
	for(int i=0;i<__size;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 and key<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}//插入排序 
void tong_sort(int a[],int __size){
	int t[100000]={0};
	for(int i=0;i<__size;i++){
		t[a[i]]++;
	}
	int top=0;
	for(int i=0;i<100000;i++){
		while(t[i]>0){
			a[top++]=i;
			t[i]--;
		}
	}
}//桶排序 
int flatis(string __str,char __letter){//在字符串__str中找__letter出现的次数 
	int __count=0;
	for(int i=0;i<__str.size();i++){
		if(__str[i]==__letter){
			__count++;
		}
	}
	return __count;
}
class intStack{//数字类型栈 
	private:
		int __arr[100001]={0};int __top=0;
	public:
		inline int size(){
			return this->__top;//返回栈数据量 
		}
		inline int top(){
			return this->__arr[(this->__top-1)];
		}//返回栈顶元素（不弹出） 
		inline int at(unsigned int addr){
			return this->__arr[addr-1];//返回第addr个值 
		}
		inline int pop(){
			if(this->__top>0){
				int tmp=this->__arr[this->__top-1];
				this->__arr[this->__top-1]=0;
				this->__top-=1;
				return tmp; 
			}else if(this->__top==0){
				cout<<"Error: At class intStack, Empty array!There's nothing to pop."<<endl;return 0;
			}else{
				cout<<"Error: At class intStack, __top shouldn't smaller than 0!Excepted error.";return 0;
			}
		}//弹出
		inline void push(int __number){
			if(this->__top>100000){
				cout<<"Warning: At class intStack, __top is bigger than the max element you can put.";return;
			}
			this->__arr[this->__top++]=__number;
		}//推入
		inline int* last(){
			return &(this->__arr[0]);
		}//返回栈底地址 
		inline int* first(){
			if(this->__top==0)  return &(this->__arr[0]);
			else return &(this->__arr[this->__top-1]);
		}//返回栈顶地址 
		inline bool empty(){
			if(this->__top>=0){
				return this->__top==0;
			}else{
				cout<<"Error: At class intStack, __top shouldn't smaller than 0!Excepted error.";return 0;
			}
		}//返回是否为空 
};
struct linkedList_node{
	long long data;
	linkedList_node *next;
};
struct linkedList_node_2way{
	long long data;
	linkedList_node_2way *next,*pre;
};
