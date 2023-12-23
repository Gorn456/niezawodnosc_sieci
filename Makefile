# Sprawdź typ systemu
ifeq ($(OS),Windows_NT)
    # Komendy dla systemu Windows
    BUILD_PATH := ./build_windows
    COMPILER := g++
    OUTPUT := output.exe
else
    # Komendy dla systemów Unix-like (Linux, macOS)
    BUILD_PATH := ./build
    COMPILER := clang++
    OUTPUT := output
endif

default:
	$(COMPILER) -c messages.cpp -o $(BUILD_PATH)/messages.o
	$(COMPILER) -c files.cpp -o $(BUILD_PATH)/files.o
	$(COMPILER) -std=c++20 main.cpp $(BUILD_PATH)/messages.o $(BUILD_PATH)/files.o -o $(BUILD_PATH)/$(OUTPUT)



