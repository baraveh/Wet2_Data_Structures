//
// Created by Bar The magical on 01/05/2019.
//

#ifndef WET1_DATA_STRUCTURES_EXCEPTION_H
#define WET1_DATA_STRUCTURES_EXCEPTION_H

#include <exception>

class KeyAlreadyExists : public std::exception{
    virtual const char* what() const throw(){
        return "Key already exists";
    }
};

class NoSuchKey : public  std::exception{
    virtual const char* what() const throw(){
        return "No such key";
    }
};

class MemError : public std::exception{
    virtual const char* what() const throw(){
        return "Memory error";
    }
};

class IllegalIndex : public std::exception{
    virtual const char* what() const throw(){
        return "Illegal Index";
    }
};

class IllegalParameters : public std::exception{
    virtual const char* what() const throw(){
        return "Illegal Parameters";
    }
};


#endif //WET1_DATA_STRUCTURES_EXCEPTION_H
