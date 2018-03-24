OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

FriendlyBounce.run: main.o game.o player.o ball.o physics.o object.o
	g++ -o FriendlyBounce.run main.o game.o player.o ball.o physics.o object.o -lsfml-window -lsfml-graphics -lsfml-system

game.o: game.cc
	g++ -c game.cc $(OPCIONS)

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

player.o: player.cc
	g++ -c player.cc $(OPCIONS)

ball.o: ball.cc
	g++ -c ball.cc $(OPCIONS)

object.o: object.cc
	g++ -c object.cc $(OPCIONS)

physics.o: physics.cc
	g++ -c physics.cc $(OPCIONS)

clean:
	rm *.o
	rm *.run
