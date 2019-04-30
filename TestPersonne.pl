#!/usr/bin/env perl
use strict;
use warnings;
use 5.010;
use Attribute::Abstract;
use Data::Dumper;

{
    package Personne;
    sub new {
        my ($class, $nom, $prenom) = @_;
        my $this = {
        		nom => $nom,
                prenom => $prenom
        };
        bless($this,$class);  
        return $this;
    }

    sub personneToString {
        my ($this) = @_;
        return "$this->{nom} $this->{prenom}";
    }
}

{
    package Etudiant;
    our @ISA = qw(Personne);
    our $NB = 0;

    sub new {
	    my ($class, $nom, $prenom, $num) = @_;   
        my $this = $class->SUPER::new($nom, $prenom);
        bless($this, $class);
        $this->{num} = $num;
        ++$NB;
        return $this;
    }

    sub personneToString {
        my ($this) = @_;
        return "$this->{nom} $this->{prenom} $this->{num} Student";
    }
}

# Une instance
my $p = Personne->new('Duchemin ', 'paul');
say $p->personneToString();

# Une Collection
my @numbers = (1..10);
my @al1 = map { Personne->new("Duchemin$_ ", "paul$_ ")} @numbers;

foreach my $p (@al1) {
    say $p->personneToString();
}

# Polymorphisme
my @pnumbers = (1..10);
my @al2;
foreach my $pnumber (@pnumbers){
    push @al2, Personne->new("Duchemin$pnumber", "paul$pnumber") if ($pnumber % 2 == 0);
    push @al2, Etudiant->new("Durand$pnumber", "jules$pnumber", $pnumber) if ($pnumber % 2 == 1);
}

foreach my $p (@al2) {
    say $p->personneToString();
}
say "Nombre d'étudiants: $Etudiant::NB";