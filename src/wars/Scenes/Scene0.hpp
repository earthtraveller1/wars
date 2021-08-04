#ifndef CA8FD98D_7FEB_46CB_9664_3F04AAF6A8D1
#define CA8FD98D_7FEB_46CB_9664_3F04AAF6A8D1

#include "../sprite-types/Button.hpp"
#include "../Scene.hpp"

class Scene0: public Scene {
private:
    Button playButton;
    Button otherButton;
    
public:
    Scene0();
    
    virtual void render() override;
    
    virtual void update(double deltaTime) override;
};

#endif /* CA8FD98D_7FEB_46CB_9664_3F04AAF6A8D1 */
