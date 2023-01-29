#include <iostream>
#include <string>
#include <iomanip>

#define T 100


#include "header\entreprise.hpp"
#include "header\admin.hpp"

using namespace std;



void menu_entreprise()
{
    int m;
    entreprise liste[T];
    int compteur{0}, position, id;
    do
    {
        menu:
        system("cls");system("color b");
        cout<<"\t#################_ENTREPRISE_#################"<<endl;
        cout<<"\t##\t\t 1. Ajouter                    ##"<<endl;
        cout<<"\t##\t\t 2. Afficher                   ##"<<endl;
        cout<<"\t##\t\t 3. Rechercher                 ##"<<endl;
        cout<<"\t##\t\t 4. Supprimer                  ##"<<endl;
        cout<<"\t##\t\t 5. Modifier                   ##"<<endl;
        cout<<"\t##\t\t 0. Retour                     ##"<<endl;
        cout<<"\t############################################"<<endl;

        cout<<"\tOption --> ";
        while (!(cin>>m))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"\tErreur !! de saisie"<<endl;
            cout<<"\tOption --> ";
        }

        switch (m)
        {
            case 1:{system("cls");system("color 1");ajouter_ent(liste, compteur);system("pause >null");goto menu;break;}
            case 2:{system("cls");system("color 2");afficher_ents(liste,compteur);system("pause >null");goto menu;break;}
            case 3:{system("cls");system("color 3");
                cout<<"Recherche d'une Entreprise :"<<endl;
                cout<<"Veuillez entrer l'identifiant de l'entreprise --> ";
                
                while (!(cin>>id))
                {
                    cin.clear();
                    cin.ignore(255,'\n');
                    cout<<"Erreur !! de saisie"<<endl;
                    cout<<"Veuillez entrer l'identifiant de l'entreprise --> ";
                }
                
                position = verifier_ent(liste, compteur, id);
                if (position !=-1)
                {
                    cout << "-----------------------------------------------" << endl;
                    cout << "Identifiant : " << liste[position].idEnt << endl;
                    cout << "Nom : " << liste[position].nomEnt << endl;
                    cout << "Type : " << liste[position].typeEnt << endl;
                    cout << "Siege : " << liste[position].addressEnt << endl;
                    cout << "Adresse E-mail : " << liste[position].emailEnt << endl;
                    cout << "-----------------------------------------------" << endl;
                }else{
                    cout<<"l'Identifiant de l'entreprise n'existe pas "<<endl;
                }
                system("pause >null");goto menu;break;}
            case 4:{system("cls");system("color 5");supprimer_ent(liste, compteur, id);system("pause >null");goto menu;break;}
            case 5:{system("cls");system("color 5");modifier_ent(liste, compteur, id);system("pause >null");goto menu;break;}
            case 0:
                return admin();
            default:
                system("cls");
                cout<<"******__Thank You___****** "<<endl<<endl;
                break;
        }
    } while (m<0 || m> 6);
    
    
}

//************************************************************
//************************************************************
//************************************************************
//************************************************************


void  ajouter_ent(entreprise *tab, int &nbrEnt)/// Ajoute d'une Entreprise
{
    int id;

    if(nbrEnt>=T){
        system("color 4a");
        cout <<"{Attention !!! Nombre total atteint !!! }" <<endl;
    }
    else{
        cout<<"Veuillez saisir les Information Suivante de l'Entreprise:"<<endl;
        cout<<"Entrer l'ID de l'Entrerpise -->";
        while (!(cin>> id)){
            cin.clear();
            cin.ignore(255, '\n');
            cout<<"Erreur !! de saisie"<<endl;
            cout<<"Entrer l'ID de l'Entrerpise -->";
        }
        
        while (verifier_ent(tab, nbrEnt, id) !=-1)
        {
            cout<<"Erreur !!! Cet Identifiant existe dans le programme"<<endl;
            cout<<"Veuillez saisir un autre ID : ";
            
            while (!(cin>> id)){
                cin.clear();
                cin.ignore(255, '\n');
                cout<<"Erreur !! de saisie"<<endl;
                cout<<"Entrer l'ID de l'Entrerpise -->";
            }
        }
        

        tab[nbrEnt].idEnt = id;
        cin.ignore(255, '\n');
        cout<<"Nom de Entreprise -->  ";
        getline(cin, tab[nbrEnt].nomEnt);
        cout<<"Type d'Entreprise -->";
        cin>>tab[nbrEnt].typeEnt;
        cin.ignore(255,'\n');
        cout<<"Siege --> ";
        cin>>tab[nbrEnt].addressEnt;
        cin.ignore(255,'\n');
        cout<<"E-mail --> ";
        cin>>tab[nbrEnt].emailEnt;
        cin.ignore(255,'\n');

        nbrEnt++;
        cout<<"Felicitation Enregistrement avec Succes"<<endl;
        
    }

}


/*********************************************************************/
/********************************************************************/

