#include <iostream>
#include "maze.h"
#include "Stack.cpp"
#include "Item.h"
#define LENGTH 10
using namespace std;


enum dir{N,NE,E,SE,S,SW,W,NW};;
struct offset{
    int x;
    int y;
};

offset moves[8];


int main()
{
    moves[N]={-1,0};
    moves[NE]={-1,1};
    moves[E]={0,1};
    moves[SE]={1,1};
    moves[S]={1,0};
    moves[SW]={1,-1};
    moves[W]={0,-1};
    moves[NW]={-1,-1};
    cout << "N_X: " << moves[N].x << endl;
    int **mazeMap;
    int **mark;
    Item temp;
    mazeMap = new int*[LENGTH+1];
    mark = new int*[LENGTH+1];
    /**(1.1)~(10.10)**/
    int i,j,d;

    Stack<Item> S;

    for(i = 1 ; i <= LENGTH ; i++){
        mazeMap[i]= new int[LENGTH+1];
        mark[i]= new int[LENGTH+1];
    }

    for(i = 1 ; i <= LENGTH ; i++){
        for( j = 1 ; j <= LENGTH ; j++){
            mazeMap[i][j]=is_valid(i,j);
            mark[i][j] = 0;
            cout << mazeMap[i][j];
        }

        cout << endl;
    }
    mark[1][1] = 1;
    temp.x = 1;
    temp.y = 1;
    temp.dir = E;
    //cout << "PUSH:(" << temp.x << "," << temp.y << "," << temp.dir << ")" << endl;
    int done=0;
    S.Add(temp);

    while(!S.IsEmpty() && !done ){
        temp = *S.Delete(temp);
        int i = temp.x;
        int j = temp.y;
        int d = temp.dir;
       // cout << "POP:(" << i << "," << j << "," << d << ")" << endl;
        while( d < 8 ){
            int g = i + moves[d].x;
            int h = j + moves[d].y;
            cout <<h-moves[d].y <<"!!!!"<< endl;
            if((g == 10)&&( h == 10)){
                S.Add(temp);
                done = 1;
                break;
            }
            if((mazeMap[g][h]==1)&&(mark[g][h]==0)){
                //cout << "forward!" << endl;
                mark[g][h] = 1;
                temp.x = i;
                temp.y = j;
                temp.dir = d;
                S.Add(temp);
               // cout << "PUSH:(" << temp.x << "," << temp.y << "," << temp.dir << ")" << endl;

                i = g;
                j = h;
                d = N;
            }else d++;


        }


    }
    if(!done)
        cout << "no path!" <<endl;
    else{
        cout << "done!" << endl;
        cout << "route:(10,10,x)" << endl;
        mazeMap[10][10]=8;
        while(!S.IsEmpty()){
            temp = *S.Delete(temp);
            int i = temp.x;
            int j = temp.y;

            cout << "(" << temp.x << "," << temp.y << "," << temp.dir << ")" << endl;

            mazeMap[i][j]=8;
        }

    }

    for(i = 1 ; i <= LENGTH ; i++){
        for( j = 1 ; j <= LENGTH ; j++){
            cout << mazeMap[i][j];
        }

        cout << endl;
    }


    for(i = 1 ; i <= LENGTH ; i++){
        delete []mazeMap[i];
    }
        delete []mazeMap;

    return 0;
}

