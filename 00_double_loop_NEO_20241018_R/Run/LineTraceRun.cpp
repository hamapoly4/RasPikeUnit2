/******************************************************************************
 *  ファイル名：LineTraceRun.cpp
 *　　　　内容：ライントレース走行クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "LineTraceRun.h"


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：ライントレース走行用PD制御、エッジ、走行速度
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
LineTraceRun::LineTraceRun(eEdge edge, Control* conforrun, eSpeed speed)
    : Edge(edge), Run(conforrun, speed)
{
    ;
}

/******************************************************
 *  関数名：run
 *    概要：ライントレース走行をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void LineTraceRun::run()
{
    turn = mConForRun->getTurn();

    switch (Edge)
    {
        case eEdge::LEFT:
            mLeftMotorForRun.setPWM(pwm + turn);
            mRightMotorForRun.setPWM(pwm - turn);
            break;
        case eEdge::RIGHT:
            mLeftMotorForRun.setPWM(pwm - turn);
            mRightMotorForRun.setPWM(pwm + turn);
            break;
        default:
            break;
    }
}
