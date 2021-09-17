#ifndef D7DD1C83_E713_4ECD_9AFA_B011189C92CF
#define D7DD1C83_E713_4ECD_9AFA_B011189C92CF

#include <pch.hpp>
#include <engine/events/key_press_event.hpp>
#include <engine/events/event_listener.hpp>

namespace wars::engine::events
{
    class event_dispatcher
    {
    public:
        event_dispatcher() = default;
        
        event_dispatcher(std::vector<event_listener>& listeners): m_listeners(listeners) {}
        
        void add_listener(event_listener& listener) { m_listeners.push_back(listener); }
        
        void dispatch_key_press();
        
        void dispatch_all();
        
    private:
        std::vector<event_listener> m_listeners;
    };
}

#endif /* D7DD1C83_E713_4ECD_9AFA_B011189C92CF */
