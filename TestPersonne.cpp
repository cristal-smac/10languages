#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

class Personne
{
private:
   string nom, prenom;

public:
   // Utilisation de la liste de construction pour appeller les
   // constructeurs des attribus de façon explicite + utilisation de
   // ref (plus performant, sinon, une copie de l'objet est faite
   // quand il est passes en paramètre)
   Personne(string &nom, string &prenom) : nom(nom), prenom(prenom)
   {
   }
   // Un deuxième constructeur pour pouvoir construire à partir de
   // chaînes C (const char *) std::string a un constructeur qui
   // prends un const char * mais ça ne peux être implicite que si on
   // appelle une fonction qui prend un string en paramètre et pas un
   // string & comme le constructeur précédent
   Personne(const char *nom, const char *prenom) : nom(nom), prenom(prenom)
   {
   }

   // La méthode doit être virtuelle pour pouvoire être surchargée
   // proprement par la classe fille. La méthode ne modifiant pas
   // l'instance, on utilise le mot clé const ce qui permet de
   // l'utiliser sur un objet const. Celà indique au compilateur que
   // la méthode ne modifie pas l'instance.

   // Contrairement à des langage comme java, le nom de méthode
   // toString ne veut rien dire en soit. Aucun appel implicite de
   // sera fait à cette méthode pour obtenir la représentation sous
   // forme de chaîne de l'objet.
   virtual string toString() const
   {
      // this est toujours un pointeur en C++, d'où l'utilisation de
      // -> au lieu de .
      // Derrière cette écriture se cache deux appels
      // à la méthode operator+ de la classe string..
      return this->prenom + " " + this->nom;
   }

   
   // Comme il y a une méthode virtuelle, il faut un destructeur
   // virtuel pour s'assurer que tous les constructeurs (de toutes les
   // classes filles) soient appelés correctement
   virtual ~Personne() {}
};


class Etudiant: public  Personne
{
public:
   // L'appel explicite au constructeur de la classe Personne est
   // obligatoire par la liste de construction car le fait d'avoir
   // défini un constructeur avec paramètres dans la classe Personne
   // supprime le constructeur par défaut
   Etudiant(string &nom, string &prenom, int num) : Personne(nom, prenom), num(num)
   {
   }

   // On définit également le constructeur prennant en paramètre des chaînes C
   Etudiant(const char *nom, const char *prenom, int num) : Personne(nom, prenom), num(num)
   {
   }
   
   // Le mot clé virtual n'est plus obligatoire ici (car la méthode a
   // déjà été définie comme virtuelle dans la classe Personne), mais
   // on le voit souvent réutilisé pour plus de lisibilité
   virtual string toString() const {
      // La concaténation string + nombre n'est pas possible de base, faut passer par un stringstream
      std::ostringstream stream;
      // super n'existe pas en C++, principalement à cause des
      // problème liés à l'héritage multiple, donc il faut préciser
      // exactement de quelle classe parente provient la méthode que l'on veut appeler
      stream << this->Personne::toString() << " " << this->num;
      return stream.str();
   }
private:
   int num;
};
   
   

// Une fabrique de personnes ou d'étudiants
class PersonneFactory {
public:
   // On fabrique une personne avec un indice
   static Personne *creerPersonne(int idx) {
      std::string nom("Duchemin");
      std::string prenom("Paul");
      nom += std::to_string(idx);
      prenom += std::to_string(idx);
      return new Personne(nom, prenom);
   }
   // On fabrique une personne ou un étudiant en fonction de l'indice (pair  personne, impair etudiant)
   static Personne *creerPersonneOuEtudiant(int idx) {
      if (0 == (idx % 2))
         return PersonneFactory::creerPersonne(idx);
      std::string nom("Durand");
      std::string prenom("Jules");
      nom += std::to_string(idx);
      prenom += std::to_string(idx);
      return new Etudiant(nom, prenom, idx);
   }
};

   
int main(int argc, char **argv)
{
   // Test 1 : une instance

   //En C++ la gestion mémoire est la même qu'en C. On peut allouer
   // notre objet sur la pile (déclaration de variable simple) ou sur
   // le tas (appel à new, "équivalent" C++ de malloc)
   // Ici, sur la pile
   Personne p("Mathieu", "Philippe");

   cout << "Une personne : " << p.toString() << endl ;

   // Ici, sur le tas. Par contre, on doit maintenant manipuler
   // l'objet à l'aide d'un pointeur.
   Etudiant *e = new Etudiant("Foo", "Bar", 10);
   // Comme e est ici un pointeur, on doit utiliser la notation '->'
   // pour déréférencer le pointeur et accéder à l'objet.
   cout << "Un etudiant : " << e->toString() << endl ;

   // Par contre, quand on a terminé avec cette instance, il faut
   // libérer la mémoire (équivalent du "free" de C). L'appel à delete
   // va appeller les destructeurs nécessaires et libérer la mémoire.
   delete e;
   // Pour l'objet p, l'appel à son destructeur aura lieu quand on
   // sortira du contexte dans lequel la variable a été déclarée (ici, en sortant du main)

   // Test 2 : une collection
   
   // Deux solutions possibles
   // - les tableaux classiques
   // - les classes outils comme std::vector ou std::list

   // On ne montre que vector, mais les tableaux classiques fonctionnent
   // également bien si on connait (à la compilation, ou dynamiquement)
   // le nombre exact de personnes.
   std::vector<Personne*> des_gens;

   for (int i = 0 ; i < 10 ; ++i) {
      // On utilise une factory pour l'allocation car concaténer des
      // string et des entiers n'est pas si simple qu'en Java, donc on
      // regroupe le code dans la factory pour simplifier la lecture.
      // La méthode PersonneFactory::creerPersonne est une méthode
      // statique (de classe), qui instancie une personne à l'aide de
      // new.
      des_gens.push_back(PersonneFactory::creerPersonne(i));
   }
   // le vector implémente l'opérateur [], on peut donc s'en servir
   // comme d'un tableau
   for (int i = 0 ; i < 10 ; ++i)
      cout << des_gens[i]->toString() << endl;

   // Il faut également désallouer
   for (int i = 0 ; i < 10 ; ++i)
      delete des_gens[i];

   // Test 3 : polymorphisme

   // On utilise encore les pointeurs, seul moyen (avec les
   // références) d'avoir du polymorphisme
   std::vector<Personne*> dautres_gens;
   for (int i = 0 ; i < 10 ; ++i) {
      // On utilise la même factory, mais avec une méthode qui crée
      // une personne ou un etudiant en fonction de l'indice passé en
      // paramètre.
      dautres_gens.push_back(PersonneFactory::creerPersonneOuEtudiant(i));
   }
   // pour changer, on peut parcourir le vector avec un iterateur. Ici,
   // l'utilisation de l'opérateur préfixé ++it prend tout son sens,
   // car l'opérateur post-fixé (it++) devrait créer une copie
   // (inutile ici) de l'itérateur avant de retourner le précédent. Le
   // ++it est donc plus performant sur des objets complexes.
   for (std::vector<Personne *>::iterator it = dautres_gens.begin() ; it != dautres_gens.end() ; ++it)
      // it s'utilise alors comme un "pointeur" vers le contenu du
      // vecteur qui est lui même un pointeur.
      // Donc: (*it) est un Personne* sur lequel on applique l'opérateur ->
      cout << (*it)->toString() << endl;

   // Il faut également désallouer
   for (int i = 0 ; i < 10 ; ++i)
      delete dautres_gens[i];
   
   return 0;
}
