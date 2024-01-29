##  06-sock-espnow-main

  Mecatronica - FIE
  EAM

### ESP-NOW One Way master-slave communication with WebSocket in master for controlling slave LED brightness

  see doc/README.md for further instructions

  Miercoles 3 de Enero de 2024.  
  Se bajó de Notion el apk que se incluye en este repositorio bajo el directorio _android_ (Nota de último momento: ver README.md en _android_).  

  Reportado por Pablo a través de Eduardo Sacerdoti.  
  _sólo modifiqué el archivo websock.cpp e incorporé la librería <ArduinoJson.h> para manejar los elementos json_.  

  Viernes 5 de Enero de 2024.  
  Probado por Eduardo Martínez utilizando un celular Samsung Note 8 - Version Android 9, One UI version 1.0.  
  Resultados:
  1. Se cargó el _apk_ en el celular
  2. El celular tiene habilitada la conexión a WiFi pero se deshabilito la conexión automática a redes previamente conocidas.
  3. Se compiló y se cargó _master_ a un ESP32
  4. Se corrió el _apk_ en el celular
  5. Aparentemente, se cargó bien
  6. Se tomó la opción de conectarse a la red
  7. Se dió permiso de hacerlo
  8. Intentó conectarse pero no se obtuvo nada

### Agregado por Eduardo Martinez (28/Jan/2024)

  La modificación se hizo solamente en el _master_ a los fines de simular el estado del blanco; a los fines de la prueba, se simuló un reporte del blanco cada segundo en bloques de 10 reportes, un bloque reportando que no hubo blanco y otro bloque reportando que hubo blanco.  
  A tal fin, se agregó un archivo que realiza dicha simulación y que se llama _target.cpp_ con su consabido archivo de prototipos _target.h_.  
  En el archivo _main_master.cpp_ se incluyó el archivo _target.cpp_; en la función _setup_ se llamó a _target_init_ para inicializar el funcionamiento y en la función _loop_ se agregó la llamada a _target_process_ con la finalidad de hacer _polling_ de la simulación. 
  El reporte a través de _Websocket_ se realiza desde la función _task_target_ (archivo _target.cpp_) que, cada vez que tiene que reportar, llama a _send_websock_ con el texto; dicho texto es _tgt,#_ donde # es un solo dígito que puede ser _*0*_, si el blanco no fué impactado y _*1*_ si lo fué.  
  Teniendo en cuenta que quien escribe no entiende casi nada de _javascript_, generó la función dentro del archivo _websock.cpp_ denominada _send_websock_ que, por el momento en la línea 95 solo imprime; habria que ciambiar ahi por el código adecuado para que sea tratado en el nivel superior.

### Sugerencias para la ejecución

  Si bien para el futuro en el proyecto, la conexión al _Access Point_ para acceder a la página de Websockets va a estar en el mismo ESP32 para independizarse de un _Access Point_ externo, trabajar en el desarrollo teniendo que desconectar la computadora del _Access Point_ externo para conectarse al del ESP32 es realmente un incordio; esa es la razón por la cual hay en _platformio.ini_ la definición de un símbolo denominado _WIFI_MODE_ en la línea 29 del mencionado archivo, que puede estar en 0 si se desea conectar a un AP externo y en 1 si se desea conectar al AP del ESP32.  
  También es muy incómodo trabajar con el número de IP dado por el AP, por lo cual se usa _mDNS_ de manera que, desde la misma red donde está conectado el ESP32 puede accederse como el URL, en este caso, _robot.local_.  
  Por lo tanto, si se va a usar con _WIFI_MODE_ en 0, es decir por AP externo, debe cambiarse ante todo el _SSID_ y el _PASS_ del mismo, lo cual debe hacerse en el archivo _wifi_data.h_ en las líneas 8 y 9, respectivamente; de paso, recordar que el ESP32 _sólo se puede conectar a las redes de 2.4GHz_.  
  Una vez hechas estas preparaciones, puede probarse lo que está realizado, haciendo lo siguiente:

  1. Compilar y cargar el programa con el comando de PlatformIO siguiente: _pio run -e master -t upload_.  
  2. Una vez cargado el programa, cargar el programa monitor mediante el comando de PlatformIO siguiente: _pio run -e master -t monitor_.  
  3. Se verá cada segundo la información que se produce para enviar el estado del blanco.  
  4. Si se desea ver la página de Websocks, se debe abrir un _browser_ y poner el siguiente URL _robot.local_; se observarán la tipica págica ya conocida con el deslizante

