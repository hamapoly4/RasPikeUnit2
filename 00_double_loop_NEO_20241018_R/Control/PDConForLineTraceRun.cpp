/******************************************************************************
 *  ファイル名：PDConForLineTraceRun.cpp
 *　　　　内容：ライントレース走行用PD制御クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "PDConForLineTraceRun.h"  // ライントレース走行用PD制御クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：HSV値取得、制御用パラメータ
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
PDConForLineTraceRun::PDConForLineTraceRun(const ColorSensorManage* gethsv, const con_param_t& con)
    : mGetHSV(gethsv), Control(con)
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
int PDConForLineTraceRun::getTurn()
{
    mGetHSV->readHSV(Hsv);
    measured_value = Hsv.v;
    calcP();
    calcD();
    turn = Pvalue + Dvalue;
    return turn;
}

/******************************************************
 *  関数名：calcP
 *    概要：P演算をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void PDConForLineTraceRun::calcP()
{
    diff = measured_value - Con.threathold;
    Pvalue = static_cast<int>(diff * Con.kp);
}

/******************************************************
 *  関数名：calcD
 *    概要：D演算をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void PDConForLineTraceRun::calcD()
{
    Dvalue = static_cast<int>((diff - old_diff) * Con.kd);
    old_diff = diff;
}
