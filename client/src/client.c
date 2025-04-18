#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	log_info(logger,"Soy un log");
	
	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config(logger);
	char* clave = config_get_string_value(config,"CLAVE");


	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	ip = config_get_string_value(config,"IP");
	puerto = clave = config_get_string_value(config,"PUERTO");

	// Loggeamos el valor de config
	if (clave == NULL){
		log_error(logger,"no se obtuvo la clave correctamente");
	}
	log_info(logger,clave);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(clave,conexion);
	// Armamos y enviamos el paquete
	//paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("tp0.log","log_del_tp0",true,LOG_LEVEL_TRACE);

	return nuevo_logger;
}

t_config* iniciar_config(t_log* logger)
{
	t_config* nuevo_config = config_create("../cliente.config");
	if (nuevo_config == NULL) {
		log_error(logger,"no se inicializo el config");
	}

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;


	do {
		leido = readline("> ");

		if (leido == NULL) {
			log_warning(logger, "readline devolvió NULL");
			break;
		}
		if((strcmp(leido,"") == 0)){
			free(leido);
			break;
		}
		log_info(logger,leido);
		free(leido);
	}while(true);


	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}


void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
