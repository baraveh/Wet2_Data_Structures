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

    Course(const CourseID &courseID = 0) : c_ID(courseID), c_totalLectures(0),
                                           c_totalStudents(0), c_lectureTree(),
                                           c_studentsRanker() {}

    Course(const Course &) = default;

    ~Course() = default;

    Course &operator=(const Course &aCourse) {
        c_ID = aCourse.c_ID;
        c_totalLectures = aCourse.c_totalLectures;
        c_totalStudents = aCourse.c_totalStudents;
        c_lectureTree = aCourse.c_lectureTree;
        c_studentsRanker = aCourse.c_studentsRanker;
    }

    void
    addLecture(const RoomID &roomID, const Hour &hour, const GroupID &groupID,
               const NumOfStudents &numOfStudents) {
        try {
            c_lectureTree.insertElement(LectureKey(groupID, hour),
                                        LectureValue(roomID, numOfStudents));
            c_studentsRanker.insertElement(
                    RankKey(numOfStudents, groupID, hour), NO_VAL);
        }
        catch (KeyAlreadyExists &e) {
            throw KeyAlreadyExists();
        }
        c_totalLectures++;
        c_totalStudents += numOfStudents;
    }

    void removeLecture(const GroupID &groupID, const Hour &hour) {
        LectureKey lectureKeyToRemove = LectureKey(groupID, hour);
        try {
            NumOfStudents numToRemove = c_lectureTree[lectureKeyToRemove].p_second;
            RankKey rankToRemove = RankKey(numToRemove, groupID, hour);
            c_lectureTree.deleteElement(lectureKeyToRemove);
            c_studentsRanker.deleteElement(rankToRemove);
            c_totalLectures--;
            c_totalStudents -= numToRemove;

        }
        catch (NoSuchKey &e) {
            throw NoSuchKey();
        }
    }

    void mergeCourses(const Course& aCourse){
        try{
            c_lectureTree.mergeTrees(c_lectureTree, aCourse.c_lectureTree); //TODO in avl tree merge, if this doesn't work delete the line delete temp and put a temp parameter here
            c_studentsRanker.mergeTrees(c_studentsRanker, aCourse.c_studentsRanker);
            c_totalLectures += aCourse.c_totalLectures;
            c_totalStudents += aCourse.c_totalStudents;
        }
        catch (KeyAlreadyExists& e){
            throw KeyAlreadyExists();
        }
    }

    int competition(const Course& aCourse, int numLectures){
        const AVLNode<RankKey,int>* thisCourseCandidate = c_studentsRanker.searchIndex(c_totalLectures- numLectures); //TODO check math
        const AVLNode<RankKey, int>* otherCourseCandidate = aCourse.c_studentsRanker.searchIndex(aCourse.c_totalLectures- numLectures);
        if(thisCourseCandidate == nullptr || otherCourseCandidate == nullptr){
            throw IllegalParameters();
        }
    }

};


#endif //WET2_DATA_STRUCTURES_COURSE_H
