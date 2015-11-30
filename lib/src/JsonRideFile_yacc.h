/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_JSONRIDEFILE_JSONRIDEFILE_TAB_H_INCLUDED
# define YY_JSONRIDEFILE_JSONRIDEFILE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int JsonRideFiledebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    JS_STRING = 258,
    JS_INTEGER = 259,
    JS_FLOAT = 260,
    RIDE = 261,
    STARTTIME = 262,
    RECINTSECS = 263,
    DEVICETYPE = 264,
    IDENTIFIER = 265,
    OVERRIDES = 266,
    TAGS = 267,
    INTERVALS = 268,
    NAME = 269,
    START = 270,
    STOP = 271,
    CALIBRATIONS = 272,
    VALUE = 273,
    REFERENCES = 274,
    SAMPLES = 275,
    SECS = 276,
    KM = 277,
    WATTS = 278,
    NM = 279,
    CAD = 280,
    KPH = 281,
    HR = 282,
    ALTITUDE = 283,
    LAT = 284,
    LON = 285,
    HEADWIND = 286,
    SLOPE = 287,
    TEMP = 288,
    LRBALANCE = 289,
    LTE = 290,
    RTE = 291,
    LPS = 292,
    RPS = 293,
    THB = 294,
    SMO2 = 295,
    RVERT = 296,
    RCAD = 297,
    RCON = 298,
    LPCO = 299,
    RPCO = 300,
    LPPB = 301,
    RPPB = 302,
    LPPE = 303,
    RPPE = 304,
    LPPPB = 305,
    RPPPB = 306,
    LPPPE = 307,
    RPPPE = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int JsonRideFileparse (struct JsonContext *jc);

#endif /* !YY_JSONRIDEFILE_JSONRIDEFILE_TAB_H_INCLUDED  */
