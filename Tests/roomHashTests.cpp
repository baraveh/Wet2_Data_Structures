//
// Created by Bar The magical on 05/06/2019.
//

#include "Submission/RoomHash.h"

int main(){
    RoomHash hash = RoomHash();
    hash.addRoom(5);
    hash.printHash();
    hash.addRoom(10);
    hash.printHash();
    hash.addRoom(12);
    hash.printHash();
    hash.addRoom(13);
    hash.printHash();
}