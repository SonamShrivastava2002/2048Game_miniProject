#include <bits/stdc++.h>
using namespace std;
//declaring the matrix as global variable
int  matrix[4][4];
//combinations of all directions
/*x - row
y - column
{1,0} - right
{-1,0} - left
{0,1} - down
{0,-1} - up*/
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
//generating random position on board for start
pair<int,int> generatePosition(){
    int var = 1,line,column;
    while(var){
        line = rand() % 4;
        column = rand() % 4;
        if(matrix[line][column] == 0){
            var = 0;
        }
    }
    return make_pair(line,column);
}
//adding new piece
void addPiece(){
    pair<int,int> pos = generatePosition();
    matrix[pos.first][pos.second] = 2;
}
//function for new game
void newGame(){
    //when a player starts a new game of the cells are at 0
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            matrix [i][j] = 0;
        }
    }
    addPiece();
}
//printing the matrix 
void printMatrix(){
    system("cls"); //to clear the previous matrix
    //instructions to the user
    /*taking notations from default keyboard*/
    cout<<"n - new game"<<endl;
    cout<<"w - up"<<endl;
    cout<<"a - left"<<endl;
    cout<<"s - down"<<endl;
    cout<<"d - right"<<endl;
    cout<<"q - quit game"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j] == 0){
                cout<<setw(4)<<'_'; 
                //setw function make the grid of 4x4
            }
            else{
                cout<<setw(4)<<matrix[i][j];
            }
        }
        cout<<endl;
    }
}
//checking for a valid move
bool checkMove(int row,int col,int newRow,int newCol){
    if(newRow < 0 || newCol < 0 || newRow >= 4 || newCol >= 4 || 
    (matrix[row][col] != matrix[newRow][newCol] && matrix[newRow][newCol] != 0)){
        return false;
    }
    return true;
}
//checking for win
bool win(int matrix[][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(matrix[i][j] == 2048){
                return true;
            }
        }
    }
    return false;
}
//main function where all process takes place
void applyChanges(int dir){
    int stRow = 0,stCol = 0,lineDiff = 1,colDiff = 1;
    if(dir == 0){
        stRow = 3;
        lineDiff = -1;
    }
    if(dir == 1){
        stCol = 3;
        colDiff = -1;
    }
    bool possible = 0,adding = 0;
    do{
        possible = 0;
        for(int i=stRow;i>=0 && i<4;i += lineDiff){
            for(int j=stCol;j>=0 && j<4;j += colDiff){
                int newi = i + dx[dir],newj = j + dy[dir]; 
                // cout<<i<<" "<<j<<" "<<newi<<" "<<newj<<endl;
                if(matrix[i][j] && checkMove(i,j,newi,newj)){
                    matrix[newi][newj] += matrix[i][j];
                    matrix[i][j] = 0;
                    possible = 1;
                    adding = 1;
                }
            }
        }
        if(win(matrix)){
            cout<<"Congratulations, You Won"<<endl;
            cout<<"Do you want to continue(type 'Yes' if yes else 'No')"<<endl;
            string con;
            cin>>con;
        }
    }while(possible);
    if(adding){
        addPiece();
    }
}