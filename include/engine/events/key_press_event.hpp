#ifndef D6949424_AD21_4A71_B273_A5650B3F008D
#define D6949424_AD21_4A71_B273_A5650B3F008D

namespace wars
{
    class key_press_event
    {
    public:
        key_press_event(int32_t key_code);
        
        int32_t get_key_code();
        
        virtual ~key_press_event();
    private:
        int32_t m_key_code;
    };
}

#endif /* D6949424_AD21_4A71_B273_A5650B3F008D */
