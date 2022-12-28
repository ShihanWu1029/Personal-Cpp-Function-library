//<Basic.cpp> -*- rC++ -*-

//Copyright (c) 2022 iNeverNobody, Github.
//
//
/** 
 *  @file Basic.cpp
 *  This headfile define the part of basic grammer.
 *  Suggest C++14 at least.
 *  @author iNeverNobody
 *  @version v1.0
 *  @copyright GNU Public License V3.0
 *  @date 2022/12/28
**/
//namespace
#define import using namespace
#define newNamespace namespace
#define startNamespace {
#define endNamespace }

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
#define Argument_list(__Argument_list) (__Argument_list)
#define Argument_list_with_2(__Argument_list1,__Argument_list2) (__Argument_list1,__Argument_list2)
#define Argument_list_with_3(__Argument_list1,__Argument_list2,__Argument_list3) (__Argument_list,__Argument_list2,__Argument_list3)

//line end
#define end ;