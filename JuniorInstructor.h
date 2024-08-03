//
// Created by moham on 8/2/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_JUNIORINSTRUCTOR_H
#define COURSEREGISTRATIONMINIPROJECT_JUNIORINSTRUCTOR_H

#include "bits/stdc++.h"
#include "User.h"
using namespace std;

namespace course {

    class JuniorInstructor:public Instructor, public User{
    public:
        void welcome() override{
            cout<<"Hello...You are signed in as Instructor!"<<endl;
        }

        void resign() override{
            cout<<"Processing reignation request..."<<endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout<<"Resignation request accepted!"<<endl;
        }

        JuniorInstructor(string ID,string NAME,double RATE,int EXP): Instructor(ID,NAME,RATE,EXP){

        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_JUNIORINSTRUCTOR_H
