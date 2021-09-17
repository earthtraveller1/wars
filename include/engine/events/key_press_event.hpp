#ifndef FA5917BB_90E7_477C_9490_F85BD08D225E
#define FA5917BB_90E7_477C_9490_F85BD08D225E

namespace wars::engine::events
{
    class key_press_event
    {
    public:
        key_press_event(int16_t key_code);
        
        int16_t get_key_code() { return m_key_code; };
        
    private:
        int16_t m_key_code;
    }
}

#endif /* FA5917BB_90E7_477C_9490_F85BD08D225E */
