#include <memory>

class Sound;

class SoundSource : public Component
{
private:
  ALuint sourceId;
  bool autoRemove;
  
public:
  void onInit();
  void onInit(std::shared_ptr<Sound> sound);
  void onTick();
  
  void setAutoRemove(bool autoRemove);
  void setSound(std::shared_ptr<Sound> sound);
}