#include <pch.hpp>

#include <engine/events/key_press_event.hpp>

using namespace wars;

key_press_event::key_press_event(int32_t key_code): m_key_code(key_code)
{
    
}

int32_t key_press_event::get_key_code()
{
    return m_key_code;
}

key_press_event::~key_press_event()
{
    
}