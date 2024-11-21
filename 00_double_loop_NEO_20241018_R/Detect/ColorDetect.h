/******************************************************************************
 *  ファイル名：ColorDetect.h
 *　　　　内容：色検出クラスの定義
 *  　　作成日：2024/10/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_COLOR_DETECT
#define ___CLASS_COLOR_DETECT   // インクルードカード

#include "common_enum_class.h"  // 色列挙体クラス
#include "common_struct.h"      // HSV値構造体
#include "ColorSensorManage.h"  // カラーセンサ管理クラス


/* 色検出クラス */
class ColorDetect {
public:
    ColorDetect(const ColorSensorManage* gethsv);   // コンストラクタ

    eColor detectColor(eColor color); // 色を検出する関数

private:
    void detectBlack();     // 黒色を検出する関数
    void detectBlue();      // 青色を検出する関数

    /* 動的インスタンス */
    const ColorSensorManage* mGetHSV; // HSV値取得

    hsv_raw_t Hsv;  // HSV値
    eColor Color;   // 色

};

#endif // ___CLASS_COLOR_DETECT
