#include <bits/stdc++.h>
#include "functions.h"
using namespace std;
int main(){
    //up,down,right,left mapping
    char direction[4]; //as we have 4 directions
    direction['s'] = 0;
    direction['d'] = 1;
    direction['w'] = 2;
    direction['a'] = 3;
    //starting new game
    newGame();
    while(true){
        printMatrix();
        char data;
        cin>>data;
        if(data == 'n'){
            newGame();
        }
        else if(data == 'q'){
            break;
        }
        else{
            int temp = direction[data];
            applyChanges(temp);     
        }
    }
    return 0;
}