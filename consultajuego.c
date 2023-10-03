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

	err=mysql_query(conn,"SELECT * FROM jugador);
	if(err!=0){
		printf("Error al consultar datos de la base: %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	resultado=mysql_store_result(conn);
	row=mysql_fetch_row(resultado);
	rows=SELECT COUNT(*) FROM jugador;
	int i=0;
	maxid=0;
	maxganadas=0;
	for(i=0;i<rows,i++){
		if(row[i]<row[i+1]){
			maxid=row[i+1];
			maxganadas=row[i+1];
		}row=mysql_fetch_row(resultado);
	}
	}


}
