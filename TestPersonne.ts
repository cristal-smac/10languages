// TypeScript 3.4 - ES6
// .tsconfig.json
// {
//   "compilerOptions": {
//     "target": "es6",
//     "module": "commonjs",
//     "sourceMap": true
//   }
// }
// Compiler en js => tsc TestPersonne.ts
// nodejs TestPersonne.js

class Person {
  private nom: string;
  private prenom: string;
  constructor(nom: string, prenom: string) {
    this.nom = nom;
    this.prenom = prenom;
  }
  public toString(): string {
    return `${this.nom} ${this.prenom}`;
  }
}

class Etudiant extends Person {
  static nb_etudiant: number = 0;
  private num: number;
  constructor(nom: string, prenom: string, num: number) {
    super(nom, prenom);
    this.num = num;
    Etudiant.nb_etudiant += 1;
  }
  public toString(): string {
    return `${super.toString()} Student ${this.num}`;
  }
}

// Une instance
let p = new Person('Duchemin', 'Paul');
console.log(p.toString());

// Une collection
let al1: Person[] = [];
for (let i: number = 0; i <= 10; i++) {
  al1.push(new Person(`Duchemin ${i}`, `Paul ${i}`));
}
al1.forEach(person => {
  console.log(person.toString());
});

//Polymorphisme
let al2: (Person | Etudiant)[] = [];
for (let i: number = 0; i <= 10; i++)
  if (i % 2 == 0) al2.push(new Person(`Duchemin${i}`, `Paul${i}`));
  else al2.push(new Etudiant(`Durand${i}`, `Jules${i}`, i));
al2.forEach(person => {
  console.log(person.toString());
});

console.log(`Nb etudiant ${Etudiant.nb_etudiant}`);
