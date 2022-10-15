#pragma once
#pragma optimize(2)
#pragma 

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include <stack>
#include <vector>

using namespace std;

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
		istrm<<text[i]<<flush;
		Sleep(10); 
	}
	return istrm;
//	cout<<endl;
} 

class cmd{
	private:
		stack<string> rec_cmd;
	public:
		cmd(void) = default;
		operator ()(const string __what){
			return system(__what.c_str());
		}
};

class error_t{
	private:
		string defaultString = "[Error]";
		string whats="Unexpected runtime error!";
		bool error=false;
	public:
		error_t (void){}
		error_t (const string __what){this->whats = __what;this->error=true;}
		string what(void){return this->whats;}
		bool isError(void){return this->error;} 
		operator string() {return this->whats;} 
};

int login(void) noexcept{
	ios::sync_with_stdio(false);
	user<string,string> user_list={
		{"admin","administrator",},
		{"guest","123456"}
	};
	print("============\n");
	print("Welcome to WHos!\n");
	print("You haven't login.\n");
	print("Please login if you want to use WHos!\n");
	print("============\n");
	string *usn=new string();
	string *psw=new string();
	int cnt=0;
	while(cnt<=10){
		print("Username: >");
		cin>>*usn;
		print("Password: >");
		cin>>*psw;
		if(user_list.check(*usn,*psw)){
			break;
		}else{
			printf("Username wrong or password wrong.\n");
		}
		cnt++;
	}
	if(! cnt<=10) return -1;
	print("Login successfully!\nWelcome ");
	print(*usn);
	print("."); 
	return ((*usn)=="admin"?0:1);
}
cmd main_cmd;
int main(){
	int get=login();
	if(get==-1){
		print("\nToo more time to try!The system will exit in 3second!Bye.");
		Sleep(3000); 
		return 0;
	}
	
	return 0;
}
