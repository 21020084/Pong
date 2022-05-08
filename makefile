#run the application
run: bin/pong.exe
	bin/pong

#create the executable file
bin/pong.exe: obj/main.o obj/Game.o obj/state-manager.o obj/Game-state.o obj/splashScreen-state.o obj/Menu-state.o
	g++ obj/main.o \
      obj/Game.o \
      obj/state-manager.o \
			obj/Game-state.o \
      obj/splashScreen-state.o \
			obj/Menu-state.o \
  -o bin/pong.exe \
  -LD:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

#compile 'main'
obj/main.o: src/main.cpp
	g++ -c src/main.cpp -o obj/main.o -ID:/SFML-2.5.1/include -g

#compile 'Game'
obj/Game.o: src/Game.cpp src/Game.h 
	g++ -c src/Game.cpp -o obj/Game.o -ID:/SFML-2.5.1/include -g

#compile 'state-manager'
obj/state-manager.o: src/state/state-manager.cpp src/state/state-manager.h
	g++ -c src/state/state-manager.cpp -o obj/state-manager.o -ID:/SFML-2.5.1/include -g

#compile 'Game-state'
obj/Game-state.o: src/state/Game-state.cpp src/state/Game-state.h
	g++ -c src/state/Game-state.cpp -o obj/Game-state.o -ID:/SFML-2.5.1/include -g

#compile 'splashScreen-state'
obj/splashScreen-state.o: src/state/splashScreen-state.cpp src/state/splashScreen-state.h
	g++ -c src/state/splashScreen-state.cpp -o obj/splashScreen-state.o -ID:/SFML-2.5.1/include -g

#compile 'Menu-state'
obj/Menu-state.o: src/state/Menu-state.cpp src/state/Menu-state.h
	g++ -c src/state/Menu-state.cpp -o obj/Menu-state.o -ID:/SFML-2.5.1/include -g

#update Game.h
src/Game.h: src/state/state-manager.h
	touch src/Game.h

#update state-manager.cpp
src/state/state-manager.cpp: src/state/splashScreen-state.h src/state/Menu-state.h
	touch src/state/state-manager.cpp

#update state-manager.h
src/state/state-manager.h: src/state/Game-state.h
	touch src/state/state-manager.h 