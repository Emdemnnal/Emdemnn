#include <memory>

class Core;
class Entity;

class Component
{
private:
	std::weak_ptr<Entity> entity;
	
	void onInit();
	void onBegin();
	void onTick();
	void onDisplay();
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore(); 
}
