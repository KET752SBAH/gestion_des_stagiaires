#include <iostream>

#include "header\stagiaire.hpp"
using namespace std;

void users()
{
    system("cls");system("color 4");
    cout<<"\t\t\t ENTREPRISE "<<endl;
    cout<<"\t\t\t ########   ######  ###### ########  ######  #######  ##   ##"<<endl;
    cout<<"\t\t\t ##         ##      ##        ##       ##    ##   ##  ###  ##"<<endl;
    cout<<"\t\t\t ##   ###   ######  #####     ##       ##    ##   ##  #### ##"<<endl;
    cout<<"\t\t\t ##    ##   ##         ##     ##       ##    ##   ##  ## ####"<<endl;
    cout<<"\t\t\t ########   ######  #####     ##     ######  #######  ##   ## "<<endl;

    cout<<"\t\t\t\tDES STAGES DANS DES ENTREPRISES"<<endl<<endl;

    int a;
    a:
    system("color a");
    cout<<"\t############################################"<<endl;
    cout<<"\t##\t\t 1. STAGIAIRES                ##"<<endl;
    cout<<"\t##\t\t 0. Quitter                   ##"<<endl;
    cout<<"\t############################################"<<endl;

    cout<<"\tOption --> ";
    while (!(cin>>a))
    {
        cin.clear();
        cin.ignore(255,'\n');
        cout<<"\tErreur !! de saisie"<<endl;
        cout<<"\tOption --> ";
    }

    switch(a)
    {
        case 1:
            system("cls");system("color c");
            menu_stagiaire();
            break;
        case 0:
            break;
        default:
            system("cls");system("color 4");
            cout<<"Error de saisie";
            goto a;
    }
}