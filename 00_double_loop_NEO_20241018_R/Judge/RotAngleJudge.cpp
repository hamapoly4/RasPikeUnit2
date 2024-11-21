/******************************************************************************
 *  ファイル名：RotAngleJudge.cpp
 *　　　　内容：旋回角度判定クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "RotAngleJudge.h"   // 旋回角度判定クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：ロール角取得、旋回方向、目標の旋回角度
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
RotAngleJudge::RotAngleJudge(const GyroSensorManage* getrollangle, eDire dire, int16_t trgt_agle)
    : mGetRollAngle(getrollangle), Dire(dire), target_angle(trgt_agle)
{
    ;
}

/******************************************************
 *  関数名：Judge
 *    概要：終了条件の判定をする
 *  　引数：なし
 *  返却値：終了条件を満たした：true、満たしてない：false
 *  　備考：なし
 ******************************************************/
bool RotAngleJudge::judge()
{
    current_angle = mGetRollAngle->readRollAngle();

    if (Dire == eDire::LEFT)
    {
        if (current_angle <= target_angle)
        {
            return true;
        }
    }
    else if (Dire == eDire::RIGHT)
    {
        if (current_angle >= target_angle)
        {
            return true;
        }
    }

    return false;
}
