#include "playGame.h"
#include <iostream>
#include "level1.h"
#include <fstream>
#include "playerdetails.h"
#include "leaderBoard.h"
using namespace std;
inline string add(int a,string b){
 return to_string(a)+"*"+b;
}
inline void displaypg(int &opt){
    system("CLS");
    cout<<"1-> Start Game"<<endl;
    cout<<"2-> post Score"<<endl;
    cout<<"3-> display leaderboard"<<endl;
    cout<<"pick an option:"<<endl;
    cin>>opt;
}
void writetextfile(string s);
void selectoptions(int i);

struct player{
    string name;
    int scoretotal;
};
playGame::playGame()
{
   int lans=0;
   displaypg(lans);
   selectoptions(lans);

}//playgame
void writetextfile(string s){
    string filename("leaderB.txt");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
    file_out << s << endl;
    cout <<"player added!" << endl;
}//writetextfile
void selectoptions(int i){
     if(i==1){
        level1 l1;
    }else if(i==2){
        string n;
        player playerinfo;
        playerdetails pd;//class that keeps track of the total score in the game
        if(pd.gettotalscore()>0){//checks if the players score is greater than 0
            playerinfo.scoretotal=pd.gettotalscore();
            cout<<"Enter your name:"<<endl;
            cin>>n;
            playerinfo.name=n;
            string sLine=to_string(playerinfo.scoretotal)+"*"+playerinfo.name;
            writetextfile(sLine);
            playGame();
        }else{
            cout<<"Score is 0. play the game and then post your score"<<endl;
            playGame();
        }
    }else if(i==3){
       leaderBoard lb;
    }
}
playGame::~playGame()
{
    //dtor
}
