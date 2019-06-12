//
// Created by Bar The magical on 04/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_HASHTABLE_H
#define WET2_DATA_STRUCTURES_HASHTABLE_H

#include "Array.h"
#include "Room.h"
#include "List.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


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

    void printHash(){
        std::cout << "Now printing hash" << std::endl;
        for(int i = 0; i < h_table.getSize(); i++){
            std::cout << "line num";
            std::cout << i << std::endl;
            Node<Room>* iterator = h_table[i].getHead();
            for(int j = 0 ; j < h_table[i].getSize(); j++){
                std::cout << iterator->data_m.getId();
                std::cout << "," << std::endl;
                iterator = iterator->next_m;
            }
        }
    }


};



#endif //WET2_DATA_STRUCTURES_HASHTABLE_H
