//
// Created by Bar on 11-Jun-19.
//

#ifndef WET2_DATA_STRUCTURES_COURSEMERGER_H
#define WET2_DATA_STRUCTURES_COURSEMERGER_H


#include "UnionFind.h"
#include "Course.h"
#include "Defintions.h"
#include "RoomHash.h"

typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} CourseMergerResult;

class CourseMerger {
    UnionFind<Course> c_courseUF;
    RoomHash c_roomHash;
    int c_numOfCourses;

public:

    CourseMerger(const int& numOfCourses);

    CourseMerger(const CourseMerger& courseMerger) = default;
    ~CourseMerger() = default;
    CourseMerger&operator= (const CourseMerger& courseMerger) = default;

    CourseMergerResult addRoom(const RoomID& roomID);

    CourseMergerResult removeRoom (const RoomID& roomID);

    CourseMergerResult addLecture(const CourseID& courseID, const GroupID& groupID, const RoomID& roomID, const Hour& hour, const NumOfStudents& numOfStudents);

    CourseMergerResult deleteLecture(const Hour& hour, const RoomID& roomID);

    CourseMergerResult mergeCourses(const CourseID& course1, const CourseID& course2);

    CourseMergerResult competition(const CourseID& course1, const CourseID& course2, const int& numOfLectures, int* winner);

    CourseMergerResult getAverageStudentsInCourse(const Hour& hour, const RoomID& roomID, float* average);

};


#endif //WET2_DATA_STRUCTURES_COURSEMERGER_H
