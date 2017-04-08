#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Links.h"
using namespace std;

void chooseData(Links *);
void printData(Links *);
void setCompData(Links *);

int main(int argc, char** argv) {
    int size = 4;
//    int player[size];
//    int comp[size];
    
    int games = 0;
    bool end = false;
    srand(static_cast<unsigned int>(time(0)));
    
    Links comp(size);
    setCompData(&comp);
    Links player(size);

    
    do {
        int inc = 0;
        
        chooseData(&player);
        cout << "Your selection: ";
        printData(&player);
        

        cout << "\n\n";
        for(int i = 0; i < 4; i++) {
            if(comp.getData(i) == player.getData(i)) {
                    cout << "RED " << "Space: " << i+1 << endl;
                    inc++;
                    if(inc == 4)
                        end = true;
            }
            else {
                for(int k = 0; k < 4; k++) {
                    if (comp.getData(i) == player.getData(k))
                        cout << "WHITE " << "Space: " << k+1 <<endl;
                }
            }
        }
        games++;
        if(games == 10)
            end == true;
        cout << "\n\n";
    } while(end == false);
    
    
    if(end == true || games == 10) {
        cout << "Computer selection: ";
        printData(&comp);
    }
    
    return 0;
}

void printData(Links *user) {
    for(int i = 0; i < 4; i++) {
        cout << user->getData(i);
    }
}

void chooseData(Links *user) {
    int temp;
    cout << "Enter a number (1 - 6)" << endl;
    for(int i = 0; i < 4; i++) {
        cin >> temp;
        while (temp < 1 || temp > 6) {
            cout << "Renter a VALID number (1 - 6)" << endl;
            cin >> temp;
        }
        user->setData(i, temp);
        
    }
    cin.clear();
    cin.ignore(10000, '\n');
}

void setCompData(Links *user) {
    //initialize computer sequence
    for(int i = 0; i < 4; i++) {
        user->setData(i, rand()%6+1);
        if(i > 0) {
            for(int k = 0;k < i; k++) {
                while(user->getData(i) == user->getData(k)) {
                    user->setData(i, rand()%6+1);
                    k = 0;
                }
            }
        }
    }
}