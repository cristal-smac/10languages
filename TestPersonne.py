class Personne:
    def __init__(self,nom,prenom):
        self.nom=nom
        self.prenom=prenom
    def __str__(self):
        return self.nom+" "+self.prenom

class Etudiant(Personne):
    NB=0;
    def __init__(self,nom,prenom,num):
        super().__init__(nom,prenom)
        self.num=num
        Etudiant.NB+=1
    def __str__(self):
        return super().__str__()+" Student "+str(self.num)
    


if __name__ == '__main__':
    #  TEST 1 : Une instance
    p = Personne("Duchemin","paul");
    print(p)
	
    # TEST 2 : Une collection
    al1 = [Personne("Duchemin"+str(i),"paul"+str(i)) for i in range(1,11)]
    for p in al1: print(p)
	
    # TEST 3 : Polymorphisme
    al2 =[]
    for i in range(1,10):
        if i%2==0:
            al2.append(Personne("Duchemin"+str(i),"paul"+str(i)))
        else:
            al2.append(Etudiant("Durand"+str(i),"jules"+str(i) , i))
    for p in al2: print(p)
    
    print("Nb etudiants "+str(Etudiant.NB))
