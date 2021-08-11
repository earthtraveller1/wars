#ifndef C55B12CB_B69C_4CBF_BB7D_3CC533177A54
#define C55B12CB_B69C_4CBF_BB7D_3CC533177A54

#include <graphics/Sprite.hpp>
#include "../CollisionBox.hpp"

class Player: public graphics::Sprite, public CollisionBox {
public:
    Player();
    
    virtual void move(double x, double y);
};

#endif /* C55B12CB_B69C_4CBF_BB7D_3CC533177A54 */
