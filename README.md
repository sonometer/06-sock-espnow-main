##  06-sock-espnow

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




