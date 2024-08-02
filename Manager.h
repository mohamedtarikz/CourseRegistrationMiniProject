//
// Created by moham on 8/3/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_MANAGER_H
#define COURSEREGISTRATIONMINIPROJECT_MANAGER_H

#include "bits/stdc++.h"
#include "User.h"
using namespace std;

namespace course {

    class Manager : public User {
    public:
        void welcome() override{
            cout<<"Hello...You are signed in as Manager!"<<endl;
        }

        void AddInstructor(string id,string name,double rating, int exp){
            if (exp < 5) {
                Instructors.emplace_back(new JuniorInstructor(id, name, rating, exp));
            } else {
                Instructors.emplace_back(new SeniorInstructor(id, name, rating, exp));
            }
        }
        void AddCourse(string id, string name, double price){
            Courses.emplace_back(id,name,price);
        }
        void AddInstructorToCourse(string idI,string idC){
            auto ins = find_if(Instructors.begin(),Instructors.end(),[idI](Instructor* i){return i->getID()==idI;});
            auto cor = find_if(Courses.begin(),Courses.end(),[idC](Course i){return i.getID() == idC;});
            if(ins == Instructors.end()){
                cout<<"No Such Instructor in System!"<<endl;
                return;
            }
            else if(cor == Courses.end()){
                cout<<"No Such Course in System!"<<endl;
                return;
            }
            else{
                cor->AddInstructor(*ins);
            }
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_MANAGER_H
