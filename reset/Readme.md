# Robotois

En esta sección se proporciona la funcionalidad de Reset para la Raspberry PI usando el botón del Shield. El reset consiste en dos opciones:

  * La primera consiste en reiniciar la aplicación ```webserverpi```, esto se realiza cuando el botón de reset se presiona por un tiempo de dos segundos hasta menos de cinco segundos.
  * La segunda opción inicia el proceso de apagado de la Raspberry PI, lo cual es muy útil para no tener que aparar ésta desconectando el cable de alimentación. Esta función se ejecuta cuando el botón de reset es presionado por cinco o mas segundos.

Se debe considerar que el proyecto ```robotois-pi-scripts``` debe descargarse en la siguiente ruta: ```/home/pi/Robotois/``` ya que ésta es la ruta por default para el software Robotois. Para incluir la funcionalidad de reset en la Raspberry PI, se deben realizar lo siguiente:

  * Editar el archivo ```/etc/rc.local/```, puede ser usando ```sudo nano /etc/rc.local```, en la última parte antes de la línea ```exit 0```, se debe poner la siguiente línea: ```sudo /home/pi/Robotois/robotois-pi-scripts/reset/run.sh```.
