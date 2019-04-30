#!/usr/bin/env ruby
class Personne
  attr_reader :nom, :prenom # dynamic getter

  def initialize(nom:, prenom:)
    @nom = nom
    @prenom = prenom
  end

  def to_s
    "#{nom} #{prenom}"
  end
end

class Etudiant < Personne
  attr_reader :num # dynamic getter
  class << self; attr_accessor :nb_etudiant end
  @nb_etudiant = 0

  def initialize(nom:, prenom:, num:)
    super(nom: nom, prenom: prenom) # call implicit parent arguments
    @num = num
    self.class.nb_etudiant += 1 # ou Etudiant.nb_etudiant += 1
  end

  def to_s
    super + " Student #{num}"
  end
end

# Une instance
p = Personne.new(nom: 'Duchemin ', prenom: 'paul')
puts p

# Une Collection
al1 = (1...10).map { |i| Personne.new(nom: "Duchemin#{i}", prenom: "paul#{i}") }
puts al1

# Polymorphisme
al2 = (1...10).map do |i|
  i.even? ? Personne.new(nom: "Duchemin#{i}", prenom: "Paul#{i}")
          : Etudiant.new(nom: "Durand#{i}", prenom: "jules#{i}", num: i)
end
puts al2; puts "Nombre d'étudiants: #{Etudiant.nb_etudiant}"
