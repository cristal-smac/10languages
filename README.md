# Principe

How to write a basic Object Oriented Program (OOP) in several languages ?

L'objectif de cette page n'est pas de fournir un cours sur les différents langages ou sur la POO, mais de donner un exemple synthétique, le plus court possible, illustrant les concepts de base de la POO. Elle n'a d'intérêt que pour ceux qui connaissent déjà les bases de la POO avec un langage donné.

Nous fournissons ici une base commune permettra à chacun de partir de l'écriture qu'il connait bien (son langage de porgrammation habituel) pour migrer facilement vers l'un des autres langages disponibles.

Le programme écrit est le même dans tous les langages : Une classe, une instance, un héritage, une méthode affinée, une variable statique, une collection, une forme de polymorphisme. L'exemple fourni est très simple volontairement et dans un seul fichier : Une classe `Personne(nom,prenom)` avec une instance de cet objet. Une classe `Etudiant` qui en hérite et l'affine avec un `num` et une variable de classe `NB` permettant de compter les instances créées. Une collection d'individus, une fois sur deux une simple personne, une fois sur deux un étudiant, pour illustrer la surcharge de méthode. La seule méthode dans ces objets est la méthode d'affichage implicite (si elle existe) qui permet son affichage texte.

Langages actuellement disponibles : Java, Python, PHP, Javascript, C++, Scala, Ruby, Perl, Crystal

## Quelques caractéristiques élémentaires

## Java

- compilé (`javac fich.java` pour compiler; `java fich` pour exécuter)
- typage explicite
- console interactive (`jshell`)
- chaque instruction se termine avec un `;`
- les blocs sont délimités par `{}`
- version actuelle : `java -version` (2019) : 11.0
- un message : `System.out.println("hello world!");`
- methode d'affichage implicite d'un objet : `toString`

## C++

- compilé (`g++ fich.cpp` fournit un `a.out` exécutable)
- typage explicite
- allocation manuelle
- un message : `cout << "hello world!" << endl;`

## Python 3

- interprété
- typage dynamique
- shell interactif (`python` : mode interactif; `python fich` : execution du fichier ; `python -i fich` : execution du fichier et reste en interactif)
- une instruction par ligne
- blocs définis par indentation
- version actuelle : `python -V` (2019) : 3.7
- un message : `print("hello world!")`
- methode d'affichage implicite d'un objet : `__str__`

## PHP 7

- influencé par C
- interprété
- typage dynamique
- shell interactif (`php -a` : mode interactif ; `php -f fich` : execution du fichier )
- chaque instruction se termine avec un `;`
- chaque variable est préfixée par un `$`
- les blocs sont délimités par `{}`
- version actuelle `php -version` (2019) : 7.1.3
- Un message : `echo("hello world!");`

## Javascript

- interprété
- shell interactif (dans une console web d'un navigateur)
- typage dynamique faible
- langage de prototypes. Un objet n’est jamais qu’une collection de clés et de valeurs
- Un message : `print("hello world!")`

## TypeScript

- compilé
- nodejs
- ajout des types à javascript
- Un message : `print("hello world!")`

## Ruby

- influencé par Smalltalk
- interprété
- shell interactif (`irb`)
- version actuelle `ruby -v` (2019) : 2.6.3
- Un message : `puts "hello world !"`
- methode d'affichage implicite d'un objet : `to_s`

## Crystal Lang

- influencé par Ruby
- compilé
- typage explicite et implicite
- version actuelle `crystal -v` (2019) : 0.28
- Un message : `puts "hello world !"`
- methode d'affichage implicite d'un objet : `to_s`

## Golang

- influencé par C
- compilé
- typage statique
- Langage impératif et concurrent
- Une message : `fmt.Println("Hello, world")`
