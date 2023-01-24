
typedef struct {
	uint32_t PDOR; // set data of all the pins
	uint32_t PSOR;  // sets data of pins with 1 to 1
	uint32_t PCOR; // sets data of pins with 1 to 0
	uint32_t PTOR; // toggles any pins set to 1
	uint32_t PDIR;
	uint32_t PDDR;
} GPIO_Struct;

/* GPIO - Peripheral instance base addresses */

/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIO_A                                    ((GPIO_Struct *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x400FF040u)
/** Peripheral GPIOB base pointer */
#define GPIO_B                                    ((GPIO_Struct *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x400FF080u)
/** Peripheral GPIOC base pointer */
#define GPIO_C                                    ((GPIO_Struct *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x400FF0C0u)
/** Peripheral GPIOD base pointer */
#define GPIO_D                                    ((GPIO_Struct *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x400FF100u)
/** Peripheral GPIOE base pointer */
#define GPIO_E                                    ((GPIO_Struct *)GPIOE_BASE)


void GPIO_Init(GPIO_Struct *gpio, uint32_t pin)
{
	gpio->PDOR |= 1u << pin;
	gpio->PDDR |= 1u << pin;
}


static inline void GPIO_Toggle(GPIO_Struct *gpio, uint32_t mask) {
	gpio->PTOR = mask;

}

static inline void GPIO_PinOn(GPIO_Struct *gpio, uint32_t mask) {
	gpio->PDIR = mask;
	gpio->PDOR |= mask;

}
static inline void GPIO_PinOff(GPIO_Struct *gpio, uint32_t mask) {
	gpio->PCOR = mask;

}

