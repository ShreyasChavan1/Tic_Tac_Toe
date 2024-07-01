#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void FulliGolaGrid(vector<vector<char>>& board){
    for(int i = 0; i< 3;++i){
        for(int j = 0; j< 3;++j){
            cout<<board[i][j];
            if(j<2) cout<<"  | ";
        }
        cout<<endl;
        if(i<2) cout<<"---------------"<<endl;
        
    }
}
bool playermove(vector<vector<char>>& board, char& player){
    int row,col;
    cout<<"Please enter the row and column you want to play: ";
    cin>>row>>col;
    if(row<0||row>3||col<0||col>3||board[row][col]!=' '){
        cout<<"please enter valid input"<<endl;
        return false;
    }
    else{
        board[row][col] = player;
        FulliGolaGrid(board);
    }
    return true;
}
void pcmove(vector<vector<char>>& board, char& pc){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);
    int row,col;
    do{
        row = dis(gen);
        col = dis(gen);
    }while(board[row][col]!=' ');
    board[row][col] = pc;
    FulliGolaGrid(board);
}
bool checkwin(vector<vector<char>>& board){
    for(int i = 0; i < 3;++i){
        if((board[i][0]==board[i][1] && board[i][1] == board[i][2] && board[i][0]!= ' ') ||
        (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i] != ' ')){
            return true;
        }
    }
        if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')||
        (board[0][2]==board[1][1] && board[1][1] == board[2][0] && board[0][2]!= ' ')){
            return true;
        }
        return false;
}
bool checkdraw(vector<vector<char>>& board){
    for(int i = 0 ;i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}


int main(){
    char player = 'X';
    char pc = 'O';
    vector<vector<char>>board(3,vector<char>(3,' '));
    FulliGolaGrid(board);

    bool gamewon = false;
    bool gamedraw = false;
    while(!gamewon && !gamedraw){
        if(playermove(board,player)){
            gamewon = checkwin(board);
            if(gamewon){
                cout<<"you win the game!"<<endl;
                break;
            }
            gamedraw = checkdraw(board);
            if(gamedraw){
                cout<<"game is draw !"<<endl;
                break;
            }
            pcmove(board,pc);
            gamewon = checkwin(board);
            if(gamewon){
                cout<<"you Lost!"<<endl;
                break;
            }
            gamedraw = checkdraw(board);
            if(gamedraw){
                cout<<"game is draw !"<<endl;
                break;
            }

        }
    }
    return 0;
}