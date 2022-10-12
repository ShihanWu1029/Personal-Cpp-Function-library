#pragma once
#pragma optimize(2)

#include <iostream>
#include <windows.h>

class cmd_base{
	public:
		cmd_base(const string __cmd , const string __re) : default_command(__cmd) , default_back(__re){}
		void cmd_do(const string __command) {system(__command.c_str());}
		void cmd(void){system(default_command.c_str());}
	protected:
		string default_command,default_back;
};

int main(){
	
}
