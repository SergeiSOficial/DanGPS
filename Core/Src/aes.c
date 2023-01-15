/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    aes.c
  * @brief   This file provides code for the configuration
  *          of the AES instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "aes.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

CRYP_HandleTypeDef hcryp2;
__ALIGN_BEGIN static const uint32_t pKeyAES2[4] __ALIGN_END = {
                            0x00000000,0x00000000,0x00000000,0x00000000};
__ALIGN_BEGIN static const uint32_t HeaderAES2[4] __ALIGN_END = {
                            0x00000000,0x00000000,0x00000000,0x00000000};
__ALIGN_BEGIN static const uint32_t B0AES2[4] __ALIGN_END = {
                            0x00000000,0x00000000,0x00000000,0x00000000};

/* AES2 init function */
void MX_AES2_Init(void)
{

  /* USER CODE BEGIN AES2_Init 0 */

  /* USER CODE END AES2_Init 0 */

  /* USER CODE BEGIN AES2_Init 1 */

  /* USER CODE END AES2_Init 1 */
  hcryp2.Instance = AES2;
  hcryp2.Init.DataType = CRYP_DATATYPE_32B;
  hcryp2.Init.KeySize = CRYP_KEYSIZE_128B;
  hcryp2.Init.pKey = (uint32_t *)pKeyAES2;
  hcryp2.Init.Algorithm = CRYP_AES_CCM;
  hcryp2.Init.Header = (uint32_t *)HeaderAES2;
  hcryp2.Init.HeaderSize = 4;
  hcryp2.Init.B0 = (uint32_t *)B0AES2;
  hcryp2.Init.DataWidthUnit = CRYP_DATAWIDTHUNIT_WORD;
  hcryp2.Init.KeyIVConfigSkip = CRYP_KEYIVCONFIG_ALWAYS;
  if (HAL_CRYP_Init(&hcryp2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN AES2_Init 2 */

  /* USER CODE END AES2_Init 2 */

}

void HAL_CRYP_MspInit(CRYP_HandleTypeDef* crypHandle)
{

  if(crypHandle->Instance==AES2)
  {
  /* USER CODE BEGIN AES2_MspInit 0 */

  /* USER CODE END AES2_MspInit 0 */
    /* AES2 clock enable */
    __HAL_RCC_AES2_CLK_ENABLE();
  /* USER CODE BEGIN AES2_MspInit 1 */

  /* USER CODE END AES2_MspInit 1 */
  }
}

void HAL_CRYP_MspDeInit(CRYP_HandleTypeDef* crypHandle)
{

  if(crypHandle->Instance==AES2)
  {
  /* USER CODE BEGIN AES2_MspDeInit 0 */

  /* USER CODE END AES2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_AES2_CLK_DISABLE();
  /* USER CODE BEGIN AES2_MspDeInit 1 */

  /* USER CODE END AES2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
