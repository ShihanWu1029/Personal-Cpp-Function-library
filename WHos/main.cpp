#pragma once
#pragma optimize(2)

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include <stack>
#include <vector>

using namespace std;

struct tree;

template <typename type1 , typename type2> class user{
	private: vector<pair<type1,type2>> __vp;
	public:
		user(void) = default;
		user(const initializer_list<pair<type1,type2>> give){
			for(auto item : give)  __vp.push_back(item); 
		}
		bool check(const type1 usn,const type2 psw){
			for(auto item : __vp)  
				if(item==make_pair(usn,psw))
					return true;
			return false;
		}
};

ostream &print(const string text,ostream &istrm=cout){
	ios::sync_with_stdio(false);
	for(int i=0;i<text.size();i++){
		cout<<text[i]<<flush;
		Sleep(25); 
	}
//	cout<<endl;
} 

class cmd{
	private:
		stack<string> rec_cmd;
	public:
		cmd(void) = default;
		
};

int main(){
	ios::sync_with_stdio(false);
	user<string,string> user_list={
		{"admin","administrator",},
		{"guest","123456"}
	};
	print("==========\n");
	print("Welcome to WHos!\n");
	print("You haven't login.\n");
	print("Please login if you want to use WHos!\n");
	print("==========\n");
	string *usn=new string();
	string *psw=new string();
	while(!user_list.check(*usn,*psw)){
		print("Username: >");
		cin>>*usn;
		print("Password: >");
		cin>>*psw;
		if(user_list.check(*usn,*psw)){
			break;
		}else{
			printf("Username wrong or password wrong.\n");
		}
	}
	print("Login successfully!\nWelcome ");
	print(*usn);
	print(".");
	return 0;
}
