all:
	g++ -std=c++11 main.cpp Path.cpp Prompt.cpp JMShell.cpp CommandLine.cpp -o program
	./program
clean: 
	rm program
