//<tree.h> -*- C++ -*-

//Copyright (c) 2022 iNeverNobody, Github.
//
//
/** 
 *  @file tree.h
 *  This is a headfile of tree.
 *  @author iNeverNobody
 *  @version beta
 *  @copyright GNU Public License V3.0
 *  @date 2022/12/20
**/
namespace std{
    //Class of tree
    template<typename __valueType>
    class ctree{
        public:
            ctree() =delete;//Can't use without telling a child number.
            ctree(const int size){this->a=new ctree[size];}
            typedef ctree *treeChildType;
            typedef __valueType treeValueType;
            treeChildType a;
            treeValueType value;
    };
}