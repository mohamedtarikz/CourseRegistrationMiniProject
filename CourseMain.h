//
// Created by moham on 8/3/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_COURSEMAIN_H
#define COURSEREGISTRATIONMINIPROJECT_COURSEMAIN_H

#include "bits/stdc++.h"
#include "Instructor.h"
#include "Course.h"
using namespace std;

vector<string> Days = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

vector<course::Instructor*> Instructors;
vector<course::Course> Courses;

map<string,bool> taken;
int numCourses = 0;
int numInstructor = 0;


#endif //COURSEREGISTRATIONMINIPROJECT_COURSEMAIN_H
