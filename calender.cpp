#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class cal{
public:
    int day,mon,year;
    public:
    int d,m,y,lc,lp,week;
    void print();
    int DayCounter();
    int MonthCounter();
    int CountYear();
    int check();
    int leap();
    cal(int i,int j,int k){
        day=1;
        mon=1;
        year=2001;
        d=i;
        m=j;
        y=k;
    }
};
cal dat2(0,0,0);
int main(){
    int i,j,k,flag=0,w1,w2;
    cout<<"Enter date in format dd-mm-yyyy\n";
    cin>>i>>j>>k;
    cal dat(i,j,k);
    dat2=dat;
    flag=dat.check();
    if(flag==1){
    w1=dat.CountYear();
    w2=dat.MonthCounter();
    dat.week=(w1+w2)%7;

    dat.print();
    }
    else cout<<"\nINVALID DATE";
    getch();
    return 0;

    }
    int cal::check(){
        int f;
        if(((y<0)||(d<0)||(m>12)||(m<1)))
        return 0;
        if(m==2){
        f=dat2.leap();
        if(~(f)&&d>28)
        return 0;
        if(f&&d>29)
        return 0;
        }
        else if(((m==4)||(m==6)||(m==9)||(m==9))&&(day>30))
        return 0;
        else if(day>31)
        return 0;
        return 1;
        }

    int cal::CountYear(){
        int lc;
        int yc;
        if(y>2000){
        yc=y-year;
        lc=yc/4;
        return((day+yc+lc)%7);
        }
        else
        {
        yc=year-y-1;
        lc=(yc+4)/4;
        return((((yc+lc)*(day+5)))%7);
    }
    }

    int cal::MonthCounter(){
        int lc,end,wk=0;
        lc=dat2.leap();
        for(int i=1;i<m;i++){
            switch(i){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:end=31;
                    break;
            case 2:end=28+lc;
                   break;
            default:end=30;
        }
        wk=wk+end;
        }
        wk%=7;
        return wk;

    }
   void cal::print(){
        int end,lc;
        lc=dat2.leap();
        cout<<"\n\t\t               |\n\t\t              ^";
        cout<<"\n\t\tSun  Mon  Tue  Wed  THu  Fri  Sat\n\t\t";
        for(int i=0;i<week;i++)
        cout<<"     ";
        switch(m){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:end=31;
                    break;
            case 2:end=28+lc;
                   break;
            default:end=30;
        }
        for(int i=1;i<=end;i++){
           if(i==d){
               cout<<"["<<i<<"]";
               if(i>9)
               cout<<" ";
               else cout<<"  ";
               week++;
               if(week>6)
               cout<<"\n\t\t";
               week%=7;
           }
           else{
             if(i>9)   cout<<i<<"   ";
             else
             cout<<i<<"    ";
            week++;
            if(week>6)
            cout<<"\n\t\t";
            week%=7;
        }
        }
   }
   int cal::leap(){
       if(y%4)
       return 0;
       else{
       if(y%100)
       return 1;
       if((y/100)%4)
       return 0;
       return 1;
       }
       }





