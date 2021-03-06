//
// Created by migue on 09/06/2022.
//
#include "mockdata.h"
#include "DuplicatedDataException.h"




void  mockdata::insertClasses(ClassContainer& container){
    for (size_t  i = 0; i < this->n_classes.size();i++){
        Class obj(this->n_i_cla[i],this->n_classes[i]);
        try{
            container.add(obj);
        }catch(DuplicatedDataException& e){

        }
    }
}

void  mockdata::insertClients(ClientContainer& container){
    for (size_t i = 0; i < n_clients.size();i++){
        int age = 15 + rand() % 80;
        Client obj(n_clients[i],age);
        container.add(obj);
    }
}

void  mockdata::insertEmployees(EmployeeContainer &container) {
    for (size_t i = 0; i < n_emp.size();i++){
        Employee obj(n_i_emp[i],n_emp[i]);
        try{
            container.add(obj);
        }catch(DuplicatedDataException& e){

        }
    }
}

Class * mockdata::getRandomClass(ClassContainer &classes) {
    list<Class> listClass = classes.getAll();
    list<Class>::iterator it = listClass.begin();
    int is = rand() % listClass.size();
    for(int i = 0; i < is; i++){
        it++;
    }
    string initials = it->getInitials();
    Class * ptr = classes.get(initials);
    return ptr;
}
void  mockdata::insertEnrolls(ClientContainer& clients, ClassContainer& class1, EnrollContainer & container){
    list<Client> listClient = clients.getAll();
    for(list<Client>::iterator it = listClient.begin(); it != listClient.end(); ++it){
        Client * client =  clients.get(it->getNumber());
        int n = 1 + rand() % ENROLLS_NR;
        for(int i = 0; i < n; i++){
            Class * classes = getRandomClass(class1);
            try{
                Enroll enroll(classes, client);
                container.add(enroll);
            }catch (DuplicatedDataException& e){
            }

        }
    }
}
void mockdata::insertFeedback(ClassContainer &class1, ClientContainer &client1,FeedbackContainer &container) {
    list<Client> lstClient = client1.getAll();
    for(list<Client>::iterator it = lstClient.begin(); it != lstClient.end(); ++it){
        Client * client =  client1.get(it->getNumber());
        int n = 1 + rand() % FEEDBACK_NR;
        for(int i = 0; i < n; i++){
            Class * classes = getRandomClass(class1);
            int feeds = 1 + rand()%5;
            try{
                Feedback feedback(classes, client, feeds);
                container.add(feedback);
            }catch (DuplicatedDataException& e){
            }

        }
    }
}

void  mockdata::insertLecture(ClassContainer & classes, EmployeeContainer & employees ){
    list<Employee> listEmployee = employees.getAll();
    for (list<Employee>::iterator it=listEmployee.begin(); it != listEmployee.end(); ++it){
        Employee * ptr = employees.get(it->getInitials());
        LectureContainer& container = ptr->getLectures();
        int n = 1 + rand() % LECTURES_NR;
        for(int i = 0; i < n; i++){
            Class * classet = getRandomClass(classes);
            try{
                Lecture lecture(classet);
                container.add(lecture);
            }catch (DuplicatedDataException& e){
            }
        }
    }
}

void  mockdata::gData(Gym& gym){
    srand (time(NULL));
    insertClasses(gym.getClassContainer());
    insertClients(gym.getClientContainer());
    insertEmployees(gym.getEmployeeContainer());
    insertEnrolls(gym.getClientContainer(), gym.getClassContainer(),gym.getEnrollContainer());
    insertLecture( gym.getClassContainer(), gym.getEmployeeContainer());
    insertFeedback(gym.getClassContainer(),gym.getClientContainer(),gym.getFeedbackContainer());


}


