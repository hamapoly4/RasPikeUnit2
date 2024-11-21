/******************************************************************************
 *  ファイル名：app.cpp
 *　　　　内容：タスクであるmain_taskの実施
 *  　　作成日：2024/8/20
 *  　　作成者：近藤　悠太
 *****************************************************************************/

#include "app.h"
#include "Scenario.h"

/*----------------------------------------------------
*                      内部結合
*-----------------------------------------------------*/
namespace {
    /* オブジェクトの定義 */
    Scenario* gScenario;

    /* システムの生成 */
    void system_create()
    {
        /* オブジェクトを動的に確保 */
        gScenario = new Scenario;
    }

    /* システムの破棄 */
    void system_destroy()
    {
        /* 動的なオブジェクトの解放 */
        delete gScenario;
        printf("Yamasaki Ten\n\n");
    }
}

/*----------------------------------------------------
*                    メインタスク
*-----------------------------------------------------*/
void main_task(intptr_t unused)
{
    system_create();

    while (true)
    {
        gScenario->run();
        if (gScenario->finish() == true)
        {
            break;
        }
    }

    system_destroy();  /* 終了処理 */
    printf("Morita Hikaru\n\n");

    ext_tsk();  /* タスクの終了 */
}
