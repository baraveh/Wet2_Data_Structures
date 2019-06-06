//
// Created by Bar The magical on 01/05/2019.
//

#ifndef WET1_DATA_STRUCTURES_EXCEPTION_H
#define WET1_DATA_STRUCTURES_EXCEPTION_H

#include <exception>

template <typename T>
class KeyAlreadyExists : public std::exception{

    T key;
public:
    KeyAlreadyExists(const T& key = T()) : key(key) {}
    virtual const char* what() const throw(){
        return "Key already exists";
    }

    const T& whatKey() const{
        return key;
    }

};

class NoSuchKey : public  std::exception{
public:
    virtual const char* what() const throw(){
        return "No such key";
    }
};

class MemError : public std::exception{
public:
    virtual const char* what() const throw(){
        return "Memory error";
    }
};

class IllegalIndex : public std::exception{
public:
    virtual const char* what() const throw(){
        return "Illegal Index";
    }
};

class UnionFailed : public std::exception{
public:
    virtual const char* what() const throw(){
        return "KeysAreInTheSameGroup";
    }
};


class IllegalParameters : public std::exception{
public:
    virtual const char* what() const throw(){
        return "Illegal Parameters";
    }
};



#endif //WET1_DATA_STRUCTURES_EXCEPTION_H
