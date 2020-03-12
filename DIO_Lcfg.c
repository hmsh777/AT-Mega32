#include "DIO_Lcfg.h"

const Pin_Status_type Pins_Status[TOTAL_PINS]=
{
	OUTPUT,   /* Port A Pin 0 */
	OUTPUT,   /* Port A Pin 1 */
	OUTPUT,   /* Port A Pin 2 */
	OUTPUT,   /* Port A Pin 3 */
	OUTPUT,   /* Port A Pin 4 */
	OUTPUT,   /* Port A Pin 5 */
	OUTPUT,   /* Port A Pin 6 */
	OUTPUT,   /* Port A Pin 7 */
	OUTPUT,   /* Port B Pin 0   /SS */
	OUTPUT,   /* Port B Pin 1   /SCK*/
	OUTPUT,   /* Port B Pin 2   /MOSI*/
	OUTPUT,   /* Port B Pin 3   /MISO*/
	OUTPUT,   /* Port B Pin 4 */
	OUTPUT,   /* Port B Pin 5 */
	OUTPUT,   /* Port B Pin 6 */
	OUTPUT,   /* Port B Pin 7 */
	OUTPUT,   /* Port C Pin 0 */
	OUTPUT,   /* Port C Pin 1 */
	OUTPUT,   /* Port C Pin 2 */
	OUTPUT,   /* Port C Pin 3 */
	OUTPUT,   /* Port C Pin 4 */
	OUTPUT,   /* Port C Pin 5 */
	OUTPUT,   /* Port C Pin 6 */
	OUTPUT,   /* Port C Pin 7 */
	INPULLUP,   /* Port D Pin 0 */
	INPULLUP,   /* Port D Pin 1 */
	INPULLUP,   /* Port D Pin 2 */
	INPULLUP,   /* Port D Pin 3   OC1A*/
	OUTPUT,     /* Port D Pin 4   OC1B*/
	OUTPUT,   /* Port D Pin 5 */
	INFREE,   /* Port D Pin 6     ICP*/
	OUTPUT    /* Port D Pin 7 */
};
