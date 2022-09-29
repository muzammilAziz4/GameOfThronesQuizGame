#include "level1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "level2.h"
#include "playerdetails.h"
#include "playGame.h"
using namespace std;
void generateRandomNumbers();
void readTFile(int *n);
void display(string s);
void displayfeedback();
string correctanswer;
int score;
int questionCounter;
level1::level1()
{
    score=0;
    generateRandomNumbers();
    displayfeedback();
}
void generateRandomNumbers(){
 int numbers[10]={0,0,0,0,0,0,0,0,0,0};//array to store random question numbers with default values
 srand(time(0));
 int rNumber;
 int i=0;
 bool bfound;
 while (i<10){
    rNumber=1+(rand()%20);
    bfound=false;
    for(int j=0;j<10;j++){
        if(numbers[j]==rNumber){
            bfound=true;
        }//if
    } //for
    if(bfound==false){
        numbers[i]=rNumber;
        //cout<<numbers[i]<<endl;
        i++;
    }
 }//while
 readTFile(numbers);
}//generate Numbers
void readTFile(int *n){
    string sinput;//used to get user input
// Create a text string, which is used to output the text file
    string myText;

 for(int k=0;k<10;k++){//loop array
        int arrRandomNum=n[k];
        bool bfound=false;
        // Read from the text file
        ifstream MyReadFile("qlevel1.txt");
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (MyReadFile, myText) && bfound==false ) {
            // get the text from the file
            int j=myText.find_first_of("*");
            string sNum=myText.substr(0,j);
            int inum=stoi(sNum);
            if(arrRandomNum==inum){//check if the random number generated is in the text file
                    bfound=true;
                    display(myText);
                    cin>>sinput;
                    if(sinput==correctanswer){
                        score=score+1;
                    }//if input
            }//if arr
  }//while
 // Close the file
  MyReadFile.close();
 }//for k
}//readTFile
void display(string s){
    system("CLS");//clear the console
    questionCounter++;
    cout<<"LEVEL 1 PROGRESS-This is question: "<<questionCounter<<"/10     ";
    cout<<"SCORE: "<<score<<endl;
    int j=s.find_first_of("*");
    string temp;
    temp=s.substr(0,j);
    //display the question
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    temp=s.substr(0,j);
    cout<<temp<<endl;
    //get the correct answer from text file
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    correctanswer=s.substr(0,j);//stores the correct answer in correct answer
    //instructions
    cout<<"enter 't' for true or 'f' for false:"<<endl;

}
void displayfeedback(){
    system("CLS");//clear the console
    cout<<"your final score for level 1 is: "<<score<<endl;
    playerdetails pd;
    pd.settotalscore(score);
    cout<<"your total score for the game this far is: "<<pd.gettotalscore()<<endl;
    cout<<"Enter 1 to continue to level 2"<<endl;
    int i;
    cin>>i;
    if(i==1){
        new level2;
    }else{
        cout<<"invalid input"<<endl;
    }
}
level1::~level1()
{
    //dtor
}
