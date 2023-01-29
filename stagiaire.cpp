#include <iostream>
#include <cstdio>
#include <iomanip>

#define T 100
#define Ts 100

#include "header\stagiaire.hpp"
#include "header\users.hpp"
#include "header\entreprise.hpp"

using namespace std;


void menu_stagiaire()
{
    
    stagiaire listeS[Ts];
    int m, compteurS(0), positionS, idS;
    do
    {
        menu:
        system("color b");system("cls");
        cout<<"\t#################_STAGIAIRE_#################"<<endl;
        cout<<"\t##\t\t 1. Ajouter                ##"<<endl;
        cout<<"\t##\t\t 2. Afficher               ##"<<endl;
        cout<<"\t##\t\t 3. Rechercher             ##"<<endl;
        cout<<"\t##\t\t 4. Supprimer              ##"<<endl;
        cout<<"\t##\t\t 5. Modifier               ##"<<endl;
        cout<<"\t##\t\t 0. Retour                 ##"<<endl;
        cout<<"\t############################################"<<endl;

        cout<<"\tOption --> ";
        while (!(cin>>m))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"\tErreur de saisie !!"<<endl;
            cout<<"\tOption --> ";
        }
        

        switch (m)
        {
        case 1:{system("cls");system("color 2");ajouter_sta(listeS, compteurS);system("pause >null");goto menu;break;}
        case 2:{system("cls");system("color 5");afficher_sta(listeS, compteurS);system("pause >null");goto menu;break;}
        case 3:{system("cls");system("color 3");
            cout<<"Recherche d'un Stagiaire : "<<endl;
            cout<<"Veuillez entrer l'ID du Stagiaire --> ";
            while (!(cin>>idS))
            {
                cin.clear();
                cin.ignore(255, '\n');
                cout<<"Erreur de saisie !!!"<<endl;
                cout<<"Veuillez entrer l'ID du Stagiaire --> ";
            }
            
            positionS = verifier_sta(listeS, compteurS, idS);
            if(positionS != -1)
            {
                cout << "-----------------------------------------------" << endl;
                cout << "Identifiant : " << listeS[positionS].idSta << endl;
                cout << "ID de l'Entreprise : " << listeS[positionS].idEnt_ << endl;
                cout << "Nom : " << listeS[positionS].nomSta << endl;
                cout << "Prenom : " << listeS[positionS].prenomSta << endl;
                cout << "Date de naissance : " << listeS[positionS].jour<<"/"<<listeS[positionS].mois<<"/"<<listeS[positionS].annee << endl;
                cout << "Niveau d'Etude :" <<listeS[positionS].niveau <<endl;
                cout << "Adresse "<< listeS[positionS].adresse <<endl;
                cout << "-----------------------------------------------" << endl;
            }else{
                cout<<"l'Identifiant du stagiaire n'existe pas "<<endl;
            }
            system("pause >null");goto menu;break;}
        case 4:{system("cls");system("color 6");supprimer_sta(listeS, compteurS,idS);system("pause >null");goto menu;break;}
        case 5:{system("cls");system("color a");modifier_sta(listeS, compteurS, idS);system("pause >null");goto menu;break;}
        case 0:
            system("cls");
            return users();
        default:
            cout<<"Erreur de Saisie"<<endl<<endl;
            system("pause >null");system("cls");
            break;
        }
    } while(m<0  || m>6);

    
    
}


