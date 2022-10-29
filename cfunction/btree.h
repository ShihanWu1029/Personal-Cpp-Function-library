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
class BinaryTree{
    public:
        //Value type reloaded
        typedef __Ty Data_Type;//__Ty type to Data_Type
        typedef BinaryTree *BinaryTreePtr;//BinaryTree type's pointer to BinaryTreePtr
        typedef BinaryTree *BinaryTreeChild_Type;//Binary tree's child type
    private:
        BinaryTreeChild_Type Left_Child,Right_Child;
        Data_Type node_value;
    public:
        inline BinaryTreeChild_Type GetLeftChild(void){return this->Left_Child;}//Return left child
        inline BinaryTreeChild_Type GetRightChile(void){return this->Right_Child;}//Return right child
        inline BinaryTreeChild_Type SetLeftChild(Data_Type __value){
            //set left child's value
            this->Left_Child=new BinaryTree;
            this->Left_Child->node_value=__value;
            //set left child's children to NULL
            this->Left_Child->Left_Child=NULL;
            this->Left_Child->Right_Child=NULL;
            //return left child
            return this->Left_Child;
        }
        inline BinaryTreeChild_Type SetRightChild(Data_Type __value){
            //set Right child's value
            this->Right_Child=new BinaryTree;
            this->Right_Child->node_value=__value;
            //set Right child's children to NULL
            this->Right_Child->Left_Child=NULL;
            this->Right_Child->Right_Child=NULL;
            //return Right child
            return this->Right_Child;
        }
        ~BinaryTree(){
            //free the memory
            delete this->Left_Child;
            delete this->Right_Child;
            delete this;
        }
};
