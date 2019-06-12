//
// Created by Bar The magical on 04/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_HASHTABLE_H
#define WET2_DATA_STRUCTURES_HASHTABLE_H

#include "Array.h"
#include "Room.h"
#include "List.h"


class RoomHash {
    int h_numOfElements;
    Array<List<Room>> h_table;

    void rehash(const Array<List<Room>>& oldTable);
    void addRoom(const Room& room);

public:

    RoomHash();

    Room* find(const RoomID& roomId);

    void addRoom(const RoomID& roomId);

    void removeRoom (const RoomID& roomId);


};



#endif //WET2_DATA_STRUCTURES_HASHTABLE_H
