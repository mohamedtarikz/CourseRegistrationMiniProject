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
        void resign(string id) override{
            cout<<"Processing resignation request..."<<endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout<<"Resignation request accepted!"<<endl;
            for (auto course:Courses) {
                auto itr = find_if(course.Instructors.begin(), course.Instructors.end(), [id](Instructor* ins){return ins->getID() == id;});
                if (itr != course.Instructors.end()) {
                    cout<<endl<<"Good Bye "<<(*itr)->getNAME()<<endl<<endl;
                    course.Instructors.erase(itr);
                }
            }
            auto instructorItr = find_if(Instructors.begin(), Instructors.end(),[id](Instructor* ins){return ins->getID() == id;});
            Instructors.erase(instructorItr);
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
