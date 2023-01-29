#include <iostream>
#include <fstream>
#include <string>

#include "header\menu.hpp"
#include "header\stagiaire.hpp"
#include "header\entreprise.hpp"
#include "header\admin.hpp"
#include "header\users.hpp"


using namespace std;

int menu(){

    string login;
    string password;
    int shut(0);

    do
    {
         
        cout<<"\t\t\t\tVeuillez vous connecter svp "<<endl;
        cout<<"\t\t\t\tVotre Login -->";cin>>login;
        cout<<"\t\t\t\tVotre Mot de pass -->";cin>>password;

        if(login=="Admin" && password=="bah"){
            system("cls");
            admin();
            break;
        }else if(login=="user" && password=="user"){
            system("cls");
            users();
            break;
        }

        shut++;
        if(shut == 4)
        {
            system("cls");system("color 4f");
            cout<<"\n\n\n\t\t\t****************************************"<<endl;
            cout<<"\t\t\t*  Veuillez Contacter l'Administrateur *\n";
            cout<<"\t\t\t*  TEL: +224 622-48-90-83              *\n";
            cout<<"\t\t\t*  E-mail: souleymanebah752@gmail.com  *\n";
            cout<<"\t\t\t****************************************"<<endl;
            system("pause >nul");
            exit(-1);
        }
        else{
            system("color 4");
             cout<<"\t\t\tIls vous reste "<<4-shut<<" tentative(s) ";
             cout<<"\n\n\t\t\tAttention:: Le login ou le Mot de pass est Incorrect \n";
            system("pause >nul");
        }
        
    } while ((login!="Admin" && password!="bah")||(login!="user" && password!="user"));
    
    return menu();
}