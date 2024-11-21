/******************************************************************************
 *  ファイル名：RunDistJudge.h
 *　　　　内容：走行距離判定クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_RUN_DIST_JUDGE
#define ___CLASS_RUN_DIST_JUDGE     // インクルードカード

/* ヘッダインクルード */
#include "Judge.h"              // 判定クラス（インターフェースクラス）
#include "RunDistMeasure.h"     // 走行距離計測クラス


/* 走行距離計測クラス */
class RunDistJudge : public Judge {
public:
    RunDistJudge(RunDistMeasure* odometer, float trgt_dst);  // コンストラクタ

    bool judge();   // 判定する関数

private:
    /* 動的インスタンス */
    RunDistMeasure* mOdometer;  // オドメーター

    float current_dist;     // 現在の走行距離
    float target_dist;      // 目標の走行距離

};

#endif // ___CLASS_RUN_DIST_JUDGE
