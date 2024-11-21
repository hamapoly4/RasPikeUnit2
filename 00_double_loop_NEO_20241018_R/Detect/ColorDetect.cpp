/******************************************************************************
 *  ファイル名：ColorDetect.cpp
 *　　　　内容：色検出クラスの定義
 *  　　作成日：2024/10/21
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "ColorDetect.h"    // 色検出クラス


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：HSV値取得
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
ColorDetect::ColorDetect(const ColorSensorManage* gethsv)
    : mGetHSV(gethsv)
{
    ;
}

/******************************************************
 *  関数名：detectColor
 *    概要：色を検出する
 *  　引数：検出目的の色
 *  返却値：検出した色
 *  　備考：なし
 ******************************************************/
eColor ColorDetect::detectColor(eColor color)
{
    mGetHSV->readHSV(Hsv);

    switch (color)
    {
        case eColor::BLACK:
            detectBlack();
            break;
        case eColor::BLUE:
            detectBlue();
            break;
        default:
            break;
    }

    return Color;
}

/******************************************************
 *  関数名：detectBlack
 *    概要：黒色を検出する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorDetect::detectBlack()
{
    Color = eColor::ELSE;

    if (180 <= Hsv.h && Hsv.h <= 250)
    {
        if (Hsv.v <= 20)
        {
            Color = eColor::BLACK;
        }
    }
}

/******************************************************
 *  関数名：detectBlue
 *    概要：青色を検出する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorDetect::detectBlue()
{
    Color = eColor::ELSE;

    if (208 <= Hsv.h && Hsv.h <= 213)
    {
        if (33 <= Hsv.s && Hsv.s <= 83)
        {
            Color = eColor::BLUE;
        }
    }
}
