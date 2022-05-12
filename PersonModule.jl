module PersonModule
export PersonBase, Person, Student, print, testCases

abstract type PersonBase end

mutable struct Person <: PersonBase
    lastname :: String
    firstname :: String
    Person(name,firstname) = new(name,firstname)
end


mutable struct Student <: PersonBase
    lastname :: String
    firstname :: String
    number :: Integer
    Student(name,firstname,number) = new(name,firstname,number)
end


function print(p::Person)
    println(string(p.firstname," ",p.lastname))
end

function print(s::Student)
    println(string(s.firstname," ",s.lastname," ",s.number))
end

function print(b::PersonBase)
    print(b)
end

function testCases()
    #  TEST 1 : An instance
    p = Person("Duchemin","paul")
    print(p)

    #  TEST 2 : A Collection
    al1 = [Person("Duchemin$i","paul") for i in 1:10]
    for p in al1
        print(p)
    end

    #  TEST 3 : Polymorphism
    al2 = []
    for i in 1:10
        i%2 == 0 ? push!(al2,Person("Duchemin$i","paul")) : push!(al2,Student("Durand$i","jules",i*1000))
    end
    for p in al2
        print(p)
    end
end
end # module
