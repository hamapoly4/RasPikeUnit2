/******************************************************************************
 *  ファイル名：ColorJudge.h
 *　　　　内容：色判定クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_COLOR_JUDGE
#define ___CLASS_COLOR_JUDGE    // インクルードカード

/* ヘッダインクルード */
#include "common_enum_class.h"  // 色列挙体クラス
#include "Judge.h"              // 判定クラス（インターフェースクラス）
#include "ColorDetect.h"        // 色検出クラス


/* 色判定クラス */
class ColorJudge : public Judge {
public:
    ColorJudge(ColorDetect* colordetector, eColor target_color);   // コンストラクタ

    bool judge();   // 判定する関数

private:
    /* 動的インスタンス */
    ColorDetect* mColorDetector;    // 色検出器

    eColor current_Color;   // 現在の色
    eColor target_Color;    // 目標の色

};

#endif // ___CLASS_COLOR_JUDGE
