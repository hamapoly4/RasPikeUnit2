/******************************************************************************
 *  ファイル名：IniDevice.cpp
 *　　　　内容：デバイス初期化クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "IniDevice.h"  // デバイス初期化クラス

using namespace ev3api; // 名前空間ev3api

/* 静的インスタンス */
GyroSensor  IniDevice::mResetRollAngle(PORT_4);             // リセットロール角
Motor       IniDevice::mStopForLeftMotor(PORT_C);           // 停止用左モータ
Motor       IniDevice::mStopForRightMotor(PORT_B);          // 停止用右モータ
Motor       IniDevice::mResetForLeftMotorEncoder(PORT_C);   // リセット用左モータエンコーダ
Motor       IniDevice::mResetForRightMotorEncoder(PORT_B);  // リセット用右モータエンコーダ


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
IniDevice::IniDevice()
    : state(START), entry_motor(true), entry_gyro(true)
{
    ;
}

/******************************************************
 *  関数名：init
 *    概要：デバイスを初期化する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void IniDevice::init()
{
    if (state == START)
    {
        prepare();
    }

    if (state == MOTOR_ENCODER_RESET)
    {
        resetMotorEncoder();
    }

    if (state == GYRO_RESET)
    {
        resetGyro();
    }
}

/******************************************************
 *  関数名：prepare
 *    概要：デバイス初期化の準備をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void IniDevice::prepare()
{
    entry_motor = true;
    entry_gyro = true;
    transState(MOTOR_ENCODER_RESET);
}

/******************************************************
 *  関数名：resetMotorEncoder
 *    概要：モータエンコーダ回転角をリセットする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void IniDevice::resetMotorEncoder()
{
    /* ---------------入場動作--------------- */

    if (entry_motor == true)
    {
        entry_motor = false;
        mStopForLeftMotor.stop();
        mStopForRightMotor.stop();

        return;
    }

    /* --------------------実行活動-------------------- */

    Count.left = mResetForLeftMotorEncoder.getCount();
    Count.right = mResetForRightMotorEncoder.getCount();

    if (Count.left == 0 && Count.right == 0)
    {
        transState(GYRO_RESET);
    }
    else
    {
        mResetForLeftMotorEncoder.reset();
        mResetForRightMotorEncoder.reset();
    }
}

/******************************************************
 *  関数名：resetGyro
 *    概要：ジャイロセンサ回転角をリセットする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void IniDevice::resetGyro()
{
    /* ---------------入場動作--------------- */

    if (entry_gyro == true)
    {
        entry_gyro = false;
        mResetRollAngle.reset();
    }

    /* --------------------実行活動-------------------- */

    roll_angle = mResetRollAngle.getAngle();
    if (roll_angle == 0)
    {
        transState(FINISH);
    }
}

/******************************************************
 *  関数名：transState
 *    概要：状態を遷移する
 *  　引数：状態
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void IniDevice::transState(eState s)
{
    state = s;
}

/******************************************************
 *  関数名：checkState
 *    概要：状態を確認する
 *  　引数：なし
 *  返却値：状態
 *  　備考：なし
 ******************************************************/
IniDevice::eState IniDevice::checkState()
{
    switch (state)
    {
        case FINISH:
            transState(START);
            return FINISH;
        default:
            return state;
    }
}
