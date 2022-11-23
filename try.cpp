#include<iostream>
using namespace std;

class Mark{
    public:
        int total=0;
    public:
        Mark(){
            cout<<"No Marks Entered!!"<<endl;
        }
        Mark(int exam_mark,int course_work_mark){
            total=exam_mark+course_work_mark;
        }
        void display(){
            if(total>0)
                cout<<"Total Marks is : "<<total<<endl;
        }
};

class Grade: public Mark{
    public:
        char g='-';
        int marks=total;
    public:
        Grade():Mark(){}
        Grade(int exam_mark,int course_work_mark):Mark(exam_mark,course_work_mark){}
        void calculate_grade(){
            if(marks>=90)
                g='A';
            else if(marks>=50 || marks<90)
                g='B';
            else if(marks>=30 || marks<50)
                g='C';
            else
                g='D';
        }
        void display(){
            Mark::display();
            cout<<"Your Grade is: "<<g<<endl;
        }
};

int main(){

    Grade g1;
    g1.display();

    Grade g2(67,24);
    g2.calculate_grade();
    g2.display();
    
    return 0;
}