/******************************************************************************
 *  ファイル名：RotAngleJudge.h
 *　　　　内容：旋回角度判定クラスの定義
 *  　　作成日：2024/10/22
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_ROT_ANGLE_JUDGE_CLASS
#define ___CLASS_ROT_ANGLE_JUDGE_CLASS  // インクルードカード

/* ヘッダインクルード */
#include "ev3api.h"             // ev3api
#include "common_enum_class.h"  // 旋回方向列挙体クラス
#include "Judge.h"              // 判定クラス（インターフェースクラス）
#include "GyroSensorManage.h"   // ジャイロセンサ管理クラス


/* 旋回角度判定クラス */
class RotAngleJudge : public Judge {
public:
    RotAngleJudge(const GyroSensorManage* getrollangle, eDire dire, int16_t trgt_agle);  // コンストラクタ

    bool judge();   // 判定する関数

private:
    /* 動的インスタンス */
    const GyroSensorManage* mGetRollAngle;  // ロール角取得

    eDire Dire;     // 旋回方向

    int16_t current_angle;  // 現在の旋回角度
    int16_t target_angle;   //目標の旋回角度

};

#endif // ___CLASS_ROT_ANGLE_JUDGE_CLASS
