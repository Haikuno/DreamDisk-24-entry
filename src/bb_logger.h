#include "gimbal_logger.h"

#define BB_LOG_DEBUG(...)   GBL_LOG_DEBUG("BB", __VA_ARGS__)
#define BB_LOG_VERBOSE(...) GBL_LOG_VERBOSE("BB", __VA_ARGS__)
#define BB_LOG_INFO(...)    GBL_LOG_INFO("BB", __VA_ARGS__)
#define BB_LOG_WARN(...)    GBL_LOG_WARN("BB", __VA_ARGS__)
#define BB_LOG_ERROR(...)   GBL_LOG_ERROR("BB", __VA_ARGS__)
#define BB_LOG_PUSH()       GBL_LOG_PUSH()
#define BB_LOG_POP(n)       GBL_LOG_POP(n)