void  ajouter_sta(stagiaire *tabS, int &nbrSta)/// Ajoute d'un stagiaire
{
    entreprise liste[T];
    int compteur{0}, position, id;

    int idS;
    if(nbrSta>=Ts)
    {
        system("color 4a");
        cout <<"{Attention !!! Nombre total atteint !!! }" <<endl;
    }else{
        cout<<"Veuillez saisir les Information du Stagaire "<<endl;
        cout<<"Entrer l'ID du Stagiaire --> ";
        cin>>idS;
        while (verifier_sta(tabS, nbrSta, idS) != -1)
        {
            cout<<"Erreur !!! Cet Identifiant existe dans le programme"<<endl;
            cout<<"Veuillez saisir l'ID du Stagaire: ";
            while (!(cin>>idS))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Veuillez saisir l'ID du Stagaire: ";
            }
        }

        cout<<"Entrer l'ID de l'Entrerpise -->";
        while (!(cin>> id))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !!"<<endl;
            cout<<"Entrer l'ID de l'Entrerpise -->";
        }

        /*while (verifier_ent(liste, compteur, id) ==-1)
        {
            cout<<"Erreur !!! l'Entreprise n'existe pas dans le programme"<<endl;
            cout<<"Veuillez saisir l'ID de l'Entreprise : ";
            while (!(cin>> id))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Entrer l'ID de l'Entrerpise -->";
            }
        }*/

        tabS[nbrSta].idSta = idS; 
        tabS[nbrSta].idEnt_ = id;
        cin.ignore(255, '\n');
        cout<<"Nom --> ";cin>>tabS[nbrSta].nomSta;cin.ignore(255, '\n');
        cout<<"Prenom --> ";getline(cin, tabS[nbrSta].prenomSta);
        cout<<"Date de Naissance :\n";
        cout<<"Jour --> ";
        while (!(cin>>tabS[nbrSta].jour))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !!"<<endl;
            cout<<"Jour -->";
        }
        while (tabS[nbrSta].jour<1 || tabS[nbrSta].jour>31)
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !! {1/31}"<<endl;
            cout<<"Jour --> ";
            while (!(cin>>tabS[nbrSta].jour))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Jour -->";
            }
        }
        
        cout<<"Mois --> ";
        while (!(cin>>tabS[nbrSta].mois))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !!"<<endl;
            cout<<"Mois -->";
        }
        while (tabS[nbrSta].mois<1 || tabS[nbrSta].mois>12)
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !! {1/12}"<<endl;
            cout<<"Mois --> ";
             while (!(cin>>tabS[nbrSta].mois))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Mois -->";
            }
        }
        
        cout<<"Annee --> ";
        while (!(cin>>tabS[nbrSta].annee))
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !!"<<endl;
            cout<<"Annee -->";
        }
        
        while (tabS[nbrSta].annee<1990 || tabS[nbrSta].annee >2007)
        {
            cin.clear();
            cin.ignore(255,'\n');
            cout<<"Erreur de saisie !! {1990/2007}"<<endl;
            cout<<"Anne --> ";
            while (!(cin>>tabS[nbrSta].annee))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Annee -->";
            }
        }
        cout<<"Niveau d'Etude --> ";cin>>tabS[nbrSta].niveau;
        cin.ignore(255,'\n');
        cout<<"Adresse --> ";cin>>tabS[nbrSta].adresse;
        cin.ignore(255,'\n');

        nbrSta++;
        cout<<"Felicitation Enregistrement avec Succes"<<endl;
    }

}


/*
    ***********************************************************
    ***********************************************************
*/

void afficher_sta(stagiaire *tabS, int nbrSta){
    cout<<"\t\t\tLA LISTE DES ENTREPRISE"<<endl;
    cout<<"     +*************************************************************************************************************+"<<endl;
    cout<<"     |"<<setw(6)<<"ID "<<"|"<<setw(13)<<"ID Entreprise"<<"|"<<setw(10)<<"Nom "<<"|"<<setw(25)<<"Prenom"<<"|"<<setw(20)<<"Date de Naissance "<<"|"<<setw(15)<<"Niveau Etude"<<"|"<<setw(13)<<"Adresse "<<"|"<<endl;
    cout<<"     +*************************************************************************************************************+"<<endl;
    if (nbrSta == 0)
    {
        system("color 4");
        cout<<"\t\t          +*****************************+"<<endl;;
        cout<< "\t\t         |         Liste vide          |" <<endl;
        cout<<"\t\t          +*****************************+"<<endl;
    }
    else
    {
        for(int i=0; i< nbrSta ; i++)
        {
            cout <<"     |" << setw(6) << tabS[i].idSta << "|" << setw(13) << tabS[i].idEnt_ << "|" << setw(10) << tabS[i].nomSta << "|" << setw(25) << tabS[i].prenomSta << "|" << setw(13) << tabS[i].jour<<"/"<<tabS[i].mois<<"/"<<tabS[i].annee << "|" <<setw(15)<<tabS[i].niveau <<"|" <<setw(13)<<tabS[i].adresse << "|" <<endl;
        }
    }
    cout<<"     +*************************************************************************************************************+"<<endl;
}

int verifier_sta(stagiaire *tabS,int nbrSta, int idS){
    int i(0);

    while (i< nbrSta && tabS[i].idSta != idS) i++;
    if(i< nbrSta){
        return i;
    }
    return -1;
}

void supprimer_sta(stagiaire *tabS, int &nbrSta, int idS){
    cout<<"Suppremsion d'un Stagiaire "<<endl;
    cout<<"Veuillez saisir l'ID du Stagiaire -->"<<endl;
    
    while(!(cin >> idS))
    {
        cin.clear();
        cin.ignore(255, '\n');
        cout<<"Erreur !! de saisie"<<endl;
        cout<<"Veuillez saisir l'ID du Stagiaire -->"<<endl;
    }

    int positionS = verifier_sta(tabS, nbrSta, idS);

    if(positionS != -1)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Identifiant : " << tabS[positionS].idSta << endl;
        cout << "ID de l'Entreprise : " << tabS[positionS].idEnt_ << endl;
        cout << "Nom : " << tabS[positionS].nomSta << endl;
        cout << "Prenom : " << tabS[positionS].prenomSta << endl;
        cout << "Date de naissance : " << tabS[positionS].jour<<"/"<<tabS[positionS].mois<<"/"<<tabS[positionS].annee << endl;
        cout << "Niveau d'Etude :" <<tabS[positionS].niveau <<endl;
        cout << "Adresse "<< tabS[positionS].adresse <<endl;
        cout << "-----------------------------------------------" << endl;
        
        char valid;
        cout<<"Confirmez O(ui)/N(on) --> ";cin>>valid; 
        if (valid=='O' || valid == 'o')
        {
            for(int i = positionS; i < nbrSta - 1; i++)
            tabS[i] = tabS[i+1];
            nbrSta--;
            cout << "Suppression effectuee avec succes !" << endl;
        }else{
            cout<<"Suppression annuller"<<endl;
        }
    }
}

