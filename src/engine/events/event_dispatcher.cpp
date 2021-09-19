#include <engine/events/event_queues.hpp>

#include <engine/events/event_dispatcher.hpp>

void wars::engine::events::event_dispatcher::dispatch_key_press() {
    for (const auto& listener: m_listeners) {
        uint16_t i = 0;
        for (auto& event: queues::key_press_queue) {
            if (listener.invoke_key_press(event)) {
                queues::key_press_queue.erase(queues::key_press_queue.begin() + i);
            }
            
            i++;
        }
    }
}

void wars::engine::events::event_dispatcher::dispatch_all() {
    dispatch_key_press();
}