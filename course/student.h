/**
 * @file student.h
 * @author Emaan Khan (khanm345@mcmaster.ca)
 * @brief student.h creates a new data type to group all student information together, and it initializes functions to be created in student.c
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Student type stores a student with the fields: first_name, last_name, id, grades and num_grades
 * 
 */
typedef struct _student 
{ 
  char first_name[50]; /**< Student's first name */
  char last_name[50]; /**< Student's last name */
  char id[11]; /**< Student's 10 digit student ID */
  double *grades; /**< A list of the student's grades */
  int num_grades; /**< The number of grades for the student */
} Student;

/** Function initialization for add_grade */
void add_grade(Student *student, double grade);

/** Function initialization for average */
double average(Student *student);

/** Function initialization for print_student */
void print_student(Student *student);

/** Function initialization for generate_random_student */
Student* generate_random_student(int grades); 
