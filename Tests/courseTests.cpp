//
// Created by Bar The magical on 05/06/2019.
//

#include "Course.h"
#include "Exception.h"

int main(){

    Course course1 = Course(11);
    Course course2 = Course(22);
    course1.addLecture(7, 1, 11, 3);
    assert(course1.getAverageStudents() == 3);
    course1.addLecture(7,2,11,3);
    assert(course1.getAverageStudents() == 3);
    course1.removeLecture(11,2);
    assert(course1.getAverageStudents() == 3);
    course1.addLecture(7,2,11,3);
}