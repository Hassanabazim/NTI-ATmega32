/*
 * STD_TYPES_h.h
 *
 *  Created on: May 31, 2023
 *      Author: Hassan
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL (void*) 0
typedef signed char          int8_t;         /*        -128 - 127        */
typedef unsigned char        uint8_t;        /*         0 - 255          */
typedef signed short         int_16;        /*      -32768 - 32767      */
typedef unsigned short       uint_16;       /*        0 - 65535         */
typedef signed long          int32_t;        /* -2147483648 - 2147483647 */
typedef unsigned long        uint32_t;       /*      0 - 4294967295      */
typedef signed long long     int64_t;        /*                          */
typedef unsigned long long   uint64_t;       /*                          */
typedef float                float32_t;      /*     3.4e-38 -> 4e+38     */
typedef double               double64_t;     /*    1.7e-308 -> 1.7e+308  */
typedef long double          double128_t;    /*  3.4e-4932 -> 1.1e+4932  */


#endif /* STD_TYPES_H_ */
