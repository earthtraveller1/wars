#ifndef D62F609B_508A_4C92_8E89_A10337AF1D71
#define D62F609B_508A_4C92_8E89_A10337AF1D71

class CollisionBox {
private:
    double right;
    double left;
    double top;
    double bottom;
    
public:
    CollisionBox(double right = 100.0, double left = -100.0, double top = 100.0, double bottom = -100.0);
    
    // Check if this collision box has collided with another collision box
    bool collided(const CollisionBox& target) const;
    
    // Move the collision box
    void move(double x, double y);
};

#endif /* D62F609B_508A_4C92_8E89_A10337AF1D71 */
