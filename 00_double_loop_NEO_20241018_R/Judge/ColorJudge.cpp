/******************************************************************************
 *  ファイル名：ColorJudge.cpp
 *　　　　内容：色判定クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "ColorJudge.h" // 色判定クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：色検出器、目標の色
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
ColorJudge::ColorJudge(ColorDetect* colordetector, eColor target_color)
    : mColorDetector(colordetector), target_Color(target_color)
{
    ;
}

/******************************************************
 *  関数名：Judge
 *    概要：終了条件の判定をする
 *  　引数：なし
 *  返却値：終了条件を満たした：true、満たしてない：false
 *  　備考：なし
 ******************************************************/
bool ColorJudge::judge()
{
    current_Color = mColorDetector->detectColor(target_Color);

    if (current_Color == target_Color)
    {
        return true;
    }
    else
    {
        return false;
    }
}
