/******************************************************************************
 *  ファイル名：Run.h
 *　　　　内容：走行クラス（抽象クラス）の定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_RUN
#define ___CLASS_RUN    // インクルードカード

/* ヘッダインクルード */
#include "common_enum_class.h"  // 走行速度列挙体クラス
#include "Control.h"            // 制御クラス（抽象クラス）
#include "Motor.h"              // モータ


/* 走行クラス（抽象クラス） */
class Run {
public:
    /* 純粋仮想関数 */
    virtual void run() = 0;  // 走行する関数

protected:
    Run(Control* conforrun, eSpeed speed);  // コンストラクタ

    /* 静的インスタンス */
    static ev3api::Motor mLeftMotorForRun;  // 走行用左モータ
    static ev3api::Motor mRightMotorForRun; // 走行用右モータ

    /* 動的インスタンス */
    Control* mConForRun;    // 各走行に応じた制御

    int pwm;    // PWM値
    int turn;   // 操作量

};

#endif // ___CLASS_RUN
