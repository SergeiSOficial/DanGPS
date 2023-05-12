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

/*!
 * @brief Defines the duty cycle threshold where the application will not send the results, results will be only logged
 * into flash memory if internal log is enable, 4.5s , value in [ms].
 */
#define TRACKER_DUTY_CYCLE_THRESHOLD 4500

/*!
 * @brief Defines the stream redundancy rate of the tracker application
 */
#define TRACKER_STREAM_REDUNDANCY_RATE 110

/*!
 * @brief Defines the application scan interval
 * when device has moved, 300s (5min), value in [ms].
 */
#define TRACKER_SCAN_INTERVAL 300000

/*!
 * @brief Defines the application keep alive frame interval
 * when device doesn't move, 12 hours, 43200 seconds, value in [ms].
 */
#define TRACKER_KEEP_ALIVE_FRAME_INTERVAL 43200000

/*!
 * @brief Defines the application data transmission duty cycle counter.
 * when device doesn't move.
 */
#define TRACKER_APP_TX_LOW_DUTYCYCLE_CTN TRACKER_KEEP_ALIVE_FRAME_INTERVAL / TRACKER_SCAN_INTERVAL

/*!
 * @brief Defines the BLE thread advertisement timeout
 * when device doesn't connect to smartphone, 30000, value in [ms].
 */
#define TRACKER_ADV_TIMEOUT_MS 30000

/*!
 * @brief Hall effect sensor activation timeout, in milliseconds.
 * @note Only relevant in airplane mode. When not in airplane mode, the
 *        sensor is always enabled.
 */
#define TRACKER_AIRPLANE_HALL_EFFECT_TIMEOUT_MS 60000

/*!
 * @brief Define the drop out voltage in mV threshold where the tracker
 * stays in airplane mode.
 * @note Used on a design without supercapacitor.
 */
#define TRACKER_BOARD_DROPOUT_VOLTAGE_THRESHOLD 0

/*!
 * @brief Define the drop out voltage recovery time, in milliseconds, above which where the tracker
 * stays in airplane mode.
 * @note Used on a design with supercapacitor.
 */
#define TRACKER_BOARD_MAX_VOLTAGE_RECOVERY_TIME 6000

/*!
 * @brief Define the battery capacity at 80%, batteries have 2400 mAh.
 */
#define TRACKER_BOARD_BATTERY_CAPACITY_80_PERCENT 1900

/*!
 * @brief Defines the application firmware version
 */
#define TRACKER_MAJOR_APP_VERSION 1
#define TRACKER_MINOR_APP_VERSION 5
#define TRACKER_SUB_MINOR_APP_VERSION 0

#define TRACKER_PCB_HW_NUMBER 595
#define TRACKER_MAJOR_PCB_HW_VERSION 1
#define TRACKER_MINOR_PCB_HW_VERSION 0

/*!
 * @brief Time during which an LED is turned on when a TX or RX event occurs, in milliseconds.
 */
#define LED_PERIOD_MS 25

/*!
 * @brief LoRaWAN application TLV Tag
 */
#define TLV_NAV_PCB_TAG 0x06
#define TLV_NAV_PATCH_TAG 0x07
#define TLV_WIFI_SCAN_TAG 0x0E
#define TLV_RESET_COUNTER_TAG 0x0C
#define TLV_SENSORS_TAG 0x0D
#define TLV_TRACKER_SETTINGS_TAG 0x4C

/*!
 * @brief LoRaWAN application TLV Len
 */
#define TLV_WIFI_SINGLE_BEACON_LEN 0x07
#define TLV_SENSOR_BASIC_VERSION_LEN 0x01
#define TLV_SENSOR_FULL_VERSION_LEN 0x07

/*!
 * @brief LoRaWAN application TLV Sensors version
 */
#define TLV_WIFI_VERSION 0x01
#define TLV_SENSOR_BASIC_VERSION 0x00
#define TLV_SENSOR_FULL_VERSION 0x01

/*!
 * @brief LoRaWAN stream application port
 */
#define LORAWAN_STREAM_APP_PORT 199

/*!
 * @brief LoRaWAN port used to the gnss push solver messages
 */
#define GNSS_PUSH_SOLVER_MSG_PORT 150

/*!
 * @brief LoRaWAN port used to trigger tracker events
 */
#define TRACKER_REQUEST_MSG_PORT 151

/*!
 * @brief Define the number of time where the tracker send a scan result once static
 */
#define TRACKER_SEND_ONE_MORE_SCANS_ONCE_STATIC 0x03
#define TRACKER_SEND_TWO_MORE_SCANS_ONCE_STATIC 0x07
#define TRACKER_SEND_THRE_MORE_SCANS_ONCE_STATIC 0x0F

/*
 * -----------------------------------------------------------------------------
 * --- PUBLIC CONSTANTS (LoRaWAN configuration) --------------------------------
 */

/*!
 * @brief LoRaWAN regulatory region.
 * One of:
 * LR1110_LORAWAN_REGION_EU868
 * LR1110_LORAWAN_REGION_US915
 * LR1110_LORAWAN_REGION_AU915
 * LR1110_LORAWAN_REGION_AS923_GRP1
 * LR1110_LORAWAN_REGION_CN470
 * LR1110_LORAWAN_REGION_AS923_GRP2
 * LR1110_LORAWAN_REGION_AS923_GRP3
 * LR1110_LORAWAN_REGION_IN865
 * LR1110_LORAWAN_REGION_KR920
 * LR1110_LORAWAN_REGION_RU864
 */
#define LORAWAN_REGION_USED LR1110_LORAWAN_REGION_EU868

/*!
 * @brief LoRaWAN regulatory region country. define LoRaWAN subregion countries to activate or not the LBT, 0 means disable, 1 means enable
 */
#define LORAWAN_COUNTRY_JAPAN 0

/*!
 * @brief LoRaWAN class.
 * One of:
 *  LR1110_LORAWAN_CLASS_A
 *  LR1110_LORAWAN_CLASS_C
 */
#define LORAWAN_CLASS_USED LR1110_LORAWAN_CLASS_A

/*!
 * @brief LoRaWAN ETSI duty cycle control enable/disable
 * Supported values:
 *  LR1110_MODEM_DUTY_CYCLE_ENABLE
 *  LR1110_MODEM_DUTY_CYCLE_DISABLE
 *
 * @remark Please note that ETSI mandates duty cycled transmissions. Set to false only for test purposes
 */
#define LORAWAN_DUTYCYCLE_ON LR1110_MODEM_DUTY_CYCLE_ENABLE

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
