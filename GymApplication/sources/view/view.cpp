//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include <list>
#include "view.h"
#include "Utils.h"
#include "InvalidDataException.h"
using namespace std;

View::View(){
}

int View::menuGym() {
    int op = -1;
    do{
        cout<<"\n\n########## Menu Gym ##########\n";
        cout<<"1 - Clients\n";
        cout<<"2 - Employees\n";
        cout<<"3 - Classes\n";
        cout<<"4 - Enrolls\n";
        cout<<"5 - Lectures\n";
        cout<<"6 - Feedback\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNumber("Option");

    }while(op < 0 || op > 6);
    return op;
}
int View::menuClients() {
    int op = -1;
    do{
        cout<<"\n\n########## Menu Client ##########\n";
        cout<<"1 - Add\n";
        cout<<"2 - Find\n";
        cout<<"3 - Remove\n";
        cout<<"4 - List\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 4);
    return op;
}
int View::menuEmployees() {
    int op = -1;
    do{
        cout<<"\n\n########## Menu Employees ##########\n";
        cout<<"1 - Add\n";
        cout<<"2 - Find\n";
        cout<<"3 - Remove\n";
        cout<<"4 - List\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 4);
    return op;
}



int View::menuClasses() {
    int op = -1;
    do{
        cout<<"\n\n########## Menu Classes ##########\n";
        cout<<"1 - Add\n";
        cout<<"2 - Find\n";
        cout<<"3 - Remove\n";
        cout<<"4 - List\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 4);
    return op;
}
int View::menuEnrolls() {
    int op = -1;
    do{
        cout<<"\n\n########## Menu Enrolls ##########\n";
        cout<<"1 - Add\n";
        cout<<"2 - Find\n";
        cout<<"3 - Remove\n";
        cout<<"4 - List\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 4);
    return op;
}
int View::menuLectures() {
    int op = -1;
    do{
        cout<<"\n\n########## Menu Lectures ##########\n";
        cout<<"1 - Add\n";
        cout<<"2 - List By Employee\n";
        cout<<"3 - Remove\n";
        cout<<"\n0 - Exit\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3);
    return op;
}
int View::menuFeedback(){
    int op = -1;
    do {
        cout<<"\n\n########## Menu Feedback ##########\n";
        cout<<"1 - Add\n";
        cout<<"2 - Find\n";
        cout<<"3 - List\n";
        cout<<"\n0 - Exit\n";
        op=Utils::getNumber("Option");
    } while (op<0 || op >3);
    return op;
}

