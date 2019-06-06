//
// Created by Bar on 05-Jun-19.
//

#ifndef WET2_DATA_STRUCTURES_COURSE_H
#define WET2_DATA_STRUCTURES_COURSE_H

#include "AVLTree.h"
#include "Pair.h"
#include "Triplet.h"
#include "Defintions.h"

typedef Pair<GroupID, Hour> LectureKey;
typedef Pair<RoomID, NumOfStudents> LectureValue;
typedef Triplet<NumOfStudents, GroupID, Hour> RankKey;

class Course {
    CourseID c_ID;
    int c_totalLectures;
    NumOfStudents c_totalStudents;
    AVLTree<LectureKey, LectureValue> c_lectureTree;
    AVLTree<RankKey, int> c_studentsRanker;

public:

    Course(const CourseID &courseID = 0);

    Course(const Course &) = default;

    ~Course() = default;

    Course &operator=(const Course &aCourse) = default;

    void
    addLecture(const RoomID &roomID, const Hour &hour, const GroupID &groupID,
               const NumOfStudents &numOfStudents);

    void removeLecture(const GroupID &groupID, const Hour &hour);

    void mergeCourses(const Course &aCourse);

    int competition(const Course &aCourse, int numLectures);

    float getAverageStudents();

};


#endif //WET2_DATA_STRUCTURES_COURSE_H
