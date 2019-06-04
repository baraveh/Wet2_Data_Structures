//
// Created by Bar The magical on 04/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_HASHTABLE_H
#define WET2_DATA_STRUCTURES_HASHTABLE_H

#include "Array.h"
#include "Room.h"
#include "List.h"

template <typename T>
class HashEntry{
    T a_data;
    bool a_isValid;

public:
    HashEntry() : a_isValid(false), a_data(){}
    HashEntry(const bool& valid, const T& data) :a_isValid(valid), a_data(data){}
    ~HashEntry() = default;
    HashEntry(const HashEntry& hashEntry) = default;
    HashEntry& operator= (const HashEntry& hashEntry){
        a_data = hashEntry.a_data;
        a_isValid = hashEntry.a_isValid;
    } 
};

class RoomHash {
    int h_numOfElements;
    Array<List<HashEntry<Room>>> h_table;

public:

    RoomHash();

    Room& find(const int& roomId);

    void addRoom(const int& roomId);

    void removeRoom (const int& roomId);


};



#endif //WET2_DATA_STRUCTURES_HASHTABLE_H
