#include <memory>
#include <list>

class Entity;

class Core
{
private:
	std::list<std::shared_ptr<Entity>> entity;
	bool running;

public:
	std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
};
