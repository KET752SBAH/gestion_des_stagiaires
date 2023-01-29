#ifndef __ENTREPRISE__
    #define __ENTREPRISE__
    #include <iostream>

    using namespace std;

    struct entreprise
    {
        int idEnt;
        string nomEnt;
        string typeEnt;
        string addressEnt;
        string emailEnt;
    };


      void menu_entreprise();

      void ajouter_ent(entreprise *, int &);
      void afficher_ents(entreprise *, int);
      void modifier_ent(entreprise *, int , int);
      int verifier_ent(entreprise *, int, int);
      void supprimer_ent(entreprise *, int &, int);
    
      
 
      
    
#endif