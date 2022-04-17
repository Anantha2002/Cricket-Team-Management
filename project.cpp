#include<iostream>
#include<fstream>
#include <cstdlib>
using namespace std;
void funStatPrint(string s1);
//main parent class PERSOn
class Person {
public:
    Person();
    string name,DOB,Nationality,Description,Gender;
    void getData();
    //void virtual showData();

};
//Constructor of the PERSON
Person::Person()
{
    //ctor
}

//function to get the data
void Person::getData()
{
    cout<<"Enter the name :";
    getline(cin,name);
    cout<<"Enter the DOB :";
    cin>>DOB;
    cout<<"Enter the Nationality of the Person:";
    cin>>Nationality;
    cout<<"Enter the Description of the Person:";
    getchar();
    getline(cin,Description);
    cout<<"Enter the Gender of the Person:";
    cin>>Gender;

}
//1st inherited class of the person PLAYER to store player information
class Player:public Person
{
    public:
        Player();
        int Role;
        string BatStyle,BowlStyle,DebutYear;
        friend ostream& operator<<(istream &in, Player &p);
        //void writeData(Player const &p);
        void getData();
        //void getStats();
        void getRole();
        void ShowData();


    protected:

    private:
};
//constructor to the player class
Player::Player()
{

}
//function to get data for the player class
void Player::getData()
{
    Person::getData();
    cout<<"Enter the jersey number of the player:";
    cin>>Role;
    cout<<"Enter the batting Style of the player:";
    cin>>BatStyle;
    cout<<"Enter the bowling Style of the player:";
    cin>>BowlStyle;
    cout<<"Enter the debut year:";
    cin>>DebutYear;
    fstream f;
    f.open("player.txt",ios::app|ios::in);
    if(f)
     {
         f<<name<<"\t\t";
         f<<DOB<<"\t\t";
         f<<Nationality<<"\t\t";
         f<<Description<<"\t\t";
         f<<Role<<"\t\t";
         f<<BatStyle<<"\t\t";
         f<<BowlStyle<<"\t\t";
         f<<DebutYear<<"\n";
     }
    //f.seekg(0,ios::beg);
    else
        cout<<"Error"<<endl;
    f.close();
    /*f.open("player.txt",ios::app|ios::in);
    string word;
    while(f>>word)
        cout<<word<<endl;*/
}

