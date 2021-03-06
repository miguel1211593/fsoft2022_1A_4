//
// Created by migue on 10/06/2022.
//
#include "gtest/gtest.h"
#include "feedback.h"
#include "InvalidDataException.h"


TEST(FeedbackConstructorTest, ValidFeedback) {
    bool flag = false;
    try{
        Feedback feedback ((Class*)1, (Client*)1,0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(FeedbackConstructorTest, InvalidFeedback) {
    bool flag = false;
    try{
        Feedback feedback ((Class*)0, (Client*)1,0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}
TEST(FeedbackSetClassTest, InvalidFeedback) {
    Feedback feedback((Class*)1,(Client*)1,0);
    bool flag = false;
    try{
        feedback.setClass((Class*)0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FeedbackSetClassTest, ValidFeedback) {
    Feedback feedback((Class*)1,(Client*)1,0);
    bool flag = false;
    try{
        feedback.setClass((Class*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(FeedbackSetClientTest, InvalidFeedback) {
    Feedback feedback((Class*)1,(Client*)1,0);
    bool flag = false;
    try{
        feedback.setClient((Client*)0);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FeedbackSetClientTest, ValidFeedback) {
    Feedback feedback((Class*)1,(Client*)1, 0);
    bool flag = false;
    try{
        feedback.setClient((Client*)1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}
TEST(FeedbackSetFeedTest, InvalidFeedback) {
    Class classes ("PIES", "Pilates");
    Client client ("Miguel", 18);
    int feed = 3;
    Feedback feedback(&classes,&client,feed);
    bool flag = false;
    try{
        feedback.setFeed(1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FeedbackSetFeedTest, ValidFeedback) {
    Feedback feedback((Class*)1,(Client*)1, 1);
    bool flag = false;
    try{
        feedback.setFeed(1);
    }catch(InvalidDataException& e){
        flag = true;
    }
    EXPECT_FALSE(flag);
}



