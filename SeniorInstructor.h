//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_SENIORINSTRUCTOR_H
#define COURSEREGISTRATIONMINIPROJECT_SENIORINSTRUCTOR_H

#include "bits/stdc++.h"
#include "User.h"
using namespace std;

namespace course {

    class SeniorInstructor:public Instructor{
    public:
        void resign(string id) override{
            cout<<"Sending Request to Manager...Please wait."<<endl;
            this_thread::sleep_for(chrono::seconds(2));
            int acc = int(rand())%10;
            if(acc < 5){
                cout<<"Resignation request denied."<<endl;
            }
            else{
                cout<<"Resignation request accepted."<<endl;
                for (int i = 0; i < Courses.size(); i++) {
                    auto itr = find_if(Courses[i].Instructors.begin(), Courses[i].Instructors.end(), [id](Instructor* ins)->bool{return ins->getID() == id;});
                    if (itr != Courses[i].Instructors.end()) {
                        Courses[i].Instructors.erase(itr);
                    }
                }
                auto instructorItr = find_if(Instructors.begin(), Instructors.end(),[id](Instructor* ins){return ins->getID() == id;});
                cout<<endl<<"Good Bye "<<(*instructorItr)->getNAME()<<endl<<endl;
                Instructors.erase(instructorItr);
            }
        }

        void AskForRaise() override{
            cout<<"Sending Request to Manager...Please wait.";
            this_thread::sleep_for(chrono::seconds(2));
            int acc = int(rand())%10;
            cout<<(acc < 2 ? "Raise request denied.":"Raise request accepted...Hoooraaay!!")<<endl;
        }
        SeniorInstructor(string ID,string NAME,double RATE,int EXP): Instructor(ID,NAME,RATE,EXP){
            srand(time(0));
        }
    };

} // course

#endif //COURSEREGISTRATIONMINIPROJECT_SENIORINSTRUCTOR_H
