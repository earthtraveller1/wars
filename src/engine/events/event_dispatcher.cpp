#include <engine/events/event_queues.hpp>

#include <engine/events/event_dispatcher.hpp>

void wars::engine::events::event_dispatcher::dispatch_key_press() {
    for (const auto& listener: m_listeners) {
        for (auto& event: queues::key_press_queue) {
            listener.invoke_key_press(event);
        }
    }
}

void wars::engine::events::event_dispatcher::dispatch_all() {
    dispatch_key_press();
}