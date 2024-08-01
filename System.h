//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_SYSTEM_H
#define COURSEREGISTRATIONMINIPROJECT_SYSTEM_H

#include "bits/stdc++.h"
using namespace std;

namespace course {

    string day[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    vector<Instructor> Instructors;
    vector<Course> Courses;

    map<string,bool> taken;

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
                    cout<<itr.Instructors[i].getNAME()<<", ";
                }
                cout<<itr.Instructors[itr.Instructors.size()-1].getNAME()<<")"<<endl;
                cout<<"---------------------------------------------------------\n";
            }
        }
        bool isValidInput(string id){
            //check if the given id is present in the courses
            auto itr = find_if(Courses.begin(),Courses.end(),[id](Course course){return course.getID() == id;});
            return (itr != Courses.end());
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
                cout<<crs->Instructors[i].getNAME()<<", ";
            }
            cout<<crs->Instructors[crs->Instructors.size()-1].getNAME()<<")"<<endl<<endl;
            //print info about every instructor (name, experience, rating)
            for(auto teach:crs->Instructors){
                cout<<"Name: "<<teach.getNAME()<<endl;
                cout<<"Experience: "<<teach.getEXP()<<endl;
                cout<<"Rating: "<<teach.getRATE()<<endl;
                cout<<endl;
            }
            cout<<"[(P)urchase]                        [(C)ancel]"<<endl;
        }
    };

    void Init_Instructors(){
        //initialize instructors
        Instructors.emplace_back("T12","Samah Abd-ElWahed",4.65,5);
        Instructors.emplace_back("T01","Adel Shakal",5.0,9);
        Instructors.emplace_back("T45","Samar Shakshouka",3.8,3);
        Instructors.emplace_back("T06","Amr Elsisi",2.9,6);
        Instructors.emplace_back("T10","Alaa Mubarak",4.5,10);
    }
    void Init_Courses(){
        //initialize courses
        Courses.emplace_back("CS101","Introduction to Computer Science",249.99);
        Courses[0].AddInstructor(Instructors[0]);
        Courses[0].AddInstructor(Instructors[2]);
        Courses[0].AddDays(day[0]);
        Courses[0].AddDays(day[4]);
        Courses.emplace_back("IT101","Introduction to Networks",549.99);
        Courses[1].AddInstructor(Instructors[1]);
        Courses[1].AddInstructor(Instructors[2]);
        Courses[1].AddDays(day[1]);
        Courses[1].AddDays(day[3]);
        Courses.emplace_back("AI201","Learning about Neural Networks",999.99);
        Courses[2].AddInstructor(Instructors[3]);
        Courses[2].AddInstructor(Instructors[4]);
        Courses[2].AddInstructor(Instructors[0]);
        Courses[2].AddDays(day[5]);
        Courses[2].AddDays(day[6]);
        Courses.emplace_back("MA121","Partial Differential Equation",749.99);
        Courses[3].AddInstructor(Instructors[1]);
        Courses[3].AddInstructor(Instructors[4]);
        Courses[3].AddDays(day[0]);
        Courses[3].AddDays(day[2]);
    }

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_SYSTEM_H
