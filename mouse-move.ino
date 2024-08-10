
const int monitorWidth = 3840;
const int monitorHeight = 2160;

const int initializeValue = 9999;

void moveMouse(int x, int y)
{
    moveMouseForX(initializeValue);
    moveMouseForY(initializeValue);
    delay(100);
    moveMouseForX(x);
    moveMouseForY(y);
}

void moveMouseForX(int x)
{
    int current_x = x;

    if (current_x > 0)
    {
        while (current_x > 0)
        {
            if (current_x > 127)
            {
                current_x -= 127;
                Mouse.move(127, 0, 0);
            }
            else
            {
                Mouse.move(current_x, 0, 0);
                current_x = 0;
            }
        }
    }
    else
    {
        while (current_x < 0)
        {
            if (current_x < -127)
            {
                current_x += 127;
                Mouse.move(-127, 0, 0);
            }
            else
            {
                Mouse.move(current_x, 0, 0);
                current_x = 0;
            }
        }
    }
}

void moveMouseForY(int y)
{
    int current_y = y;

    if (current_y > 0)
    {
        while (current_y > 0)
        {
            if (current_y > 127)
            {
                current_y -= 127;
                Mouse.move(0, 127, 0);
            }
            else
            {
                Mouse.move(0, current_y, 0);
                current_y = 0;
            }
        }
    }
    else
    {
        while (current_y < 0)
        {
            if (current_y < -127)
            {
                current_y += 127;
                Mouse.move(0, -127, 0);
            }
            else
            {
                Mouse.move(0, current_y, 0);
                current_y = 0;
            }
        }
    }
}

/// @brief 現在のマウスの位置をモニターの左上に移動する
void mousePositionInitialize()
{
    moveMouse(initializeValue, initializeValue);
}

void mvButtonHeightInitialize()
{
    moveMouse(0, -50);
}
