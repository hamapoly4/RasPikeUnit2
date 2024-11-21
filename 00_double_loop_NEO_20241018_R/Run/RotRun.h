/******************************************************************************
 *  ファイル名：RotRun.h
 *　　　　内容：旋回走行クラスの定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_ROT_RUN
#define ___CLASS_ROT_RUN    // インクルードカード

/* ヘッダインクルード */
#include "common_enum_class.h"  // 走行速度・旋回方向列挙体クラス
#include "Run.h"                // 走行クラス（抽象クラス）
#include "Control.h"            // 制御クラス（抽象クラス）


/* 旋回走行クラス */
class RotRun : public Run {
public:
    RotRun(eDire dire, Control* conforrun, eSpeed speed = eSpeed::MID); // コンストラクタ

    void run(); // 走行する関数

private:
    eDire Dire; // 旋回方向

};

#endif // ___CLASS_ROT_RUN
