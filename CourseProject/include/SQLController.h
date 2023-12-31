#pragma once

#include <sqlite3.h>
#include <wx/wx.h>
#include <fstream>
#include <string>
#include "Exception.h"

/// <summary>
/// Working with database and SQL queries useing sqlite3
/// </summary>
class SQLController
{
    sqlite3* db; // Database

public:
    SQLController();

    ~SQLController();

    /// <summary>
    /// Database file existence check 
    /// </summary>
    /// <param name="dbName"></param>
    bool isDatabaseExist(const std::string& dbName);

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

    /// <summary>
    /// Selecting data from the table and preparing SQL statement(compilation into a byte-code program) 
    /// </summary>
    /// <param name="tableName"></param>
    /// <returns>sqlite3_stmt* stmt - prepared SQL query</returns>
    sqlite3_stmt* SelectData(const char* tableName);
};