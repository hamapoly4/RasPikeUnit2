/******************************************************************************
 *  ファイル名：RotRun.cpp
 *　　　　内容：旋回走行クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "RotRun.h" // 旋回走行クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：旋回走行用P制御、旋回方向、走行速度
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
RotRun::RotRun(eDire dire, Control* conforrun, eSpeed speed)
    : Dire(dire), Run(conforrun, speed)
{
    ;
}

/******************************************************
 *  関数名：run
 *    概要：旋回走行をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void RotRun::run()
{
    turn = mConForRun->getTurn();

    switch (Dire)
    {
        case eDire::LEFT:
            mLeftMotorForRun.setPWM(-(pwm + turn));
            mRightMotorForRun.setPWM(+(pwm + turn));
            break;
        case eDire::RIGHT:
            mLeftMotorForRun.setPWM(+(pwm + turn));
            mRightMotorForRun.setPWM(-(pwm + turn));
            break;
        default:
            break;
    }
}
