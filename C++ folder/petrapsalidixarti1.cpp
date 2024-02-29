#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main ()
{
    char pcmove,gamermove,end;
     char choises[3]={'R','P','S'};
    int x,y,gamerpoints,pcpoints;
    gamerpoints=0;
    pcpoints=0;
    cout <<"a brawl is surely brewing now go:"<<endl;
    cout <<"use R(rock), P(paper) and S(scissors) to beat your opponent in a rock paper scissors game"<<endl;
    for (x=1;x<=7;x++)
    {cout<<"_________________________________________________________________"<<endl;
        cout <<"round:"<<x<<endl;
    cin >>gamermove; //player choise
    while (gamermove !='S' && gamermove !='R' && gamermove!='P' ){
        cout <<"the player choise was:"<<gamermove<<endl;
        cout<<"use R(rock), P(paper) and S(scissors) and make sure caps lock is on"<<endl;//TEST GIA SOSTO LETTER
        cin >>gamermove;
    }
    cout <<"the player choise was:"<<gamermove<<endl;
    srand (time(NULL)); 
    pcmove=choises[rand()%3]; //pc choise
    cout <<"the pc choise was:"<<pcmove<<endl;//SP FAR SO GOOD
    while (gamermove == pcmove)//an paei draw
    {
        cout<<"DRAW "<<endl;
        cin>>gamermove;
         while (gamermove != 'S' && gamermove !='R' && gamermove != 'P' ){
            cout <<"the player choise was:"<<gamermove<<endl;
            cout<<"use R(rock), P(paper) and S(scissors) and make sure caps lock is on"<<endl;// TEST GIA SOSTO LETTER
            cin >>gamermove;
         }
        cout <<"the player choise was:"<<gamermove<<endl;
        srand (time(NULL)); 
        pcmove=choises[rand()%3]; //pc choise se periptosi draw
        cout <<"the pc choise was:"<<pcmove<<endl;//SP FAR SO GOOD
    }
     if(gamermove == 'R' && pcmove == 'S'){
        gamerpoints++;
        cout<<"THE PLAYER WINS THIS ROUND"<<endl;
    }
    else if(gamermove == 'P' && pcmove == 'R'){
        gamerpoints++;
        cout<<"THE PLAYER WINS THIS ROUND"<<endl;
    }
    else if(gamermove == 'S' && pcmove == 'R'){
        gamerpoints++;
        cout<<"THE PLAYER WINS THIS ROUND"<<endl;
    }
    else{
        pcpoints++;
        cout<<"THE COMPUTER WINS THIS ROUND"<<endl;
    }
    }
    if (gamerpoints > pcpoints){
        cout<<"VICTORY THE PLAYER WINS"<<endl;
        cout<<"hey thats you :D"<<endl;
        cout<<"and the score was"<<endl;
        cout<<"_____________________________"<<endl;
    }
    else{
        cout<<"DEFEAT YOU LOSE"<<endl;
        cout<<"you gave it your best thats for sure"<<endl;
        cout<<"and the score was"<<endl;
        cout<<"_____________________________"<<endl;
    }
    cout<<"pc points:"<<pcpoints<<" | player points:"<<gamerpoints<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"press C to close the game"<<endl;
    cin >> end;
    while (end !='C') {
    return 0;
}
}
