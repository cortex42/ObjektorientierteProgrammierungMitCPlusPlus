#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>

class Room {
	public:

	unsigned int		get_number_of_neighbors() const {
		return neighbors.size();

	}
	const Room &		get_neighbor(unsigned int neighbor_index) const;
	void			add_neighbor(Room room) {
		neighbors.push_back(room);
	}

	private:
	
		unsigned int number_of_neighbors;
		std::vector<Room> neighbors;
};

#endif //ROOM_HPP
	