void modifier_sta(stagiaire *tabS, int nbrSta, int idS){
    int id;
    cout << "Modification  d'un Stagiaire "<<endl;
    cout << "Veuillez entrer l'ID du Stagiaire a modifier --> ";
    
    while(!(cin >> idS))
    {
        cin.clear();
        cin.ignore(255, '\n');
        cout<<"Erreur !! de saisie"<<endl;
        cout << "Veuillez entrer l'ID du Stagiaire a modifier --> ";
    }
    int positionS = verifier_sta(tabS, nbrSta, idS);

    if(positionS != -1)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Identifiant : " << tabS[positionS].idSta << endl;
        cout << "ID de l'Entreprise : " << tabS[positionS].idEnt_ << endl;
        cout << "Nom : " << tabS[positionS].nomSta << endl;
        cout << "Prenom : " << tabS[positionS].prenomSta << endl;
        cout << "Date de naissance : " << tabS[positionS].jour<<"/"<<tabS[positionS].mois<<"/"<<tabS[positionS].annee << endl;
        cout << "Niveau d'Etude :" <<tabS[positionS].niveau <<endl;
        cout << "Adresse "<< tabS[positionS].adresse <<endl;
        cout << "-----------------------------------------------" << endl;

        char valid;
        cout<<"Confirmez O(ui)/N(on) --> ";cin>>valid; 
        if (valid=='O' || valid == 'o')
        {
            cout<<"Veuillez saisir les nouvelles infos "<<endl;
            cout<<"Entrer l'ID du Stagiaire --> ";
            cin>>idS;
            while (verifier_sta(tabS, nbrSta, idS) != -1)
            {
                cout<<"Erreur !!! Cet Identifiant existe dans le programme"<<endl;
                cout<<"Veuillez saisir l'ID du Stagaire: ";
                while (!(cin>>idS))
                {
                    cin.clear();
                    cin.ignore(255,'\n');
                    cout<<"Erreur de saisie !!"<<endl;
                    cout<<"Veuillez saisir l'ID du Stagaire: ";
                }
            }

            cout<<"Entrer l'ID de l'Entrerpise -->";
            while (!(cin>> id))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Entrer l'ID de l'Entrerpise -->";
            }

                tabS[nbrSta].idSta = idS; 
            tabS[nbrSta].idEnt_ = id;
            cin.ignore(255, '\n');
            cout<<"Nom --> ";cin>>tabS[nbrSta].nomSta;cin.ignore(255, '\n');
            cout<<"Prenom --> ";getline(cin, tabS[nbrSta].prenomSta);
            cout<<"Date de Naissance :\n";
            cout<<"Jour --> ";
            while (!(cin>>tabS[nbrSta].jour))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Jour -->";
            }
            while (tabS[nbrSta].jour<1 || tabS[nbrSta].jour>31)
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !! {1/31}"<<endl;
                cout<<"Jour --> ";
                while (!(cin>>tabS[nbrSta].jour))
                {
                    cin.clear();
                    cin.ignore(255,'\n');
                    cout<<"Erreur de saisie !!"<<endl;
                    cout<<"Jour -->";
                }
            }
            
            cout<<"Mois --> ";
            while (!(cin>>tabS[nbrSta].mois))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Mois -->";
            }
            while (tabS[nbrSta].mois<1 || tabS[nbrSta].mois>12)
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !! {1/12}"<<endl;
                cout<<"Mois --> ";
                while (!(cin>>tabS[nbrSta].mois))
                {
                    cin.clear();
                    cin.ignore(255,'\n');
                    cout<<"Erreur de saisie !!"<<endl;
                    cout<<"Mois -->";
                }
            }
            
            cout<<"Annee --> ";
            while (!(cin>>tabS[nbrSta].annee))
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !!"<<endl;
                cout<<"Annee -->";
            }
            
            while (tabS[nbrSta].annee<1990 || tabS[nbrSta].annee >2007)
            {
                cin.clear();
                cin.ignore(255,'\n');
                cout<<"Erreur de saisie !! {1990/2007}"<<endl;
                cout<<"Anne --> ";
                while (!(cin>>tabS[nbrSta].annee))
                {
                    cin.clear();
                    cin.ignore(255,'\n');
                    cout<<"Erreur de saisie !!"<<endl;
                    cout<<"Annee -->";
                }
            }

            cout<<"Niveau d'Etude --> ";cin>>tabS[nbrSta].niveau;
            cin.ignore(255,'\n');
            cout<<"Adresse --> ";cin>>tabS[nbrSta].adresse;
            cin.ignore(255,'\n');

            cout<<"Mofication avec succes !!!"<<endl;
        }else{
                cout<<"Modification annuller"<<endl;
        }
     
    }else{
        cout<<"Cet identifiant n'existe pas "<<endl;
    }
}