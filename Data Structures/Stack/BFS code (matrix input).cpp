/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a[][5]={ {0,1,0,1,0},{1,0,1,1,0},{0,1,0,0,1},{1,1,0,0,1},{0,0,1,1,0}};
    int start=0,u;
    int visited[5];
    int rear=-1,front=-1;
    int queue[10];
    
    for(int i=0;i<5;i++)
    visited[i]=0;
    
    cout<<start+1<<" ";
    visited[start]=1;
    queue[++rear]=start;
    
    while(rear!=front)
    {
        u = queue[++front];
        //cout<<u<<"UI";
        for(int v=0;v<5;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                cout<<v+1<<" ";
                visited[v]=1;
                queue[++rear]=v;
            }
        }
    }
    

    return 0;
}
