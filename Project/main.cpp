#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


int main(int argc, char** argv) {
    int player[4];
    int comp[4];
    bool end = false;
    srand(time(0));
    
    for(int i = 0; i < 4; i++) {
        comp[i] = rand()%6+1;
        if(i > 0) {
            for(int k = 0;k < i; k++) {
                while(comp[i] == comp[k]) {
                    comp[i] = rand()%6+1;
                    k = 0;
                }
            }
        }
    }
    
    do {
        int games = 0;
        cout << "Enter numbers 1 - 6" << endl;    
        for(int i = 0; i < 4; i++) {
            cin >> player[i];
        }

        for(int i = 0; i < 4; i++) {
            cout << player[i];
        }

        cout << "\n\n";
        for(int i = 0; i < 4; i++) {
            int inc = 0;
            if(comp[i] == player[i]) {
                    cout << "RED " << "Space: " << i+1 << endl;
                    inc++;
                    if(inc = 4)
                        end = true;
            }
            else {
                for(int k = 0; k < 4; k++) {
                    if (comp[i] == player[k])
                        cout << "WHITE " << "Space: " << k+1 <<endl;
                }
            }
        }
        games++;
        if(games == 10)
            end == true;
    } while(end == false); 

    
    cout << "\n\n";
    
    for(int i = 0; i < 4; i++) {
        cout << comp[i];
    }
    
    return 0;
}