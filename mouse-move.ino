
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

/// @brief ユニット確認画面で、アイドルをランダムのおまかせ編成にする
void setRandomIdolOnUnitConfirm()
{
    // おまかせ編成ボタン
    moveMouse(-800, -580);
    Mouse.click();
    delay(0.3 * 1000);

    // 決定ボタン
    moveMouse(-450, -200);
    Mouse.click();
    delay(0.3 * 1000);
}

/// @brief 指定したインデックスのアイドルの衣装をお気に入り1に設定する
/// @param index
void setIdolCostume(int index)
{
    const int startPos = -1100;
    const int height = -230;
    const int diff = -220;

    // 衣装変更ボタン
    moveMouse(startPos - diff * index, height);
    Mouse.click();
    delay(0.5 * 1000);

    // お気に入りボタン
    moveMouse(-100, -700);
    Mouse.click();
    delay(1.2 * 1000);

    // 座標重なっているのでそのまま「適用」をクリック
    Mouse.click();
    delay(0.8 * 1000);

    // 閉じるボタン
    moveMouse(-300, bottomButtonHeight);
    Mouse.click();
    delay(0.3 * 1000);

    // 決定ボタン押下
    moveMouse(-100, bottomButtonHeight);
    Mouse.click();
    delay(1.5 * 1000);
}
