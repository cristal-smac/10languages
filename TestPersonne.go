/*
Golang version 1.12
go build -o TestPersonne TestPersonne.go
*/

package main

import (
	"fmt"
	"strconv"
)

// Go n'est pas un langage objet
// Pas d'héritage ... Mais on peut faire de la composition

// Person Interface
type Person interface {
	toString() string
}

// Struct Person
type person struct {
	toStr  func() string
	nom    string
	prenom string
}

// Etudiant Interface
type Etudiant interface {
	Person
}

// Struct Etudiant
type etudiant struct {
	person
	num int
}

// NewPerson Struct Person + méthode toStr
func NewPerson(nom string, prenom string) *person {
	p := &person{nom: nom, prenom: prenom}
	p.toStr = p.toString
	return p
}

// Retourne une chaine qui représente la structure Person
func (p *person) toString() string {
	return fmt.Sprintf("%v %v", p.nom, p.prenom)
}

// NewEtudiant Struct Etudiant composée de Person + méthode toStr
func NewEtudiant(nom string, prenom string, num int) *etudiant {
	e := &etudiant{
		person: person{nom: nom, prenom: prenom},
		num:    num,
	}
	e.toStr = e.toString
	return e
}

// Retourne une chaine qui représente la structure Etudiant
func (e *etudiant) toString() string {
	return fmt.Sprintf("%v Student %v", e.person.toString(), strconv.Itoa(e.num))
}

// print with toString (interface)
func toString(p Person) {
	println(p.toString())
}

func main() {
	// Struct
	p := NewPerson("Duchemin", "paul")
	fmt.Println(p.toStr())

	// Collection
	var al1 []*person
	for i := 1; i <= 10; i++ {
		is := strconv.Itoa(i)
		al1 = append(al1, NewPerson("Duchemin"+is, "Paul"+is))
	}
	for _, v := range al1 {
		println(v.toStr())
	}

	// Mixed Interface (mixed structs)
	al2 := make([]interface{}, 0) // mix structs
	NbEtudiant := 0
	for i := 1; i <= 10; i++ {
		is := strconv.Itoa(i)
		if i%2 == 0 {
			al2 = append(al2, NewPerson("Duchemin"+is, "Paul"+is))
		} else {
			al2 = append(al2, NewEtudiant("Durand"+is, "Jules"+is, i))
			NbEtudiant = NbEtudiant + 1
		}
	}

	for _, e := range al2 {
		// Type assertion
		switch e := e.(type) {
		case *person:
			toString(e)
		case *etudiant:
			toString(e)
		default:
			panic(fmt.Sprintf("type non supporté: %T", e))
		}
	}

	println("Nb Etudiants: ", strconv.Itoa(NbEtudiant))
}
