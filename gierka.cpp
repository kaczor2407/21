#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using  namespace std;

HANDLE h;

string log;
int pass;
int losuj_player,losuj_komputer;
static int licznik_playera = 0,licznik_komputera = 0;
char gra;
string nazwy_kart[13] = {"dwojka","trojka","czworka","piatka","szostka","siodemka","osemka","dziewiatka",
                         "dziesiatka","jopek","dama","krol","as"
                        };
int wartosci_kart[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

void Menu();
class Karty;
class Player;
vector <Karty> karty;
vector <Player> add_player;

class Player
{
public:
    string login;
    int password;
    Player(string,int);
};

class Karty
{
public:
    string nazwa;
    int wartosc;
    Karty(string,int);
    void wyswietl_player();
    void wyswietl_komputer();
    void wyswietl_karty();

};

Player::Player(string l,int p)
{
    login = l;
    password = p;
}

Karty::Karty(string n,int w)
{
    nazwa = n;
    wartosc = w;
}

void Karty::wyswietl_player()
{
    cout<<"You fated a "<<nazwa;
    cout<<" for "<<wartosc<<endl;
}

void Karty::wyswietl_komputer()
{
    cout<<"Computer fated "<<nazwa;
    cout<<" for "<<wartosc<<endl;
}

void Karty::wyswietl_karty()
{
    cout<<nazwa<< " " <<wartosc<<endl;
}
void add_player_to_game()
{
    system("CLS");
    cout<<"Loading ";
    for(int i = 0 ; i < 10 ; i++)
    {
        cout<<"#";
        Sleep(300);
    }
    system("CLS");
    cout<<"Write you login : ";
    cin>>log;
    cout<<"\nWrite your password :";
    cin>>pass;
    add_player.push_back(Player(log,pass));
    system("CLS");
    cout<<"Loading ";
    for(int i = 0 ; i < 10 ; i++)
    {
        cout<<"#";
        Sleep(300);
    }
    system("CLS");
    cout<<"-----Account Added-----";
    Sleep(1500);
    system("cls");
    Menu();

}

void dodawanie_Kart()
{
    system("CLS");
    cout<<"Loading ";
    for(int i = 0 ; i < 10 ; i++)
    {
        cout<<"#";
        Sleep(300);
    }
    for(int i = 0 ; i < 13 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            karty.push_back(Karty(nazwy_kart[i],wartosci_kart[i]));
        }
    }
    system("CLS");
    cout<<"-----Cards Added-----";
    Sleep(1500);
    system("CLS");
    Menu();
}

void tasowanie_Kart()
{
    system("CLS");
    cout<<"Loading ";
    for(int i = 0 ; i < 10 ; i++)
    {
        cout<<"#";
        Sleep(300);
    }
    for(int i = 0 ; i < karty.size() ; i++)
    {
        for(int j = karty.size() - 1 ; j >= 0 ; j--)
        {
            swap(karty[i],karty[j]);

        }
    }
    system("CLS");
    cout<<"-----Cards Shuffled-----";
    Sleep(1500);
    system("CLS");
    Menu();
}

void zagraj()
{
    if(add_player.empty() && karty.empty())
    {
        system("CLS");
        cout<<"You dont create account \n and add cards!"<<endl;
        Sleep(1500);
        system("CLS");
        Menu();

    }
    cout<<"Play Menu"<<endl;
    cout<<"Welcome "<<add_player[0].login<<" !"<<endl;
    while(licznik_playera <= 21 || licznik_komputera <= 21)
    {
        if(licznik_playera == 21 || licznik_komputera > 21)
        {
            cout<<add_player[0].login<<" won !"<<endl;
            licznik_playera = 0;
            licznik_komputera = 0;
            Menu();
        }
        else if(licznik_komputera == 21 || licznik_playera > 21)
        {
            cout<<"Computer won! " <<endl;
            licznik_playera = 0;
            licznik_komputera = 0;
            Menu();
        }

        cout<<"(g) - if you want to fate a card "<<endl;
        cout<<"(s) - if you want to surrender "<<endl;
        cin>>gra;
        system("CLS");
        if(gra == 'g' || gra == 'G')
        {
            losuj_player = rand()%52;
            karty[losuj_player].wyswietl_player();
            licznik_playera +=karty[losuj_player].wartosc;
            cout<<"Score of "<<licznik_playera<<endl;
            cout<<endl;
            losuj_komputer = rand()%52;
            karty[losuj_komputer].wyswietl_komputer();
            licznik_komputera += karty[losuj_komputer].wartosc;
            cout<<"Score of "<<licznik_komputera<<endl;
            cout<<endl;


        }
        if(gra == 's' || gra == 'S')
        {
            if(licznik_playera > licznik_komputera)
            {
                cout<<"Player "<<add_player[0].login<<" won with score "<<licznik_playera<<endl;
                licznik_playera = 0;
                licznik_komputera = 0;
                Menu();
            }
            else if(licznik_komputera > licznik_playera)
            {
                cout<<"Computer won with score "<<licznik_komputera<<endl;
                licznik_playera = 0;
                licznik_komputera = 0;
                Menu();
            }
        }
    }
    licznik_playera = 0;
    licznik_komputera = 0;
    Menu();
}

void wyswietl_Karty()
{
    int choose;
    for(int i = 0 ; i < karty.size() ; i++)
    {
        karty[i].wyswietl_karty();
    }
    cout<<"------Choose Menu------"<<endl;
    cout<<"1 - Back to Basic Menu"<<endl;
    cin>>choose;
    switch(choose)
    {
    case 1:
        system("CLS");
        cout<<"Loading ";
        for(int i = 0 ; i < 10 ; i++)
        {
            Sleep(300);
            cout<<"#";
        }
        system("CLS");
        Menu();
        break;
    default:
        break;
    }
}
void Menu()
{
    h = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

int select;
    cout<<"----------Choose Option----------"<<endl;
    cout<<"First You must create an account and add cards then you can play!"<<endl;
    cout<<" 1 - Create account "<<endl;
    cout<<" 2 - Play game " <<endl;
    cout<<" 3 - Add cards " <<endl;
    cout<<" 4 - Shuffle cards " <<endl;
    cout<<" 5 - Display cards "<<endl;
    cout<<" 6 - Exit" <<endl;
    cin>>select;
    switch(select)
    {
    case 1:
        add_player_to_game();
        break;
    case 2:
        zagraj();
        break;
    case 3:
        dodawanie_Kart();
        break;
    case 4:
        tasowanie_Kart();
        break;
    case 5:
        wyswietl_Karty();
        break;
    case 6:
        exit(0);
        karty.clear();
        add_player.clear();
        break;
    default:
        break;

    }
}

    int main()
    {
        srand(time(0));
        Menu();

        return 0;
    }


