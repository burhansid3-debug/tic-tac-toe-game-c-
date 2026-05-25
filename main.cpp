#include<iostream>
#include<vector>
using namespace std;
//function prototypes
void display_board(const vector<vector<char>>&board);
bool check_win(const vector<vector<char>>&board,char player);
bool check_draw(const vector<vector<char>>&board);
void reset_board(vector<vector<char>>&board);

//main function
int main(){
    //2d vector representing game board
    vector<vector<char>>board(3,vector<char>(3,' '));

    char currentplayer='X';
    bool gamerunning=true;

    cout<<"===================="<<endl;
    cout<<"   welcome to tic tac toe game    "<<endl;
    cout<<"===================="<<endl;

    //main game loop
    while(gamerunning){
        reset_board(board);
        currentplayer='X';
        bool matchover=false;

        //main game loop
        while(!matchover){
            display_board(board);
            int choice;
            cout<<"player "<<currentplayer<<", enter your move(1-9): ";
            cin>>choice;

            //valid input range
            if(choice<1 || choice>9){
                cout<<"invalid input range please choose numbers between 1 to 9:"<<endl;
                continue;
            }

            //map input 1 to 9 to 2d array indices
            int row=(choice-1)/3;
            int col=(choice-1)%3;
            
            //check if slot already taken
            if(board[row][col]!=' '){
                cout<<"that slot is already taken! try again."<<endl;
                continue;
            }

            //apply move
            board[row][col]=currentplayer;

            //check for win or draw
            if(check_win(board,currentplayer)){
                display_board(board);
                cout<<"testing complete! player "<<currentplayer<<" wins!\n"<<endl;
                matchover=true;
            }
            else if(check_draw(board)){
                display_board(board);
                cout<<"its a draw!\n"<<endl;
                matchover=true;
            }
            else{
                currentplayer=(currentplayer=='X') ? '0' : 'X';
            }
        }
        //replay option
        char replaychoice;
        cout<<"do you want to play again? (y/n): ";
        cin>>replaychoice;

        if(replaychoice!='y' && replaychoice!='Y'){
            gamerunning=false;
            cout<<"\nthanks for playing! goodbye."<<endl;
        }
    }
    return 0;
}

//function to dynamically display board using loops
void display_board(const vector<vector<char>>&board){
    cout<<"\n--------------------"<<endl;
    for(int i=0;i<3;++i){
        cout<<"| ";
        for(int j=0;j<3;++j){
            if(board[i][j]==' '){
                cout<<(i*3+j+1)<<" | ";
            }
            else{
                cout<<board[i][j]<<" | ";
            }
        }
        cout<<"\n--------------------"<<endl;
    }
}

//function to check win
bool check_win(const vector<vector<char>>&board,char player){
    //check rows and columns
    for(int i=0;i<3;++i){
        if((board[i][0]==player && board[i][1]==player && board[i][2]==player) || (board[0][i]==player && board[1][i]==player && board[3][i]==player)){
            return true;
        }
    }
    //check diagonals
    if((board[0][0]==player && board[1][1]==player && board[2][2]==player) || (board[0][2]==player && board[1][1]==player && board[2][0]==player)){
        return true;
    }
    return false;
}

//function to check draw
bool check_draw(const vector<vector<char>>&board){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}

void reset_board(vector<vector<char>>& board){
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            board[i][j]=' ';
        }
    }
}
