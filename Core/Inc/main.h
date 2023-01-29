/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbxx_hal.h"

#include "app_conf.h"
#include "app_entry.h"
#include "app_common.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VCC_2_4GHz_SW_Pin GPIO_PIN_8
#define VCC_2_4GHz_SW_GPIO_Port GPIOA
#define GHz2_4_SWITCH_Pin GPIO_PIN_9
#define GHz2_4_SWITCH_GPIO_Port GPIOA
#define LNA_PON_MCU_Pin GPIO_PIN_0
#define LNA_PON_MCU_GPIO_Port GPIOB
#define LR_BUSY_Pin GPIO_PIN_1
#define LR_BUSY_GPIO_Port GPIOB
#define LR_IRQ_Pin GPIO_PIN_4
#define LR_IRQ_GPIO_Port GPIOE
#define LR_NRESET_Pin GPIO_PIN_10
#define LR_NRESET_GPIO_Port GPIOA
#define TX1_Pin GPIO_PIN_11
#define TX1_GPIO_Port GPIOA
#define RX1_Pin GPIO_PIN_12
#define RX1_GPIO_Port GPIOA
#define ACC_INT1_Pin GPIO_PIN_7
#define ACC_INT1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
