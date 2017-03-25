#include <memory>
#include <iostream>

class Pedigree {
	public:
		Pedigree(const std::string& name, std::shared_ptr<Pedigree> mother, std::shared_ptr<Pedigree> father) : name{name}, mother{mother}, father{father} {}
		const std::string& get_name() const { return name; }
		std::shared_ptr<Pedigree> get_mother() const { return mother; }
		std::shared_ptr<Pedigree> get_father() const { return father; }
	private:
		std::string name;
		std::shared_ptr<Pedigree> mother, father;
};

int main() {

	Pedigree son{"son", std::make_shared<Pedigree>("mother", nullptr, nullptr), nullptr};
	
	std::cout << son.get_mother()->get_name() << "\n";

	return 0;
}

