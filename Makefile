all:

build:
	g++ src/main.cpp src/gamemode.cpp src/field_draw.cpp src/playercontroller.cpp src/ai.cpp -o main

debug:
	g++ src/main.cpp src/gamemode.cpp src/field_draw.cpp src/playercontroller.cpp src/ai.cpp -o main -g

check:
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem src/*.cpp src/*.h