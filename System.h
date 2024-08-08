//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_SYSTEM_H
#define COURSEREGISTRATIONMINIPROJECT_SYSTEM_H

#include "bits/stdc++.h"
#include "CourseMain.h"
#include "JuniorInstructor.h"
#include "SeniorInstructor.h"
using namespace std;

namespace course {

    class System{
    public:
        void ViewCourses(){//view all the courses not yet bought
            cout<<endl<<"Courses:"<<endl;
            if(Courses.size() == 0){
                cout<<"    No Courses Here!"<<endl<<endl;
                return;
            }
            bool allTaken = true;
            for(auto itr:Courses){
                if(taken[itr.getID()])
                    continue;
                allTaken = false;
                //print info about the course
                cout<<"    ID: "<<itr.getID()<<endl;
                cout<<"    Name: "<<itr.getNAME()<<endl;
                cout<<"    Price: "<<itr.getPRICE()<<endl;
                //print the days the course is active in
                cout<<"    Days: (";
                for(int i = 0; i < itr.timings.size() - 1; i++){
                    cout<<itr.timings[i]<<", ";
                }
                cout<<itr.timings[itr.timings.size()-1]<<")"<<endl;
                //print the instructors' names
                cout<<"    Instructors: (";
                for(int i = 0; i < itr.Instructors.size() - 1; i++){
                    cout<<itr.Instructors[i]->getNAME()<<", ";
                }
                cout<<itr.Instructors[itr.Instructors.size()-1]->getNAME()<<")"<<endl;
                cout<<"---------------------------------------------------------\n\n";
            }
            if(allTaken){
                cout<<"    You have purchased all courses, Thanks!!"<<endl<<endl;
            }
        }
        bool CheckForCourse(string id){
            //check if the given id is present in the courses
            auto itr = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
            return (itr != Courses.end());
        }
        bool CheckForInstructor(string id){
            auto itr = find_if(Instructors.begin(),Instructors.end(),[id](Instructor* ins){return ins->getID() == id;});
            return (itr != Instructors.end());
        }
        void ViewCertianCourse(string id){
            //find the position of the course with the given id
            auto crs = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
            //print important info about it
            cout<<"NAME: "<< crs->getNAME()<<endl;
            cout<<"PRICE: "<<crs->getPRICE()<<endl;
            //print the days the course is active in
            cout<<"Days: (";
            for(int i = 0; i < crs->timings.size() - 1; i++){
                cout<<crs->timings[i]<<", ";
            }
            cout<<crs->timings[crs->timings.size()-1]<<")"<<endl;
            //print instructors' names
            cout<<"Instructors: (";
            for(int i = 0; i < crs->Instructors.size() - 1; i++){
                cout<<crs->Instructors[i]->getNAME()<<", ";
            }
            cout<<crs->Instructors[crs->Instructors.size()-1]->getNAME()<<")"<<endl<<endl;
            //print info about every instructor (name, experience, rating)
            for(auto teach:crs->Instructors){
                cout<<"Name: "<<teach->getNAME()<<endl;
                cout<<"Experience: "<<teach->getEXP()<<endl;
                cout<<"Rating: "<<teach->getRATE()<<endl;
                cout<<endl;
            }
            cout<<"[(P)urchase]                        [(C)ancel]\nEnter(P/C): ";
        }
        void InitInstructors(){
            Instructors.push_back(new JuniorInstructor(to_string(++numInstructor),"Manar El-Sharbatly",3.7,4));
            Instructors.push_back(new SeniorInstructor(to_string(++numInstructor),"Saed El-Armot",4.2,5));
            Instructors.push_back(new SeniorInstructor(to_string(++numInstructor),"Entsar Mrato",5.0,10));
            Instructors.push_back(new JuniorInstructor(to_string(++numInstructor),"3am Samir",4.1,2));
        }
        void InitCourses(){
            Courses.emplace_back(to_string(++numCourses),"Intro to Data Analysis", 299.99);
            Courses[0].AddInstructor(Instructors[2]);
            Courses[0].AddDays("Sat");
            Courses[0].AddDays("Tue");
            Courses.emplace_back(to_string(++numCourses),"Calc. 1",199.99);
            Courses[1].AddInstructor(Instructors[3]);
            Courses[1].AddInstructor(Instructors[1]);
            Courses[1].AddDays("Mon");
            Courses[1].AddDays("Wed");
            Courses.emplace_back(to_string(++numCourses),"OOP from Beginner to Advanced", 349.99);
            Courses[2].AddInstructor(Instructors[0]);
            Courses[2].AddInstructor(Instructors[3]);
            Courses[2].AddInstructor(Instructors[2]);
            Courses[2].AddDays("Sat");
            Courses[2].AddDays("Mon");
            Courses[2].AddDays("Wed");
        }
    };
} // course

#endif //COURSEREGISTRATIONMINIPROJECT_SYSTEM_H
