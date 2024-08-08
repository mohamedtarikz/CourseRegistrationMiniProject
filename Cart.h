//
// Created by moham on 8/1/2024.
//

#ifndef COURSEREGISTRATIONMINIPROJECT_CART_H
#define COURSEREGISTRATIONMINIPROJECT_CART_H

#include "bits/stdc++.h"
#include "CourseMain.h"
using namespace std;

namespace course {


    class Cart{
        //vector for the courses bought
        vector<Course> courses;
        //total price for the items in the cart
        double total_price;
    public:
        //method to get total
        double getTOTAL(){return total_price;}

        void AddCourse(string id){
            //check for the course in the Courses vector
            auto crs = find_if(Courses.begin(),Courses.end(),[id](Course iter){return iter.getID() == id;});
            //add the course to the cart
            courses.emplace_back(*crs);
            //add the price to the total price
            total_price += crs->getPRICE();
        }
        void RemCourse(string id){
            //check if the id given is in the cart
            auto it = find_if(courses.begin(),courses.end(),[id](Course iter){return iter.getID() == id;});
            if(it != courses.end()){//if present in the cart
                //subtract the price from the total price
                total_price -= it->getPRICE();
                //remove the course from the cart
                courses.erase(it);
            }
        }

        bool isValidInput(string id){
            //check if the given id is present in cart
            auto itr = find_if(courses.begin(),courses.end(),[id](Course course){return course.getID() == id;});
            return (itr != courses.end());
        }

        void ViewCart(){
            //view every course in the cart in the following format
            //(ID)NAME-----------------PRICE
            for (auto course:courses) {
                cout<<endl<<"("<<course.getID()<<")"<<course.getNAME()<<" ";
                for (int i = 0; i < 80 - course.getNAME().size() - course.getID().size(); ++i) {
                    cout<<"-";
                }
                cout<<" "<<course.getPRICE()<<endl;
            }
            //view total price below all items
            cout<<endl<<"Total: ";
            for (int i = 0; i < 77; ++i) {
                cout<<" ";
            }
            cout<<total_price<<endl<<endl;
            cout<<"[(C)heckout]                 [(R)emove item]              [(B)ack]\nEnter(C/R/B): ";
        }

        //class constructor
        Cart(double initTotal = 0){
            total_price = initTotal;
        }
    };


} // course

#endif //COURSEREGISTRATIONMINIPROJECT_CART_H
