/******************************************************************************
 *  ファイル名：ParameterManage.h
 *　　　　内容：パラメータ管理クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_PARAMETER_MANAGE
#define ___CLASS_PARAMETER_MANAGE   // インクルードカード

/* ヘッダインクルード */
#include "GyroSensorManage.h"   // ジャイロセンサ管理クラス
#include "ColorSensorManage.h"  // カラーセンサ管理クラス
#include "MotorManage.h"        // モータ管理クラス


/* パラメータ管理クラス */
class ParameterManage {
public:
    ParameterManage(GyroSensorManage* getrollangle, ColorSensorManage* gethsv, MotorManage* getcount);  // コンストラクタ

    void getParameter();    // パラメータを取得する関数

private:
    /* 動的インスタンス */
    GyroSensorManage*   mGetRollAngle;  // ロール角取得
    ColorSensorManage*  mGetHSV;        // HSV値取得
    MotorManage*        mGetCount;      // 回転角取得

};

#endif // ___CLASS_PARAMETER_MANAGE
