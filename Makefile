CXX = g++
CFLAGS = -g -Wall -Wextra
OBJ = \
			obj/chain.o \
			obj/block.o
LINK = 

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CFLAGS) $< -c -o $@

salty: obj/main.o $(OBJ)
	$(CXX) $(CFLAGS) obj/main.o $(OBJ) -o $@ $(LINK)

clean:
	rm -rf obj ircbot
