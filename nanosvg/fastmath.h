#pragma once

inline float math_mod(float x, float y) 
{
    float quotient = x / y;
    int intQuotient = (int) quotient;
    float remainder = x - intQuotient * y;
    return remainder;
}

inline float math_pow(float base, long exponent) {
    float result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

static float math_sin(float angle)
{
    float result;
    float term;
    int sign;
    int i;

    angle = math_mod(angle, 6.28318530717958647692f); 
    if (angle > 3.14159265358979323846f) 
    {
        angle -= 6.28318530717958647692f;
    }

    result = 0.0;
    term = angle;
    sign = 1; 

    for (i = 1; i <= 5; i++) 
    {
        result += sign * term;
        sign = -sign;
        term = term * angle * angle / ((2 * i) * (2 * i + 1));
    }

    return result;
}

inline float math_cos(float angle)
{
    float result;
    float term;
    int sign;
    int i;

    angle = math_mod(angle, 6.28318530717958647692f);
    if (angle > 3.14159265358979323846f) 
    {
        angle -= 6.28318530717958647692f;
    }

    result = 1.0;
    term = 1.0;
    sign = -1;

    for (i = 1; i <= 5; i++) 
    {
        term = term * angle * angle / ((2 * i - 1) * (2 * i));
        result += sign * term;
        sign = -sign;
    }

    return result;
}

inline float math_tan(float angle)
{
    float sin_val;
    float cos_val;

    sin_val = math_sin(angle);
    cos_val = math_cos(angle);
    if (cos_val == 0.0f) 
    {
        return 0; 
    }

    return sin_val / cos_val;
}

inline float math_acos(float x) 
{
    float low;
    float high;
    float mid;
    float tolerance;

    if (x < -1.0f || x > 1.0f) 
    {
        return -1.0f;
    }

    low = 0.0f;
    high = 3.14159265358979323846f;
    mid;
    tolerance = 0.000001f; 

    while ((high - low) > tolerance) 
    {
        mid = (low + high) / 2.0f;
        if (math_cos(mid) > x) 
        {
            low = mid; 
        }
        else 
        {
            high = mid; 
        }
    }

    return mid;
}

inline float math_floor(float value)
{
	int integerPart = (int)value;
    if (value == (float)integerPart) {
        return value;
    }
    if (value < 0) {
        return (float)(integerPart - 1);
    }
    return (float)integerPart;
}

inline float math_ceil(float value)
{
	int integerPart = (int)value; 
    if (value == (float)integerPart) {
        return value;
    }
    if (value < 0) {
        return (float)integerPart;
    }
    return (float)(integerPart + 1);
}