/******************************************************************************
 *  ファイル名：PConForRotRun.h
 *　　　　内容：旋回走行用P制御クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_P_CON_FOR_ROT_RUN
#define ___CLASS_P_CON_FOR_ROT_RUN  // インクルードカード

/* ヘッダインクルード */
#include "common_struct.h"      // 制御用パラメータ構造体
#include "Control.h"            // 制御クラス（抽象クラス）
#include "GyroSensorManage.h"   // ジャイロセンサ管理クラス


/* 旋回走行用P制御クラス */
class PConForRotRun : public Control {
public:
    PConForRotRun(const GyroSensorManage* getrollangle, const con_param_t& con);    // コンストラクタ

    int getTurn();  // 操作量を取得する関数

private:
    void calcP();    // P演算をする関数

    /* 動的インスタンス */
    const GyroSensorManage* mGetRollAngle;    // ロール角取得

    int16_t roll_angle; // ロール角

};

#endif // ___CLASS_P_CON_FOR_ROT_RUN
