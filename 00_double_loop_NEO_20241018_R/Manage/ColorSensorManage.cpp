/******************************************************************************
 *  ファイル名：ColorSensorManage.h
 *　　　　内容：カラーセンサ管理クラスの定義
 *  　　作成日：2024/10/19
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "ColorSensorManage.h"  // カラーセンサ管理クラス

using namespace ev3api; // 名前空間ev3api

/* 静的インスタンス */
ColorSensor ColorSensorManage::mGetRGB(PORT_2);	// RGB値取得 


/******************************************************
 *  関数名：コンストラクタ
 *    概要：インスタンス生成時の処理をする
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
ColorSensorManage::ColorSensorManage()
{
    ;
}

/******************************************************
 *  関数名：getHSV
 *    概要：HSV値を取得する
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorSensorManage::getHSV()
{
    mGetRGB.getRawColor(Rgb);
    FindMax();
    FindMin();
    FindH();
    FindS();
    FindV();
}

/******************************************************
 *  関数名：readHSV
 *    概要：HSV値を読み出す
 *  　引数：HSV値
 *  返却値：なし
 *  　備考：constメンバ関数
 ******************************************************/
void ColorSensorManage::readHSV(hsv_raw_t& hsv) const
{
    hsv.h = Hsv.h;
    hsv.s = Hsv.s;
    hsv.v = Hsv.v;
}

/******************************************************
 *  関数名：FindMax
 *    概要：RGB値の最大値を求める
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorSensorManage::FindMax()
{
    max = Rgb.r;
	if (max < Rgb.g)
	{
		max = Rgb.g;
	}
	
	if (max < Rgb.b)
	{
		max = Rgb.b;
	}
}

/******************************************************
 *  関数名：FindMin
 *    概要：RGB値の最小値を求める
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorSensorManage::FindMin()
{
    min = Rgb.r;
	if (min > Rgb.g)
	{
		min = Rgb.g;
	}
	
	if (min > Rgb.b)
	{
		min = Rgb.b;
	}
}

/******************************************************
 *  関数名：FindH
 *    概要：H(色相)を求める
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorSensorManage::FindH()
{
    if (max == Rgb.r)
	{
		Hsv.h = 60 * ((Rgb.g - Rgb.b) / (max - min));
	}
	else if (max == Rgb.g)
	{
		Hsv.h = 60 * ((Rgb.b - Rgb.r) / (max - min)) + 120;
	}
	else if (max == Rgb.b)
	{
		Hsv.h = 60 * ((Rgb.r - Rgb.g) / (max - min)) + 240;
	}
	else if (Rgb.r == Rgb.g && Rgb.g == Rgb.b)
	{
		Hsv.h = 0;
	}
	
	if (Hsv.h < 0)
	{
		Hsv.h += 360;
	}
}

/******************************************************
 *  関数名：FindS
 *    概要：S(彩度)を求める
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorSensorManage::FindS()
{
    float f;
	f = static_cast<float>((max - min) / max);
	Hsv.s = static_cast<int>(f * 100);
}

/******************************************************
 *  関数名：FindV
 *    概要：V(明度)を求める
 *  　引数：なし
 *  返却値：なし
 *  　備考：なし
 ******************************************************/
void ColorSensorManage::FindV()
{
    float f;
	f = static_cast<float>(max / 255);
	Hsv.v = static_cast<int>(f * 100);
}
