#include <iostream>
using namespace std;

template<typename T>void print(const T __outputTarget,const char end='\n'){ios::sync_with_stdio(false);cout<<__outputTarget<<end;}
template<typename T>bool input(T &__inputTarget){ios::sync_with_stdio(false);if(cin>>__inputTarget) return true;else return false;}
