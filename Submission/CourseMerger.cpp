//
// Created by Bar on 11-Jun-19.
//

#include "CourseMerger.h"

CourseMerger::CourseMerger(const int &numOfCourses) : c_courseUF(numOfCourses), c_roomHash(), c_numOfCourses(numOfCourses){
    for(int i = 0; i < numOfCourses; i++){
        c_courseUF.find(i)->setId(i + 1);
    }
}

CourseMergerResult CourseMerger::addRoom(const RoomID &roomID) {
    if(roomID <= 0){
        return INVALID_INPUT;
    }
    try{
        c_roomHash.addRoom(roomID);
    }
    catch(KeyAlreadyExists<Room>& e){
        return FAILURE;
    }
    return SUCCESS;
}

CourseMergerResult CourseMerger::removeRoom(const RoomID &roomID) {
    if(roomID <= 0){
        return INVALID_INPUT;
    }
    try{
        Room toRemove = c_roomHash.find(roomID);
        if(!toRemove.isEmpty()){
            return FAILURE;
        }
        c_roomHash.removeRoom(roomID);
    }
    catch(NoSuchKey& e){
        //no such room
        return FAILURE;
    }
    return SUCCESS;
}

CourseMergerResult
CourseMerger::addLecture(const CourseID &courseID, const GroupID &groupID,
                         const RoomID &roomID, const Hour &hour,
                         const NumOfStudents &numOfStudents) {
    if(courseID > c_numOfCourses || groupID < 0 || hour < 1 || hour > m || numOfStudents < 0 || roomID <= 0 || courseID < 1){
        return INVALID_INPUT;
    }
    try {
        Course *coursePtr = c_courseUF.find(courseID - 1);
        Room roomToAddTo = c_roomHash.find(roomID);
        if(roomToAddTo.addLecture(hour, courseID, groupID)){
            //addition to room was successful
            coursePtr->addLecture(roomID, hour, groupID, numOfStudents);
            return SUCCESS;
        }
        return FAILURE;
    }
    catch (NoSuchKey& e){
        //room doesn't exist
        return FAILURE;
    }
    catch (KeyAlreadyExists<int>& e){
        //lecture for this course already exists
        c_roomHash.find(roomID).removeLecture(hour);
        return FAILURE;
    }
}

CourseMergerResult
CourseMerger::deleteLecture(const Hour &hour, const RoomID &roomID) {
    if(hour < 1 || hour > m || roomID <= 0){
        return INVALID_INPUT;
    }
    try{
        CourseID courseToRemoveFrom = c_roomHash.find(roomID).getLecture(hour).p_first;
        GroupID groupToRemoveFrom = c_roomHash.find(roomID).getLecture(hour).p_second;
        c_courseUF.find(courseToRemoveFrom - 1)->removeLecture(groupToRemoveFrom, hour);
        c_roomHash.find(roomID).removeLecture(hour);
        return SUCCESS;
    }
    catch (NoSuchKey& e){
        //no such room/ no such lecture
        return FAILURE;
    }
}

CourseMergerResult
CourseMerger::mergeCourses(const CourseID &course1, const CourseID &course2) {
    if(course1 < 1 || course1 > c_numOfCourses || course2 < 1 || course2 > c_numOfCourses){
        return INVALID_INPUT;
    }
    Course* firstCourse = c_courseUF.find(course1 -1);
    Course* secondCourse = c_courseUF.find(course2 - 1);
    if(firstCourse == secondCourse){
        return FAILURE;
    }
    Course mergedCourse = *firstCourse;
    try {
        mergedCourse.mergeCourses(*(secondCourse));
    }
    catch (KeyAlreadyExists<int>& e){
        return FAILURE;
    }
    c_courseUF.unite(course1-1, course2 -1);
    *(c_courseUF.find(course1-1)) = mergedCourse;
    return SUCCESS;
}

CourseMergerResult
CourseMerger::competition(const CourseID &course1, const CourseID &course2,
                          const int &numOfLectures, int *winner) {
    if(course1 < 1 || course1 > c_numOfCourses || course2 < 1 || course2 > c_numOfCourses || winner ==
                                                                                             nullptr){
        return INVALID_INPUT;
    }

    Course* firstCourse = c_courseUF.find(course1 -1);
    Course* secondCourse = c_courseUF.find(course2 - 1);
    if(firstCourse == secondCourse){
        return FAILURE;
    }
    *winner = ((*firstCourse).competition((*secondCourse), numOfLectures));
    return SUCCESS;
}

CourseMergerResult
CourseMerger::getAverageStudentsInCourse(const Hour &hour, const RoomID &roomID,
                                         float *average) {
    if(hour < 1 || hour > m || roomID <= 0){
        return INVALID_INPUT;
    }
    try {
        CourseID courseID = c_roomHash.find(roomID).getLecture(hour).p_first;
        Course* coursePtr = c_courseUF.find(courseID - 1);
        *average = coursePtr->getAverageStudents();
        return SUCCESS;
    }
    catch (NoSuchKey& e){
        return FAILURE;
    }
}
