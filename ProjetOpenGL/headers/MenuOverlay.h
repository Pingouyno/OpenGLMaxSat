#ifndef MENU_OVERLAY_CLASS_H
#define MENU_OVERLAY_CLASS_H

#include"Overlay.h"
#include"Globals.h"

class MenuOverlay : public Overlay
{
    private:
        //mettre des variables √©ventuellement

    public:
        MenuOverlay(Camera* camera);
        void setupOverlay();
};
#endif