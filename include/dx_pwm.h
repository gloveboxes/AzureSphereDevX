/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

#pragma once

#include "dx_utilities.h"
#include "stdbool.h"
#include <applibs/pwm.h>

typedef struct DX_PWM_BINDING
{
    int fd;
    PWM_ControllerId controllerId;
    PWM_ChannelId channelId;
    PwmPolarity pwmPolarity;
    bool initialized;
    char *name;
} DX_PWM_BINDING;

/// <summary>
/// Set the PWM hertz and duty cycle percentage.
/// </summary>
/// <param name="pwm_binding"></param>
/// <param name="hertz">Typical hertz range is between 1000 and 5000</param>
/// <param name="dutyCyclePercentage">Percentage between 0 and 100</param>
/// <returns></returns>
bool dx_pwmSetDutyCycle(DX_PWM_BINDING *pwm_binding, uint32_t hertz, uint32_t dutyCyclePercentage);

/// <summary>
/// Stop and disable the PWM running
/// </summary>
/// <param name="pwm_binding"></param>
/// <returns></returns>
bool dx_pwmStop(DX_PWM_BINDING *pwm_binding);

/// <summary>
/// Open and initialize the PWM
/// </summary>
/// <param name="pwm_binding"></param>
/// <returns></returns>
bool dx_pwmOpen(DX_PWM_BINDING *pwm_binding);

/// <summary>
/// Open a set of PWM Bindings
/// </summary>
/// <param name="pwmSet"></param>
/// <param name="pwmSetCount"></param>
void dx_pwmSetOpen(DX_PWM_BINDING **pwmSet, size_t pwmSetCount);
