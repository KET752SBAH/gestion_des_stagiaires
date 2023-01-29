#ifndef __STAGIAIRE__
    #define __STAGIAIRE__
    #include <iostream>
    
    using namespace std;
    

    struct stagiaire
    {
        int idSta;
        string nomSta;
        string prenomSta;
        int jour;
        int mois;
        int annee;
        string niveau;
        string adresse;
        int idEnt_;
    };


    void menu_stagiaire();

      
    void ajouter_sta(stagiaire *, int &);
    void afficher_sta(stagiaire *, int);
    int verifier_sta(stagiaire *, int, int);
    void modifier_sta(stagiaire *, int, int);
    void supprimer_sta(stagiaire *, int &, int);
      
#endif