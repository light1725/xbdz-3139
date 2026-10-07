/***************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	CallBackFunction.c
  * @author	
  * @version 	V3.0
  * @date	2022.07.14
  * @brief	Write the logic you want to implement in the function body
  * @details
  **************************************************************************************/ 
#include "SC_Init.h"
#include "SC_it.h"
#include "..\Drivers\SCDriver_list.h"
#include "HeadFiles\SysFunVarDefine.h"

/**
  * @brief  低功耗实现利用了BTM资源，用户需要在BTM中实现的内容在此函数实现
  * @note   该函数已在TKDriver.C文件LowPower_Touchkey_Scan()函数中调用
  *         //该函数已在低功耗模式扫描函数中调用
  *         //此函数为BTM定时唤醒后，用户的处理函数
  *         //低功耗模式下，用户需在BTM中实现的功能可在此函数实现
  *         //比如查询某个IO，电平发生变化等条件成立，(TK唤醒除外)需退出低功耗模式可在此函数中调用TouchKey_QuitLowPowerMode()
  * @param  None
  * @retval None
  */
void Customer_BTM_Dispose()
{
	
}
/**
  * @brief  在进入低功耗前，用户需要关闭外围耗电的电路，使电流最低
  * @note   该函数已在TKDriver.C文件TouchKey_IntoLowPowerMode()函数中调用,用户只需填写函数内部实现（关外设）
  *         //进入低功耗前设置
  *         //该函数已在TouchKey_IntoLowPowerMode()里调用
  *         //用户无需调用该函数！！！
  *         //用户需要自己编写该函数实体！！！
  *  		//关闭耗电的外设，保持最低功耗
  * @param  None
  * @retval None
  */
void Customer_IntoLowPowerMode_Init()
{
	
}
/**
  * @brief  在退出低功耗前，用户进行的必要操作（开外设）
  * @note   该函数已在TKDriver.C文件TouchKey_QuitLowPowerMode()函数中调用，用户只需填写函数内部实现（开外设）
  *         //退出低功耗前设置
  *         //该函数已在低功耗下满足TK唤醒退出低功耗时调用，即在TouchKey_QuitLowPowerMode()中调用
  *         //用户无需调用该函数！！！
  *         //用户需要自己编写该函数实体！！！
  * 		//恢复必要的外设
  * @param  None
  * @retval None
  */
void Customer_QuitLowPowerMode_Init()
{
	
}
