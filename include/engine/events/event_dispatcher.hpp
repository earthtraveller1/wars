#ifndef C68542C9_6E3C_4DE7_8FDE_6018344FB702
#define C68542C9_6E3C_4DE7_8FDE_6018344FB702

#include <pch.hpp>

namespace wars
{
    class event_listener;
    
    class event_dispatcher
    {
    public:
        event_dispatcher() = default;
        
        // Attach a listener that listen for events to this dispatcher
        void add_key_press_listener(event_listener& listener);
        
        // Dispatch the key press events
        void dispatch_events();
        
    private:
        // The list of all of the listeners that will listen for key
        // presses
        std::vector<event_listener> listeners;
    };
}

#endif /* C68542C9_6E3C_4DE7_8FDE_6018344FB702 */
