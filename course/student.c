/**
 * @file student.c
 * @author Emaan Khan (khanm345@mcmaster.ca)
 * @brief student.c contains all the functions that involve either accessing or changing the student's information
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * @brief add_grade function adds each grade percentage to the list of grades within the Student data type for that specific student
 * 
 * @param student A specific student with all its information enclosed within the Student data type
 * @param grade The grade the student has 
 * @return nothing
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;

  /** calloc is used to create an empty list of size one if the number of grades is 1 */
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double)); 
  else 
  {
    /** realloc is used to allocate more space within the list of grades to add in a new grade */
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * @brief The average function calculates the total average a student has within the course
 * 
 * @param student A specific student with all its information enclosed within the Student data type
 * @return A double-precision floating point number which is the student's grade average within the course
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;

  /** This for loop adds all the grades together and stores it into total variable */
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

/**
 * @brief The function print_student prints out the student's name, student ID, list of grades, and the average the student has within the course
 * 
 * @param student A specific student with all its information enclosed within the Student data type
 * @return nothing
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");

  /** This for loop is used to print all the student's grades */
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);


  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * @brief The function generate_random_student randomly generates a student with all its information randomly generated encolosed within the Student data type
 * 
 * @param grades The number of grades the student will have
 * @return A specific student with all its information enclosed within the Student data type
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  /** The new_student's first and last name is randomely chosen from the first_names and last_names list */
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  /** This for loop generates a random 10 digit integer and converts each integer into a string per iteration */
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  /** This for loop generates a random integer in each iteration and calls the add_grade function to add the grade to the student's list of grades */
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}