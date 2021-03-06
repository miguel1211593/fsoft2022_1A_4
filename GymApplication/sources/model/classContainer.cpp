//
// Created by migue on 09/06/2022.
//
#include "DuplicatedDataException.h"
#include "classContainer.h"
#include "DataConsistencyException.h"

list<Class>::iterator ClassContainer::search(const string& initials){
    list<Class>::iterator it = classes.begin();
    for (; it != classes.end(); ++it){
        if((*it) == initials){
            return it;
        }
    }
    return it;
}
list<Class> ClassContainer::getAll(){
    list<Class> newlist (classes);
    return newlist;
}
Class* ClassContainer::get(const string& initials){
    list<Class>::iterator it = search(initials);
    if(it != classes.end()){
        return &(*it);
    }
    return NULL;
}
void ClassContainer::add(const Class& obj){
    list<Class>::iterator it = search(obj.getInitials());
    if(it == classes.end()){
        classes.push_back(obj);
    }else{
        string msg = "Class: Error";
        throw DuplicatedDataException(msg);
    }

}
void ClassContainer::remove(const string& initials){
    list<Class>::iterator it = search(initials);
    if(it != classes.end()){
        classes.erase(it);
    }
}


void ClassContainer::setEnrolls(EnrollContainer *enrolls){
    this->enrolls = enrolls;
}
void ClassContainer::setEmployees(EmployeeContainer *employees) {
    this->employees = employees;
}
void ClassContainer::setFeeds(FeedbackContainer *feeds) {
    this->feeds = feeds;
}


