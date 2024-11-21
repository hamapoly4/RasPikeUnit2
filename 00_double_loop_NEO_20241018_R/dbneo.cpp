/******************************************************************************
 *  ファイル名：dbneo.cpp
 *　　　　内容：ダブルループNEO攻略システムの定義
 *  　　作成日：2024/10/27
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include "dbneo.h"

/* ダブルループNEO名前空間 */
namespace dbneo {

/* 管理パッケージに関するポインタ */
GyroSensorManage*   gGetRollAngle = nullptr;    // ロール角取得
ColorSensorManage*  gGetHSV = nullptr;          // HSv値取得
MotorManage*        gGetCount = nullptr;        // 回転角取得
ParameterManage*    gGetParam = nullptr;        // パラメータ取得

/* 検出パッケージに関するポインタ */
ColorDetect*    gColorDetector = nullptr;   // 色検出器
RunDistMeasure* gOdometer = nullptr;        // 走行距離計測器

/* 制御パッケージに関するポインタ */
Control* gConForRun[SIZE] = { nullptr };        // 各走行に応じた制御

/* 走行パッケージに関するポインタ */
Run* gRunForScene[SIZE] = { nullptr };          // 各シーンに応じた走行

/* 判定パッケージに関するポインタ */
Judge* gJudgeForScene[SIZE] = { nullptr };      // 各シーンに応じた判定

/* シナリオトレーサパッケージに関するポインタ */
Scene*          gEachAreaScene = nullptr;           // 各区間に応じたシーン
IniDevice*      gInitializer = nullptr;             // 初期化装置
Scenario*       gConqDoubleScenario = nullptr;      // ダブルループNEO攻略用シナリオ
ScenarioTracer* gConDoubleScenarioTracer = nullptr; // ダブルループNEO攻略用シナリオトレーサ


/* システムの生成 */
void system_create()
{
    /* 管理パッケージに関するインスタンス */
    gGetRollAngle = new GyroSensorManage();
    gGetHSV = new ColorSensorManage();
    gGetCount = new MotorManage();
    gGetParam = new ParameterManage(gGetRollAngle, gGetHSV, gGetCount);

    /* 検出パッケージに関するインスタンス */
    gColorDetector = new ColorDetect(gGetHSV);
    gOdometer = new RunDistMeasure(gGetCount);

    /* -------------------------------------------------------------
     * 概要　　：シーン１
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[0] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[0]);
    gRunForScene[0] = new RotRun(eDire::LEFT, gConForRun[0]);
    gJudgeForScene[0] = new RotAngleJudge(gGetRollAngle, eDire::LEFT, Con_Param_Rot[0].threathold);

    /* -------------------------------------------------------------
     * 概要　　：シーン２
     * 走行方法：直進走行
     * 判定方法：走行距離判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[1] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[1] = new StraRun(gConForRun[1], eSpeed::HIGH);
    gJudgeForScene[1] = new RunDistJudge(gOdometer, target_dist[0]);

    /* -------------------------------------------------------------
     * 概要　　：シーン３
     * 走行方法：直進走行
     * 判定方法：色判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[2] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[2] = new StraRun(gConForRun[2], eSpeed::LOW);
    gJudgeForScene[2] = new ColorJudge(gColorDetector, eColor::BLACK);

    /* -------------------------------------------------------------
     * 概要　　：シーン４
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[3] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[1]);
    gRunForScene[3] = new RotRun(eDire::LEFT, gConForRun[3]);
    gJudgeForScene[3] = new RotAngleJudge(gGetRollAngle, eDire::LEFT, Con_Param_Rot[1].threathold);

    /* -------------------------------------------------------------
     * 概要　　：シーン５
     * 走行方法：ライントレース走行
     * 判定方法：走行距離判定
     * 制御方法：ラインに沿って走行するための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[4] = new PDConForLineTraceRun(gGetHSV, Con_Param_LineTrace);
    gRunForScene[4] = new LineTraceRun(eEdge::LEFT, gConForRun[4], eSpeed::LOW);
    gJudgeForScene[4] = new RunDistJudge(gOdometer, target_dist[1]);

    /* -------------------------------------------------------------
     * 概要　　：シーン６
     * 走行方法：ライントレース走行
     * 判定方法：色判定
     * 制御方法：ラインに沿って走行するための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[5] = new PDConForLineTraceRun(gGetHSV, Con_Param_LineTrace);
    gRunForScene[5] = new LineTraceRun(eEdge::LEFT, gConForRun[5], eSpeed::MID);
    gJudgeForScene[5] = new ColorJudge(gColorDetector, eColor::BLUE);

    /* -------------------------------------------------------------
     * 概要　　：シーン７
     * 走行方法：直進走行
     * 判定方法：走行距離判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[6] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[6] = new StraRun(gConForRun[6], eSpeed::HIGH);
    gJudgeForScene[6] = new RunDistJudge(gOdometer, target_dist[2]);

    /* -------------------------------------------------------------
     * 概要　　：シーン８
     * 走行方法：直進走行
     * 判定方法：色判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[7] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[7] = new StraRun(gConForRun[7], eSpeed::LOW);
    gJudgeForScene[7] = new ColorJudge(gColorDetector, eColor::BLACK);

    /* -------------------------------------------------------------
     * 概要　　：シーン９
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[8] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[2]);
    gRunForScene[8] = new RotRun(eDire::RIGHT, gConForRun[8]);
    gJudgeForScene[8] = new RotAngleJudge(gGetRollAngle, eDire::RIGHT, Con_Param_Rot[2].threathold);

    /* -------------------------------------------------------------
     * 概要　　：シーン１０
     * 走行方法：ライントレース走行
     * 判定方法：走行距離判定
     * 制御方法：ラインに沿って走行するための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[9] = new PDConForLineTraceRun(gGetHSV, Con_Param_LineTrace);
    gRunForScene[9] = new LineTraceRun(eEdge::RIGHT, gConForRun[9], eSpeed::LOW);
    gJudgeForScene[9] = new RunDistJudge(gOdometer, target_dist[3]);

    /* -------------------------------------------------------------
     * 概要　　：シーン１１
     * 走行方法：ライントレース走行
     * 判定方法：色判定
     * 制御方法：ラインに沿って走行するための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[10] = new PDConForLineTraceRun(gGetHSV, Con_Param_LineTrace);
    gRunForScene[10] = new LineTraceRun(eEdge::RIGHT, gConForRun[10], eSpeed::MID);
    gJudgeForScene[10] = new ColorJudge(gColorDetector, eColor::BLUE);

    /* -------------------------------------------------------------
     * 概要　　：シーン１２
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[11] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[3]);
    gRunForScene[11] = new RotRun(eDire::RIGHT, gConForRun[11]);
    gJudgeForScene[11] = new RotAngleJudge(gGetRollAngle, eDire::RIGHT, Con_Param_Rot[3].threathold);

    /* -------------------------------------------------------------
     * 概要　　：シーン１３
     * 走行方法：直進走行
     * 判定方法：走行距離判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[12] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[12] = new StraRun(gConForRun[12], eSpeed::HIGH);
    gJudgeForScene[12] = new RunDistJudge(gOdometer, target_dist[4]);

    /* -------------------------------------------------------------
     * 概要　　：シーン１４
     * 走行方法：直進走行
     * 判定方法：色判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[13] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[13] = new StraRun(gConForRun[13], eSpeed::LOW);
    gJudgeForScene[13] = new ColorJudge(gColorDetector, eColor::BLACK);

    /* -------------------------------------------------------------
     * 概要　　：シーン１５
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[14] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[4]);
    gRunForScene[14] = new RotRun(eDire::LEFT, gConForRun[14]);
    gJudgeForScene[14] = new RotAngleJudge(gGetRollAngle, eDire::LEFT, Con_Param_Rot[4].threathold);

    /* -------------------------------------------------------------
     * 概要　　：シーン１６
     * 走行方法：ライントレース走行
     * 判定方法：色判定
     * 制御方法：ラインに沿って走行するための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[15] = new PDConForLineTraceRun(gGetHSV, Con_Param_LineTrace);
    gRunForScene[15] = new LineTraceRun(eEdge::LEFT, gConForRun[15], eSpeed::LOW);
    gJudgeForScene[15] = new ColorJudge(gColorDetector, eColor::BLUE);

    /* -------------------------------------------------------------
     * 概要　　：シーン１７
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[16] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[5]);
    gRunForScene[16] = new RotRun(eDire::LEFT, gConForRun[16]);
    gJudgeForScene[16] = new RotAngleJudge(gGetRollAngle, eDire::LEFT, Con_Param_Rot[5].threathold);

    /* -------------------------------------------------------------
     * 概要　　：シーン１８
     * 走行方法：直進走行
     * 判定方法：走行距離判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[17] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[17] = new StraRun(gConForRun[17], eSpeed::HIGH);
    gJudgeForScene[17] = new RunDistJudge(gOdometer, target_dist[5]);

    /* -------------------------------------------------------------
     * 概要　　：シーン１９
     * 走行方法：直進走行
     * 判定方法：色判定
     * 制御方法：まっすぐ走るための制御(PD)
     * ------------------------------------------------------------*/
    gConForRun[18] = new PDConForStraRun(gGetRollAngle, Con_Param_Stra);
    gRunForScene[18] = new StraRun(gConForRun[18], eSpeed::LOW);
    gJudgeForScene[18] = new ColorJudge(gColorDetector, eColor::BLACK);

    /* -------------------------------------------------------------
     * 概要　　：シーン２０
     * 制御方法：旋回角度に近づくたび減速する制御(P)
     * 走行方法：旋回走行
     * 判定方法：旋回角度判定
     * ------------------------------------------------------------*/
    gConForRun[19] = new PConForRotRun(gGetRollAngle, Con_Param_Rot[6]);
    gRunForScene[19] = new RotRun(eDire::LEFT, gConForRun[19]);
    gJudgeForScene[19] = new RotAngleJudge(gGetRollAngle, eDire::LEFT, Con_Param_Rot[6].threathold);

    /* シナリオトレーサパッケージに関するインスタンス */
    gEachAreaScene = new Scene[SIZE] {
        { gRunForScene[0],  gJudgeForScene[0] },    // シーン１
        { gRunForScene[1],  gJudgeForScene[1] },    // シーン２
        { gRunForScene[2],  gJudgeForScene[2] },    // シーン３
        { gRunForScene[3],  gJudgeForScene[3] },    // シーン４
        { gRunForScene[4],  gJudgeForScene[4] },    // シーン５
        { gRunForScene[5],  gJudgeForScene[5] },    // シーン６
        { gRunForScene[6],  gJudgeForScene[6] },    // シーン７
        { gRunForScene[7],  gJudgeForScene[7] },    // シーン８
        { gRunForScene[8],  gJudgeForScene[8] },    // シーン９
        { gRunForScene[9],  gJudgeForScene[9] },    // シーン１０
        { gRunForScene[10], gJudgeForScene[10] },   // シーン１１
        { gRunForScene[11], gJudgeForScene[11] },   // シーン１２
        { gRunForScene[12], gJudgeForScene[12] },   // シーン１３
        { gRunForScene[13], gJudgeForScene[13] },   // シーン１４
        { gRunForScene[14], gJudgeForScene[14] },   // シーン１５
        { gRunForScene[15], gJudgeForScene[15] },   // シーン１６
        { gRunForScene[16], gJudgeForScene[16] },   // シーン１７
        { gRunForScene[17], gJudgeForScene[17] },   // シーン１８
        { gRunForScene[18], gJudgeForScene[18] },   // シーン１９
        { gRunForScene[19], gJudgeForScene[19] },   // シーン２０
    };

    gInitializer = new IniDevice();     // 初期化装置

    gConqDoubleScenario = new Scenario(gInitializer, gGetParam, gEachAreaScene, 0, SIZE - 1);   // ダブルループNEO攻略用シナリオ

    gConDoubleScenarioTracer = new ScenarioTracer(gConqDoubleScenario);     // ダブルループNEO攻略用シナリオトレーサ
}

/* システムの破棄 */
void system_destroy()
{
    int8_t i;

    /* シナリオトレーサパッケージに関するインスタンス */
    delete gConDoubleScenarioTracer;
    delete gConqDoubleScenario;
    delete gInitializer;
    delete[] gEachAreaScene;

    /* 判定・走行・制御パッケージに関するインスタンス */
    for (i = 0; i < SIZE; i++)
    {
        delete gJudgeForScene[i];   // 判定
        delete gRunForScene[i];     // 走行
        delete gConForRun[i];       // 制御
    }

    /* 検出パッケージに関するインスタンス */
    delete gOdometer;
    delete gColorDetector;

    /* 管理パッケージに関するインスタンス */
    delete gGetParam;
    delete gGetCount;
    delete gGetHSV;
    delete gGetRollAngle;

    printf("シナリオオブジェクトの解放！！\n\n");
}

}
