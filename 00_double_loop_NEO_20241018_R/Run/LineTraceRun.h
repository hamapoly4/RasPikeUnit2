/******************************************************************************
 *  ファイル名：LineTraceRun.h
 *　　　　内容：ライントレース走行クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_LINE_TRACE_RUN
#define ___CLASS_LINE_TRACE_RUN     // インクルードカード

/* ヘッダインクルード */
#include "common_enum_class.h"  // 走行速度・エッジ列挙体クラス
#include "Run.h"                // 走行クラス（抽象クラス）
#include "Control.h"            // 制御クラス（抽象クラス）


/* ライントレース走行クラス */
class LineTraceRun : public Run {
public:
    LineTraceRun(eEdge edge, Control* conforrun, eSpeed speed); // コンストラクタ

    void run(); // 走行する関数

private:
    eEdge Edge; // エッジ

};

#endif // ___CLASS_LINE_TRACE_RUN
