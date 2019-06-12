//
// Created by Bar on 12-Jun-19.
//

#include "library2.h"
#include "CourseMerger.h"
#include "Exception.h"

void* Init(int n){
    try{
        if(n < 1){
            return nullptr;
        }
        auto *DS = new CourseMerger(n);
        return (void*)DS;

    }
    catch (std::bad_alloc& e){
        return nullptr;
    }
    catch (MemError& e){
        return nullptr;
    }

}

StatusType addRoom(void *DS, int roomID){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->addRoom(roomID));

    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType deleteRoom(void *DS, int roomID){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->removeRoom(roomID));
    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType addLecture(void *DS, int courseID, int groupID, int roomID, int hour, int numStudents){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->addLecture(courseID, groupID, roomID, hour, numStudents));
    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType deleteLecture(void *DS, int hour, int roomID){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->deleteLecture(hour, roomID));
    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType mergeCourses(void *DS, int courseID1, int courseID2){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->mergeCourses(courseID1, courseID2));
    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType competition(void *DS, int courseID1, int courseID2, int numGroups, int * winner){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->competition(courseID1, courseID2, numGroups, winner));
    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType getAverageStudentsInCourse(void *DS, int hour, int roomID, float * average){
    try{
        if(!DS){
            return INVALID_INPUT;
        }
        return StatusType(((CourseMerger*)DS)->getAverageStudentsInCourse(hour, roomID, average));
    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

void Quit(void** DS){
    if(!DS){
        return;
    }

    if((*DS) != nullptr) {
        auto temp = (CourseMerger*) *DS;
        *DS = nullptr;
        delete temp;
    }

}
