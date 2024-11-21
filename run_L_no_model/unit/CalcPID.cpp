/******************************************************************************
 *  ファイル名：CalcPID.cpp
 *　　　　内容：CalcPIDクラスの実施
 *  　　作成日：2024/8/3
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "CalcPID.h"
#include <stdio.h>

using namespace ev3api;

/* 静的const付きメンバ定数の定義 */
const float CalcPID::KP = 0.1;  // Pゲイン
const float CalcPID::KI = 0.005;  // Iゲイン
const float CalcPID::KD = 3;     // Dゲイン
const int CalcPID::TARGET = 69;  // 目標値

/*-------------------------------------------------------
*                  コンストラクタ定義
---------------------------------------------------------*/
CalcPID::CalcPID(const ColorSensor& colorsensor)
    : mColorSensor(colorsensor), old_diff(0), sum(0), i(0)
{
    ;
}

/*-------------------------------------------------------
*                   メンバ関数定義
---------------------------------------------------------*/
int CalcPID::calcP()    // P演算
{
    diff = mColorSensor.getBrightness() - TARGET;
    p_value = KP * diff;
    
    printf("p_value : %d\n", p_value);
    return p_value;
}

int CalcPID::calcI()    // I演算
{
    i++;
    sum += diff;

    i_value = sum * KI;
    
    if (i >= 20)
    {
        i = 0;
        sum = 0;
    }
    
    printf("i_value : %d\n", i_value);
    return i_value;
}

int CalcPID::calcD()    // D演算
{
    d_value = (diff - old_diff) * KD;
    old_diff = diff;
    printf("old_diff : %d\n", old_diff);

    printf("d_value : %d\n", d_value);
    return d_value;
}

int CalcPID::calcPID()   // PID制御から制御値を求める
{
    turn = calcP() + calcI() + calcD();
    
    printf("turn : %d\n\n", turn);
    return turn;
}
