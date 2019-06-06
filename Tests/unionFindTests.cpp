//
// Created by Bar on 06-Jun-19.
//

#include "Submission/UnionFind.h"
#include <cassert>

int main(){
    UnionFind<int> uf1 = UnionFind<int>(10);
    for(int i = 0; i < 10; i++){
        *(uf1.find(i)) = 10 + i;
    }
    uf1.unite(1 , 2);
    int data1 = *(uf1.find(1));
    int data2 = *(uf1.find(2));
    assert(data1 == data2);
}