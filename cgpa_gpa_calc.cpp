/*
  =========================== THIS PROJECT IS TO CALCULATE CGPA AND GPA  ============================================= 
            
        
    HERE WAITAGE OF GRADES ARE:
           S = 10
           A = 9
           B = 8
           C = 7
           D = 6
           E = 5
           F = 0 ( FAILED CASE )



 */


#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
/*

FORMULA TO CALCULATE CGPA : (SUM TOTAL MARKS OBTAINED  / SUM OF MAXIMUM MARKS )  * 100      

*/

template <class T = int>
class Cgpa{
    protected:
    int maximum_marks; // here maximum marks is maximum marks possible i.e total marks 
    T marks[10];
    int subjects; // it denotes number of subjects
    public:
    void getdata(){
        
        cout << "How much subject do you have : " << endl;
        cin >> subjects;
        for (int i = 0 ; i < subjects ; i++ ){
            cout << "Enter marks for subject Number " << i+1<<endl;
            cin >> marks[i];
        }
        cout << "Enter Total Marks of subject Entered "<<endl;
        cin >> maximum_marks;

    }
    void getcgpa(){
        T sum_of_marks = 0;
        for (int i = 0 ; i < subjects ; i++ ){
            sum_of_marks = sum_of_marks + marks[i];
        }
        cout<<"-------------------------------------------------------------\n";
        cout << "\nCGPA OBTAINED IS " << (sum_of_marks*1.0/(subjects*maximum_marks))*100<< endl;

    }
};

/*1

FORMULA TO CALCULATE GPA : (SUM TOTAL MARKS OBTAINED  / SUM OF MAXIMUM MARKS )  * 100      

*/


class Gpa{
    protected:
    string failed_in;
    int sumpoints = 0; // it have sum  of all credit * grade
    int sum_of_credit = 0 ;
    int credit_value;
    int total_subjects;
    char grade;
    int chk_fail=0;
    public:
    void getcredit(){
        cout << "Enter Total Number of subject you have Enrolled for ?  " << endl;
        cin >> total_subjects;
        for (int i = 0 ; i < total_subjects ; i++ ){

            cout<<"Enter Credit of Course Number " << i+1  <<" From these (2/3/4/6/8)"<<endl;
            cin >> credit_value ;
            sum_of_credit = credit_value + sum_of_credit ;
            cout << "Enter Grade of  Subject Number "<< i+1 <<" (A/B/C/D/E/F)"<<endl;
            cin >> grade;
            if (grade == 'A' || grade== 'a'){
                sumpoints=credit_value*9+sumpoints;
            }
            else if( grade == 'S' || grade == 's'){
                sumpoints = sumpoints + credit_value*10 ;
            }

            else if( grade == 'B' || grade == 'b'){
                sumpoints = sumpoints + credit_value*8;
            }

            else if( grade == 'C' || grade == 'c'){
                sumpoints = sumpoints + credit_value*7;
            }

            else if( grade == 'D' || grade == 'd'){
                sumpoints = sumpoints + credit_value*6 ;
            }


            else if ( grade == 'E' || grade == 'e' ){
                sumpoints = sumpoints + credit_value*5 ;
            }


            else if(grade =='f'||grade=='F'){
                sumpoints = sumpoints + credit_value*0;
                chk_fail++;
                cout<<"Enter name of subject in which you got F grade  "<<endl;
                cin>>failed_in;

            }
            else{
                cout<<"Entered WRONG VALUE !!!!!!!!"<<endl;;
                break;
            }
            
        }
    }
        void showgpa(){
            if (chk_fail==0){
                cout<<"-------------------------------------------------------------\n";
                cout<<"CONGRATULATIONS ! YOUR GPA OBTAINED IS "<<(sumpoints*1.0/sum_of_credit)<<endl;             
           }
           else{
            cout<<"-------------------------------------------------------------\n";
            cout<<"FAILED"<<endl;;
            cout<<"You have got F grade in subject"<<failed_in;
           }
        }
    };

int main(){
    int op;
    cout<<"=====================================================================================================\n";
    cout<<"\n"<<endl;
    cout<<"Which Operation do you want to perform ?\n\n1. Calculate Cgpa\n2. Calculate Gpa "<<endl;
    cout<<"\n==================================================================================================="<<endl;
    cout<<"Enter Your Option From Above Mentioned ?  "<<endl;
    cin >> op ;
    if (op==1){
        int type;
        cout<<"Do You Have Any Marks In Decimal ? (1/0)"<<endl;
        cin>>type;
        if (type==1){
            Cgpa <float> sem;
            sem.getdata();
            sem.getcgpa();

        }
        else{
            Cgpa <int> sem;
            sem.getdata();
            sem.getcgpa();

        }
    }
    else if(op==2){
        Gpa sem;
        sem.getcredit();
        sem.showgpa();

    }
    cout<<"\nBEST WISHES FOR FUTURE !! "<<endl;
    cout<<"-------------------------------------------------------------\n";
}