void afficher_ents(entreprise *tab, int nbrEnt)
{
    cout<<"     +*******************************************************************************+"<<endl;
    cout<<setw(6)<<"|"<<setw(6)<<"ID "<<"|"<<setw(20)<<"Nom de l'Entreprise"<<"|"<<setw(17)<<"Type d'Entreprise"<<"|"<<setw(12)<<"Siege"<<"|"<<setw(20)<<"Adresse E-mail"<<"|"<<endl;
    cout<<"     +*******************************************************************************+"<<endl;
    if (nbrEnt == 0)
    {
        system("color 4");
        cout<<"\t\t          +*****************************+"<<endl;;
        cout<< "\t\t         |         Liste vide          |" <<endl;
        cout<<"\t\t          +*****************************+"<<endl;
    }
    else
    {
        for(int i=0; i< nbrEnt ; i++)
        {
            cout<<setw(6)<< "|" << setw(6) << tab[i].idEnt << "|" << setw(20) << tab[i].nomEnt << "|" << setw(17) << tab[i].typeEnt << "|" << setw(12) << tab[i].addressEnt << "|" << setw(20) << tab[i].emailEnt << "|" << endl;
        }
    }
}

int verifier_ent(entreprise *tab, int nbrEnt, int id){
    int i(0);

    while (i< nbrEnt && tab[i].idEnt != id) i++;
    if(i< nbrEnt){
        return i;  
    }
    
    return -1;
}

 void supprimer_ent(entreprise *tab, int &nbrEnt, int id){
    cout << "Suppression d'une Entreprise " << endl << "Veuillez entrer l'identifiant de l'entreprise a supprimer >> ";
    
    while(!(cin >> id))
    {
        cin.clear();
        cin.ignore(255, '\n');
        cout<<"Erreur !! de saisie"<<endl;
        cout<< "Veuillez entrer l'identifiant de l'entreprise a supprimer --> ";
    }
    
    int position = verifier_ent(tab, nbrEnt, id);

    if (position !=-1)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Identifiant : " << tab[position].idEnt << endl;
        cout << "Nom : " << tab[position].nomEnt << endl;
        cout << "Type : " << tab[position].typeEnt << endl;
        cout << "Siege : " << tab[position].addressEnt << endl;
        cout << "Adresse E-mail : " << tab[position].emailEnt << endl;
        cout << "-----------------------------------------------" << endl;
        
        char valid;
        cout<<"Confirmez O(ui)/N(on) --> ";

        while (!(cin>>valid))
        {
            cin.clear();
            cin.ignore(255, '\n');
            cout<<"Erreur !! de saisie"<<endl;
            cout<<"Confirmez O(ui)/N(on) --> ";
        }
         
        if (valid=='O' || valid == 'o')
        {
            for(int i = position; i < nbrEnt - 1; i++)
            tab[i] = tab[i+1];
            nbrEnt--;
            cout << "Suppression effectuee avec succes !" << endl;
        }else{
            cout<<"Suppression annuller"<<endl;
        }
        
    }else{
        cout<<"l'Identifiant de l'entreprise n'existe pas "<<endl;
    }
 }

 void modifier_ent(entreprise *tab, int nbrEnt, int id)
 {
    cout << "Modification d'une Entreprise " << endl << "Veuillez entrer l'identifiant de l'entreprise a modifier >> ";
    while (!(cin>>id))
    {
        cin.clear();
        cin.ignore(255,'\n');
        cout<<"Erreur !! de saisie"<<endl;
        cout<<"Veuillez entrer l'identifiant de l'entreprise a modifier --> ";
    }
    int position = verifier_ent(tab, nbrEnt, id);

    if(position != -1)
    {
        cout << "---------------------- Infos existants de L'entreprise -------------------------" << endl;
        cout << "Identifiant : " << tab[position].idEnt << endl;
        cout << "Nom : " << tab[position].nomEnt << endl;
        cout << "Type : " << tab[position].typeEnt << endl;
        cout << "Siege : " << tab[position].addressEnt << endl;
        cout << "Adresse E-mail : " << tab[position].emailEnt << endl;
        cout << "-----------------------------------------------" << endl;

        char valid;
        cout<<"Confirmez O(ui)/N(on) --> ";
        while (!(cin>>valid))
        {
            cin.clear();
            cin.ignore(255, '\n');
            cout<<"Erreur !! de saisie"<<endl;
            cout<<"Confirmez O(ui)/N(on) --> ";
        }
        if (valid=='O' || valid == 'o')
        {
            cout<<"Veuillez saisir les nouvelles infos "<<endl;
            cout<<"Identifiant --> ";
            while (!(cin>> id)){
                cin.clear();
                cin.ignore(255, '\n');
                cout<<"Erreur !! de saisie"<<endl;
                cout<<"Entrer l'ID de l'Entrerpise -->";
            }

            while (verifier_ent(tab, nbrEnt, id) !=-1)
            {
                cout<<"Erreur !!! Cet Identifiant existe dans le programme"<<endl;
                cout<<"Veuillez saisir un autre ID : ";
                
                while (!(cin>> id)){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cout<<"Erreur !! de saisie"<<endl;
                    cout<<"Entrer l'ID de l'Entrerpise -->";
                }
            }
                
                tab[position].idEnt = id;
                cin.ignore(255, '\n');
                cout<<"Nom de Entreprise -->  ";
                getline(cin, tab[nbrEnt].nomEnt);
                cout<<"Type d'Entreprise -->";
                cin>>tab[nbrEnt].typeEnt;
                cin.ignore(255,'\n');
                cout<<"Siege --> ";
                cin>>tab[nbrEnt].addressEnt;
                cin.ignore(255,'\n');
                cout<<"E-mail --> ";
                cin>>tab[nbrEnt].emailEnt;
                cin.ignore(255,'\n');

            cout<<"Modification effectuee avec succes !"<<endl;
        }else{
            cout<<"Modification annuller"<<endl;
        }
        
    }else{
        cout<<"Cet identifiant est introuvable "<<endl;
    }
 }
