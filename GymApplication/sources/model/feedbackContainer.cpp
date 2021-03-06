//
// Created by migue on 10/06/2022.
//
#include "DuplicatedDataException.h"
#include "feedback.h"
#include "feedbackContainer.h"

using namespace std;

list<Feedback>::iterator FeedbackContainer::searchCla(int number, const string& initials){
    list<Feedback>::iterator it = feedbacks.begin();
    for (; it != feedbacks.end(); ++it){
        Class * classes = it->getClass();
        Client * client = it->getClient();
        if(client->getNumber() == number && classes->getInitials() == initials){
            return it;
        }
    }
    return it;
}
list<Feedback> FeedbackContainer::getAll(){
    list<Feedback> newlist (feedbacks);
    return newlist;
}
Feedback* FeedbackContainer::getCla(int number, const string& initials){
    list<Feedback>::iterator it = searchCla(number,initials);
    if(it != feedbacks.end()){
        return &*it;
    }
    return NULL;
}

void  FeedbackContainer::add(const Feedback& feedback){
    Class* classes = feedback.getClass();
    Client* client = feedback.getClient();
    list<Feedback>::iterator it = searchCla(client->getNumber(),classes->getInitials());
    if(it == feedbacks.end()){
        feedbacks.push_back(feedback);
    }else{
        string msg = "Feedback Error";
        throw DuplicatedDataException(msg);
    }
}


