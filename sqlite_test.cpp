#include <stdio.h>
#include <iostream>
#include <clocale>
#include <sqlite3.h>


static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	sqlite3* db = 0;
	char* err = 0;
	const char* SQL;
	int tp;
	int n;
	char name[50];
	char line[1000];

	//tp = sqlite3_open("goods.db", &db);
	//if (tp) printf("Opening database fallen. \n");
	//else printf("Connection successed. \n");

	printf("Press 1 to make sql request.\nPress 2 to open/add db.\nPress 0 to stop running program.\n");

	while (1 > 0)
	{
		scanf_s("%d", &n);
		if (n == 1) {
			getchar();
			fgets(line, 1000, stdin);
			SQL = line;
			sqlite3_exec(db, SQL, callback, 0, &err);
		}
		else if (n == 2) {
			scanf_s("%s", &name, 35);
			tp = sqlite3_open(name, &db);
			if (tp) printf("Opening database fallen. \n");
			else printf("Connection successed. \n");
		}
		else if (n == 0) break;
		else printf("You entered wrong symbol!\n");
		printf("...,,...");
	}

	//SQL = "CREATE TABLE new (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(50), phone VARCHAR(50));";
	//sqlite3_exec(db, SQL, callback, 0, &err);

	//SQL = "INSERT INTO new (name, phone) VALUES ('Kate', '8906571');";
	//sqlite3_exec(db, SQL, callback, 0, &err);

	//SQL = "SELECT * FROM new;";
	//sqlite3_exec(db, SQL, callback, 0, &err);

	sqlite3_close(db);
	return 0;
}

