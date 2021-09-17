#ifndef DFB5913A_2568_49EF_B084_535847734032
#define DFB5913A_2568_49EF_B084_535847734032

namespace wars
{
    class key_press_event;
    
    class event_listener
    {
    public:
        virtual bool invoke_key_press(key_press_event& event) const;
    };
}

#endif /* DFB5913A_2568_49EF_B084_535847734032 */
