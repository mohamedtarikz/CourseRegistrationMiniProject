//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_COURSE_H
#define COURSEREGISTRATIONMINIPROJECT_COURSE_H

#include "bits/stdc++.h"
#include "Instructor.h"
using namespace std;

namespace course {

    class Course{
        //info about course
        string id;
        string name;
        int num_subs;
        double price;
    public:
        //vector of Instructors
        vector<Instructor> Instructors;
        //vector of timings of the course
        vector<string> timings;

        //getters and setters
        void setID(string ID){id = ID;}
        string getID(){return id;}

        void setNAME(string NAME){name = NAME;}
        string getNAME(){return name;}

        void setNUMSUBS(int NUMSUBS){num_subs = NUMSUBS;}
        int getNUMSUBS(){return num_subs;}

        void setPRICE(double PRICE){price = PRICE;}
        double getPRICE(){return price;}

        //method to add instructor
        void AddInstructor(Instructor teacher){Instructors.emplace_back(teacher);}
        //method to add a day for the course
        void AddDays(string day){timings.emplace_back(day);}

        //class constructor
        Course(string ID, string NAME, double PRICE, int init_Subs = 0){
            id = ID;
            name = NAME;
            price = PRICE;
            num_subs = init_Subs;
        }
    };


} // course

#endif //COURSEREGISTRATIONMINIPROJECT_COURSE_H
