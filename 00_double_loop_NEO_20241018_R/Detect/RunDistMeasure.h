/******************************************************************************
 *  ファイル名：RunDistMeasure.h
 *　　　　内容：走行距離計測クラスの定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_RUN_DIST_MEASURE
#define ___CLASS_RUN_DIST_MEASURE   // インクルードカード

/* ヘッダインクルード */
#include "common_struct.h"  // エンコーダ回転角構造体
#include "MotorManage.h"    // モータ管理クラス


/* 走行距離計測クラス */
class RunDistMeasure {
public:
    RunDistMeasure(const MotorManage* getcount);    // コンストラクタ

    float measureRunDist();     // 走行距離を計測する関数

private:
    void FindRunDist();     // 走行距離を求める関数

    /* 動的インスタンス */
    const MotorManage* mGetCount;   // 回転角取得

    static constexpr float RUNDIST_ECDR_CNT = 0.87266;  // (走行距離/エンコーダ回転角)の値

    ecdr_cnt_t Count;   // 回転角
    float run_dist;     // 走行距離

};

#endif // ___CLASS_RUN_DIST_MEASURE
