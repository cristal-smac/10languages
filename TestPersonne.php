/*
* Un $ devant toute les variables (sauf avec this, auquel cas c'est thios qui prend le $)
* Pas de type à indiquer
* Le foreach est inversé par rapport à Python et Java
* L'appel de méthode se fait avec ->
* la concaténation de chaines se fait avec .  (et pas avec +)
* Pas d'équivalent à toString() en PHP
* __construct pour PHP>5.3.3 , nomclasse() pour PHP<=5.3.3
* self, parent, static  depuis PHP>=5.3.0
*/

<?php

class Personne
{
	private $nom;
	private $prenom;
	
	public function __construct($nom,$prenom)
	{$this->nom=$nom; $this->prenom=$prenom;}

	public function toString() {return $this->nom." ".$this->prenom;}
}


class Etudiant extends Personne
{
	private $num;
	public static $NB=0;
	
	function __construct($nom,$prenom,$num)
	{
		parent::__construct($nom,$prenom);
		$this->num = $num;
		self::$NB++;
	}

	public function toString() {return parent::toString()." Student ".$this->num;}
}


//  TEST 1 : Une instance
$p = new Personne("Duchemin","paul");
echo $p->toString()."\n";

// TEST 2 : Une collection
$al1=array();
for ($i=1;$i<=10;$i++)
	$al1[] = new Personne("Duchemin".$i,"paul".$i);
foreach ($al1 as $p1) echo($p1->toString()."\n");
	
// TEST 3 : Polymorphisme
$al2=array();
for ($i=1;$i<=10;$i++)
	if ($i%2==0) $al2[] = new Personne("Duchemin".$i,"paul".$i);
	else $al2[] = new Etudiant("Durand".$i,"jules".$i , $i);
foreach ($al2 as $p2) echo($p2->toString()."\n");

echo("Nb etudiants ".Etudiant::$NB."\n");

?>
