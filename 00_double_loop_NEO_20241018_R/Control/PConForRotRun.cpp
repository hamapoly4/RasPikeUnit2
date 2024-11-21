/******************************************************************************
 *  ファイル名：PConForRotRun.cpp
 *　　　　内容：旋回走行用P制御クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "PConForRotRun.h"  // 旋回走行用P制御クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：ロール角取得、制御用パラメータ
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
PConForRotRun::PConForRotRun(const GyroSensorManage* getrollangle, const con_param_t& con)
    : mGetRollAngle(getrollangle), Control(con)
{
    ;
}

/******************************************************
 *  関数名：getTurn
 *    概要：モータの操作量を取得する
 *  　引数：なし
 *  返却値：操作量
 *  　備考：なし
 ******************************************************/
int PConForRotRun::getTurn()
{
    measured_value = mGetRollAngle->readRollAngle();
    calcP();
    turn = Pvalue;
    return turn;
}

/******************************************************
 *  関数名：calcP
 *    概要：P演算をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void PConForRotRun::calcP()
{
    diff = Con.threathold - measured_value;
    if (Con.threathold < 0)
    {
        diff = -diff;
    }

    Pvalue = static_cast<int>(diff * Con.kp);
}
