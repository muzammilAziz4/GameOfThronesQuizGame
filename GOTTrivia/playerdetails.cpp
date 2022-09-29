#include "playerdetails.h"
static int ts;//used to keep track of score of all three levels
playerdetails::playerdetails()
{
    //ctor
}
void playerdetails::settotalscore(int i){
    ts=ts+i;
}
int playerdetails::gettotalscore(){
    return ts;
}
playerdetails::~playerdetails()
{
    //dtor
}
