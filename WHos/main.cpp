#pragma once
#pragma optimize(2)
#pragma 

#include <iostream>
#include <cstdio>

#ifdef _WIN32
#include <windows.h>
#endif

#include <stack>
#include <vector>

using namespace std;


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


template <typename type1 , typename type2> class listed{
	private: vector<pair<type1,type2>> __vp;
	public:
		listed(void) = default;
		listed(const initializer_list<pair<type1,type2>> give){
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
		if(istrm<<text[i]<<flush);
		else throw error_t("[Error] Exception happens when output!");
		Sleep(10); 
	}
	return istrm;
//	cout<<endl;
} 

class cmd{
	private:
		void noSpace(string &tag){
			for(int i=0;i<tag.size();i++){
				if(tag[i]==' ') tag.erase(i,1);
				else break;
			}
 		}
 		vector<string> get_canshu(string th){
 			int cnt=0,cnt2=0,cntpos=0;
		 	bool flag=false;
			vector<string> ret;
			//BUG DOWN HERE!!!!!
			for(int i=0;i<th.size();i++){
				if(flag && th[i]!=' '){
					flag=false;
					cntpos=i;
				}
				if(!flag && th[i]!=' '){
					cnt++;
				}
				if(th[i]==' ' && !flag){
					flag=true;
					ret.push_back(th.substr(cntpos,cnt));//SomeBug Here
					cout<<(ret.back())<<endl;
					cnt=0;
				}
			}
			return ret;
		}
	public:
		cmd(void) = default;
		operator ()(string __what){
			for(int i=0;i<__what.size();i++){
				if(__what[i]==' ') __what.erase(i,1);
				else break;
			}
			/*vector<string> canshu=*/get_canshu(__what);
//			string command=get_command(__what);
		}
};


//login function
int login(void){
	ios::sync_with_stdio(false);
	listed<string,string> user_list={
		{"admin","administrator",},
		{"guest","123456"}
	};
	print("============\n");
	print("Welcome to WHos!\n");
	print("You haven't login.\n");
	print("Please login if you want to use WHos!\n");
	print("============\n");
	string *usn=new string();//record username
	string *psw=new string();//record password
	int cnt=0;
	while(cnt<=10){
		print("Username: >");
		if(cin>>*usn);
		else{
			delete usn;
			delete psw;
			throw error_t("[Error] Excepted input type!");
		}	
		print("Password: >");
		if(cin>>*psw);
		else{
			delete usn;
			delete psw;
			throw error_t("[Error] Excepted input type!");
		}
		if(user_list.check(*usn,*psw)){
			break;
		}else{
			printf("Username wrong or password wrong.\n");
		}
		cnt++;
	}
	if(cnt>=10) return -1;
	print("Login successfully!\nWelcome ");
	print(*usn);
	print(".\n"); 
	return ((*usn)=="admin"?0:1);
}
cmd main_cmd;
bool isAdmin=false;
int main(){
	system("color 0A");
	system("title WHos");
	int get;
	try{
		get=login();
	}catch(error_t error){
		cerr<<error.what()<<endl;
		Sleep(3000);
		return 0;
	}
	if(get==-1){
		print("Too more time to try!The system will exit in 3second!Bye.\n");
		Sleep(3000); 
		return 0;
	}else{
		isAdmin=(get==0?true:false);
		cin.ignore();
//		cout<<boolalpha<<isAdmin<<noboolalpha;
		while(true){
			//main code here!
			try{
				print("C: > ");
				string what;
				getline(cin,what);
				if(what.find("exit") != what.npos) return 0;
				main_cmd(what);
			}catch(error_t error){
				cerr<<error.what()<<endl;
				Sleep(3000);
				return 0;
			}
		}
	}
	
	return 0;
}
