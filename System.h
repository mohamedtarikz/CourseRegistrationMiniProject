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
            cout<<"Courses:"<<endl;
            for(auto itr:Courses){
                if(taken[itr.getID()])
                    continue;
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
                cout<<"---------------------------------------------------------\n";
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
            cout<<"[(P)urchase]                        [(C)ancel]"<<endl;
        }
    };

    void InitInstructors(){
        Instructors.push_back(new JuniorInstructor(to_string(++numInstructor),"Manar El-Sharbatly",3.7,4));
        Instructors.push_back(new SeniorInstructor(to_string(++numInstructor),"Saed El-Armot",4.2,5));
        Instructors.push_back(new SeniorInstructor(to_string(++numInstructor),"Entsar Mrato",5.0,10));
        Instructors.push_back(new JuniorInstructor(to_string(++numInstructor),"3am Samir",3.2,2));
    }
} // course

#endif //COURSEREGISTRATIONMINIPROJECT_SYSTEM_H
