//
// Created by Kisely Tamás on 2018. 10. 10..
//

#ifndef STACK_H
#define STACK_H


#include<stdio.h>
#include<stdexcept>
#include<string>

class stack_exception: public std::exception
{
    std::string message;

public:
    stack_exception(std::string message):message(message){};

    const char * what()const throw() {
        return message.c_str();
    }

};

class Stack
{
    unsigned int elementNum;
    int *pData;

public:
    Stack() {elementNum=0;pData=NULL;}
    // A másoló konstruktor szükséges a dinamikus adattagok miatt
    Stack(const Stack& theOther);
    // A destruktor felszabadítja a dinamikus adattagot
    ~Stack() {if(pData!=NULL) delete[]pData;}

    bool isEmpty()const{return !elementNum;}
    void pop(int& element);
    void push(int element);
    // Az = operátor, amely a mély másolást valósítja meg
    const Stack& operator= (const Stack& theOther);
};


#endif //STACK_H
