#include "Room.hpp"
#include <iostream>

int main() {
	Room room;
	Room room2;
	std::cout << room.get_number_of_neighbors() << "\n";
	room.add_neighbor(room2);
	std::cout << room.get_number_of_neighbors()<<"\n";


	return 0;
}

