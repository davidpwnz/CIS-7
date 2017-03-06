/* 
 * File:   main.cpp
 * Author: David Covell
 * Created on February 21, 2017, 8:35 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    char revCrdCard[SIZE-1];
    int sumNum = 0;
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Now create a function that fills the last digit
    
    //Added last digit and displays all digits
    cout << "Added number for last digit" << endl;
    crdCard[SIZE-1] = rand()%10+48;
    for(int i = 0; i < SIZE;i++) {
        cout << crdCard[i];
    }
    cout << endl;
    
    //Places in reverse order without last digit
    cout << "Numbers in reverse order without last digit" << endl;
    for(int i = SIZE-3, k = 0; i >= 0;i--, k++){
        revCrdCard[k] = crdCard[i];
        cout << revCrdCard[k];
    }
    cout << endl;

    cout << endl;
    cout << "Odd placed numbers multiplied by 2" << endl;
    for(int i = 0; i < SIZE-2;i++) {
        if(i%2 == 0) {
            int tempNum((revCrdCard[i] - 48));
            tempNum *= 2;
            if(tempNum > 9)
                tempNum -= 9;
            revCrdCard[i] = static_cast<char>(tempNum+48);
        }
            
        cout << revCrdCard[i];
    }
    cout << endl;
    for(int i = 0; i < SIZE-2; i++) {
        int tempNum((revCrdCard[i] - 48));
        sumNum = sumNum + tempNum;
        if(i == SIZE-3)
            cout << "SUM: " << sumNum << endl;
    }
    
    
    cout << "Modular: ";
    cout << sumNum*9%10 << endl;
    //using the Luhn Algorithm
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    cout << "Last Digit: ";
    cout << crdCard[SIZE-1] << endl;
    if(sumNum*9%10 == (crdCard[SIZE-1]-48))
        cout << "VERIFIED SUCCESSFUL" << endl;
    else
        cout << "VERIFICATION FAILED" << endl;
    
    cout << endl;
    
    
    //Exit Stage Right
    return 0;
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}



