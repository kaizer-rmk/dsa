#include<iostream>
#include<algorithm>

using namespace std;

struct point {
    int x,y;
};

bool mycmp(point p1,point p2){
    return (p1.x<p2.x);
}

int main(){

    point p[] = {{3,10},{2,8},{5,4}};
    sort((p),p+3,mycmp);

    for(auto i : p)
        cout<<"("<<i.x<<","<<i.y<<")"<<" ";

    return 0;
}