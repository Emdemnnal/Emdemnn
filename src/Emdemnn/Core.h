#include <memory>

class Entity;

class Core
{
private:
	std::list<std::shared_ptr<Entity>>;
	bool running;

public:
	std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
}