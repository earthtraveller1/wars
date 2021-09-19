#ifndef EB383F48_FF8D_4C7C_B0B7_BEA615AF9270
#define EB383F48_FF8D_4C7C_B0B7_BEA615AF9270

#pragma once

#include <engine/events/key_press_event.hpp>

namespace wars::engine::events
{
    class event_listener
    {
    public:
        virtual bool invoke_key_press(key_press_event& event) const { return false; }
        
        virtual ~event_listener() {};
    };
}

#endif /* EB383F48_FF8D_4C7C_B0B7_BEA615AF9270 */
