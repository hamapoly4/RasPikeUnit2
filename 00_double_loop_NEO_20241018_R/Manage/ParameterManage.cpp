/******************************************************************************
 *  ファイル名：ParameterManage.cpp
 *　　　　内容：パラメータ管理クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "ParameterManage.h"    // パラメータ管理クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：ロール角取得、HSV値取得、回転角取得
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
ParameterManage::ParameterManage(GyroSensorManage* getrollangle, ColorSensorManage* gethsv, MotorManage* getcount)
    : mGetRollAngle(getrollangle), mGetHSV(gethsv), mGetCount(getcount)
{
    ;
}

/******************************************************
 *  関数名：getParameter
 *    概要：パラメータを取得する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ParameterManage::getParameter()
{
    mGetRollAngle->getRollAngle();
    mGetHSV->getHSV();
    mGetCount->getCount();
}
