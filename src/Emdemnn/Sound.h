#include <string>

#include "Resource.h"

class Sound : public Resource
{
private:
  ALuint bufferId;
  
public:
  void onLoad(const string& path);
}