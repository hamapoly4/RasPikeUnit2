/******************************************************************************
 *  ファイル名：Control.h
 *　　　　内容：制御クラス（抽象クラス）の定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_CONTROL
#define ___CLASS_CONTROL // インクルードカード

/* ヘッダインクルード */
#include "common_struct.h"  // 制御用パラメータ構造体


/* 制御クラス（抽象クラス） */
class Control {
public:
    /* 純粋仮想関数 */
    virtual int getTurn() = 0;  // 操作量を取得する関数

protected:
    Control(const con_param_t& con);    // コンストラクタ

    const con_param_t& Con; // 制御用パラメータ

    int measured_value; // 観測値
    int diff;           // 偏差
    int old_diff;       // 過去の偏差
    int Pvalue;         // P制御値
    int Dvalue;         // D制御値
    int turn;           // 操作量

};

#endif // ___CLASS_CONTROL
