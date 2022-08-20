#include <iostream>
using namespace std;

/*************************************************Input and Output***************************************************************/
template<typename T>void print(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<__outputTarget<<end;}
template<typename T>bool input(T &__inputTarget){ios::sync_with_stdio(false);if(cin>>__inputTarget) return true;else return false;}
/***************************************************end line**********************************************************************/

class kw{
	private:
		string __kwlist="False None True and as assert break class continue def del elif else except finally for from global if import in is lambda nonlocal not or pass raise return try while with yield";
	public:
		string kwlist(void){return "['False', 'None', 'True', 'and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']";}
		bool isKeyword(const string __tag){
			if(this->__kwlist.find(__tag)==this->__kwlist.npos)  return false;
			else return true;
		}
};
kw keyword;
