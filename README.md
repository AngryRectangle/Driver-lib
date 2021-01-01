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

7. #### Microstep constants
| Const         | Microstep Resolution|
| ------------- |:-------------------:|
| FULL_STEP     | Full Step           |
| HALF_STEP     | Half Step           |
| QUARTER_STEP     | Quarter Step           |
| EIGHTH_STEP     | Eighth Step           |
| SIXTEENTH_STEP     | Sixteenth Step           |

### DegreesDriverLib
1. #### Конструктор
```c++
DegreesDriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin, float degreesPerStep)
```
- stepPin - номер пина, подключённого к step драйвера.
- ms1Pin - номер пина, подключённого к ms1 драйвера.
- ms2Pin - номер пина, подключённого к ms2 драйвера.
- ms3Pin - номер пина, подключённого к ms3 драйвера.
- dirPin - номер пина, подключённого к dir драйвера.
- degreesPerStep - вращение в градусов на каждый шаг мотора.

2. #### setMaxSpeed
```c++
void setMaxSpeed(float speed)
```
- speed - количество градусов, которые совершает мотор за 1 секунду.

3. #### setAcceleration
```c++
void setAcceleration(float acceleration)
```
- acceleration - прирост скорости за 1 секунду в градусах.

4. #### setMicrosteps
```c++
void setMicrosteps(int pow)
```
- pow - каждый шаг делится на 2^pow микрошагов. (При 0 (2^0) в каждом шаге будет только 1 микрошаг, при 4 в каждом шаге будет 2^4 микрошагов).

5. #### rotateTo
```c++
void rotateTo(float angle);
```
- angle - абсолютное целевое вращение двигателя в градусах.

6. #### rotateBy
```c++
void rotateBy(float angle);
```
- angle - относительное вращение двигателя в градусах.

### LinearDriverLib
1. #### Конструктор
```c++
LinearDriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin, float millimetersPerStep);
```
- stepPin - номер пина, подключённого к step драйвера.
- ms1Pin - номер пина, подключённого к ms1 драйвера.
- ms2Pin - номер пина, подключённого к ms2 драйвера.
- ms3Pin - номер пина, подключённого к ms3 драйвера.
- dirPin - номер пина, подключённого к dir драйвера.
- millimetersPerStep - перемещение в миллиметрах на каждый шаг мотора.

2. #### setMaxSpeed
```c++
void setMaxSpeed(float speed)
```
- speed - количество миллиметров, которые совершает мотор за 1 секунду.

3. #### setAcceleration
```c++
void setAcceleration(float acceleration)
```
- acceleration - прирост скорости за 1 секунду в миллиметрах.

4. #### setMicrosteps
```c++
void setMicrosteps(int pow)
```
- pow - каждый шаг делится на 2^pow микрошагов. (При 0 (2^0) в каждом шаге будет только 1 микрошаг, при 4 в каждом шаге будет 2^4 микрошагов).

5. #### moveTo
```c++
void moveTo(float millimeters);
```
- millimeters - абсолютное целевое перемещение двигателя в миллиметрах.

6. #### moveBy
```c++
void moveBy(float millimeters);
```
- millimeters - относительное перемещение двигателя в миллиметрах.
