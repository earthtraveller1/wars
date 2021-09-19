#ifndef BE8CDCB3_3B1D_47D9_B64F_14C5D72F0F63
#define BE8CDCB3_3B1D_47D9_B64F_14C5D72F0F63

#include <Window.hpp>
#include <Input.hpp>

namespace wars
{
    class Game
    {
    public:
        Game();
        
        void mainLoop();
        
        ~Game();
        
    private:
        Window m_window;
        
        Input m_input;
    };
}

#endif /* BE8CDCB3_3B1D_47D9_B64F_14C5D72F0F63 */
