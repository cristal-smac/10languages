import java.util.ArrayList;

class Personne
{
	private String nom;
	private String prenom;

        Personne (String nom, String prenom)
	{this.nom=nom; this.prenom=prenom;}

	public String toString() {return nom+" "+prenom;}
}


class Etudiant extends Personne
{
        public static int NB=0;

        private int num;
	Etudiant(String nom, String prenom, int num)
	{
		super(nom,prenom);
		this.num=num;
		NB++;
	}

	public String toString() {return super.toString()+" Student "+num;}
}


public class TestPersonne 
{
	public static void main(String args[])
	{

	//  TEST 1 : Une instance
	Personne p = new Personne("Duchemin","paul");
	System.out.println(p);
	
	// TEST 2 : Une collection
	ArrayList<Personne> al1 = new ArrayList<Personne>();
	for (int i=1;i<=10;i++)
		al1.add(new Personne("Duchemin"+i,"paul"+i));
	System.out.println(al1.size());
	for (Personne p1 : al1) System.out.println(p1);
	
	// TEST 3 : Polymorphisme
	ArrayList<Personne> al2 = new ArrayList<Personne>();
	for (int i=1;i<=10;i++)
		if (i%2==0) al2.add(new Personne("Duchemin"+i,"paul"+i));
		else al2.add(new Etudiant("Durand"+i,"jules"+i , i));
	for (Personne p2 : al2) System.out.println(p2);


	System.out.println("Nb etudiants "+Etudiant.NB);
	}
}
