#include <iostream>

#include "gamemode.h"

using namespace std;

int main() {
    cout<<"Input the game mode:"<<endl;
    cout<<"\t0 - You are player A VS AI is player B;"<<endl;
    cout<<"\t1 - You are player A VS Your friend is player B;"<<endl;
    cout<<"\t2 - AI is player A VS AI is also player B (demo mode)"<<endl;
    int mode_;
    cin>>mode_;
    cout<<"Input the field size - from 3 to 5"<<endl;
    int size_;
    cin>>size_;

    GameMode newGame(size_, mode_);
    newGame.game();

    return 0;
}