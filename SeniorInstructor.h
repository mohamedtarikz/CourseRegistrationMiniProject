//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_SENIORINSTRUCTOR_H
#define COURSEREGISTRATIONMINIPROJECT_SENIORINSTRUCTOR_H

#include "bits/stdc++.h"
#include "Instructor.h"
using namespace std;

namespace course {

    class SeniorInstructor:public Instructor{
    public:
        void resign(){
            cout<<"Sending Request to Manager...Please wait.";
            this_thread::sleep_for(chrono::seconds(2));
            int acc = rand()%10;
            cout<<(acc < 5 ? "Resignation request denied.":"Resignation request accepted.")<<endl;
        }
        SeniorInstructor(string ID,string NAME,double RATE,int EXP): Instructor(ID,NAME,RATE,EXP){
            srand(time(0));
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_SENIORINSTRUCTOR_H
