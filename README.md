# Vúmetro con Arduino
Su funcionamiento se basa en la recepción de sonido con el micrófono amplificado MAX9812, las señales captadas son filtradas por una ventada temporal de 35 milisegundos, equivalente a una frecuencia de 28.5 Hz, para después convertir la medición en voltaje, posterior a esto se mapea con una función para variar la iluminación de una tira de RGB WS2812 de 8 neopixels.. Podrás encontrar este proyecto con más detalles aquí [Vúmetro con Arduino](https://www.proyecto-teos.com/vumetro-con-arduino).
### Empezando
Este proyecto se basa en los sensores que hemos usado anteriormente, si no tienes mucha experiencia en el manejo de dichos sensores puedes consultar nuestros repositorios.

- Micrófono amplificado https://github.com/proyectoTEOS/Microfono-amplificado-MAX9812-con-Arduino
- Neopixel WS2812  https://github.com/proyectoTEOS/NeoPixel-WS2812-con-Arduino

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Contar con las librería [Neopixel](https://github.com/adafruit/Adafruit_NeoPixel) 
- Tener el material para hacer el proyecto (claro)

### Materiales
Enlistaremos los materiales que se necesitan para realizar el proyecto, pero puedes conseguir componentes similares.
- 1 Arduino UNO R3
- 2	Neopixel Bar 8 WS2812	
- 1	Micrófono amplificado MAX9812	
- 1	Protoboard
- **Necesitarás una fuente de poder de 5 volts a 1 Amper (esto dependerá de la cantidad de neopixels que uses, en este proyecto es indispensable para suministrar la corriente demandada por el número de neopixels. Por ningún motivo suministres la corriente directamente con Arduino).**

### Código
**[Aqui](https://github.com/proyectoTEOS/Vumetro-con-Arduino-con-Arduino/blob/master/Vumetro-con-Arduino-con-Arduino.ino)** podrás obtener el link del código, esta comentado de tal forma que puedas entender su estructura y función.

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](/resources/diagrama-vumetro-con-arduino.jpg)

Toma en cuenta estas consideraciones:
-Instalar todas las librerías mencionadas en el proyecto, previo a esto dejamos los enlaces. 
-La variable numPixelsT establece el número de pixels que tiene la barra, si la tira de neopixels cuenta con más pixels debes modificar este valor. 
-En el programa existen 2 instancias para los neopixels, esto es porque se quieren controlar de forma independiente. Puedes utilizar una sola instancia o unir ambas tiras y tener una sola, pero con 16 neopixels. 
-Para mapear el nivel de volumen se establecen 3 tonos de colores (verde, amarillo y rojo). Dichos colores están dados por vuMeterAT.Color(), puedes cambiar y poner tonos que sean de tu agrado. Recuerda que es RGB y puedes tomar un valor de 0 a 255. 
-Si estas utilizando más de 7 neopixels en tu tira, tendrás que modificar la restricción de rango en la siguiente línea de código: voltsToNeoPixelT = constrain(voltsToNeoPixelT, 0, 7); 

### Prototipo
Aquí dejaremos imágenes de nuestro prototipo, pronto subiremos los pasos para que puedas realizar un prototipo similar.
![](/resources/prototipo-vumetro-con-arduino-1.jpg)
![](/resources/prototipo-vumetro-con-arduino-2.jpg)

Si requieres más información de este y otros proyectos, puedes ir a nuestra [página web](https://www.proyecto-teos.com) y dar clic en la parte de proyectos en donde encontraras los códigos, diagramas, hojas de datos, librerías, recursos y una documentación más extensa.