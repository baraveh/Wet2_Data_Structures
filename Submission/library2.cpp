//
// Created by Bar on 12-Jun-19.
//

#include "NotForSubmission/library2.h" //TODO change includes before submission!
#include "CourseMerger.h"
#include "Exception.h"

void* Init(int n){
    try{

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

    }
    catch (std::bad_alloc& e){
        return ALLOCATION_ERROR;
    }
    catch (MemError& e){
        return ALLOCATION_ERROR;
    }
}

StatusType mergeCourses(void *DS, int courseID1, int courseID2){

}

StatusType competition(void *DS, int courseID1, int courseID2, int numGroups, int * winner){

}

StatusType getAverageStudentsInCourse(void *DS, int hour, int roomID, float * average){

}

void Quit(void** DS){
    
}
