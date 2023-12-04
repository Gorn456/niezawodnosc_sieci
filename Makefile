default:
	clang++ -c messages.cpp -o ./build/messages.o
	clang++ -c files.cpp -o ./build/files.o
	clang++ -std=c++20 main.cpp ./build/messages.o ./build/files.o -o ./build/output
	./build/./output -i input.txt -o output.txt