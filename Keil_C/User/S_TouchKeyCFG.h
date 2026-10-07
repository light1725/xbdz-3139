/*****************************************************************************************************
 * @file    S_TouchKeyCFG.h
 * @brief   0010903139 触控键参数配置文件 (MCU: SC92F8411B SOP16)
 * @details 引脚映射:
 *          - 通道 0: TK8  (Pin 13 / P2.0) -> K2 照明按键
 *          - 通道 1: TK13 (Pin 10 / P2.5) -> K4 风速+延时按键
 *****************************************************************************************************/
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__

#define SOCAPI_SET_TOUCHKEY_TOTAL          2
#define SOCAPI_SET_TOUCHKEY_CHANNEL        0x00002100  /* (1UL << 8) | (1UL << 13) */
#define SOCAPI_SET_TOUCHKEY_CHANNEL2       0x00000000

/*
 * TKCFG[17]:
 * [3]  CONFIRMTOUCHCNT       = 5
 * [4]  INIT_AUTO_UPDATE_TIME = 10
 * [5]  SET_KEY_CONTI_TIME    = 3000
 * [6]  SET_SYNC_UPDATE       = 200
 * [7]  SET_UPDATE_SPEED      = 100
 * [8]  AUTO_UPDATE_TIME      = 2
 * [11] TOTAL_KEY_NUM         = 2
 * [16] NOISE                 = 20
 */
unsigned int code TKCFG[17] = {0,0,0,5,10,3000,200,100,2,1,0,2,0,1,65535,65535,20}; 

/*
 * TKChannelCfg[2][8]:
 * Ch0: TK8  (P2.0, K2 照明键)      -> 阈值 0x0096 (150)
 * Ch1: TK13 (P2.5, K4 风机+延时键)  -> 阈值 0x0096 (150)
 */
unsigned char code TKChannelCfg[SOCAPI_SET_TOUCHKEY_TOTAL][8] = {
    0x02,0x28,0x04,0x08,0x1b,0x05,0x00,0x96, /* Ch0: TK8  (P2.0, K2) */
    0x02,0x28,0x04,0x08,0x19,0x05,0x00,0x96  /* Ch1: TK13 (P2.5, K4) */
};

#endif