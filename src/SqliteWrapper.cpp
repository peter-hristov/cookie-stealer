#include "SqliteWrapper.h"

SqliteWrapper::SqliteWrapper()
{
    //ctor
}

SqliteWrapper::~SqliteWrapper()
{
    //dtor
}


std::vector<Cookie> SqliteWrapper::printCookies(const char *filename, int mode)
{
    std::vector<Cookie> c;

    int rc;
	char *error;

	sqlite3 *db;
	rc = sqlite3_open(filename, &db);
	if (rc)
	{
		std::cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(db) << std::endl << std::endl;
		sqlite3_close(db);
		return c;
	}

    const char *sqlSelect;

    if ( mode == 1)
        sqlSelect = "SELECT name, value, expiry FROM moz_cookies;";

    else if ( mode ==2 )
        sqlSelect = "SELECT name, value, expires_utc FROM cookies;";

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(db, sqlSelect, &results, &rows, &columns, &error);
	if (rc)
	{
		std::cerr << "Error executing SQLite3 query: " << sqlite3_errmsg(db) << std::endl << std::endl;
		sqlite3_free(error);
	}
	else
	{
		for (int rowCtr = 0; rowCtr <= rows; ++rowCtr)
		{
		    std::string a[3];
			for (int colCtr = 0; colCtr < columns; ++colCtr)
			{
				int cellPosition = (rowCtr * columns) + colCtr;
				a[colCtr] = results[cellPosition];
			}

			c.push_back(Cookie(a[0], a[1],a[2]));
		}
	}
	sqlite3_free_table(results);
	sqlite3_close(db);
}
