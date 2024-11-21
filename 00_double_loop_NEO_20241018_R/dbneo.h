/******************************************************************************
 *  ファイル名：dbneo.h
 *　　　　内容：ダブルループNEO攻略システムの宣言
 *  　　作成日：2024/10/27
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#ifndef ___DB_NEO_H
#define ___DB_NEO_H     // インクルードカード

/* ヘッダインクルード */
#include <stdio.h>

#include "ev3api.h"

#include "common_struct.h"      // 構造体
#include "common_enum_class.h"  // 列挙体

#include "ScenarioTracer.h"
#include "Scenario.h"
#include "IniDevice.h"
#include "Scene.h"

#include "Run.h"
#include "RotRun.h"
#include "StraRun.h"
#include "LineTraceRun.h"

#include "ColorJudge.h"
#include "RotAngleJudge.h"
#include "RunDistJudge.h"

#include "PConForRotRun.h"
#include "PDConForStraRun.h"
#include "PDConForLineTraceRun.h"

#include "ColorDetect.h"
#include "RunDistMeasure.h"

#include "GyroSensorManage.h"
#include "ColorSensorManage.h"
#include "MotorManage.h"
#include "ParameterManage.h"

/* ダブルループNEO名前空間 */
namespace dbneo {

const int8_t SIZE = 20;     // シーン数

/* 旋回走行用P制御の制御用パラメータ */
const con_param_t Con_Param_Rot[7] = {
    {  -1, 0.1, 0 },    // 左旋回　１度
    { -15, 0.1, 0 },    // 左旋回１５度
    {  20, 0.1, 0 },    // 右旋回２０度
    {  15, 0.1, 0 },    // 右旋回１５度
    { -20, 0.1, 0 },    // 左旋回２０度
    { -25, 0.1, 0 },    // 左旋回２５度
    { -10, 0.1, 0 },    // 左旋回１０度
};

/* 直進走行用PD制御の制御用パラメータ */
const con_param_t Con_Param_Stra = { 0, 1.5, 3 };

/* ライントレース走行用PD制御の制御用パラメータ */
const con_param_t Con_Param_LineTrace = { 70, 0.5, 2, };

/* 走行距離 */
const float target_dist[6] = {
    300, 150, 300, 100, 400, 400,
};

/* 管理パッケージに関するポインタ */
extern GyroSensorManage*   gGetRollAngle;   // ロール角取得
extern ColorSensorManage*  gGetHSV;         // HSv値取得
extern MotorManage*        gGetCount;       // 回転角取得
extern ParameterManage*    gGetParam;       // パラメータ取得

/* 検出パッケージに関するポインタ */
extern ColorDetect*    gColorDetector;  // 色検出器
extern RunDistMeasure* gOdometer;       // 走行距離計測器

/* 制御パッケージに関するポインタ */
extern Control* gConForRun[SIZE];       // 各走行に応じた制御

/* 走行パッケージに関するポインタ */
extern Run* gRunForScene[SIZE];         // 各シーンに応じた走行

/* 判定パッケージに関するポインタ */
extern Judge* gJudgeForScene[SIZE];     // 各シーンに応じた判定

/* シナリオトレーサパッケージに関するポインタ */
extern Scene*          gEachAreaScene;              // 各区間に応じたシーン
extern IniDevice*      gInitializer;                // 初期化装置
extern Scenario*       gConqDoubleScenario;         // ダブルループNEO攻略用シナリオ
extern ScenarioTracer* gConDoubleScenarioTracer;    // ダブルループNEO攻略用シナリオトレーサ


/* システムの生成 */
void system_create();

/* システムの破棄 */
void system_destroy();

}

#endif // ___DB_NEO_H
