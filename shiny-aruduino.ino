#include "Mouse.h"

const int notification_led_port = 13;

void setup()
{
    // put your setup code here, to run once:
    pinMode(notification_led_port, OUTPUT);
    digitalWrite(notification_led_port, LOW);

    // シリアルポートを開く
    Serial.begin(9600);

    // Mouseライブラリの初期化
    Mouse.begin();

    // 初期化完了を通知
    flashLED(notification_led_port);
    flashLED(notification_led_port);

    randomSeed(analogRead(0));
}

// マウス移動処理中かどうかのフラグ
bool isProcessing = false;

void loop()
{
    if (Serial.available() > 0)
    {
        int x = Serial.parseInt();

        if (x == 1 && !isProcessing)
        {
            // MV再生処理完了
            flashLED(notification_led_port);
            flashLED(notification_led_port);

            // ここでマウスを動かす

            // 処理中フラグ設定
            isProcessing = true;

            moveMouseForStartingMv();

            // MV再生処理完了
            flashLED(notification_led_port);
            flashLED(notification_led_port);

            // フラグクリア
            isProcessing = false;
        }
    }
}

void flashLED(int port)
{
    digitalWrite(port, HIGH);
    delay(100);
    digitalWrite(port, LOW);
}

void moveMouseForStartingMv()
{
    // カーソル位置初期化
    mousePositionInitialize();
    mvButtonHeightInitialize();

    // ランダムボタン押下
    int randNumber = random(1, 10); // 10から9の乱数を生成
    moveMouse(-800, 0);

    for (int i = 0; i < randNumber; i++)
    {
        Mouse.click();
        delay(0.8 * 1000);
    }

    // MV再生ボタン押下
    moveMouse(500, 0);
    Mouse.click();
    delay(2 * 1000);

    // スタートボタン押下
    moveMouse(200, 0);
    Mouse.click();
    delay(1 * 1000);

    // マウスを元の位置に戻す
    mousePositionInitialize();
}
