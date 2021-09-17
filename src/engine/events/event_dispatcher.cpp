#include <engine/events/event_listener.hpp>
#include <engine/events/event_queues.hpp>

#include <engine/events/event_dispatcher.hpp>

using namespace wars;

void event_dispatcher::add_key_press_listener(event_listener& listener) 
{
    listeners.push_back(listener);
}




void event_dispatcher::dispatch_events() 
{
    // Loop through all the the event listeners
    for (const event_listener& listener: listeners) 
    {
        // Loop through all the key press events
        for (uint16_t i = 0; i < event_queues::key_press.size(); i++) 
        {
            // Pass the events in the key press queue to the listeners.
            // Remove the event from the queue if the listener returns that it
            // has been handled.
            if (listener.invoke_key_press(event_queues::key_press.front())) 
            {
                event_queues::key_press.pop();
            }
        }
    }
}