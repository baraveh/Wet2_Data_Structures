//
// Created by Bar The magical on 04/06/2019.
//

#include "RoomHash.h"

RoomHash::RoomHash() : h_numOfElements(0){}

Room* RoomHash::find(const RoomID& roomId) {
    int hash = roomId%(h_table.getSize());
    Node<Room>* iterator = h_table[hash].getHead();
    for(int i = 0; i < h_table[hash].getSize(); i++){
        assert(iterator != nullptr);
        if((iterator->data_m).getId() == roomId){
            return &(iterator->data_m);
        }
        iterator = iterator->next_m;
    }

    throw NoSuchKey();
}

void RoomHash::addRoom(const RoomID& roomId) {
    try {
        find(roomId);
    }
    catch (NoSuchKey& e) {
        int hash = roomId%(h_table.getSize());
        Room roomToAdd = Room(roomId);
        h_table[hash].addLast(roomToAdd);
        h_numOfElements++;

        if(h_numOfElements == h_table.getSize()){
            Array<List<Room>> oldTable = h_table;
            h_table = Array<List<Room>>(((oldTable.getSize())*2));
            rehash(oldTable);
        }
        return;
    }
    throw KeyAlreadyExists<Room>(*(find(roomId)));
}

void RoomHash::removeRoom(const RoomID& roomId) {
    int hash = roomId%(h_table.getSize());
    Node<Room>* iterator = h_table[hash].getHead();
    for(int i = 0; i < h_table[hash].getSize(); i++){
        assert(iterator != nullptr);
        if((iterator->data_m).getId() == roomId){
            h_table[hash].deleteNode(iterator);
            h_numOfElements--;
            if(h_numOfElements == h_table.getSize()/4){
                Array<List<Room>> oldTable = h_table;
                h_table = Array<List<Room>>(oldTable.getSize()/2);
                rehash(oldTable);
            }
            return;
        }
        iterator = iterator->next_m;
    }

    throw NoSuchKey();
}

void RoomHash::rehash(const Array<List<Room>> &oldTable) {
    h_numOfElements = 0;
    for(int i = 0; i < oldTable.getSize(); i++){
        List<Room> elementsToCopy = oldTable[i];
        Node<Room>* iterator = oldTable[i].getHead();
        for(int j = 0; j < elementsToCopy.getSize(); j++) {
            assert(iterator != nullptr);
            addRoom(iterator->data_m);
            iterator = iterator->next_m;
        }
    }
}

void RoomHash::addRoom(const Room &room) {
    try {
        find(room.getId());
    }
    catch (NoSuchKey& e) {
        int hash = room.getId()%(h_table.getSize());
        h_table[hash].addLast(room);
        h_numOfElements++;

        if(h_numOfElements == h_table.getSize()){
            Array<List<Room>> oldTable = h_table;
            h_table = Array<List<Room>>(oldTable.getSize()*2);
            rehash(oldTable);
        }
        return;
    }
    assert(false);
    throw KeyAlreadyExists<Room>(*(find(room.getId())));
}
