//
// Created by Bar on 05-Jun-19.
//

#include "Course.h"

Course::Course(const CourseID &courseID) : c_ID(courseID), c_totalLectures(0), c_totalStudents(0), c_lectureTree(), c_studentsRanker(){}

void Course::addLecture(const RoomID &roomID, const Hour &hour,
                        const GroupID &groupID,
                        const NumOfStudents &numOfStudents) {
    LectureKey lectureToAdd = LectureKey(groupID, hour);
    LectureValue valueToAdd = LectureValue(roomID, numOfStudents);
    RankKey rankToAdd = RankKey(numOfStudents, groupID, hour);
    try{
        c_lectureTree.insertElement(lectureToAdd, valueToAdd);
        c_studentsRanker.insertElement(rankToAdd,NO_VAL);
    }
    catch(KeyAlreadyExists<LectureKey>& e){
        throw KeyAlreadyExists<int>();
    }
    c_totalStudents += numOfStudents;
    c_totalLectures++;
}

void Course::removeLecture(const GroupID &groupID, const Hour &hour) {
    LectureKey keyToRemove = LectureKey(groupID, hour);
    NumOfStudents numToRemove = 0;
    try{
        numToRemove = c_lectureTree[keyToRemove].p_second;
    }
    catch (NoSuchKey& e){
        throw NoSuchKey();
    }
    c_lectureTree.deleteElement(keyToRemove);
    RankKey rankKeyToRemove = RankKey(numToRemove, groupID, hour);
    c_studentsRanker.deleteElement(rankKeyToRemove);
    c_totalLectures--;
    c_totalStudents-=numToRemove;
}

int Course::competition(const Course &aCourse, int numLectures) {

    if(c_totalLectures == 0){
        return aCourse.c_ID;
    }
    if(aCourse.c_totalLectures == 0){
        return c_ID;
    }

    int thisRankToSearch = numLectures > c_totalLectures ? c_totalLectures -1 : c_totalLectures - numLectures;
    int otherRankToSearch = numLectures > aCourse.c_totalLectures ? aCourse.c_totalLectures - 1 : aCourse.c_totalLectures - numLectures;
    const AVLNode<RankKey, int>* thisCandidate = c_studentsRanker.searchIndex(thisRankToSearch);
    const AVLNode<RankKey, int>* otherCandidate = aCourse.c_studentsRanker.searchIndex(otherRankToSearch);

    assert(thisCandidate != nullptr && otherCandidate != nullptr);

    return c_studentsRanker.rightSum(thisCandidate) >= aCourse.c_studentsRanker.rightSum(otherCandidate) ? c_ID : aCourse.c_ID;
}

float Course::getAverageStudents() {
    return c_totalLectures ? float(c_totalStudents)/float(c_totalLectures) : 0;
}

void Course::mergeCourses(const Course &aCourse) {
    try{
        c_lectureTree.mergeTrees(c_lectureTree, aCourse.c_lectureTree);
        c_studentsRanker.mergeTrees(c_studentsRanker, aCourse.c_studentsRanker);
        c_totalLectures += aCourse.c_totalLectures;
        c_totalStudents += aCourse.c_totalStudents;
    }
    catch (KeyAlreadyExists<LectureKey>& e){
        throw KeyAlreadyExists<int>();
    }

}

void Course::setId(const int &id) {
    if(id < 1){
        throw IllegalParameters();
    }
    c_ID = id;
}
