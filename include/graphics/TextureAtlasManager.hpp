#ifndef BD11F907_3386_4067_82FF_5F46ED6D8E54
#define BD11F907_3386_4067_82FF_5F46ED6D8E54

namespace std {
    template<typename T>
    class allocator;
    
    template<typename T, typename Allocator = std::allocator<T>>
    class vector;
}

namespace graphics {
    // A Singleton class that basically just manages the texture atlases
    class TextureAtlasManager {
    private:
        // The Vector of texture atlases
        std::vector<unsigned int> atlases;
        
        // Latest index
        unsigned int latestIndex = 0;
        
        // The Constructors are private because this is a singleton class
        TextureAtlasManager();
        TextureAtlasManager(TextureAtlasManager& src);
        TextureAtlasManager(TextureAtlasManager&& src);
        
    public:
        // Obtain the one and only instance of this class
        static TextureAtlasManager& getInstance();
        
        // Adds an atlas to the vector and return the index
        unsigned int add(unsigned int atlas);
        
        // Remove the atlas at the specified index
        void remove(unsigned int index);
        
        // Destroys all the remaining atlases that hasn't been destroyed
        ~TextureAtlasManager();
    }
}

#endif /* BD11F907_3386_4067_82FF_5F46ED6D8E54 */
