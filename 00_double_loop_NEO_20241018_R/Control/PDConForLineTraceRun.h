/******************************************************************************
 *  ファイル名：PDConForLineTraceRun.h
 *　　　　内容：ライントレース走行用PD制御クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_PD_CON_FOR_LINE_TRACE_RUN
#define ___CLASS_PD_CON_FOR_LINE_TRACE_RUN  // インクルードカード

#include "common_struct.h"      // 制御用パラメータ、HSV値構造体
#include "Control.h"            // 制御クラス（抽象クラス）
#include "ColorSensorManage.h"  // カラーセンサ管理クラス


/* ライントレース走行用PD制御クラス */
class PDConForLineTraceRun : public Control {
public:
    PDConForLineTraceRun(const ColorSensorManage* gethsv, const con_param_t& con);  // コンストラクタ

    int getTurn();  // 操作量を取得する関数

private:
    void calcP();    // P演算をする関数
    void calcD();    // D演算をする関数

    /* 動的インスタンス */
    const ColorSensorManage* mGetHSV;    // HSV値取得

    hsv_raw_t Hsv;      // HSV値

};

#endif // ___CLASS_PD_CON_FOR_LINE_TRACE_RUN
