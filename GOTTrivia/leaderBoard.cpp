#include "leaderBoard.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "playGame.h"
using namespace std;
std::vector<string> players;//stores each line from the text file
template <class T>
class  swapplayer{
public:
    swapplayer(T &b1,T &b2){
        T temp;
        temp=b2;
        b2=b1;
        b1=temp;
    }
};
void readtextfile();
void sortvector(std::vector<string> &data1);
void displayplayers(std::vector<string> &data1);
leaderBoard::leaderBoard()
{
    players.clear();
    readtextfile();
    sortvector(players);
    displayplayers(players);
}
void readtextfile(){
    // Create a text string, which is used to output the text file
    string myText;
// Read from the text file
   ifstream MyReadFile("leaderB.txt");
 // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    players.push_back(myText);
  }//while
 // Close the file
  MyReadFile.close();
}
void sortvector(std::vector<string> &data1){
    string p1,p2;
    for(int i=0;i<data1.size();i++){
        for(int j=i+1;j<data1.size();j++){
            p1=data1[i];
            p2=data1[j];
            int n1=p1.find_first_of("*");
            int n2=p2.find_first_of("*");
            if(stoi(p1.substr(0,n1))<stoi(p2.substr(0,n2))){
                swapplayer<string>(p1,p2);

            }//if
            data1[i]=p1;
            data1[j]=p2;
        }//j
    }//for int i
}//sort vector
void displayplayers(std::vector<string> &data1){
    system("CLS");//clear the console
    string sPlayer;
    cout<<"\t score \t name"<<endl;
    for(int i=0;i<data1.size();i++){
        sPlayer=data1[i];
        int j=sPlayer.find_first_of("*");
        cout<<i+1<<"-\t"<<sPlayer.substr(0,j)<<"\t"<<sPlayer.substr(j+1,sPlayer.length())<<endl;
    }
    cout<<"Enter 1 to go to the menu:"<<endl;
    int i;
    cin>>i;
    if(i==1){
        new playGame;
    }else{
        cout<<"invalid input"<<endl;
    }
}//display
leaderBoard::~leaderBoard()
{
    //dtor
}
