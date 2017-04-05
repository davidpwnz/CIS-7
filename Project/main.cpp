/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 5, 2017, 1:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int player[4];
    int comp[4];
    srand(time(0));
    
    for(int i = 0, inc = 1; i < 4; i++, inc++) {
        comp[i] = rand()%4+1;
        if(i > 0) {
            for(int k = 0;k < inc; k++) {
                while(comp[i] == comp[i-(k+1)]) {
                    comp[i] = rand()%4+1;
                }
            }
        }
    }
    
//    for(int i = 0; i < 4; i++) {
//        cin >> player[i];
//    }
//   
//    for(int i = 0; i < 4; i++) {
//        cout << player[i];
//    }
    cout << endl;
    for(int i = 0; i < 4; i++) {
        cout << comp[i];
    }
    
    
    return 0;
}

