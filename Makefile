all : build run

build :
				g++ src/* -o phonem-trainer -lSDL -lSDL_image -lSDL_mixer -lm -Wall -Wshadow

install :
				apt-get install libsdl1.2debian libsdl1.2-dev libsdl-image1.2-dev libsdl-image1.2 libsdl-mixer1.2 libsdl-mixer1.2-dev

run :
				./phonem-trainer
