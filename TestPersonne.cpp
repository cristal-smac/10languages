#include <iostream>
#include <sstream>
#include <cstring>

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
   
   
   
   
int main(int argc, char **argv)
{
   Personne p("Mathieu", "Philippe");

   cout << "Une personne : " << p.toString() << endl ;

   Etudiant e("Foo", "Bar", 10);
   cout << "Un etudiant : " << e.toString() << endl ;
   return 0;
}
