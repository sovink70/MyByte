#ifndef MYBYTE_H
#define MYBYTE_H

#include <iostream>

class MyByte {
public:
    unsigned char value;
    MyByte(); // Default constructor
    MyByte(const  unsigned char &new_value); // Constructor from MyByte
    MyByte(const MyByte   &new_value); // Copy constructor - создание MyByte из MyByte

    unsigned char getValue() const;
    void setValue(const  unsigned char &new_value);

    MyByte   &operator = (const MyByte   &rhs); // Copy assignment

    MyByte operator* (const MyByte&);
    MyByte operator/ (const MyByte&);
    MyByte operator+(const MyByte&);
    MyByte &operator +=(const MyByte&);
    MyByte operator- (const MyByte&);
    MyByte &operator -=(const MyByte&);

    //friend MyByte operator - (const MyByte &lhs, const MyByte &rhs);

    friend std::ostream &operator << (std::ostream &os, const MyByte &rhs);

};


bool operator== (MyByte& obj1, MyByte& obj2)
{
    if (obj1 == obj2)
        return true;
    else return false;
}

MyByte   ::MyByte() : value (0) {
    std::cerr << "Default constructor\n";
}


MyByte ::MyByte(const  unsigned char &new_value) : value(new_value) {
    std::cerr << "Constructor from byte\n";
}


MyByte   ::MyByte(const MyByte   &new_value) : value(new_value.value) {
    std::cerr << "Copy constructor\n";
}


unsigned char MyByte::getValue() const {
    return value;
}


void MyByte   ::setValue(const  unsigned char &new_value) {
    value = new_value;

    return;
}


MyByte  & MyByte   ::operator = (const MyByte   &rhs) {
    std::cerr << "Copy assignment" << std::endl;

    if (this == &rhs) {
        return *this;
    }

    value = rhs.value;

    return *this;
}

MyByte   MyByte::operator * (const MyByte   &rhs) {
    MyByte c;
    c = this->value*rhs.value;
    return c;
    }

MyByte   MyByte::operator / (const MyByte   &rhs) {
    MyByte c;
    c = this->value/rhs.value;
    return c;
    }

MyByte   MyByte::operator + (const MyByte   &rhs) {
    MyByte c;
    c = this->value + rhs.value;
    return c;
    }


MyByte& MyByte::operator+=(const MyByte& b) {
   value = value + b.value;
   return *this;
}


MyByte MyByte::operator-(const MyByte &rhs){
    MyByte c;
    c = this->value - rhs.value;
    return c;
}

MyByte& MyByte::operator-=(const MyByte& b) {
    value = value - b.value;
    return *this;
}

std::ostream &operator << (std::ostream &os, const MyByte &rhs) {
    os << rhs.value;

    return os;
}

#endif // MYBYTE_H
