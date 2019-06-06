//
// Created by Bar The magical on 05/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_UNIONFIND_H
#define WET2_DATA_STRUCTURES_UNIONFIND_H

#include "Array.h"
#include <cassert>

class UnionFindNode{
public:
    int u_index;
    UnionFindNode* u_parent;
    int numOfChildren;
    UnionFindNode(const int& index, UnionFindNode* parent = nullptr) : u_index(index), u_parent(parent), numOfChildren(0){}

};


template <typename T>
class UnionFind {
    Array<UnionFindNode*> u_elementArr;
    Array<T*> u_dataArr;
    int u_numOfElements;

public:

    UnionFind(const int& numOfElements = 0) :u_numOfElements(0){
        u_elementArr = Array<UnionFindNode*>(numOfElements);
        u_dataArr = Array<T*>(numOfElements);

        for(int i = 0; i < numOfElements; i++){
            u_elementArr[i] = new UnionFindNode(i, nullptr);
            u_dataArr[i] = new T();
        }
    }

    UnionFind(const UnionFind& aUnionFind){
        u_numOfElements = aUnionFind.u_numOfElements;
        u_elementArr = Array<UnionFindNode*>(u_numOfElements);
        u_dataArr = Array<T*>(u_numOfElements);

        for(int i = 0; i < u_numOfElements; i++){
            u_elementArr[i] = new UnionFindNode(i, nullptr);
            u_dataArr[i] = new T(aUnionFind.u_dataArr[i]);
        }

        for(int i = 0; i < u_numOfElements; i ++){
            //go over each element in aUnionFind, and find its root. make that the root of the corresponding element in this union find
            UnionFindNode* iterator = aUnionFind.u_elementArr[i]->u_parent;
            UnionFindNode* root = nullptr;
            while(iterator != nullptr){
                root = iterator;
                iterator = root->u_parent;
            }
            if(root != nullptr) {
                //make this nodes parent the correct parent
                u_elementArr[i]->u_parent = u_elementArr[root->u_index];
                u_elementArr[root->u_index]->numOfChildren++;
                //point its data at the root data and delete previous data
                T* temp = u_dataArr[i];
                u_dataArr[i] = u_dataArr[root->u_index];
                delete temp;


            }
        }
    }

    ~UnionFind(){
        for(int i = 0; i < u_numOfElements; i++){
            //if this is root delete its data
            if(u_elementArr[i]->u_parent == nullptr){
                delete u_dataArr[i];
            }
        }
        for(int i = 0; i < u_numOfElements; i++){
            delete u_elementArr[i];
        }
    }

    UnionFind& operator=(const UnionFind& aUnionFind){

        for(int i = 0; i < u_numOfElements; i++){
            //if this is root delete its data
            if(u_elementArr[i]->u_parent == nullptr){
                delete u_dataArr[i];
            }
        }
        for(int i = 0; i < u_numOfElements; i++){
            delete u_elementArr[i];
        }

        u_numOfElements = aUnionFind.u_numOfElements;
        u_elementArr = Array<UnionFindNode*>(u_numOfElements);
        u_dataArr = Array<T*>(u_numOfElements);

        for(int i = 0; i < u_numOfElements; i++){
            u_elementArr[i] = new UnionFindNode(i, nullptr);
            u_dataArr[i] = new T(aUnionFind.u_dataArr[i]);
        }

        for(int i = 0; i < u_numOfElements; i ++){
            //go over each element in aUnionFind, and find its root. make that the root of the corresponding element in this union find
            UnionFindNode* iterator = aUnionFind.u_elementArr[i]->u_parent;
            UnionFindNode* root = nullptr;
            while(iterator != nullptr){
                root = iterator;
                iterator = root->u_parent;
            }
            if(root != nullptr) {
                //make this nodes parent the correct parent
                u_elementArr[i]->u_parent = u_elementArr[root->u_index];
                u_elementArr[root->u_index]->numOfChildren++;
                //point its data at the root data and delete previous data
                T* temp = u_dataArr[i];
                u_dataArr[i] = u_dataArr[root->u_index];
                delete temp;
            }
        }
    }

    T& find(const int& index){
        if (index > u_numOfElements-1 || index < 0){
            throw IllegalIndex();
        }
        Array<UnionFindNode*> nodesToConnect = Array<UnionFindNode*>(u_numOfElements);
        UnionFindNode* iterator = u_elementArr[index];
        int numOfChildren = 0;

        while(iterator->u_parent != nullptr){
            nodesToConnect[numOfChildren] = iterator;
            numOfChildren++;
            iterator = iterator->u_parent;
        }

        assert(iterator->numOfChildren == numOfChildren);

        while(numOfChildren != 0){
            nodesToConnect[numOfChildren]->u_parent = iterator;
            u_dataArr[nodesToConnect[numOfChildren]->u_index] = u_dataArr[iterator->u_index];
            numOfChildren--;
        }

        return u_dataArr[iterator->u_index];
    }

    void unite(const int& index1, const int& index2){
        UnionFindNode* firstRoot = u_elementArr[index1];
        UnionFindNode* secondRoot = u_elementArr[index2];

        while(firstRoot->u_parent != nullptr){
            firstRoot = firstRoot->u_parent;
        }

        while(secondRoot->u_parent != nullptr){
            secondRoot = secondRoot->u_parent;
        }

        UnionFindNode* biggerRoot;
        UnionFindNode* smallerRoot;

        firstRoot->numOfChildren > secondRoot->numOfChildren ? biggerRoot = firstRoot, smallerRoot = secondRoot : biggerRoot = secondRoot, smallerRoot = secondRoot;

        smallerRoot->u_parent = biggerRoot;
        biggerRoot->numOfChildren += smallerRoot->numOfChildren;
    }
};


#endif //WET2_DATA_STRUCTURES_UNIONFIND_H
