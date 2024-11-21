/******************************************************************************
 *  ファイル名：StraRun.h
 *　　　　内容：直進走行クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_STRA_RUN
#define ___CLASS_STRA_RUN   // インクルードカード

/* ヘッダインクルード */
#include "common_enum_class.h"  // 走行速度列挙体クラス
#include "Run.h"                // 走行クラス（抽象クラス）
#include "Control.h"            // 制御クラス（抽象クラス）


/* 直進走行クラス */
class StraRun : public Run {
public:
    StraRun(Control* conforrun, eSpeed speed);   // コンストラクタ

    void run(); // 走行する関数

};

#endif // ___cLASS_STRA_RUN
