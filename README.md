# Driver-lib
Эта библиотека предназначена для управления драйвером для шагового мотора [A4988](https://www.pololu.com/product/1182) в однопоточном режиме.

## Возможности:
  * Поддержка всех возможных [дроблений шага](https://www.pololu.com/file/0J450/A4988.pdf) (от 1 до 1/16)
  * Управление линейным перемещением в относительной и абсолютной системе координат
  * Установка текущей позиции мотора
  * Управление ускорением движения мотора
  * Реализация 2 режимов работы: линейное перемещение (миллиметры) и управление вращением (градусы)
  * Управление углом поворота вала шагового двигателя
## Документация
### DriverLib
1. #### Конструктор
```c++
DriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin)
```
- stepPin - номер пина, подключённого к step драйвера.
- ms1Pin - номер пина, подключённого к ms1 драйвера.
- ms2Pin - номер пина, подключённого к ms2 драйвера.
- ms3Pin - номер пина, подключённого к ms3 драйвера.
- dirPin - номер пина, подключённого к dir драйвера.

![](https://www.allegromicro.com/-/media/images/products/4988/a4988-typical-application.ashx)

2. #### setMaxSpeed
```c++
void setMaxSpeed(float speed)
```
- speed - количество шагов, которые совершает мотор за 1 секунду.

3. #### setAcceleration
```c++
void setAcceleration(float acceleration)
```
- acceleration - прирост скорости за 1 секунду в шагах.

4. #### setMicrosteps
```c++
void setMicrosteps(int pow)
```
- pow - каждый шаг делится на 2^pow микрошагов. (При 0 (2^0) в каждом шаге будет только 1 микрошаг, при 4 в каждом шаге будет 2^4 микрошагов).

5. #### moveTo
```c++
void moveTo(long step)
```
- step - абсолютное целевое вращение измеряемое в шагах.

6. #### moveBy
```c++
void moveBy(long step)
```
- step - относительно вращение измеряемое в шагах.

### DegreesDriverLib
1. #### Конструктор
```c++
DegreesDriverLib(DriverLib* driver, float degreesPerStep)
```
- driver - драйвер.
- degreesPerStep - вращение в градусов на каждый шаг мотора.

2. #### rotateTo
```c++
void rotateTo(float angle);
```
- angle - абсолютное целевое вращение двигателя в градусах.

3. #### rotateBy
```c++
void rotateBy(float angle);
```
- angle - относительное вращение двигателя в градусах.

### LinearDriverLib
1. #### Конструктор
```c++
LinearDriverLib(DegreesDriverLib* driver, float millimetersPerRotation);
```
- driver - драйвер.
- millimetersPerRotation - перемещение в миллиметрах на каждый оборот мотора.

2. #### moveTo
```c++
void moveTo(float millimeters);
```
- millimeters - абсолютное целевое перемещение двигателя в миллиметрах.

3. #### moveBy
```c++
void moveBy(float millimeters);
```
- millimeters - относительное перемещение двигателя в миллиметрах.

## Примеры
1. Пример DriverLib.
```c++
#include "DriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

DriverLib *driver;
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ms1Pin, OUTPUT);
  pinMode(ms2Pin, OUTPUT);
  pinMode(ms3Pin, OUTPUT);
  // Создать экземпляр драйвера
  driver = new DriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
  // Установить скорость вращения двигателя
  driver->setMaxSpeed(100000);
}

void loop() {
  // Сдвинуть мотора на 5000 шагов (абсолютное перемещение)
  driver->moveBy(5000);
  // Сдвинуть мотор на 10000 шагов назад
  driver->moveBy(-10000);
}
```

2. Пример DegreesDriverLib.
```c++
#include "DegreesDriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

DriverLib *driver;
DegreesDriverLib *degreeDriver;
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ms1Pin, OUTPUT);
  pinMode(ms2Pin, OUTPUT);
  pinMode(ms3Pin, OUTPUT);
  // Создать экземпляр драйвера
  driver = new DriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
  // Создаёт вращательный драйвер для мотора с шагом в 1.8 градуса
  degreeDriver = new DegreesDriverLib(driver, 1.8f);
  // Установить скорость вращения двигателя
  driver->setMaxSpeed(100000);
}

void loop() {
  // Вращение на 720 градусов по часовой
  degreeDriver->rotateBy(720);
  // Установка вращения двигателя на 0 (абсолютное перемещение)
  degreeDriver->rotateTo(0);
}
```

3. Пример LinearDriverLib.
```c++
#include "LinearDriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

DriverLib *driver;
DegreesDriverLib *degreeDriver;
LinearDriverLib *linearDriver;
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ms1Pin, OUTPUT);
  pinMode(ms2Pin, OUTPUT);
  pinMode(ms3Pin, OUTPUT);
  // Создать экземпляр драйвера
  driver = new DriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
  // Создаёт вращательный драйвер для мотора с шагом в 1.8 градуса
  degreeDriver = new DegreesDriverLib(driver, 1.8f);
  // Создать линейный драйвер для двигателя который за каждый оборот смещает на 1 сантиметр
  linearDriver = new LinearDriverLib(degreeDriver, 10);
  // Установить скорость вращения двигателя
  driver->setMaxSpeed(100000);
}

void loop() {
  // Передвинуть на 2m
  linearDriver->moveBy(2000);
  // Установить положение мотора в 1 cm (абсолютное перемещение)
  linearDriver->moveTo(10);
}
```
