//
// Created by Bar The magical on 05/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_UNIONFIND_H
#define WET2_DATA_STRUCTURES_UNIONFIND_H

#include "Array.h"

class UnionFindNode{
public:
    int u_index;
    UnionFindNode* u_parent;
    UnionFindNode(const int& index, UnionFindNode* parent = nullptr) : u_index(index), u_parent(parent){}
};


template <typename T>
class UnionFind {
    Array<UnionFindNode*> u_elementArr;
    Array<T> u_
};


#endif //WET2_DATA_STRUCTURES_UNIONFIND_H
