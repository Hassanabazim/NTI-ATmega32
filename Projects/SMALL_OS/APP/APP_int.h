/*
 * app.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Hassa
 */

#ifndef APP_INT_H_
#define APP_INT_H_

typedef struct
{
	void (*ptrfn)(void);
}task_t;

void APP_voidInitApp(void);
void APP_voidStartApp(void);

#endif  /* APP_INT_H_ */
