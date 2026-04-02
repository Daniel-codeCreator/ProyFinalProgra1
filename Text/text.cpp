#include "text.h"

TextBox::TextBox(int x, int y, int w, int h)
{
    bounds = { (float)x,(float)y,(float)w,(float)h };
    text[0] = '\0';
    length = 0;
    active = false;
}

void TextBox::update()
{

    if (CheckCollisionPointRec(GetMousePosition(), bounds) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        active = true;
    }

    if (!CheckCollisionPointRec(GetMousePosition(), bounds) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        active = false;
    }

    if (active)
    {

        int key = GetCharPressed();

        while (key > 0)
        {

            if ((key >= 32) && (key <= 125) && (length < 63))
            {
                text[length] = (char)key;
                length++;
                text[length] = '\0';
            }

            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            length--;
            if (length < 0) length = 0;
            text[length] = '\0';
        }
    }
}

void TextBox::draw()
{

    DrawRectangleRec(bounds, LIGHTGRAY);
    DrawRectangleLines(bounds.x, bounds.y, bounds.width, bounds.height, DARKGRAY);

    DrawText(text, bounds.x + 5, bounds.y + 10, 20, BLACK);
}

const char* TextBox::getText()
{
    return text;
}