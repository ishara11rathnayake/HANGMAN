#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

int NUM_TRY=6;
string message;

int dmode; ///dificullty mode

int checkGuess (char, string, string&); ///checkGuess function declaration

char gamename[31][79] {     ///set main screen
    "                                                                              ",
    " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
    " M                                                                           M",
    " M          HHHH   HHHH     HHHHHHH     HHHHHHH    HHHH   HHHHHHHHH          M",
    " M          HHHH   HHHH   HHHHH HHHHH   HHHHHHHH   HHHH  HHHHHHHHHH          M",
    " M          HHHHHHHHHHH  HHHHH   HHHHH  HHHH HHHH  HHHH  HHHH                M",
    " M          HHHHHHHHHHH  HHHHHHHHHHHHH  HHHH  HHHH HHHH  HHHH  HHHH          M",
    " M          HHHH   HHHH  HHHHH   HHHHH  HHHH   HHHHHHHH  HHHHHHHHHHH         M",
    " M          HHHH   HHHH  HHHHH   HHHHH  HHHH    HHHHHHH   HHHHHHHHH          M",
    " M                                                                           M",
    " M               MMMMM    MMMMM     HHHHHH      HHHHHHH    HHHH              M",
    " M               MMMMMM  MMMMMM   HHHHH HHHHH   HHHHHHHH   HHHH              M",
    " M               MMMM MMMM MMMM  HHHHH   HHHHH  HHHH HHHH  HHHH              M",
    " M               MMMM  MM  MMMM  HHHHHHHHHHHHH  HHHH  HHHH HHHH              M",
    " M               MMMM      MMMM  HHHHH   HHHHH  HHHH   HHHHHHHH              M",
    " M               MMMM      MMMM  HHHHH   HHHHH  HHHH    HHHHHHH              M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " M                                                                           M",
    " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
    };

void set_main_position()  ///set screen position
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void screen()  ///print screen
{
    set_main_position();
    HANDLE h= GetStdHandle( STD_OUTPUT_HANDLE);
    for(int i=0; i<31; i++) {
        for(int j=0; j<79; j++){
            switch(gamename[i][j]) ///add ascii characters
            {
                case 'H':
                    SetConsoleTextAttribute(h,12);
                    cout<<(char)219;
                    break;

                case 'M':
                    SetConsoleTextAttribute(h,11);
                    cout<<(char)219;
                    break;

                default:
                    cout<<gamename[i][j];
                    break;
            }
        }
        cout<<endl;
    }
}

char hangman[13][98] {      ///set hangman screen
    "                                                                                                 ",
    "                                                                                  MMMMMMMMMMMMMMM",
    "                                                                                  M      T      M",
    "                                                                                  M     OOO     M",
    "                                                                                  M     OOO     M",
    "                                                                                  M      L      M",
    "                                                                                  M  IIGGGGGII  M",
    "                                                                                  M II GGGGG II M",
    "                                                                                  M    GGGGG    M",
    "                                                                                  M    YY YY    M",
    "                                                                                  M   YY   YY   M",
    "                                                                                  M             M",
    "                                                                                  MMMMMMMMMMMMMMM",
    };

void set_hangman_position()  //set hangman scrren position
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 8;
	SetConsoleCursorPosition(hOut, Position);
}

void hscreen()      ///print hangman screen
{
    set_hangman_position();
    HANDLE h= GetStdHandle( STD_OUTPUT_HANDLE);

    for(int i=0; i<13; i++) {
        for(int j=0; j<98; j++){
            if (NUM_TRY==6)
                {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
                }

                else if(NUM_TRY==5)
                {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'T':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
                }

                else if(NUM_TRY==4)
                {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'T':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'O':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
                }

                else if(NUM_TRY==3)
                {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'T':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'O':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'L':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
                }

                else if(NUM_TRY==2)
                {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'T':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'O':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'L':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'G':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
                }
               else if(NUM_TRY==1)
               {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'T':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'O':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'L':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'G':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'I':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
               }
                else
                {
                    switch(hangman[i][j])
                    {
                        case 'M':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'T':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'O':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'L':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'G':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'I':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        case 'Y':
                            SetConsoleTextAttribute(h,11);
                            cout<<(char)219;
                            break;

                        default:
                            cout<<hangman[i][j];
                            break;
                    }
                }
            }
            cout<<endl;
        }
}

