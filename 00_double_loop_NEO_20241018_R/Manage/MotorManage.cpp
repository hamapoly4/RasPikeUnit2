/******************************************************************************
 *  ファイル名：MotorManage.cpp
 *　　　　内容：モータ管理クラスの定義
 *  　　作成日：2024/10/19
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "MotorManage.h"    // モータ管理クラス

using namespace ev3api; // 名前空間ev3api

/* 静的インスタンス */
Motor MotorManage::mLeftMotorEncoder(PORT_C);   // 左モータエンコーダ
Motor MotorManage::mRightMotorEncoder(PORT_B);  // 右モータエンコーダ


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
MotorManage::MotorManage()
{
    ;
}

/******************************************************
 *  関数名：getCount
 *    概要：回転角を取得する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void MotorManage::getCount()
{
    Count.left = mLeftMotorEncoder.getCount();
    Count.right = mRightMotorEncoder.getCount();
}

/******************************************************
 *  関数名：readCount
 *    概要：回転角を読み出す
 *  　引数：回転角
 *  返却値：なし
 *  　備考：constメンバ関数
 ******************************************************/
void MotorManage::readCount(ecdr_cnt_t& count) const
{
    count.left = Count.left;
    count.right = Count.right;
}
