#include <iostream>
#include <string.h>
#include <fstream>

#include "header\entreprise.hpp"
#include "header\admin.hpp"
#include "header\menu.hpp"
#include "header\stagiaire.hpp"


using namespace std;

void admin(){
    system("cls");
    cout<<"\t\t\t ADMINISTRATEUR "<<endl;
    cout<<"\t\t\t ########   ######  ###### ########  ######  #######  ##   ##"<<endl;
    cout<<"\t\t\t ##         ##      ##        ##       ##    ##   ##  ###  ##"<<endl;
    cout<<"\t\t\t ##   ###   ######  #####     ##       ##    ##   ##  #### ##"<<endl;
    cout<<"\t\t\t ##    ##   ##         ##     ##       ##    ##   ##  ## ####"<<endl;
    cout<<"\t\t\t ########   ######  #####     ##     ######  #######  ##   ## "<<endl;

    cout<<"\t\t\t\tDES STAGES DANS DES ENTREPRISES"<<endl<<endl;

    int a;
    do
    {
        system("color b");
        cout<<"\t############################################"<<endl;
        cout<<"\t##\t\t 1. Entreprise                ##"<<endl;
        cout<<"\t##\t\t 2. Stagiaire                 ##"<<endl;
        cout<<"\t##\t\t 0. Quitter                   ##"<<endl;
        cout<<"\t############################################"<<endl;

        cout<<"\tOption --> ";
        while (!(cin>>a))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"\tErreur !!"<<endl;
            cout<<"\tOption --> ";
        }
        

        switch(a)
        {
            case 1:
                system("cls");
                menu_entreprise();
                break;
            case 2:
                system("cls");
                menu_stagiaire();
                break;
            case 0:
                break;
            default:
                system("cls");system("color 4");
                cout<<"Error de saisie";
        }
    } while (a<0 || a>2); 
    
}