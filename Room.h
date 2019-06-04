//
// Created by Bar The magical on 04/06/2019.
//

#ifndef WET2_DATA_STRUCTURES_ROOM_H
#define WET2_DATA_STRUCTURES_ROOM_H


#include "Pair.h"
#include "Array.h"
#include "defintions.h"


class HourArrayEntry{
public:
    Pair<CourseID , GroupID> data;
    bool isValid;
    HourArrayEntry() : data(), isValid(false){}
};

class Room {
    RoomID r_roomId;
    Array<HourArrayEntry> r_hoursArr;

public:

    Room(const int& roomId = 1);

    bool addLecture(const int& hour, const CourseID& courseID, const GroupID& groupID);

    Pair<CourseID , GroupID>& removeLecture(const int& hour);

    Pair<CourseID , GroupID>& getLecture (const int& hour);

    int getId();

};


#endif //WET2_DATA_STRUCTURES_ROOM_H
