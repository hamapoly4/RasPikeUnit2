/******************************************************************************
 *  ファイル名：Run.cpp
 *　　　　内容：走行クラス（抽象クラス）の定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "Run.h"    // 走行クラス（抽象クラス）

using namespace ev3api;     // 名前空間ev3api

/* 静的インスタンス */
Motor Run::mLeftMotorForRun(PORT_C);    // 走行用左モータ
Motor Run::mRightMotorForRun(PORT_B);   // 走行用右モータ


/******************************************************
 *  関数名：コンストラクタ
 *    概要：走行速度を決定する
 *  　引数：走行速度
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
Run::Run(Control* conforrun, eSpeed speed)
    : mConForRun(conforrun)
{
    switch (speed)
    {
        case eSpeed::LOW:
            pwm = 35;
            break;
        case eSpeed::MID:
            pwm = 45;
            break;
        case eSpeed::HIGH:
            pwm = 70;
            break;
        default:
            break;
    }
}
