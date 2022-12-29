//<Function.cpp> -*- rC++ -*-

//Copyright (c) 2022 iNeverNobody, Github.
//
//
/** 
 *  @file Function.cpp
 *  This headfile define the part of function externing.
 *  Suggest C++14 at least.
 *  @author iNeverNobody
 *  @version v1.0
 *  @copyright GNU Public License V3.0
 *  @date 2022/12/28
**/
//Main Function
#define main int main(
#define mainArgument int argv,char* argc[]
#define startMain ){
#define endMain return 0;}

//function
#define startFunc {
#define endFunc }
#define func void
#define return_type(__Return_Type) __Return_Type
#define usingFunction(__Function_name) __Function_name

//Argument list
#define noArg ()
#define startArgList (
#define endArgList )
#define argAnd ,