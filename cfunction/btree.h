//<btree.h> -*- C++ -*-

//Copyright (c) 2022 iNeverNobody, Github.
//
//
/** 
 *  @file btree.h
 *  This is a headfile of binary tree.
 *  @author iNeverNobody
 *  @version beta
 *  @copyright GNU Public License V3.0
 *  @date 2022/10/29
**/
//!> Next is the class of binary tree.
template<typename __Ty>
struct BinaryTree{
    public:
        //Value type reloaded
        typedef __Ty Data_Type;//__Ty type to Data_Type
        typedef BinaryTree *BinaryTreePtr;//BinaryTree type's pointer to BinaryTreePtr
        typedef BinaryTree *BinaryTreeChild_Type;//Binary tree's child type
        BinaryTreeChild_Type Left_Child,Right_Child;
        Data_Type value;
};
