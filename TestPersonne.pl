#!/usr/bin/env perl
use 5.24.1;
use experimental qw( signatures );

package Personne;
sub new ($class, $nom, $prenom){
    my $this = {
      	nom => $nom,
        prenom => $prenom
    };
    bless($this,$class);  
    return $this;
}

sub toString ($this){
    return "$this->{nom} $this->{prenom}";
}

package Etudiant;
our @ISA = qw(Personne);
our $NB = 0;

sub new ($class, $nom, $prenom, $num){
    my $this = $class->SUPER::new($nom, $prenom);
    $this->{num} = $num;
    bless($this, $class);
    ++$NB;
    return $this;
}

sub toString ($this){
    my $parent = $this->SUPER::toString();
    return "$parent Student $this->{num}";
}

# Une instance
my $p = Personne->new('Duchemin ', 'paul');
say $p->toString();

# Une Collection
my @al1 = map { Personne->new("Duchemin$_ ", "paul$_ ")} my @numbers = (1..10);
print map{$_->toString() . "\n"} @al1;

# Polymorphisme
my @al2 = map { if ($_ % 2 == 0) {Personne->new("Duchemin$_ ", "paul$_ ")} else { Etudiant->new("Durand$_", "jules$_", $_)} } my @numbers = (1..10);
print map{$_->toString() . "\n"} @al2; say "Nombre d'étudiants: $Etudiant::NB";