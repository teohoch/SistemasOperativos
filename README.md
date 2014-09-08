SistemasOperativos
==================
Grupo: 02
Nombres: Teodoro Hochfarber/Fabián Viani
Rol (respectivos a los nombres): 201173039-9/201003048-2

Pregunta 2: wc-exploratorio

Supuestos : Se supone una estructura de árbol finita, es decir, una anidación de carpetas numerable con una cantidad finita de archivos también. Además, se supone permisible el uso de funciones y comandos básicos de UNIX, uso de expresiones regulares y funciones pre-definidas.

Archivos y carpetas: El archivo que contiene el código para esta pregunta se llama "exp-wc", sin terminación en ".sh". Es necesario darle permisos antes de correrlo en consola, utilizando "chmod u+x exp-wc".

Explicación de la estrategia: Para esta pregunta, se consideró lo siguiente:
-Función error(): Esta función es utilizada para avisar sobre posibles errores al ingresar el directorio como argumento del script
-Cadena condicional para comprobar si el argumento precisamente es un directorio, o si no se está ingresando ningún parámetro.
-Sentencia principal: Primero realiza un filtro del argumento, buscando los archivos contenidos en la cadena del directorio, luego aplica la función "wc -l" que cuenta lineas que tiene el archivo a cada archivo dentro de cada directorio, donde se lista la suma acumuluda, y la suma final queda en la última línea de salida.
Con "tail -l" se guarda esa última línea con el resultado de la suma total, luego se filtra sólo el resultado numérico con grep -o -e "[0-9]*", la cual es una expresión regular, y finalmente el resultado se guarda en un nuevo archivo, donde se utiliza una nueva expresión regular para conseguir el mismo nombre del directorio inicial que se usó como argumento, es decir, de "carpeta1" se obtiene "carpeta1.result".
