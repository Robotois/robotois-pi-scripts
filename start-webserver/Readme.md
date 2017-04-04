# Robotois

[![N|Solid](http://robotois.com/static/media/logo-footer.b6f7cf5a.svg)](http://robotois.com)

Este script se encarga de inicializar el webserver de robotois cada que la raspberry pi arranca.

  - Crear el archivo en ```/etc/init.d/robotois-service.sh```
  - Validar que el script tenga la el path de la instalación de node correcta ```which node```
  - Cambiar los privilegios mediante ```sudo chmod 755 /etc/init.d/robotois-service.sh```
  - Para probar el script ```sh /etc/init.d/robotois-service.sh start/stop```
  - Para hacerlo que corra al inicio ```$ sudo update-rc.d robotois-service.sh defaults```
  - Para removerlo de correr al inicio ```$ sudo update-rc.d -f robotois-service.sh remove```

  - Para listar los procesos activos de node ```$ ps -xa | grep node```

License
----

MIT


**Software Libre!**
