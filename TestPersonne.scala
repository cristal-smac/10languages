class Personne(nom: String, prenom: String) {

  override def toString: String = this.nom + " " + this.prenom

}

object Etudiant {

  var NB: Int = 0

}

class Etudiant(nom: String, prenom: String, num: Int)
    extends Personne(nom, prenom) {

  Etudiant.NB += 1

  override def toString: String = super.toString + " Student " + this.num

}

object TestPersonne extends App {

	//  TEST 1 : Une instance
	val p = new Personne("Duchemin","paul")
	println(p)

	// TEST 2 : Une collection
  val al1 = for (i <- 1 to 10) yield new Personne("Duchemin" + i, "paul" + i)
  println(al1.size)
  al1 foreach println

	// TEST 3 : Polymorphisme
  val al2 = for (i <- 1 to 10) yield {
    if (i % 2 == 0) new Personne("Duchemin" + i, "paul" + i)
    else new Etudiant("Durand" + i, "jules" + i, i)
  }
  al2 foreach println

	println("Nb etudiants " + Etudiant.NB);

}
