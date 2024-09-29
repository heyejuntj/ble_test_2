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
/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led_10 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led_11 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led_12 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led_13 = GPIO_DT_SPEC_GET(LED3_NODE, gpios);
static const struct gpio_dt_spec led_14 = GPIO_DT_SPEC_GET(LED4_NODE, gpios);  
static const struct gpio_dt_spec led_15 = GPIO_DT_SPEC_GET(LED5_NODE, gpios);  
static const struct gpio_dt_spec led_16 = GPIO_DT_SPEC_GET(LED6_NODE, gpios);  
static const struct gpio_dt_spec led_17 = GPIO_DT_SPEC_GET(LED7_NODE, gpios);  
static const struct gpio_dt_spec led_18 = GPIO_DT_SPEC_GET(LED8_NODE, gpios);  

static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));

////////////////////////////////////////////////////////////////////////////////////////

#define SLEEP_TIME_MS	1

/*
 * Get button configuration from the devicetree sw0 alias. This is mandatory.
 */
#define SW0_NODE	DT_ALIAS(sw0)
#if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
#error "Unsupported board: sw0 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios,
							      {0});
static struct gpio_callback button_cb_data;

/*
 * The led0 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */
static struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led8), gpios,
						     {0});

void button_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());
}





////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{

	int ret;
	bool led_state = true;

	// if (!gpio_is_ready_dt(&led_10)) {
	// 	return 0;
	// }

	if (!gpio_is_ready_dt(&led_14)) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_14, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	ret = gpio_pin_set_dt(&led_14,1);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_10, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_11, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_12, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_13, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led_15, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_16, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_configure_dt(&led_17, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led_18, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	ret = gpio_pin_set_dt(&led_10,0);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_set_dt(&led_11,0);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_set_dt(&led_12,0);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_set_dt(&led_13,0);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_set_dt(&led_15,0);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_set_dt(&led_16,0);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_set_dt(&led_17,0);
	if (ret < 0) {
		return 0;
	}


	// while (1) {
	// 	ret = gpio_pin_toggle_dt(&led_10);
	// 	if (ret < 0) {
	// 		return 0;
	// 	}
	// 	ret = gpio_pin_toggle_dt(&led_11);
	// 	if (ret < 0) {
	// 		return 0;
	// 	}
	// 	if(led_state==true)
	// 	{
	// 		ret = gpio_pin_set_dt(&led_12,1);
	// 		if (ret < 0) {
	// 			return 0;
	// 		}
	// 		ret = gpio_pin_set_dt(&led_13,1);
	// 		if (ret < 0) {
	// 			return 0;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		ret = gpio_pin_set_dt(&led_12,0);
	// 		if (ret < 0) {
	// 			return 0;
	// 		}
	// 		ret = gpio_pin_set_dt(&led_13,0);
	// 		if (ret < 0) {
	// 			return 0;
	// 		}
	// 	}

	// 	// ret = gpio_pin_toggle_dt(&led_15);//
	// 	// if (ret < 0) {
	// 	// 	return 0;
	// 	// }
	// 	// ret = gpio_pin_toggle_dt(&led_16);//
	// 	// if (ret < 0) {
	// 	// 	return 0;
	// 	// }
	// 	// ret = gpio_pin_toggle_dt(&led_17);//
	// 	// if (ret < 0) {
	// 	// 	return 0;
	// 	// }

	// 	ret = gpio_pin_toggle_dt(&led_18);
	// 	if (ret < 0) {
	// 		return 0;
	// 	}

	// 	led_state = !led_state;
	// 	printf("LED state: %s\n", led_state ? "ON" : "OFF");
	// 	k_msleep(SLEEP_TIME_MS);
	// }
	// return 0;
// 	////////////////////////////////////////////////////////////////////////////////////
// 	uint32_t max_period;
// 	uint32_t period;
// 	uint8_t dir = 0U;
// //	int ret;

// 	printk("PWM-based blinky\n");


// 	if (!pwm_is_ready_dt(&pwm_led0)) {
// 		printk("Error: PWM device %s is not ready\n",
// 		       pwm_led0.dev->name);
// 		return 0;
// 	}

// 	/*
// 	 * In case the default MAX_PERIOD value cannot be set for
// 	 * some PWM hardware, decrease its value until it can.
// 	 *
// 	 * Keep its value at least MIN_PERIOD * 4 to make sure
// 	 * the sample changes frequency at least once.
// 	 */
// 	printk("Calibrating for channel %d...\n", pwm_led0.channel);
// 	max_period = MAX_PERIOD;
// 	while (pwm_set_dt(&pwm_led0, max_period, max_period / 200U)) {
// 		max_period /= 2U;
// 		if (max_period < (4U * MIN_PERIOD)) {
// 			printk("Error: PWM device "
// 			       "does not support a period at least %lu\n",
// 			       4U * MIN_PERIOD);
// 			return 0;
// 		}
// 	}

// 	printk("Done calibrating; maximum/minimum periods %u/%lu nsec\n",
// 	       max_period, MIN_PERIOD);

// 	period = max_period;
// 	while (1) {
// 		ret = pwm_set_dt(&pwm_led0, period, period / 200U);
// 		if (ret) {
// 			printk("Error %d: failed to set pulse width\n", ret);
// 			return 0;
// 		}
// 		printk("Using period %d\n", period);

// 		period = dir ? (period * 2U) : (period / 2U);
// 		if (period > max_period) {
// 			period = max_period / 2U;
// 			dir = 0U;
// 		} else if (period < MIN_PERIOD) {
// 			period = MIN_PERIOD * 2U;
// 			dir = 1U;
// 		}

// 		k_sleep(K_SECONDS(4U));
// 	}
// 	return 0;
/////////////////////////////////////////////////////////////////////////////////////


	if (!gpio_is_ready_dt(&button)) {
		printk("Error: button device %s is not ready\n",
		       button.port->name);
		return 0;
	}

	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, button.port->name, button.pin);
		return 0;
	}

	ret = gpio_pin_interrupt_configure_dt(&button,
					      GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, button.port->name, button.pin);
		return 0;
	}

	gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
	gpio_add_callback(button.port, &button_cb_data);
	printk("Set up button at %s pin %d\n", button.port->name, button.pin);

	if (led.port && !gpio_is_ready_dt(&led)) {
		printk("Error %d: LED device %s is not ready; ignoring it\n",
		       ret, led.port->name);
		led.port = NULL;
	}
	if (led.port) {
		ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT);
		if (ret != 0) {
			printk("Error %d: failed to configure LED device %s pin %d\n",
			       ret, led.port->name, led.pin);
			led.port = NULL;
		} else {
			printk("Set up LED at %s pin %d\n", led.port->name, led.pin);
		}
	}

	printk("Press the button\n");
	if (led.port) {
		while (1) {
			/* If we have an LED, match its state to the button's. */
			int val = gpio_pin_get_dt(&button);

			if (val >= 0) {
				gpio_pin_set_dt(&led, val);
			}
			k_msleep(SLEEP_TIME_MS);
		}
	}
	return 0;

///////////////////////////////////////////////////////////////////////////////////
}
