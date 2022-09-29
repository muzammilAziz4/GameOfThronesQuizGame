#include "level3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "playerdetails.h"
#include "playGame.h"
using namespace std;
void generateRandomNumbers3();
void readTFile3(int *n);
void display3();
void display3(string s);
string correctanswer3;
int icorrectanswer3;
int score3;
int questionCounter3;
void shuffle3(string s1,string s2,string s3);
void displayfeedback3();
level3::level3()
{
    score3=0;
    questionCounter3=0;
    generateRandomNumbers3();
    displayfeedback3();

}

void generateRandomNumbers3(){
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
 readTFile3(numbers);
}//generate Numbers


void readTFile3(int *n){//receives a pointer to the array as a parameter
    string sinput;//used to get user input
// Create a text string, which is used to output the text file
    string myText;
for(int k=0;k<10;k++){//loop array
        int arrRandomNum=n[k];
        bool bfound=false;
        // Read from the text file
        ifstream MyReadFile("qlevel3.txt");
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (MyReadFile, myText) && bfound==false) {
            // Output the text from the file
            int j=myText.find_first_of("*");
            string sNum=myText.substr(0,j);
            int inum=stoi(sNum);
            if(arrRandomNum==inum){//if the number in the array matches the question number in the textfile
                    display3();//displays the progress and score
                    display3(myText);//used to seperate the line and display the question and answers
                    cin>>sinput;
                    int iInput=stoi(sinput);
                    if(iInput==icorrectanswer3){
                        score3=score3+1;
                        cout<<"your answer is correct"<<endl;
                    }else{
                        cout<<"incorrect answer,the correct answer is:"<<correctanswer3<<endl;
                    }//else
                    cout<<"Enter '1' followed by the Enter key to continue:"<<endl;
                    cin>>sinput;
            }//if
  }//while
 // Close the file
  MyReadFile.close();
}//for k
}//readTFile
void display3(string s){
    string incorrectans1;
    string incorrectans2;
    int j=s.find_first_of("*");
    string temp;//used to display up until the delimiter
    temp=s.substr(0,j);
    //display the question
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    temp=s.substr(0,j);
    cout<<temp<<endl;
    //get the correct answer from text file
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    correctanswer3=s.substr(0,j);
    //get the remaining incorrect answers
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    incorrectans1=s.substr(0,j);
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    incorrectans2=s.substr(0,j);
    shuffle3(correctanswer3,incorrectans1,incorrectans2);
    //instructions
    cout<<"Enter the number for your choice:"<<endl;

}//display2(string s) function
void display3(){
    system("CLS");//clear the console
    questionCounter3++;
    cout<<"level 3 PROGRESS-This is question:"<<questionCounter3<<"/10      ";
    cout<<"SCORE: "<<score3<<endl;
}
void shuffle3(string s1,string s2,string s3){
    int answerpositions[3]={0,0,0};//stores the order in which the answers will be displayed
    int randoma;
    int n=0;
    while(n<3){
       randoma=1+(rand()%3);
       bool bfound=false;
       for(int j=0;j<3;j++){
             if(answerpositions[j]==randoma){
                 bfound=true;
             }//if
       } //for
       if(bfound==false){
            if(randoma==1){
                icorrectanswer3=n+1;
                cout<<n+1<<":"<<s1<<endl;
            }else if(randoma==2){
                cout<<n+1<<":"<<s2<<endl;
            }else if(randoma==3){
                cout<<n+1<<":"<<s3<<endl;
            }//else
            answerpositions[n]=randoma;
            n++;
       }//if bfound==false
    }//while
}
void displayfeedback3(){
    system("CLS");//clear the console
    cout<<"your final score for level 3 is :"<<score3<<endl;
    playerdetails pd;
    pd.settotalscore(score3);
    cout<<"your total score out of 30 for all three levels is:"<<pd.gettotalscore()<<endl;
    cout<<"Enter 1 to continue to the menu where you will be able to post your score to the leader board"<<endl;
    int i;
    cin>>i;
    if(i==1){
       playGame pg;
    }else{
        cout<<"invalid input"<<endl;
    }
}
level3::~level3()
{
    //dtor
}
