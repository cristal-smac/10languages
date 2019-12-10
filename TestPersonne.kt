open class Personne(private val nom: String, private val prenom: String) {
    override fun toString(): String = "$nom $prenom"
}

class Etudiant(nom: String, prenom: String, private val num: Int) : Personne(nom, prenom) {
    override fun toString(): String = super.toString() + " Student " + num
    companion object {
        var NB = 0
    }
    init {
        NB++
    }
}

object TestPersonne {
    @JvmStatic
    fun main(args: Array<String>) {
        //  TEST 1 : Une instance
        val p = Personne("Duchemin", "paul")
        println(p)
        // TEST 2 : Une collection
        val al1 = ArrayList<Personne>()
        for (i in 1..10) al1.add(Personne("Duchemin$i", "paul$i"))
        println(al1.size)
        for (p1 in al1) println(p1)
        // TEST 3 : Polymorphisme
        val al2 = ArrayList<Personne>()
        for (i in 1..10) if (i % 2 == 0) al2.add(
            Personne("Duchemin$i", "paul$i")
        ) else al2.add(Etudiant("Durand$i", "jules$i", i))
        for (p2 in al2) println(p2)
        println("Nb etudiants " + Etudiant.NB)
    }
}
