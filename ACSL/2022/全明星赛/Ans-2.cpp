/*
名称 波浪 

题目描述
	给定一列整数，将这些数字呈波浪式排列，即数字依次按照升
序、降序、升序和降序进行排列，以此类推。给定一个数字N 和一
列数字，将前 N 个数字升序排列；接下来的 N-1 个数字降序排列；
之后的 N-2 个数字升序排列；N-3 个数字降序排列。当波浪长度只
有一个元素时，停止该过程，并将剩下的数字按照与前一个波浪相
反的方向重新排列。如果列表中的数字不能排列成完整的波浪，在
其后面增加一列原有的数字，继续排列，直到形成长度为 1 的波浪。

输入: 一个正整数 N（第一个波浪的长度）和一列整数，每个整数之
间由一个空格分隔。数列中的整数最多有 100 个

输出: 一个新的字符串，表示组成的新数列，如上述所示，每个整
数之间由一个空格分隔。

样本输入
6 3 14 1 59 26 535 8 97 932 38 462 64 3 3 83 279 50 288 4 19 716 939 9 37510 

5 3 14 1 59 26 535 8 97 932 38 462 64 3 3 83 279 50 288 4 19 716 939 9 37510 

8 3 14 1 59 26 535 8 97 932 38 462 64 3 3 83 279 50 288 4 19 716 939 9 37510

6 3 1 4 1 5 9 2 6

9 3 141 5926 535 89 72 3 846 26 43 383 27 

样本输出
1 3 14 26 59 535 932 462 97 38 8 3 3 64 83 288 279 50 4 19 716 9 939 37510

1 3 14 26 59 932 535 97 8 38 64 462 3 3 83 37510 939 716 288 279 50 19 9 4

1 3 8 14 26 59 97 535 932 462 83 64 38 3 3 4 19 50 279 288 716 37510 939 14 9 3 1 26 59 535 932 97 8 38 462 64 3 3 4 9 19 50 83 279 288 716 939 37510

1 1 3 4 5 9 6 4 3 2 1 1 2 5 9 6 3 1 1 4 5 2 6 9

3 3 26 72 89 141 535 846 5926 5926 535 383 141 89 43 27 3 3 26 27 43 72 383 846 5926 535 141 89 72 3 3 26 43 383 846 5926 141 27 3 72 89 535 846 3 26 383 43 27 
*/ 
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
void copyy(long long *a,int addr){for(int i=0;i<addr;i++)  a[addr+i]=a[i];}
bool cmp1(long long a,long long b){return a<b;}
bool cmp2(long long a,long long b){return a>b;}
void get_plus(long long size,long long tag,long long &plus){
	for(int i=1;i<=size;i++){
		if(abs(size*i-tag)<size){
			if(cmp1(abs(size*i-tag),abs(size*i+size-tag))){
				plus=abs(size*i-tag);
			}else{
				plus=abs(size*i+size-tag);
			}
		}
	}
}
long long to_num(string a){
	long long record_=0;
	for(int i=0;i<a.size();i++) record_+=pow(10,a.size()-1-i)*(a[i]-'0');
	return record_;
}
int main(){
	ios::sync_with_stdio(false);
	string input;
	getline(cin,input);
	long long n,a[100000]={0},how_many=0,size=0,mod=0,topOfa=0,s=0,plus=3;
	int st=-1,len=0,flag=1;
	for(int i=0;i<input.size();i++){
		if(st==-1)  st=i;
		if(input[i]!=' ') len++;
		if(input[i]==' '){
			if(flag){
				flag=0;
				n=to_num(input.substr(st,len));
				st=i+1;
				len=0;
			}else{
				a[topOfa++]=to_num(input.substr(st,len));
				st=i+1;
				len=0;
				how_many++;
			}
		}
	}
	how_many++,mod=1;
	a[topOfa]=to_num(input.substr(st,len)),size=how_many;
	if(how_many==1){
		for(int i=0;i<((n*(n-1)/2));i++)  cout<<a[0]<<" ";
		return 0;
	}
	for(int i=0;i<5;i++){
		if(size>100000) break;
		copyy(a,size);
		size+=size;
	}
	for(int i=n;i>=1;i--){
		if(mod%2==1)  sort(a+s,a+s+i,cmp1);
		else  sort(a+s,a+s+i,cmp2);
		s+=i,mod++;
	}
	get_plus(how_many,s,plus);
	if(mod%2==1)  sort(a+s,a+s+plus,cmp1);
	else  sort(a+s,a+s+plus,cmp2);
	for(int i=0;i<s+3;i++){
		cout<<a[i];
		if(i!=s+2)  cout<<" ";
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
*/
