#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x, y, cost, h;

    Point( int xVal, int yVal, int costVal, int hVal){
        x = xVal;
        y = yVal;
        cost = costVal;
        h = hVal;
    }

    bool operator>(const Point &p) const {
        int currentF = cost + h;      
        int otherF = p.cost + p.h;    
        return currentF > otherF;     
    }

};

int heuristic( Point a, Point b){
    return abs(a.x - b.x) + abs(a.y - b.y);  
}

bool isValid( int x, int y, int rows, int cols){
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void aStar( int grid[5][5], Point start, Point goal){
    
    priority_queue<Point, vector<Point>, greater<Point>> pq;  
    pq.push(start);

    while( !pq.empty() ){

        Point curr = pq.top(); 
        pq.pop();

        if( curr.x == goal.x && curr.y == goal.y ){  
            cout << "Goal reached!\n"; return;
        }

        for( const pair<int, int>& direction : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}} ){

            int dx = direction.first;
            int dy = direction.second;
            int nx = curr.x + dx, ny = curr.y + dy;

            if( isValid(nx, ny, 5, 5) && grid[nx][ny] == 0 ){
                pq.push( Point(nx, ny, curr.cost + 1, heuristic(Point(nx, ny, 0, 0), goal)) );
            }
        }
    }
}


int main(){

    int grid[5][5] = {0};
    aStar(grid, Point(0, 0, 0, 0), Point(4, 4, 0, 0));
    
    return 0;
}
