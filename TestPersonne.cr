#  Crystal lang version

class Personne
  def initialize(@nom : String, @prenom : String)
  end

  def to_s(io : IO)
    io << "#{@nom} #{@prenom}"
  end
end

class Etudiant < Personne
  @@nb_etudiant = 0

  def initialize(@nom : String, @prenom : String, @num : Int32)
    super(@nom, @prenom) # pass arguments to parent
    @num = num
    @@nb_etudiant += 1
  end

  def self.nb_etudiant
    @@nb_etudiant
  end

  def to_s(io : IO)
    super << " Student #{@num}"
  end
end

# Une instance
p = Personne.new("Duchemin ", "paul")
puts p

# Une Collection
al1 = (1..10).map { |i| Personne.new("Duchemin#{i}", "paul#{i}").to_s }
al1.each { |p| puts p }

# Polymorphisme
al2 = (1..10).map do |i|
  i.even? ? Personne.new("Duchemin#{i}", "Paul#{i}") : Etudiant.new("Durand#{i}", "jules#{i}", i)
end
al2.each { |p| puts p }; puts "Nombre d'étudiants: #{Etudiant.nb_etudiant}"
