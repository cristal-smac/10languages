# Principe

How to write a basic Object Oriented Program (OOP) in several languages ?

L'objectif de cette page n'est pas de fournir un cours sur les différents langages, mais de donner un exemple synthétique, le plus court possible, illustrant les concepts de base de la POO.
Une classe, une instance, un héritage, une méthode affinée, une variable statique, une collection, une forme de polymorphisme. L'exemple fourni est très simple volontairement : Une classe `Personne(nom,prenom)` avec une instance de cet objet. Une classe `Etudiant` qui en hérite et l'affine avec un `num` et une variable de classe `NB` permettant de compter les instances créées. Une collection d'individus, parfois une simple personne, parfois un étudiant pour illustrer la surcharge de méthode. La seule méthode dans ces objets est la méthode `toString` (ou son équivalent s'il existe) qui permet son affichage texte.

- Java
- Python
- PHP
- Javascript
- C++
- Scala
- Ruby
- Perl
- Crystal

Fournir une base commune permettra à chacun de partir de l'écriture qu'il connait bien (son langage de porgrammation habituel) pour migrer vers l'un des autres langages.


# Quelques caractéristiques élémentaires

## Java
- compilé
- typage explicite
- chaque instruction se termine avec un ;
- les blocs sont délimités par {}
- version actuelle : java -version (2019) : 11.0
- un message : System.out.println("hello world!");


## C++
- compilé
- typage explicite
- allocation manuelle
- un message : cout << "hello world!" << endl;


## Python 3
- interprété
- shell interactif
- typage dynamique
- une instruction par ligne
- blocs définis par indentation
- version actuelle : python -V (2019) : 3.7
- un message : print("hello world!")

- python         mode interactif
- python fich    execution du fichier
- python -i fich execution du fichier et reste en interactif


## PHP
- influencé par C
- interprété
- shell interactif
- typage dynamique
- chaque instruction se termine avec un ;
- chaque variable est préfixée par un $
- les blocs sont délimités par {}
- version actuelle php -version (2019) : 7.1.3
- Un message : echo("hello world!");


- php -a         mode interactif
- php -f fich    execution du fichier


## Javascript
- interprété
- shell interactif (dans une console web d'un navigateur)
- typage dynamique faible
- langage de prototypes. Un objet n’est jamais qu’une collection de clés et de valeurs
- Un message : print("hello world!")

- Mode interactif dans la console du navigateur

## Ruby
- influencé par Eiffel
- interprété
- shell interactif (irb)
- version actuelle ruby -v (2019) : 2.3.7
- Un message : puts "hello world !"
