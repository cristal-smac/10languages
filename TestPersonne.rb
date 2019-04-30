#!/usr/bin/env ruby
class Personne
  def initialize(nom, prenom)
    @nom = nom
    @prenom = prenom
  end

  def to_s; "#{@nom} #{@prenom}" end
end

class Etudiant < Personne
  class << self; attr_accessor :nb_etudiant end
  @nb_etudiant = 0

  def initialize(nom, prenom, num)
    super(nom, prenom) # pass arguments to parent
    @num = num
    self.class.nb_etudiant += 1 # or Etudiant.nb_etudiant += 1
  end

  def to_s; super + " Student #{@num}" end
end

# Une instance
p = Personne.new('Duchemin ', 'paul')
puts p

# Une Collection
al1 = (1..10).map { |i| Personne.new("Duchemin#{i}", "paul#{i}") }
puts al1

# Polymorphisme
al2 = (1..10).map do |i|
  i.even? ? Personne.new("Duchemin#{i}", "Paul#{i}")
          : Etudiant.new("Durand#{i}", "jules#{i}", i)
end
puts al2; puts "Nombre d'étudiants: #{Etudiant.nb_etudiant}"
