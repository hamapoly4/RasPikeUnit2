/******************************************************************************
 *  ファイル名：GyroSensorManage.h
 *　　　　内容：ジャイロセンサ管理クラスの定義
 *  　　作成日：2024/10/19
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_GYRO_SENSOR_MANAGE
#define ___CLASS_GYRO_SENSOR_MANAGE // インクルードカード

/* ヘッダインクルード */
#include "ev3api.h"         // ev3api
#include "GyroSensor.h"     // ジャイロセンサ


/* ジャイロセンサ管理クラス */
class GyroSensorManage {
public:
    GyroSensorManage();                 // コンストラクタ
    void getRollAngle();                // ロール角を取得する関数
    int16_t readRollAngle() const;      // ロール角を読み出す関数

private:
    /* 静的インスタンス */
    static ev3api::GyroSensor mGetRollAngle; // ロール角取得

    int16_t roll_angle;  // ロール角

};

#endif // ___CLASS_GYRO_SENSOR_MANAGE
