#ifndef B84FAA61_C9C7_4546_901C_4F06F96A2EFA
#define B84FAA61_C9C7_4546_901C_4F06F96A2EFA

#include <scp/Scene.hpp>

class MenuScene: public scp::Scene
{
public:
    MenuScene();
    
    void onUpdate(double deltaTime) override;
    
    void render() override;
    
    ~MenuScene() override;
};

#endif /* B84FAA61_C9C7_4546_901C_4F06F96A2EFA */
