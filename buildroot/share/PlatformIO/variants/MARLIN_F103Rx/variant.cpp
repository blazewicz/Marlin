/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(GD32F10x)
  #define RCC_PLL_MUL6_5 (13UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL17  (16UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL18  (17UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL19  (18UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL20  (19UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL21  (20UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL22  (21UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL23  (22UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL24  (23UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL25  (24UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL26  (25UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL27  (26UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL28  (27UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL29  (28UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL30  (29UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL31  (30UL << RCC_CFGR_PLLMULL_Pos)
  #define RCC_PLL_MUL32  (31UL << RCC_CFGR_PLLMULL_Pos)

  #define RCC_CFGR_USBFSPSC_Pos       (22UL)
  #define RCC_USBCLKSOURCE_PLL_DIV1   (1UL << RCC_CFGR_USBFSPSC_Pos)
  #define RCC_USBCLKSOURCE_PLL_DIV2_5 (2UL << RCC_CFGR_USBFSPSC_Pos)
  #define RCC_USBCLKSOURCE_PLL_DIV2   (3UL << RCC_CFGR_USBFSPSC_Pos)
#endif

const PinName digitalPin[] = {
  PA_0,
  PA_1,
  PA_2,
  PA_3,
  PA_4,
  PA_5,
  PA_6,
  PA_7,
  PA_8,
  PA_9,  // RXD
  PA_10, // TXD
  PA_11, // USB D-
  PA_12, // USB D+
  PA_13, // JTDI
  PA_14, // JTCK
  PA_15,
  PB_0,
  PB_1,
  PB_2,
  PB_3,  // JTDO
  PB_4,  // JTRST
  PB_5,
  PB_6,
  PB_7,
  PB_8,
  PB_9,
  PB_10,
  PB_11,  // LED
  PB_12,
  PB_13,
  PB_14,
  PB_15,
  PC_0,
  PC_1,
  PC_2,
  PC_3,
  PC_4,
  PC_5,
  PC_6,
  PC_7,
  PC_8,
  PC_9,
  PC_10,
  PC_11,
  PC_12,
  PC_13,
  PC_14,  // OSC32_1
  PC_15,  // OSC32_2
  PD_0,   // OSCIN
  PD_1,   // OSCOUT
  PD_2
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  0,  // A0,  PA0
  1,  // A1,  PA1
  2,  // A2,  PA2
  3,  // A3,  PA3
  4,  // A4,  PA4
  5,  // A5,  PA5
  6,  // A6,  PA6
  7,  // A7,  PA7
  16, // A8,  PB0
  17, // A9,  PB1
  32, // A10, PC0
  33, // A11, PC1
  34, // A12, PC2
  35, // A13, PC3
  36, // A14, PC4
  37  // A15, PC5
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {};

  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

  #if BOARD_F_CPU > 72000000L && !defined(GD32F10x)
    #error "CPU clock frequency higher than 72 MHz is supported only on GD32F10x based boards."
  #endif

  #if BOARD_F_CPU == 108000000L
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL27;
  #elif BOARD_F_CPU == 96000000L
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  #elif BOARD_F_CPU == 72000000L
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  #else
    #error "Unsupported clock speed, please check board_build.f_cpu"
  #endif

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }

  /** ADC clock
   *
   * This clock must not exceed 14 MHz.
   */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  #if BOARD_F_CPU == 108000000L
    // 13.5 MHz
    PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV8;
  #elif BOARD_F_CPU == 96000000L
    // 12 MHz
    PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV8;
  #elif BOARD_F_CPU == 72000000L
    // 12 MHz
    PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  #else
    #error "Unsupported clock speed, please check board_build.f_cpu"
  #endif

  /** USB clock
   *
   * This clock must be set to exactly 48 MHz.
   */
  #ifdef USBCON
    PeriphClkInit.PeriphClockSelection |= RCC_PERIPHCLK_USB;
    #if BOARD_F_CPU == 108000000L
      #error "USB support is not possible with 108 MHz system clock"
    #elif BOARD_F_CPU == 96000000L
      PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV2;
    #elif BOARD_F_CPU == 72000000L
      PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
    #else
      #error "Unsupported clock speed, please check board_build.f_cpu"
    #endif
  #endif

  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
    Error_Handler();
  }
}

#ifdef __cplusplus
}
#endif
