all: program4

p1: program4.cpp
	g++ -g program4.cpp -o program4
  
clean:
	rm -rf program4
