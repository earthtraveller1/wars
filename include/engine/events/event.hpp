#ifndef C5DC771B_C597_41B4_B2F1_7BF87C0D38A6
#define C5DC771B_C597_41B4_B2F1_7BF87C0D38A6

#pragma once

namespace wars
{
    class event
    {
    public:
        event() = default;
        
        virtual ~event();
        
    private:
        event_type type;
    };
}

#endif /* C5DC771B_C597_41B4_B2F1_7BF87C0D38A6 */
