/**
 * @file course.h
 * @author Emaan Khan (khanm345@mcmaster.ca)
 * @brief course.h creates a new data type to group all course information together, and it initializes functions to be created in course.c
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "student.h"
#include <stdbool.h>
 
/**
 * @brief Course type stores a course with the fields: name, code, students, and total students
 * 
 */
typedef struct _course 
{
  char name[100]; /**< Name of the course */
  char code[10]; /**< The course code which is a 10 digit number  */
  Student *students; /**< List of students of type Student */
  int total_students; /**< Total number of students enrolled within the course */
} Course;

/** Function initialization for enroll_student */
void enroll_student(Course *course, Student *student);

/** Function initialization for print_course */
void print_course(Course *course);

/** Function initialization for top_student */
Student *top_student(Course* course);

/** Function initialization for passing */
Student *passing(Course* course, int *total_passing);


