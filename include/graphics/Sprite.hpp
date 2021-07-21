#ifndef C0D911E7_8ADB_4629_80C3_A1DEEC083B8E
#define C0D911E7_8ADB_4629_80C3_A1DEEC083B8E

namespace graphics {
    // A Class that represents a sprite. Really basic for now, since I don't have much special needs
    class Sprite {
    private:
        // Graphics Card object handles
        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;
        
    public:
        // Default Constructor
        Sprite();
    };
}

#endif /* C0D911E7_8ADB_4629_80C3_A1DEEC083B8E */
