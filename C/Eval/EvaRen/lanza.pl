#**************************************************************
#               Pontificia Universidad Javeriana
#     Autor: J. Corredor
#     Fecha: Febrero 2024
#     Materia: Sistemas Operativos
#     Tema: Taller de Evaluación de Rendimiento
#     Fichero: script automatización ejecución por lotes 
#****************************************************************

#**************************************************************
# 
#****************************************************************

# Obtiene el directorio de trabajo actual y lo asigna a $Path
my $Path = `pwd`;

# Elimina cualquier salto de línea al final de la salida del comando 'pwd'
chomp($Path);  

# Define el nombre del ejecutable que se usará en las pruebas
$Nombre_Ejecutable = ("_clasico", "_transpuesto");

# Define los tamaños de matrices para las pruebas en un arreglo

# Define los números de hilos que se usarán en las pruebas en otro arreglo
@Num_Hilos = (1, 2);

# Establece el número de repeticiones que se realizarán para cada configuración
$Repeticiones = 30;

#Ciclo para iterar sobre ambos ejecutables de codigo _clasico y _transpuesto
foreach $nombre (@Nombre_Ejecutable) {
    # Ciclo for para cada tamaño de hilo y numero de hilos
    foreach $hilo (@Num_Hilos) {
		#Concatena la ruta, nombre del ejecutable, tamaño e hilos
        $file = "$Path/$nombre-$size-Hilos-$hilo.dat";
        for($m = 200; $m < 3600; $m*2){
            # Ciclo que itera por la cantidad de repeticiones
            for ($i = 0; $i < $Repeticiones; $i++) {
                # Ejecutar linea de comando y sino se puede decir mensaje de error
                system($cmd, "-|", "$Path/$nombre $m $hilo") or die "No se pudo ejecutar el comando: $!";
                while ($line = <$cmd>) {
                    print $fh $line;  # Imprime la linea en el archivo
                }
                close $cmd; #Finaliza el uso de la consola
            }
        }
        
        close $fh; #Cierra el archivo y finaliza el script
    }
}

