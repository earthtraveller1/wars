#ifndef D62F609B_508A_4C92_8E89_A10337AF1D71
#define D62F609B_508A_4C92_8E89_A10337AF1D71

class CollisionBox {
private:
    int right;
    int left;
    int top;
    int bottom;
    
public:
    // Check if this collision box has collided with another collision box
    bool collided(const CollisionBox& target);
};

#endif /* D62F609B_508A_4C92_8E89_A10337AF1D71 */
