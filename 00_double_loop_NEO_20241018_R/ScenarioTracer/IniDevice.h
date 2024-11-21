/******************************************************************************
 *  ファイル名：IniDevice.h
 *　　　　内容：デバイス初期化クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_INI_DEVICE
#define ___CLASS_INI_DEVICE     // インクルードカード

/* ヘッダインクルード */
#include "ev3api.h"         // ev3api
#include "common_struct.h"  // エンコーダ回転角構造体
#include "GyroSensor.h"     // ジャイロセンサ
#include "Motor.h"          // モータ


/* デバイス初期化クラス */
class IniDevice {
public:
    /* 列挙体 */
    typedef enum { START, MOTOR_ENCODER_RESET, GYRO_RESET, FINISH, } eState;    // 状態

    IniDevice();    // コンストラクタ

    void init();                // デバイスを初期化する関数
    eState checkState();        // 状態を確認する関数

private:
    void prepare();             // デバイス初期化の準備をする
    void resetMotorEncoder();   // モータエンコーダ回転角をリセットする関数
    void resetGyro();           // ジャイロセンサ回転角をリセットする関数
    void transState(eState s);  // 状態を遷移する関数

    /* 静的インスタンス */
    static ev3api::GyroSensor   mResetRollAngle;            // リセットロール角
    static ev3api::Motor        mStopForLeftMotor;          // 停止用左モータ
    static ev3api::Motor        mStopForRightMotor;         // 停止用右モータ
    static ev3api::Motor        mResetForLeftMotorEncoder;  // リセット用左モータエンコーダ
    static ev3api::Motor        mResetForRightMotorEncoder; // リセット用右モータエンコーダ

    eState state;   // 状態

    /* 入場動作フラグ */
    bool entry_motor;   // モータエンコーダ回転角リセット中
    bool entry_gyro;    // ジャイロセンサ回転角リセット中

    ecdr_cnt_t Count;   // 回転角
    int16_t roll_angle; // ロール角

};

#endif // ___CLASS_INI_DEVICE
