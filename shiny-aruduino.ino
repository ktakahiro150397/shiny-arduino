#include "Mouse.h"

const int notification_led_port = 13;

/// 初期化後、画面下部ボタンへの移動量
const int bottomButtonHeight = -50;

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
    delay(100);
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
            delay(100);
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
    // ランダムボタン押下
    int randNumber = random(1, 10); // 10から9の乱数を生成
    moveMouse(-800, bottomButtonHeight);

    for (int i = 0; i < randNumber; i++)
    {
        Mouse.click();
        delay(0.8 * 1000);
    }

    // MV再生ボタン押下
    moveMouse(-300, bottomButtonHeight);
    Mouse.click();
    delay(1.5 * 1000);

    // ユニットランダム設定
    setRandomIdolOnUnitConfirm();

    setIdolCostume(0);
    setIdolCostume(1);
    setIdolCostume(2);
    setIdolCostume(3);
    setIdolCostume(4);

    // スタートボタン押下
    moveMouse(-100, bottomButtonHeight);
    Mouse.click();
    delay(1 * 1000);

    // マウスを元の位置に戻す
    mousePositionInitialize();
}
