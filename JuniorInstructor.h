//
// Created by moham on 8/2/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_JUNIORINSTRUCTOR_H
#define COURSEREGISTRATIONMINIPROJECT_JUNIORINSTRUCTOR_H

#include "bits/stdc++.h"
#include "User.h"
using namespace std;

namespace course {

    class JuniorInstructor:public Instructor{
    public:
        void resign() override{
            cout<<"Processing reignation request..."<<endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout<<"Resignation request accepted!"<<endl;
        }

        void AskForRaise() override{
            cout<<"Sending Request to Manager...Please wait.";
            this_thread::sleep_for(chrono::seconds(2));
            int acc = int(rand())%10;
            cout<<(acc < 8 ? "Raise request denied.":"Raise request accepted...Hoooraaay!!")<<endl;
        }
        JuniorInstructor(string ID,string NAME,double RATE,int EXP): Instructor(ID,NAME,RATE,EXP){
            srand(time(0));
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_JUNIORINSTRUCTOR_H
