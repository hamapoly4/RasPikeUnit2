/******************************************************************************
 *  ファイル名：ColorSensorManage.h
 *　　　　内容：カラーセンサ管理クラスの定義
 *  　　作成日：2024/10/19
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_COLOR_SENSOR_MANAGE
#define ___CLASS_COLOR_SENSOR_MANAGE // インクルードカード

/* ヘッダインクルード */
#include "common_struct.h"  // HSV値構造体
#include "ColorSensor.h"    // カラーセンサ


/* カラーセンサ管理クラス */
class ColorSensorManage {
public:
    ColorSensorManage();                // コンストラクタ
    void getHSV();                      // HSV値を取得する関数
    void readHSV(hsv_raw_t& hsv) const; // HSV値を読み出す関数

private:
    void FindMax(); // 最大値を求める関数
    void FindMin(); // 最小値を求める関数
    void FindH();   // Hを求める関数
    void FindS();   // Sを求める関数
    void FindV();   // Vを求める関数

    /* 静的インスタンス */
    static ev3api::ColorSensor mGetRGB;  // RGB値取得

    rgb_raw_t Rgb;  // RGB値
    hsv_raw_t Hsv;  // HSV値
    float max;      // 最大値
    float min;      // 最小値

};

#endif // ___CLASS_COLOR_SENSOR_MANAGE
