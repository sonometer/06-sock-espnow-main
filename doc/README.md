##  Project 06-sock-espnow

###    Archivos en _src_ comunes a _master_ y _slave_

 1. _mac_data.h_ y _mac_data.cpp_: para el manejo de los MAC address registrados
 2. _led.h_ y _led.cpp_: para el manejo del LED integrado en la placa de desarrollo
 3. _data.h_: para el tipo de estructura utilizado en la comunicación
 4. _button.h_: para _debounce_ de pulsadores (para futuro uso)

###     Archivos en _src/_

####    Utilizados por lado _master_ exclusivamente

 1. _main_master.cpp_: archivo principal en el ESP32 que transmite o _master_
 3. _espnow_master.cpp_ y _espnow_master.h_: archivos de manejo de _espnow_ para master
 4. _websock.cpp_ y _websock.h_: archivos de manejo de _WebSockets_
 5. _webpage.h_: archivo con la página de Web
 6. _wifi_ruts.cpp_ y _wifi_ruts.h_: archivos de manejo de _WiFi_
 7. _wifi_data.h_: archivo con _ssid_ y _passwords_ de acceso a _WiFi_

####    Utilizados de lado _slave_ exclusivamente

 1. _main_slave.cpp_: archivo principal en el ESP32 que recibe o _slave_
 2. _pwm.cpp_ y _pwm.h_: archivos de manejo de brillo de LED

###     Comandos de compilación, carga y monitoreo

 1. $ pio run: para compilar ambos, _master_ y _slave_
 2. $ pio run -e master -t upload: para cargar _master_
 3. $ pio run -e slave -t upload: para cargar _slave_
 4. $ pio run -e master -t monitor: para monitorear _master_
 4. $ pio run -e slave -t monitor: para monitorear _slave_

###  Links

 [Getting Started with ESP-NOW (ESP32 with Arduino IDE)](https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/)

 [ESP-NOW with ESP32: Send Data to Multiple Boards (one-to-many)](https://randomnerdtutorials.com/esp-now-one-to-many-esp32-esp8266/)

 [ESP-NOW with ESP32: Receive Data from Multiple Boards (many-to-one)](https://randomnerdtutorials.com/esp-now-many-to-one-esp32/)

 [ESP-NOW Two-Way Communication Between ESP32 Boards](https://randomnerdtutorials.com/esp-now-two-way-communication-esp32/)

 [ESP-NOW based Mesh network for ESP8266/ESP32](https://github.com/aZholtikov/ZHNetwork#esp-now-based-mesh-network-for-esp8266esp32)

