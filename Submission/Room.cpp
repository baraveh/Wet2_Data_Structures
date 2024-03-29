//
// Created by Bar The magical on 04/06/2019.
//

#include "Room.h"

Room::Room(const int &roomId) : r_hoursArr(m){
    if(roomId <= 0){
        throw IllegalParameters();
    }
    r_roomId = roomId;
}

bool Room::addLecture(const int &hour, const CourseID &courseID,
                      const GroupID &groupID) {
    if(groupID < 0 || hour > m || hour < 1){
        throw IllegalParameters();
    }
    if(r_hoursArr[hour-1].isValid){
        return false;
    }
    r_hoursArr[hour-1].data.p_first = courseID;
    r_hoursArr[hour-1].data.p_second = groupID;
    r_hoursArr[hour-1].isValid = true;
    return true;
}

Pair<CourseID, GroupID>& Room::removeLecture(const int &hour) {
    if(hour > m || hour < 1){
        throw IllegalParameters();
    }
    if (!(r_hoursArr[hour - 1].isValid)){
       throw NoSuchKey();
    }
    r_hoursArr[hour-1].isValid = false;
    return r_hoursArr[hour-1].data;
}

Pair<CourseID, GroupID> &Room::getLecture(const int &hour) {
    if(hour < 1 || hour > m){
        throw IllegalParameters();
    }
    if(r_hoursArr[hour-1].isValid){
        return r_hoursArr[hour-1].data;
    }

    throw NoSuchKey();
}

const int& Room::getId() const{
    return r_roomId;
}

const bool Room::isEmpty() const {
    for(int i = 0; i < m; i++){
        if (r_hoursArr[i].isValid){
            return false;
        }
    }
    return true;
}
