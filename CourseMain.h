//
// Created by moham on 8/3/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_COURSEMAIN_H
#define COURSEREGISTRATIONMINIPROJECT_COURSEMAIN_H

#include "bits/stdc++.h"
#include "Instructor.h"
#include "Course.h"
using namespace std;

string dayArr[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
vector<string> Days;

void Init_Days(){
    for (int i = 0; i < 7; ++i) {
        Days.push_back(dayArr[i]);
    }
}

vector<course::Instructor*> Instructors;
vector<course::Course> Courses;

map<string,bool> taken;

#endif //COURSEREGISTRATIONMINIPROJECT_COURSEMAIN_H
