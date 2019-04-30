#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Personne
{
private:
   string nom, prenom;

public:
   // Utilisation de la liste de construction pour appeller les constructeurs des attribus de façon explicite
   // + utilisation de ref (plus performant, sinon, ça fait une copie de l'objet quand tu le passes en paramètre)
   Personne(string &nom, string &prenom) : nom(nom), prenom(prenom)
   {
   }
   // Un deuxième constructeur pour pouvoir construire à partir de chaînes C (const char *)
   // std::string a un constructeur qui prends un const char * mais ça ne peux être implicite que si tu appelle une fonction
   // qui prend un string en paramètre et pas un string & comme je l'ai fait pour corriger le constructeur précédent
   Personne(const char *nom, const char *prenom) : nom(nom), prenom(prenom)
   {
   }

   // La méthode doit être virtuelle pour pouvoire être surchargée proprement par la classe fille
   // En bonus, la méthode ne modifiant pas l'instance, je la passe const ce qui permet de l'utiliser sur un objet const
   virtual string toString() const
   {
      // this est toujours un pointeur en C++, d'où l'utilisation de -> au lieu de .
      return this->prenom + " " + this->nom;
   }

   // Comme il y a une méthode virtuelle, il faut un destructeur
   // virtuel pour s'assurer que tous les constructeurs soient appelés
   // correctement
   virtual ~Personne() {}
};


class Etudiant: public  Personne
{
public:
   // L'appel explicite au constructeur de la classe Personne est
   // obligatoire par la liste de construction car le fait d'avoir
   // défini un constructeur avec paramètres dans la classe Personne
   // supprime le constructeur par défaut
   Etudiant(string &nom, string &prenom) : Personne(nom, prenom), num(0)
   {
   }
   // Le mot clé virtual n'est plus obligatoire ici, mais j'ai l'habitude de le remettre pour plus de lisibilité
   virtual string toString() const {
      // super n'existe pas en C++, principalement à cause des
      // problème liés quand t'as de l'héritage multiple, donc faut préciser exactement
      // de quelle classe tu appelle la méthode

      // La concaténation string + nombre n'est pas possible de base, faut passer par un stringstream
      std::ostringstream stream;
      stream << this->Personne::toString() << " " << this->num;
      return stream.str();
   }
private:
   int num;
};
   
   
   
   
int main(int argc, char **argv)
{
   // La conversion de const char * (ce que sont les chaines entre "" n'est pas implicite, il te faut donc
   // des vrai string pour les passer au constructeur.
   // Une solution serait d'ajouter un constructeur :
   // Personne(const char *nom, const char *prenom) : nom(nom), prenom(prenom) {}
   
   string nom("Mathieu"), prenom("Philippe");
   Personne p(nom,prenom);

   cout << "Une personne : " << p.toString() << endl ;
   nom = "Hauspie";
   prenom = "Michael";
   Etudiant e(nom, prenom);
   cout << "Un etudiant : " << e.toString() << endl ;
}
