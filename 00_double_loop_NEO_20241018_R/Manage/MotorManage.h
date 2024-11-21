/******************************************************************************
 *  ファイル名：MotorManage.h
 *　　　　内容：モータ管理クラスの定義
 *  　　作成日：2024/10/19
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___CLASS_MOTOR_MANAGE
#define ___CLASS_MOTOR_MANAGE // インクルードカード

/* ヘッダインクルード */
#include "ev3api.h"         // ev3api
#include "common_struct.h"  // エンコーダ回転角構造体
#include "Motor.h"          // モータ


/* モータ管理クラス */
class MotorManage {
public:
    MotorManage();      // コンストラクタ
    void getCount();    // 回転角を取得する関数

    void readCount(ecdr_cnt_t& count) const;   // 回転角を読み出す関数

private:
    /* 静的インスタンス */
    static ev3api::Motor mLeftMotorEncoder;  // 左モータエンコーダ
    static ev3api::Motor mRightMotorEncoder; // 右モータエンコーダ

    ecdr_cnt_t Count;   // 回転角

};

#endif // ___CLASS_MOTOR_MANAGE
