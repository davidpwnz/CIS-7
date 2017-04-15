#include "Links.h"
#include <cstdlib>
#include <iostream>

Links::Links() {
}

Links::Links(int size) {
    //Set comp array to new size of 4
    user = new int[size];
}

Links::~Links() {
    delete [] user;
}

void Links::setData(int i, int data) {
        this->user[i] = data;
    }