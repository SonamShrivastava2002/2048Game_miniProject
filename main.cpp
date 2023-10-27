#include <bits/stdc++.h>
#include "functions.h"
using namespace std;
int main(){
    game g;
    //up,down,right,left mapping
    char direction[4]; //as we have 4 directions
    direction['s'] = 0;
    direction['d'] = 1;
    direction['w'] = 2;
    direction['a'] = 3;
    //starting new game
    g.newGame();
    while(true){
        g.printMatrix();
        char data;
        cin>>data;
        if(data == 'n'){
            g.newGame();
        }
        else if(data == 'q'){
            break;
        }
        else{
            int temp = direction[data];
            g.applyChanges(temp);     
        }
    }
    return 0;
}