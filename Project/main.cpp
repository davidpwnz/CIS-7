#include <cstdlib>
#include <iostream>
#include <ctime>

#include "SortedList.h"
#include "Links.h"
using namespace std;

void chooseData(Links *, int);
void printData(Links *, int);
void setCompData(Links *, int);
int setDifficulty();

int main(int argc, char** argv) {
    int size = 4, min = 1, max = 8, dif = 0, games = 0;
    bool end = false, win = false;
    srand(static_cast<unsigned int>(time(0)));
    SortedList<int> sortedLink;
    
    dif = setDifficulty();
    Links comp(dif);
    setCompData(&comp, dif);
    Links player(dif);
    
    do {
        SortedList<int> sortedLink;
        int inc = 0, del = 0;
        chooseData(&player, dif);
        cout << "Your selection: ";
        printData(&player, dif);
        

        cout << "\n\n";
        for(int i = 0; i < dif; i++) {
            if(comp.getData(i) == player.getData(i)) {
                    sortedLink.push(player.getData(i), i, "RED");
                    del++;
                    inc++;
                    if(inc == dif) {
                        end = true;
                        win = true;
                    }
            }
            else {
                for(int k = 0; k < dif; k++) {
                    if (comp.getData(i) == player.getData(k)) {
                        sortedLink.push(player.getData(k), k, "WHITE");
                        del++;
                    }
                }
            }
        }
        
        sortedLink.display();

        games++;
        if(games == 10)
            end = true;
        cout << "\n\n";
    } while(end == false);
    
    if(end == true || games == 10) {
        if(win == true)
            cout << "YOU WIN" << endl;
        else
            cout << "YOU LOSE" << endl;
        cout << "# of games: " << games << endl;
        cout << "Computer selection: ";
        printData(&comp, dif);
    }
    
    return 0;
}

void printData(Links *user, int dif) {
    for(int i = 0; i < dif; i++) {
        cout << user->getData(i);
    }
}

void chooseData(Links *user, int dif) {
    int temp;
    cout << "Enter a number (1 - 8)" << endl;
    for(int i = 0; i < dif; i++) {
        cin >> temp;
        while (temp < 1 || temp > 8) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Renter a VALID number (1 - 8)" << endl;
            cin >> temp;
        }
        user->setData(i, temp);
    }
    cin.clear();
    cin.ignore(10000, '\n');
}

void setCompData(Links *user, int dif) {
    //initialize computer sequence
    for(int i = 0; i < dif; i++) {
        user->setData(i, rand()%8+1);
        if(i > 0) {
            for(int k = 0;k < i; k++) {
                while(user->getData(i) == user->getData(k)) {
                    user->setData(i, rand()%8+1);
                    k = 0;
                }
            }
        }
    }
}

int setDifficulty() {
    int temp;
    cout << "Please choose which difficulty you would like to play:\n(Easy = 4), (Medium = 6), (Hard = 8)" << endl;
    cin >> temp;
    
    switch(temp) {
        case 4: return temp;
            break;
        case 6: return temp;
            break;
        case 8: return temp;
            break;
        default: cout << "Difficulty did not exist, please reenter your selection." << endl;
            setDifficulty();
    }
}