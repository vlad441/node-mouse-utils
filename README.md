Mouse and Keyboard Functions / Функции мыши и клавиатуры
Only for Windows / Только для Windows

## Пример
```js
const mkutils = require("mouse-utils");

(async function(){ console.log(await mkutils.GetCursorPos()); console.log(await mkutils.SetCursorPos(400, 500)); })();
```
## Методы
##### **GetCursorPos()** - узнать координаты курсора, возвращает Promise(Object).
##### **SetCursorPos(x, y)** - установить позицию курсора, возвращает Promise(Boolean).
##### **Click("left"/"right"/"double")** - Клик левой кнопкой мыши, возвращает Promise(Boolean).
##### **PressKey(keycode)** - Нажать клавишу по коду клавиши, возвращает Promise(Boolean). [Коды клавиш](https://keycode.inicar.info/KeyCode/1_KeyCode.php)
##### **GetPxColor(x, y)** - Узнать цвет пикселя по координатам в виде HEX, возвращает Promise(String).
