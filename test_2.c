/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdbool.h>
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/sys/util.h>
#include <inttypes.h>


#define MIN_PERIOD PWM_SEC(1U) / 128U
#define MAX_PERIOD PWM_SEC(1U)

////////////////////////////////////////////////////////////////////////////////

/* 1000 msec = 1 sec */
// #define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)//电量灯
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)
#define LED3_NODE DT_ALIAS(led3)
#define LED4_NODE DT_ALIAS(led4)//36V上电
#define LED5_NODE DT_ALIAS(led5)//蓝
#define LED6_NODE DT_ALIAS(led6)//绿
#define LED7_NODE DT_ALIAS(led7)//红
#define LED8_NODE DT_ALIAS(led8)//蜂鸣器



void main(void)
{
    while(1);
}

