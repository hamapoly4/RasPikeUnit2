/******************************************************************************
 *  ファイル名：app.cpp
 *　　　　内容：タスクであるmain_taskの実施
 *  　　作成日：2024/10/27
 *  　　作成者：近藤　悠太
 *****************************************************************************/

/* ヘッダインクルード */
#include <stdio.h>
#include "app.h"
#include "dbneo.h"
#include "ScenarioTracer.h"

/*----------------------------------------------------
*                    メインタスク
*-----------------------------------------------------*/
void main_task(intptr_t unused)
{
    dbneo::system_create();     // 開始処理

    /* 周期ハンドラ開始 */
    sta_cyc(CYC_DOUBLE_LOOP_NEO);

    slp_tsk();  // メインタスクの起床待ち

    /* 周期ハンドラ停止 */
    stp_cyc(CYC_DOUBLE_LOOP_NEO);

    dbneo::system_destroy();    // 終了処理

    ext_tsk();  // タスクの終了
}

/*----------------------------------------------------
*              ダブルループNEO攻略タスク
*-----------------------------------------------------*/
void double_loop_NEO_task(intptr_t exinf)
{
    dbneo::gConDoubleScenarioTracer->conquer();    // シナリオトレーサが攻略する

    if (dbneo::gConDoubleScenarioTracer->checkState() == ScenarioTracer::FINISH || ev3_button_is_pressed(ENTER_BUTTON))
    {
        wup_tsk(MAIN_TASK);     // メインタスクを起こす
    }
}
