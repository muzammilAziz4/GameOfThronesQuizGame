#include "level2.h"
#include "level3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "playerdetails.h"
using namespace std;
void generateRandomNumbers2();
void readTFile2(int *n);
void display2(string s);
string correctanswer2;
int icorrectanswer2;
int score2;
int questionCounter2;
void shuffle2(string s1,string s2,string s3);
void displayfeedback2();
level2::level2()
{
    score2=0;
    questionCounter2=0;
    generateRandomNumbers2();
    displayfeedback2();

}
void generateRandomNumbers2(){
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
 readTFile2(numbers);
}//generate Numbers


void readTFile2(int *n){
    string sinput;//used to get user input
// Create a text string, which is used to output the text file
    string myText;

for(int k=0;k<10;k++){//loop array
        int arrRandomNum=n[k];
        bool bfound=false;
        // Read from the text file
        ifstream MyReadFile("qlevel2.txt");
        // Use a while loop together with the getline() function to read the file line by line
        while (getline (MyReadFile, myText) && bfound==false) {
            // Output the text from the file
            int j=myText.find_first_of("*");
            string sNum=myText.substr(0,j);
            int inum=stoi(sNum);
            if(arrRandomNum==inum){//if the number in the array matches the question number in the textfile
                    bfound=true;
                    display2(myText);//sends the line of code to the display2 function
                    cin>>sinput;
                    int iInput=stoi(sinput);
                    if(iInput==icorrectanswer2){
                        score2=score2+1;
                        cout<<"your answer is correct"<<endl;
                    }else{
                        cout<<"incorrect answer,the correct answer is:"<<correctanswer2<<endl;
                    }//else
                    cout<<"Enter '1' followed by the Enter key to continue:"<<endl;
                    cin>>sinput;
            }//if
  }//while
 // Close the file
  MyReadFile.close();
}//for k
}//readTFile
void display2(string s){
    system("CLS");//clear the console
    questionCounter2++;
    cout<<"LEVEL 2 PROGRESS-This is question:"<<questionCounter2<<"/10      ";
    cout<<"SCORE: "<<score2<<endl;
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
    correctanswer2=s.substr(0,j);//stores the correct answer in correctanswer2
    //get the remaining incorrect answers
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    incorrectans1=s.substr(0,j);
    s=s.substr(j+1,s.length());
    j=s.find_first_of("*");
    incorrectans2=s.substr(0,j);
    shuffle2(correctanswer2,incorrectans1,incorrectans2);
    //instructions
    cout<<"Enter the number for your choice:"<<endl;

}//display2 function
void shuffle2(string s1,string s2,string s3){
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
                icorrectanswer2=n+1;
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
}//shuffle
void displayfeedback2(){
    system("CLS");//clear the console
    cout<<"your final score for level 2 is: "<<score2<<endl;
    playerdetails pd;
    pd.settotalscore(score2);
    cout<<"your total score for level 1 and level 2 is: "<<pd.gettotalscore()<<endl;
    cout<<"Enter 1 to continue to level 3"<<endl;
    int i;
    cin>>i;
    if(i==1){
        new level3;
    }else{
        cout<<"invalid input"<<endl;
    }
}
level2::~level2()
{
    //dtor
}
