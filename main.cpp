#include<iostream>
//#include<stdlib.h>
//#include<term.h>
//#include<curses.h>
//#include<unistd.h>
#include<ctime>
using namespace std;
char xo[9]={'1','2','3','4','5','6','7','8','9'};
class x_o
{
protected:
    char player=' ',computer=' ',xoro;

    public:
    x_o()
    {
      
        //drawing();
    }
/**/
   void drawing()
    {
       // system("clear");
        cout<<"✺✺✺✺✺✺✺✺✺✺✺✺\n";
        for(int i=0;i<9;i++)
            {
               cout<<"┇"<< xo[i]<<" ┇";
               if((i+1)%3==0)
                   cout<<endl;
            }
        cout<<"✺✺✺✺✺✺✺✺✺✺✺✺\n";
    }
    
   int check()
    {
        for(int i=0;i<9;i++)
        {
            if(xo[i]!='x'&&xo[i]!='o')
                return 0;
        }
        return 1;
    }
    char whowin()
    {
        int o=0,k=0;
        for(int i=0;i<3;i++)
        {
            for(int l=0;l<3;l++)
            {
                if(xo[(i*3)+l]=='x')
                    ++o;
                else if(xo[(i*3)+l]=='o')
                    ++k;
            }
            if(o==3)
                return'x';
                else if(k==3)
                    return'o';
            o=0;
            k=0;
            for(int h=0;h<3;h++)
            {
                if(xo[(h*3)+i]=='x')
                    ++o;
                else if(xo[(h*3)+i]=='o')
                    ++k;
            }
            if(o==3)
                return'x';
                else if(k==3)
                    return'o';
            o=0;
            k=0;
        }
        for(int i=o;i<3;i++)
        {
            if(xo[o]=='x'&& xo[4]=='x'&& xo[8]=='x')
                return 'x';
            else if(xo[2]=='o'&& xo[4]=='o'&& xo[6]=='o')
                return 'o';
            if(xo[o]=='o'&& xo[4]=='o'&& xo[8]=='o')
                return 'o';
            else if(xo[2]=='x'&& xo[4]=='x'&& xo[6]=='x')
                return 'x';
        }
        return'-';
    }
    
};
class twoplayer :public x_o
{
private:

    char p='x';
public:
    void play()
    {
        int i=0;
       tryagain: cout<<"\nwher ur position player "<<p<<":";
        cin>>i;
        if(i>9||i<1)
        { cout<<"try again enter netween 0,9 only\n"; goto tryagain;}
        if(xo[i-1]=='x'|| xo[i-1]=='o')
        {
            cout<<"try again and choose the empty position \n";
            goto tryagain;
        }
        xo[i-1]=p;
        if(p=='x')
            p='o';
        else
            p='x';
    }
};
class oneplayer:public x_o
{
public:
    void play()
    {
        int i=0;
        
        if(player=='x'||player=='o')
            goto position;
    tryagain:    cout<<"do u need play with x or o?\n";
        cin>>xoro;
        if(xoro=='x')
        {player='x'; computer='o';}
        else if(xoro=='o')
        { player='o'; computer='x';}
        else
        {cout<<"choose only x or o \n"; goto tryagain;}
        position:
       tryagain2: cout<<"\nwher ur position player "<<player<<":";
        cin>>i;
        if(i>9||i<1)
        { cout<<"try again enter netween 0,9 only\n"; goto tryagain2;}
        if(xo[i-1]=='x'|| xo[i-1]=='o')
        {
            cout<<"try again and choose the empty position \n";
            goto tryagain2;
        }
        else
            xo[i-1]=player;
        int t=0;
        
        randagain:
        srand(time(0));
        t=rand()%9;
        if(xo[t]=='x' || xo[t]=='o')
        goto randagain;
        else
        xo[t]=computer;
        
    }
};

 void playing(x_o x1,string y,twoplayer d1,oneplayer o1)
{
    x1.drawing();
    while(x1.check()==0)
    {
        if(y=="1"){d1.play();}
        else if(y=="2"){  o1.play();}
        x1.drawing();
        if(x1.whowin()=='x')
        {
            cout<<"player x win\n";
            break;
        }
        else if(x1.whowin()=='o')
        {
            cout<<"player o win\n";
            break;
        }
        
        if(x1.check()==1)
        {
            cout<<"no one win\n";
            break;
        }
}
}

int main()
{
    x_o x1;
    twoplayer d1;
    oneplayer o1;
    
    //x1.drawing();
    string y;
  tryagain:  cout<<"how u want to play?\n1-two player?\n2-one player?\n";
    cin>>y;
    if(y=="1"||y=="2")
    {
    playing(x1,y,d1,o1);
    }
    else
    {cout<<"choose only one or two and try again\n"; goto tryagain;}
    
}