void select_difficulty()
{
    HANDLE out;     ///set cout font position
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD atext={20,20}, btext={20,22}, ctext={20,24}, dtext={15,26};

    SetConsoleCursorPosition(out,atext);
    cout<<"1-Easy";
    SetConsoleCursorPosition(out,btext);
    cout<<"2-Intermediate";
    SetConsoleCursorPosition(out,ctext);
    cout<<"3-Master";
    SetConsoleCursorPosition(out,dtext);
    cout<<"Select difficulty mode - ";
    cin>>dmode;
}

void main_menu()
{
    system("color 05");
    system("cls"); ///clear screen

    hscreen();
    screen();

    HANDLE h= GetStdHandle( STD_OUTPUT_HANDLE);     ///set font colors
    SetConsoleTextAttribute(h,06);

    HANDLE out;     ///set cout font position
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD ctext={12,18}, ntext={20,20};

    SetConsoleCursorPosition(out,ctext);
    cout<<"You have "<<NUM_TRY<<" tries to try and guess country.";

    SetConsoleTextAttribute(h,11);
    SetConsoleCursorPosition(out,ntext);
    cout<<message;

    SetConsoleTextAttribute(h,06);
}

int main(int argc, char *argv[])
{
    int n;
    int play=0;

    screen();
    select_difficulty();

    while(play!=1)
    {
        string name;
        char letter;
        string country;

        switch(dmode)
        {
        case 1: ///Easy mode
            {
                string countries[] =
                {
                    "syria",
                    "china",
                    "ghana",
                    "japan",
                    "greece",
                    "norway",
                    "spain",
                    "oman",
                    "brazil",
                    "korea",
                    "canada",
                    "italy",
                };

                ///choose and copy a word from array of words randomly
                srand(time(NULL));
                n=rand()%12;
                country=countries[n];
                break;
            }

        case 2: ///Intermediate mode
            {
                string countries[] =
                {
                    "colombia",
                    "denmark",
                    "srilanka",
                    "portugal",
                    "belgium",
                    "indonesia",
                    "singapore",
                    "venezuela",
                    "england",
                    "australia",
                    "nigeria",
                    "argentina",
                };

                ///choose and copy a word from array of words randomly
                srand(time(NULL));
                n=rand()%12;
                country=countries[n];
                break;
            }

            case 3: ///Master mode
            {
                string countries[] =
                {
                    "switzerland",
                    "bangladesh",
                    "kazakhstan",
                    "netherlands",
                    "afghanistan",
                    "philippines",
                    "saudiarabia",
                    "newzealand",
                    "tajikistan",
                    "madagascar",
                    "uzbekistan",
                    "azerbaijan",
                };

                ///choose and copy a word from array of words randomly
                srand(time(NULL));
                n=rand()%12;
                country=countries[n];
                break;
            }

            default :
                cout<<"Invalid!!!";
        }


        HANDLE out;     ///set cout font position
        out=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD utext={33,22}, rtext={16,24}, atext={20,22}, btext={20,22}, vtext{15,24};

        ///Initialize the secret word
        string hide_c(country.length(),'X');

        while(NUM_TRY!=0)
        {
            main_menu();
            SetConsoleCursorPosition(out,utext);
            cout<<hide_c;
            SetConsoleCursorPosition(out,rtext);
            cout<<"Guess a letter: ";
            cin>>letter;

            if(checkGuess(letter, country, hide_c)==0)
            {
                message="Incorrect letter.";
                NUM_TRY=NUM_TRY-1;

            }
            else
            {
                message = "NICE! You  guess a letter";
            }

            if(country==hide_c)
            {
                message="congratulations! You got it!";
                main_menu();
                SetConsoleCursorPosition(out,atext);
                cout<<"The country is : "<<country<<endl;
                break;
            }

        }
        if (NUM_TRY==0)
        {
            message="NOOOOOO!....you've been hanged.";
            main_menu();
            SetConsoleCursorPosition(out,btext);
            cout<<"The country was : "<<country<<endl;
        }
        cin.ignore();
        cin.get();

        SetConsoleCursorPosition(out,vtext);
        cout<<"Do you want play again?(yes-0/no-1) ";
        cin>>play;
            if(play==0)
            {
                NUM_TRY=6;
                message="Let's play again";
            }
    }

    return 0;
}

int checkGuess(char guess, string secretcountry, string &guesscountry)
{
    int i;
    int matches=0;
    int len=secretcountry.length();
    for(i=0; i<len; i++)
    {
        if(guess==secretcountry[i])
        {
            guesscountry[i]=guess;
            matches++;
        }
    }
    return matches;
}


