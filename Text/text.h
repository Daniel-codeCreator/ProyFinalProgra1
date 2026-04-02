#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "raylib.h"
#include <cstring>

class TextBox {

private:

    Rectangle bounds;
    char text[64];
    int length;
    bool active;

public:

    TextBox(int x, int y, int w, int h);

    void update();
    void draw();

    const char* getText();

};

#endif