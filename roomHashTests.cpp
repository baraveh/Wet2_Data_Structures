//
// Created by Bar The magical on 05/06/2019.
//

#include "RoomHash.h"

int main(){
    RoomHash hash = RoomHash();
    hash.addRoom(1);
    Room room1 = hash.find(1);
    bool test = room1.addLecture(1,234218, 12);
    assert(test);
    room1.removeLecture(1);
    hash.addRoom(2);
    hash.addRoom(3);
    hash.find(2);
    hash.find(3);
    hash.removeRoom(2);
    hash.removeRoom(3);
}