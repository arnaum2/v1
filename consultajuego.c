#include <my_global_h>
#include <mysql.h>
#include <string.h>

void main(){

	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta[80];

	conn = mysql_init(NULL);
	if(conn==NULL){
		printf("Error al crear la conexión: %u %s\n",mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	conn = mysql_real_connect(conn,"localhost","root","mysql","juego",0,NULL,0);
	if(conn==NULL){
		printg("Error al inicializar la conexion: %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}

	err=mysql_query(conn,"SELECT Jugador.Nombre,Partida.fecha FROM Partida,Participacion,Jugador WHERE Jugador.Username='%s' and Participacion.Jugador=Jugador.Username and Participacion.Posicion='1');
	if(err!=0){
		printf("Error al consultar datos de la base: %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}else{
		resultado=mysql_store_result(conn);
		if(resultado==NULL){
		printf("No se han encontrado");
		}else{
			row=mysql_fetch_row(resultado);
			while(row!=NULL){
				printf("Nombre: %s, Fechag: %s\n", row[0], row[1]);
				row=mysql_fetch_row(resultado);
			}
		}	
	
	}


}
