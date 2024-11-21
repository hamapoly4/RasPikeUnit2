/******************************************************************************
 *  ファイル名：PDConForStraRun.h
 *　　　　内容：直進走行用PD制御クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_PD_CON_FOR_STRA_RUN
#define ___CLASS_PD_CON_FOR_STRA_RUN  // インクルードカード

#include "common_struct.h"      // 制御用パラメータ構造体
#include "Control.h"            // 制御クラス（抽象クラス）
#include "GyroSensorManage.h"   // ジャイロセンサ管理クラス


/* 直進走行用PD制御クラス */
class PDConForStraRun : public Control {
public:
    PDConForStraRun(const GyroSensorManage* getrollangle, const con_param_t& con);  // コンストラクタ

    int getTurn();  // 操作量を取得する関数

private:
    void calcP();    // P演算をする関数
    void calcD();    // D演算をする関数

    /* 動的インスタンス */
    const GyroSensorManage* mGetRollAngle;    // ロール角取得

    int16_t roll_angle; // ロール角

};

#endif // ___CLASS_PD_CON_FOR_STRA_RUN