/*void Player::ShowData()
{

}*/
//Inherited class of the main class person COACH
class Coach:public Person
{
    public:
    Coach();
    string CoachType;
    float Experience;
    void getData();

};
//Constructor for the class Coach
Coach::Coach()
{
    //ctor
}
//Function to get data and store the coach details
void Coach::getData()
{
    Person::getData();
    cout<<"Enter the type of coach:";
    cin>>CoachType;
    cout<<"Enter the experience of the coach:";
    cin>>Experience;
    fstream f;
    f.open("Coach.txt",ios::app|ios::in);
    if(f)
    {
        f<<name<<"\t\t\t";
        f<<DOB<<"\t\t\t";
        f<<Nationality<<"\t\t\t";
        f<<Description<<"\t\t\t";
        f<<CoachType<<"\t\t";
        f<<Experience<<"\n";
        f.close();


    }
    else
        cout<<"ERROR"<<endl;
}
class PlayerStats
{
public:
    Player p;
    double Average;
    int Innings,Centuries,Fifties,runs;
    void getData();
};
void PlayerStats::getData()
{
    p.getData();
    cout<<"Enter the total innings of the player:";
    cin>>Innings;
    cout<<"Enter the no. of Centuries Scored by the player:";
    cin>>Centuries;
    cout<<"Enter the no. of fifties scored by the player:";
    cin>>Fifties;
    cout<<"Enter the total runs Scored by the player:";
    cin>>runs;
    Average=runs/Innings;
    fstream f;
    f.open("PlayerStats.txt",ios::app|ios::in);
    if(f)
    {
        f<<p.name<<"\t\t";
         f<<Innings<<"\t\t\t\t";
         f<<Centuries<<"\t\t\t";
         f<<Fifties<<"\t";
         f<<runs<<"\t\t";
         f<<Average<<"\n";
    }
}
void MenuPage()
{
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\tWELCOME TO IPL TEAM MANAGEMENT SYSTEM"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t -----------------------------------"<<endl;
    cout<<"Press 1 to enter the Details of person"<<endl;
    cout<<"Press 2 to enter the Details of Coach"<<endl;
    cout<<"Press 3 to show stats of a existing player"<<endl;
    cout<<"Press 4 to show all the stats of existing players"<<endl;
    cout<<"Press 5 to show all the existing players"<<endl;
    cout<<"Press 6 to show all the existing coach"<<endl;
    cout<<"Press 0 to exit"<<endl;
    cout<<"Enter your choice:";
}
void funStatPrint(string s1)
{
    //cout<<"Inside function"<<endl;
    fstream f;
    int lenS,countS=0;
    f.open("PlayerStats.txt",ios::in);
    string s2;
    lenS=s1.length();
    if(f.is_open())
    {
        while(getline(f,s2))
        {
            for(int i=0;i<lenS;i++)
            {
                if(s1[i]==s2[i])
                    countS++;
            }
            if(countS==lenS)
                cout<<s2<<endl;
            else
                cout<<"NO RECORD FOUND FOR THE NAME"<<endl;
        }
    }
    else
        cout<<"CANT OPEN THE FILE"<<endl;
        f.close();
}
int main()
{
    int choice;
    string Name;
    char Cont='y';

    while(Cont=='y')
    {
        MenuPage();
        cin>>choice;
        getchar();
        if(choice==1)
        {
            char ch1='y';
            while(ch1=='y')
            {
                PlayerStats *p1;
                p1=new PlayerStats;
                p1->getData();
                delete p1;
                cout<<"do you wanna continue(y/n)";
                cin>>ch1;
                getchar();
            }getchar();
            main();

        }
        else if(choice == 2)
        {
            char ch2='y';
            while(ch2=='y')
            {
                Coach *c1;
                c1= new Coach;
                c1->getData();
                delete c1;
                cout<<"Do you wanna continue(y/n)";
                cin>>ch2;
                getchar();
            }main();
        }
        else if(choice == 3)
        {
            char ch3='y';
            while(ch3 == 'y')
            {
                cout<<"Enter the player name:";
                getline(cin,Name);
                //getchar();
                cout<<"Name\t\tMatches played\t\tCenturies\t\tFifties\t\tRuns\t\tAvg"<<endl;
                funStatPrint(Name);
                cout<<"Do you wanna continue(y/n):";
                cin>>ch3;
                getchar();
            }main();

        }
        else if(choice==4)
        {
            system("cls");
            fstream f;
            string s;
            f.open("PlayerStats.txt",ios::in);
            if(f)
            {
                cout<<"Name\t\tMatches played\t\tCenturies\t\tFifties\t\tRuns\t\tAvg"<<endl;
                while(getline(f,s))
                {
                    cout<<s<<endl;
                }
                cout<<"END OF THE PLAYER"<<endl;
            }
            else
                cout<<"NOT ABLE TO OPEN THE FILE CONTACT ADMIN";
            getchar();
            main();
        }
        else if(choice==5)
        {
            system("cls");
            fstream f;
            string s;
            f.open("Player.txt",ios::in);
            if(f)
            {
                cout<<"Name\tDOB\tNationality\tDescription\tJersy number\tBatting style\tBowling Style\tDebut Year"<<endl;
                while(getline(f,s))
                {
                    cout<<s<<endl;
                }
                cout<<"END OF THE PLAYER"<<endl;
            }
            else
                cout<<"NOT ABLE TO OPEN THE FILE CONTACT ADMIN";
                getchar();
            main();
        }
        else if(choice == 6)
        {
            system("cls");
            fstream f;
            string s;
            f.open("Coach.txt",ios::in);
            if(f)
            {
                cout<<"Name\tDOB\tNationality\tDescription\tCoach Type\tExperience" <<endl;
                while(getline(f,s))
                {
                    cout<<s<<endl;
                }
                cout<<"END OF THE Coach list"<<endl;
            }
            else
                cout<<"NOT ABLE TO OPEN THE FILE CONTACT ADMIN";
            getchar();
            main();

        }
        else
        {
            break;
        }
        Cont='n';
    }
}
