CXX = g++
CFLAGS = -g -Wall -Wextra
OBJ = \
			obj/salty_list.o
LINK = 

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CFLAGS) $< -c -o $@

salty: obj/main.o $(OBJ)
	$(CXX) $(CFLAGS) obj/main.o $(OBJ) -o $@ $(LINK)

clean:
	rm -rf obj ircbot
