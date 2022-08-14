#ifndef GAME_OVERLAY_CLASS_H
#define GAME_OVERLAY_CLASS_H

#include"Overlay.h"

class GameOverlay : public Overlay
{
    
    public:
        GameOverlay(Camera* camera);
        void setupOverlay();
};
#endif