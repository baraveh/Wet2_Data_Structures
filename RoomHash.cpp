//
// Created by Bar The magical on 04/06/2019.
//

#include "RoomHash.h"

RoomHash::RoomHash() : h_numOfElements(0){}

Room &RoomHash::find(const int &roomId) {
    int hash = roomId%(h_table.getSize());
}

void RoomHash::addRoom(const int &roomId) {

}

void RoomHash::removeRoom(const int &roomId) {

}
