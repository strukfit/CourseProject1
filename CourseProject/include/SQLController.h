#pragma once

#include <sqlite3.h>
#include "Exception.h"

class SQLController
{
    sqlite3* db; // Database

public:
    SQLController();

    ~SQLController();

    /// <summary>
    /// Creates and opens database
    /// </summary>
    /// <param name="name - database name"></param>
    void OpenDB(const char* name);

    /// <summary>
    /// Executing an SQL query
    /// </summary>
    /// <param name="sql - SQL statement"></param>
    /// <returns></returns>
    void ExecuteSQL(const char* sql);

    /// <summary>
    /// Preparing SQL statement(compilation into a byte-code program)
    /// </summary>
    /// <param name="stmt - sqlite3_stmt*"></param>
    /// <param name="sql - SQL statement"></param>
    /// <returns>sqlite3_stmt* stmt - prepared SQL query</returns>
    sqlite3_stmt* PrepareSQL(const char* sql);

    /// <summary>
    /// Database initialization
    /// </summary>
    void DatabaseInit();

    void CreateData();

    void DeleteData(); 

    void UpdateData();

    /// <summary>
    /// Selecting data from the table and preparing SQL statement(compilation into a byte-code program) 
    /// </summary>
    /// <param name="tableName"></param>
    /// <returns>sqlite3_stmt* stmt - prepared SQL query</returns>
    sqlite3_stmt* SelectData(const char* tableName);

    void Test();
};